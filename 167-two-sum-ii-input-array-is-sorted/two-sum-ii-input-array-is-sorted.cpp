class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[numbers[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(mpp.count(target-numbers[i])){
                for(auto& j:mpp[target-numbers[i]]){
                    if(i!=j){
                        return {i+1,j+1};
                    }
                }
            }
        }
        return {-1,-1};
    }
};