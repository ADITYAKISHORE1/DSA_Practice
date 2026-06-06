class Solution {
    void addA(string& s, int& a) {
        a--;
        s += 'a';
    }
    void addB(string& s, int& b) {
        b--;
        s += 'b';
    }
    void addC(string& s, int& c) {
        c--;
        s += 'c';
    }

public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        while (a > 0 or b > 0 or c > 0) {
            int maxm = max({a, b, c});
            if (s.size() >= 2 and s[s.size() - 1] == s[s.size() - 2]) {
                if (s[s.size() - 1] == 'a') {
                    if (b == 0 and c == 0)
                        break;
                    else if (b >= c) {
                        addB(s, b);
                    } else if (c > b) {
                        addC(s, c);
                    }
                } else if (s[s.size() - 1] == 'b') {
                    if (a == 0 and c == 0)
                        break;
                    else if (a >= c) {
                        addA(s, a);
                    } else if (c > a) {
                        addC(s, c);
                    }
                } else if (s[s.size() - 1] == 'c') {
                    if (a == 0 and b == 0)
                        break;
                    if (b >= a) {
                        addB(s, b);
                    } else if (a > b) {
                        addA(s, a);
                    }
                }
            } else {
                if (maxm == a)
                    addA(s, a);
                else if (maxm == b)
                    addB(s, b);
                else
                    addC(s, c);
            }
        }
        return s;
    }
};