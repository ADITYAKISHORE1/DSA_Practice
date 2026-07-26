class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            if(mpp.count(target-numbers[i])){
                for(auto& j:mpp[target-numbers[i]]){
                    if(i!=j){
                        return {j+1,i+1};
                    }
                }
            }
            mpp[numbers[i]].push_back(i);
        }
        return {-1,-1};
    }
};