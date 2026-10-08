class Solution {
    vector<string> ans;
    string s;
    int sz;
    void f(int idx, int open, string a) {
        if (idx == s.size()) {
            if (open == 0 and sz == a.size())
                ans.push_back(a);
            return;
        }

        if (s[idx] >= 'a' and s[idx] <= 'z') {
            int i = idx;
            string tmp;
            while (i < s.size() and s[i] >= 'a' and s[i] <= 'z') {
                tmp += s[i];
                i++;
            }
            f(i, open, a + tmp);
        } else {
            int i = idx;
            int cnt = 0;
            while (i < s.size() and s[i] == s[idx]) {
                i++;
                cnt++;
            }
            for (int j = 0; j <= cnt; j++) {

                string tmp = s.substr(idx, j);
                if (s[idx] == ')' and j <= open)
                    f(i, open - j, a + tmp);
                else if (s[idx] == '(')
                    f(i, open + j, a + tmp);
            }
        }
        // f(idx+1,open,a);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int extra = 0;
        int open = 0;
        int ch = 0;
        for (auto& c : s) {
            if (c >= 'a' and c <= 'z')
                ch++;
            else if (c == '(') {
                open++;
                extra++;
            } else {
                if (extra > 0)
                    extra--;
            }
        }
        sz = ch + 2 * (open - extra);
        // cout<<sz<<" "<<extra;
        f(0, 0, "");
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};