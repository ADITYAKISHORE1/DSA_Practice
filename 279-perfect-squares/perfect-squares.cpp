class Solution {
public:
    int numSquares(int n) {
        //Lagrange's Four-Square Theorem.

        //no. of sq = 1
        if(pow((int)sqrt(n),2)==n) return 1;

        //no. of sq = 4  to satisfy -> n=4^a(8b+7)
        int t=n;
        while(t%4==0) t/=4;
        if(t%8==7) return 4;

        //no of sq = 2  to satisfy -> n= a^2 + b^2
        for(int i=1;i<sqrt(n);i++){
            int x=n-pow(i,2);
            if(pow((int)sqrt(x),2)==x) return 2;
        }

        //else no. of sq = 3
        return 3;
    }
};