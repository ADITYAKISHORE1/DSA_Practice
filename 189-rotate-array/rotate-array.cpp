class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums.end()-k%n,nums.end());
        reverse(nums.begin(),nums.end()-k%n);
        reverse(nums.begin(),nums.end());
    }
};