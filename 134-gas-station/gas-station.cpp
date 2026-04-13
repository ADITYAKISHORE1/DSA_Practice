class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasLeft=0;
        int curGasLeft=0;
        int stIdx=0;
        for(int i=0;i<gas.size();i++){
            totalGasLeft+=(gas[i]-cost[i]);
            curGasLeft+=(gas[i]-cost[i]);
            if(curGasLeft<0){
                curGasLeft=0;
                stIdx=i+1;
            }
        }
        return (totalGasLeft<0)?-1:stIdx;
    }
};