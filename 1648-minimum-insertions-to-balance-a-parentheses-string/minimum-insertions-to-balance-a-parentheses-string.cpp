class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else {
                if (open > 0)
                    open--;
                else
                    cnt++;
                    
                if (i < n - 1 and s[i + 1] == ')') {
                    i++;
                } else {
                    cnt++;
                }
            }
        }
        return cnt + open * 2;
    }
};