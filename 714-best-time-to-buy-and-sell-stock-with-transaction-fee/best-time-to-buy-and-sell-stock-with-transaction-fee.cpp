class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int curSell=0;
        int aheadBuy=0,aheadSell=0;
        for(int i=n-1;i>=0;i--){
            curSell=max(prices[i]+aheadBuy,aheadSell);
            aheadBuy=max(-prices[i]-fee+aheadSell,aheadBuy);
            aheadSell=curSell;
        }
        return aheadBuy;
    }
};