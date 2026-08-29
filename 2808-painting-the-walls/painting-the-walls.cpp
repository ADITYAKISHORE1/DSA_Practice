class Solution {
    int dp[501][501];
    int f(int n, int walls, vector<int>& cost, vector<int>& time) {
        if (walls <= 0)
            return 0;
        if (n < 0) {
            return 1e9;
        }
        if (dp[n][walls] != -1)
            return dp[n][walls];
        int take = cost[n] + f(n - 1, walls - time[n] - 1, cost, time);
        int notTake = f(n - 1, walls, cost, time);
        return dp[n][walls] = min(take, notTake);
    }
    // here the dp state is if i hire paid painter of ith wall then totalWalls -
    // time[i]-1 walls will be left Bcz till paid painter painting ith wall the
    // free painter will paint walls equal to time[i] as we know free painter
    // takes only 1 unit for time to paint the wall. so we take two state var ->
    // idx and no. of walls left.
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return f(n - 1, n, cost, time);
    }
};