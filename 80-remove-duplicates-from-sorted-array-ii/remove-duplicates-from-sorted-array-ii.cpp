class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            bool t=0;
            while(i<nums.size()-1 and nums[i]==nums[i+1]){
                i++;
                t=1;
            }
            nums[j++]=nums[i];
            if(t) nums[j++]=nums[i];
        }
        return j;
    }
};