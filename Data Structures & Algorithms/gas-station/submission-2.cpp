class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxm=INT_MIN;
        int idx=0;
        int sum=0;
        int cursum=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            cursum+=gas[i]-cost[i];
            if(cursum<0){
                cursum=0;
                idx=i+1;
            }
        }
        if(sum<0) return -1;
        return idx;
    }
};
