class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        for (auto& i : matches) {
            if (mpp.find(i[0]) == mpp.end())
                mpp[i[0]] = 0;
            mpp[i[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto& i : mpp) {
            if (i.second == 0)
                ans[0].push_back(i.first);
            if (i.second == 1)
                ans[1].push_back(i.first);
        }
        return ans;
    }
};