class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n) {
            if ((n & 1) == 0) {
                n >>= 1;
            } else {
                if (n == 1) {
                    ans++;
                    break;
                } else {
                    if ((n & 3) == 3)
                        n++;
                    else
                        n--;
                    ans++;
                }
            }
        }
        return ans;
    }
};