class Solution {
    int maxCnt = 0;
    vector<int> empCnt;
    void f(int n, int cnt, vector<vector<int>>& req) {
        if (n == req.size()) {
            int change = 0;
            for (auto& i : empCnt)
                change += (i != 0);
            if (change == 0) {
                maxCnt = max(maxCnt, cnt);
            }
            return;
        }
        empCnt[req[n][1]]++;
        empCnt[req[n][0]]--;
        f(n + 1, cnt + 1, req);
        empCnt[req[n][1]]--;
        empCnt[req[n][0]]++;
        f(n + 1, cnt, req);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        empCnt.resize(n, 0);
        f(0, 0, requests);
        return maxCnt;
    }
};