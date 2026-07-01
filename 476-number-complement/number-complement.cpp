class Solution {
public:
    int findComplement(int num) {
        int m=0;
        for(int i=0;i<32 and num!=0;i++){
            m|=(((num&1)^1)<<i);
            num>>=1;
        }
        return m;
    }
};