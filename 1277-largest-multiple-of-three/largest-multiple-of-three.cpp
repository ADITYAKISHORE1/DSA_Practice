class Solution {
    bool remov(int cnt, int rem, int& n, string& s) {
        for (int i = n - 1; i >= 0 and cnt > 0; i--) {
            if ((s[i] - '0') % 3 == rem) {
                s.erase(i, 1);
                cnt--;
                if (cnt == 0) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        int rem = 0;
        string s;
        for (auto& i : digits) {
            rem = (rem + i) % 3;
            s.push_back(i + '0');
        }
        sort(s.rbegin(), s.rend());
        if (rem == 1) {
            if (remov(1, 1, n, s) == true) {
                if (!s.empty() and s[0] == '0')
                    return "0";
                return s;
            }
            if (remov(2, 2, n, s) == true) {
                if (!s.empty() and s[0] == '0')
                    return "0";
                return s;
            }
            return "";
        } else if (rem == 2) {
            if (remov(1, 2, n, s) == true) {
                if (!s.empty() and s[0] == '0')
                    return "0";
                return s;
            }
            if (remov(2, 1, n, s) == true) {
                if (!s.empty() and s[0] == '0')
                    return "0";
                return s;
            }
            return "";
        }
        if (!s.empty() and s[0] == '0')
            return "0";
        return s;
    }
};

// rem=1  1 , 2,2
// rem=2  2,  1,1