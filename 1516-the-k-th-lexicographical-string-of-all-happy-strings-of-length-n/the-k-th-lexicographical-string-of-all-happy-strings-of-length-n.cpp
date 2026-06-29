class Solution {
    string ans;
    int cnt = 0;
    void f(int n, int k, char c, string s) {
        if (n < 0) {
            cnt++;
            if (cnt == k)
                ans = s;
            return;
        }
        for (int i = 0; i < 3; i++) {
            char ch = i + 'a';
            if (c != ch) {
                f(n - 1, k, ch, s + ch);
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        ans = "";
        f(n - 1, k, 0, "");
        return ans;
    }
};