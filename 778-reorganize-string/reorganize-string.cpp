class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char& c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > ((n + 1) / 2))
                return "";
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], (i + 'a')});
        }
        string a;
        while (!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();
            if (a.empty() or a.back() != c) {
                a += c;
                f--;
            } else if (!pq.empty()) {
                auto [af, ac] = pq.top();
                pq.pop();
                a += ac;
                af--;
                if (af > 0)
                    pq.push({af, ac});
            }
            if (f > 0)
                pq.push({f, c});
        }
        return a;
    }
};