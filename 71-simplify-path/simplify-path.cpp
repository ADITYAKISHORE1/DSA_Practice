class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        for (int i = 0; i < n;) {
            if (path[i] == '/') {
                while (i < n and path[i] == '/')
                    i++;
                st.push("/");
            } else {
                string s;
                while (i < n and path[i] != '/') {
                    s += path[i];
                    i++;
                }
                if (s == ".") {
                    if (!st.empty())
                        st.pop();
                    continue;
                } else if (s == "..") {
                    if (!st.empty())
                        st.pop();
                    if (!st.empty())
                        st.pop();
                    if (!st.empty())
                        st.pop();
                } else
                    st.push(s);
            }
        }
        while (!st.empty() and st.top() == "/")
            st.pop();
        string ans;
        while (!st.empty()) {
            // cout<<st.top()<<endl;
            ans = st.top() + ans;
            st.pop();
        }
        if(ans.empty()) return "/";
        return ans;
    }
};