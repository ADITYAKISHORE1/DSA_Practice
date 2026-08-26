class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxLen=0;
        for(auto& i:st){
            if(!st.count(i-1)){
                int len=1;
                while(st.count(i+len)) len++;
                maxLen=max(len,maxLen);
            }
        }
        return maxLen;
    }
};