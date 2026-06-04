class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        int l = 0, r = costs.size() - 1;
        int i;
        for(i=l;i<candidates;i++) pq.push({costs[i], 'L'});
        l=i;
        for(i=r;i>r-candidates and i>=l;i--)pq.push({costs[i], 'R'});
        r=i;
        long long sum = 0;
        while (k > 0) {
            auto [v, c] = pq.top();
            pq.pop();
            sum += v;
            k--;
            if (k == 0)
                break;
            if (l <= r) {
                if (c == 'L') {
                    pq.push({costs[l], 'L'});
                    l++;

                } else if (c == 'R') {
                    pq.push({costs[r], 'R'});
                    r--;
                }
            }
        }
        return sum;
    }
};