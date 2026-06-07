class Solution {
    vector<string> ans;
    string s;

    void f(int prev, int n, int k) {
        if (k < 0)
            return;
        if (n == 0) {
            s.push_back('0');
            ans.push_back(s);
            s.pop_back();
            if (!prev) {
                s.push_back('1');
                ans.push_back(s);
                s.pop_back();
            }
            return;
        }
        s.push_back('0');
        f(0, n - 1, k);
        s.pop_back();

        if (!prev) {
            s.push_back('1');
            f(1, n - 1, k - n);
            s.pop_back();
        }
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        s.reserve(n);
        f(0, n - 1, k);
        for(auto & s:ans) reverse(s.begin(),s.end());
        return ans;
    }
};