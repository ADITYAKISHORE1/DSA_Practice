class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ones, zeros;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ones.push_back({i, j});
                else
                    zeros.push_back({i, j});
            }
        }
        int ans=0;
        for (auto& j : zeros) {
            int minCompDist = INT_MAX;
            for (auto& i : ones) {
                minCompDist=min(minCompDist,(abs(j[0]-i[0])+abs(j[1]-i[1])));
            }
            ans=max(ans,minCompDist);
        }
        return (ans==INT_MAX or ans==0)?-1:ans;
    }
};