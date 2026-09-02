class Solution {
    static constexpr int MOD=1e9+7;
    long long expo(long long base,long long power){
        long long res=1;
        base%=MOD;

        while(power){
            if(power&1) res=(res*base)%MOD;

            base=(base*base)%MOD;
            power>>=1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        long long evenWays=expo(5,even);
        long long oddWays=expo(4,odd);

        return (evenWays*oddWays)%MOD;
    }
};