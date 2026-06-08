class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int cntEqual = 0;
        for (auto& i : nums) {
            if (i < pivot)
                less.push_back(i);
            else if (i > pivot)
                greater.push_back(i);
            else
                cntEqual++;
        }
        while(cntEqual--) less.push_back(pivot);
        for(auto& i:greater){
            less.push_back(i);
        }
        return less;
    }
};