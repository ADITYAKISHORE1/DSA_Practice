class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;
        stack<int> ct;
        int num = 0;
        string cur = "";
        for (auto& c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                ct.push(num);
                st.push(cur);
                num = 0;
                cur = "";
            } else if (c == ']') {
                int k = ct.top();
                ct.pop();
                string prev = st.top();
                st.pop();
                while (k--)
                    prev += cur;
                cur = prev;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};