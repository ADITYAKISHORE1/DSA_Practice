class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n) {
            if ((n & 1) == 0) { // if 0th bit is unset do right shift until you get set bit
                n >>= 1;
            } else { // 0th bit is set
                ans++;
                if (n == 1) // if only 0th bit is set bit (Base condition) -> return
                    break;
                else { // more than one bit is set
                    if ((n & 3) == 3) // if continuous set bits from 0th bit are there, so
                                      // best way will be to add 1 to reduce k consecutive
                                      // set to 1 set bit bcz 001111 + 1 = 010000
                        n++;
                    else // if no continuous set bit starts from 0th idx
                         //101001 - 1 = 101000
                        n--;
                }
            }
        }
        return ans;
    }
};