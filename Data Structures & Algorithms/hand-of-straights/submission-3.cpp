class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        vector<int> hash(hand[n-1]+1,0);
        for(auto& i:hand) hash[i]++;
        for(int i=0;i<=hand[n-1];i++){
            if(hash[i]>0){
                int freq=hash[i];
                for(int j=1;j<groupSize;j++){
                    if(i+j>hand[n-1] or hash[i+j]<freq)
                        return false;
                    hash[i+j]-=freq;
                }
                hash[i]=0;
            }
        }
        return true;
    }
};
