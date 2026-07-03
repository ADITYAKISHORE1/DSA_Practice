class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> seq(1,0);
        for(int i=0;i<n;i++){
            int add=(1<<i);
            for(int j=seq.size()-1;j>=0;j--){
                seq.push_back(add+seq[j]);
            }
        }
        return seq;
    }
};