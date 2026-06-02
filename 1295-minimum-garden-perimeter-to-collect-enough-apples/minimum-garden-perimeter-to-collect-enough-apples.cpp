class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l=1,r=1e6,mid;
        long long a=0;
        while(l<=r){
            mid=l+(r-l)/2;
            long long apples=2LL*mid*(2*mid+1)*(mid+1);
            if(neededApples<=apples){
                a=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return 8*a;
    }
};