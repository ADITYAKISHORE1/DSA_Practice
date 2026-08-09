class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n = prices.size();
        int m = discounts.size();
        int i = 0;
        double ans = 0;
        for (int j = 0; j < n; j++) {
            if (i < m) {
                ans += (double)(prices[j] * (100 - discounts[i]) / 100.0);
                i++;
            } else
                ans += prices[j];
        }
        return ans;
    }
};