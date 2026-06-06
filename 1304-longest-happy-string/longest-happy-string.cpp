class Solution {
    void add(string& s, char c, int& a) {
        a--;
        s += c;
    }

public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        while (a > 0 or b > 0 or c > 0) {
            int n = s.size();
            if (n >= 2 and s[n - 1] == s[n - 2]) {
                if (s[n - 1] == 'a') {
                    if (b == 0 and c == 0)
                        break;
                    else if (b >= c) {
                        add(s, 'b', b);
                    } else {
                        add(s, 'c', c);
                    }
                } else if (s[n - 1] == 'b') {
                    if (a == 0 and c == 0)
                        break;
                    else if (a >= c) {
                        add(s, 'a', a);
                    } else {
                        add(s, 'c', c);
                    }
                } else if (s[n - 1] == 'c') {
                    if (a == 0 and b == 0)
                        break;
                    else if (b >= a) {
                        add(s, 'b', b);
                    } else {
                        add(s, 'a', a);
                    }
                }
            } else {
                int maxm = max({a, b, c});
                if (maxm == a)
                    add(s, 'a', a);
                else if (maxm == b)
                    add(s, 'b', b);
                else
                    add(s, 'c', c);
            }
        }
        return s;
    }
};