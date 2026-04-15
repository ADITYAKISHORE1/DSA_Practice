class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, int>> pq;
        vector<int> hash(26, 0);
        for (char& c : tasks) {
            hash[c - 'A']++;
        }
        for (int i = 0; i < 26; i++)
            if (hash[i] > 0) pq.push({hash[i], i});
        queue<pair<int, pair<int, int>>> cool;
        int idx = 0;
        while (!pq.empty() || !cool.empty()) {
            while (!cool.empty() and cool.front().first <= idx) {
                pq.push(cool.front().second);
                cool.pop();
            }
            if (!pq.empty()) {
                auto [freq, c] = pq.top();
                pq.pop();
                if (--hash[c] > 0) cool.push({idx + n + 1, {hash[c], c}});
            }

            idx++;
        }
        return idx;
    }
};
