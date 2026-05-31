class Solution {
    string add(string& a, string& b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;

        while (i >= 0 || j >= 0 || c) {
            int s = c;

            if (i >= 0)
                s += a[i--] - '0';
            if (j >= 0)
                s += b[j--] - '0';

            ans.push_back((s % 10) + '0');
            c = s / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ans="0";
        for (int i = num1.size() - 1; i >= 0; i--) {
            string s;
            int carry = 0;
            for (int k = 0; k < num1.size() - i - 1; k++)
                s += "0";
            for (int j = num2.size() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0') + carry;
                s += ((mul % 10) + '0');
                carry = mul / 10;
            }
            if (carry > 0)
                s += (carry + '0');
            reverse(s.begin(), s.end());
            ans = add(ans, s);
        }
        return ans;
    }
};