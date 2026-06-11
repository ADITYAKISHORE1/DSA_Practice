class Solution {
    vector<vector<int>> dp;
    int f(int i, int prev, vector<int>& v) {
        if (i == v.size())
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int take = 0;
        if (v[i] % v[prev] == 0) {
            take = 1 + f(i + 1, i, v);
        }
        int notTake = f(i + 1, prev, v);
        return dp[i][prev] = max(take, notTake);
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        nums.push_back(1);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        vector<int> ans;
        // cout<<len;
        int i = 1, prev = 0;
        while (i < n) {
            int take = INT_MIN;

            if (nums[i] % nums[prev] == 0) {
                take = 1 + f(i+1,i,nums);
            }

            int notTake = f(i+1,prev,nums);

            if (take >= notTake) {
                ans.push_back(nums[i]);
                prev = i;
            }

            i++;
        }

        return ans;
    }
};