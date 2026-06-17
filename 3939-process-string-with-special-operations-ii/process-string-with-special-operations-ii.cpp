class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0;
        for (auto& c : s) {
            if (c == '#')
                len *= 2;
            else if (c == '*') {
                if (len)
                    len--;
            } else if (c == '%')
                continue;
            else
                len++;
        }
        if (len <= k)
            return '.';
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                len = len / 2;
                k = k % len;
            } else if (s[i] == '%')
                k = len - k - 1;
            else if (s[i] == '*') {
                len++;
            } else {
                if (k == len - 1)
                    return s[i];
                len--;
            }
        }

        return '.';
    }
};