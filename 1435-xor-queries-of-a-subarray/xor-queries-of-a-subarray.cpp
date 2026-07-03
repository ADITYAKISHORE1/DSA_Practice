class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefXOR=arr;
        for(int i=1;i<prefXOR.size();i++){
            prefXOR[i]^=prefXOR[i-1];
        }
        vector<int> ans;
        for(auto& q:queries){
            if(q[0]-1>=0){
                ans.push_back(prefXOR[q[1]]^prefXOR[q[0]-1]);
            }else{
                ans.push_back(prefXOR[q[1]]);
            }
        }
        return ans;
    }
};