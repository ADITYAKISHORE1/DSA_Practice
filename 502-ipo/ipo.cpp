class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            capital_minimize;
        for (int i = 0; i < profits.size(); i++) {
            capital_minimize.push({capital[i], profits[i]});
        }
        priority_queue<pair<int, int>> profit_maximize;
        while (k > 0) {
            while (!capital_minimize.empty() and
                   w >= capital_minimize.top().first) {
                auto [ct, pt] = capital_minimize.top();
                capital_minimize.pop();
                profit_maximize.push({pt, ct});
            }
            if (profit_maximize.empty())
                break;
            else {
                auto [pr, cp] = profit_maximize.top();
                profit_maximize.pop();
                w += pr;
                k--;
                if (k == 0)
                    return w;
            }
        }
        return w;
    }
};