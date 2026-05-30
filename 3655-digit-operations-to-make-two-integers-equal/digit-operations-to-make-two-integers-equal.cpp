class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int minOperations(int n, int m) {
        if (isPrime(n) or isPrime(m))
            return -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unordered_map<int, int> dist;
        pq.push({n, n});
        dist[n] = n;
        int ans = INT_MAX;
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (d > dist[v])
                continue;
            if (v == m)
                ans = min(ans, d);
            string s = to_string(v);
            for (int c = 0; c < s.size(); c++) {
                if (s[c] != '9') {
                    string x = s;
                    x[c]++;
                    int x_num = stoi(x);
                    if (!isPrime(x_num)) {
                        int nd = d + x_num;
                        if (!dist.count(x_num) or nd < dist[x_num]) {
                            dist[x_num] = nd;
                            pq.push({nd, x_num});
                        }
                    }
                }
                if (s[c] != '0') {
                    string x = s;
                    x[c]--;
                    int x_num = stoi(x);
                    if (!isPrime(x_num)) {
                        int nd = d + x_num;
                        if (!dist.count(x_num) or nd < dist[x_num]) {
                            dist[x_num] = nd;
                            pq.push({nd, x_num});
                        }
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};