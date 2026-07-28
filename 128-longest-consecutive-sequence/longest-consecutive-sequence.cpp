class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int maxCnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1){
                cnt++;
            }
            else if(nums[i+1]-nums[i]==0){
                continue;
            }
            else{
                cnt=1;
            }
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};