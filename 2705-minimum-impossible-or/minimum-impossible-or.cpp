class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=1;
        for(auto& v:nums){
            if(v>n) return n;
            if(v==n) n*=2;
        }
        return n;
    }
};
// only pow of 2 is not possible to obtain from any or operation
// all other can be achieved by doing bitwise OR of smaller numbers
// OR of large no. can't give smaller number