class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curCool=0;
        int aheadBuy=0,aheadSell=0,aheadCool=0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            curCool = max(aheadCool, aheadBuy);
            aheadBuy = max(aheadBuy, -prices[i] + aheadSell);
            aheadSell = max(aheadSell, prices[i] + aheadCool);
            aheadCool=curCool;
        }
        return aheadBuy;
    }
};