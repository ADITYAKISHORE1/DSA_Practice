class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        vector<int> hash(1001,0);
        for(auto& i:hand) hash[i]++;
        for(int i=0;i<1001;i++){
            if(hash[i]>0){
                for(int j=1;j<groupSize;j++){
                    if(hash[i+j]<hash[i])
                        return false;
                    hash[i+j]-=hash[i];
                }
                hash[i]=0;
            }
        }
        return true;
    }
};
