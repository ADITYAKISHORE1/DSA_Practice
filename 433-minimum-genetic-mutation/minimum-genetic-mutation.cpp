class Solution {
    bool strDiff(string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            cnt += (s[i] != t[i]);
        }
        return (cnt == 1);
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.insert(bank.begin(), startGene);
        int n = bank.size();
        vector<int> dist(n, 1e9);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int& it = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (it != i && strDiff(bank[it], bank[i]) &&
                    dist[i] > dist[it] + 1) {
                    dist[i] = dist[it] + 1;
                    q.push(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (bank[i] == endGene) {
                return (dist[i] == 1e9) ? -1 : dist[i];
            }
        }
        return -1;
    }
};