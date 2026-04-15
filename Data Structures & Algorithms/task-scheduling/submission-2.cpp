class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26, 0);
        for (auto& c : tasks) hash[c - 'A']++;
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> cool;
        int time = 0;
        for (int c = 0; c < 26; c++)
            if (hash[c] > 0) pq.push({hash[c], c});
        while (!pq.empty() or !cool.empty()) {
            if (!cool.empty() and cool.front().first <= time) {
                int c = cool.front().second;
                cool.pop();
                pq.push({hash[c], c});
            }
            if (!pq.empty()) {
                auto c = pq.top().second;
                pq.pop();
                if (--hash[c] > 0) cool.push({time + n + 1, c});
            }
            time++;
        }
        return time;
    }
};
