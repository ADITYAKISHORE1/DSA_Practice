class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mpp;
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                cnt++;
            else {
                mpp[{nums[i], nums[i - 1]}]++;
                mpp[{nums[i - 1], nums[i]}]++;
            }
        }
        int mx = 0;
        for (auto& i : mpp) {
            mx = max(mx, i.second);
        }
        return cnt+mx;
    }
};