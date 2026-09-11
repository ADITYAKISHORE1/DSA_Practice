class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;

        for (char&c:s) {
            if (c == ']' && imbalance > 0) {
                imbalance--;
                continue;
            }
            imbalance++;
        }
        return imbalance / 2;
    }
};