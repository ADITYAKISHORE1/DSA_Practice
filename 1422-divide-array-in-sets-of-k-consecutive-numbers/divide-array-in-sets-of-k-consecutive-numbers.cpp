class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        for (auto& i : nums)
            freq[i]++;
        while (!freq.empty()) {
            int x = freq.begin()->first;
            int f = freq.begin()->second;
            for (int i = x; i < x + k; i++) {
                if (freq.find(i) == freq.end() or freq[i] < f)
                    return false;
                freq[i] -= f;
                if (freq[i] == 0) {
                    freq.erase(i);
                }
            }
        }
        return true;
    }
};