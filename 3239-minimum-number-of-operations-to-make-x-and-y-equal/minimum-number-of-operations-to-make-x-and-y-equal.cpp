class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x)
            return y - x;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, x});
        unordered_map<int, int> vis;
        while (!pq.empty()) {
            auto [st, v] = pq.top();
            pq.pop();
            if (vis[v])
                continue;
            if (v == y)
                return st;

            pq.push({st + abs(y - v), y}); // direct inc or dec for cur val to result y
            vis[v] = 1;

            int r = v % 5;
            pq.push({st + r + 1, v / 5}); // going to nearest multiple of 5 less
                                          // than cur val and dividing it
            if (r)
                pq.push({st + (5 - r) + 1, v / 5 + 1}); // going to nearest multiple of 5 greater
                                                        // than cur val and dividing it

            r = v % 11;
            pq.push({st + r + 1, v / 11}); // going to nearest multiple of 11
                                           // less than cur val and dividing it
            if (r) {
                pq.push({st + (11 - r) + 1, v / 11 + 1}); // going to nearest multiple of 11
                                                          // greater than cur val and dividing it
            }
        }
        return -1;
    }
};