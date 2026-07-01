class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int b=-1;
        for(int i=31;i>=0;i--){
            if(((left>>i)&1) == ((right>>i)&1)){
                b=i;
            }else break;
        }
        // cout<<b;
        if(b==-1) return 0;
        int ans=0;
        for(int i=31;i>=b;i--){
            int v=(left>>i)&1;
            ans=ans|(v<<i);
        }
        return ans;
    }
};