class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int open = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == ']' && open > 0) {
                open--;
                continue;
            }
            open++;
        }
        cout << open;
        return open / 2 > 0 ? open / 2 : 0;
    }
};