class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto& i : asteroids) {
            bool exp = 0;
            while (!st.empty() and st.top() > 0 and i < 0) {
                if (abs(st.top()) < abs(i))
                    st.pop();
                else if (abs(st.top()) == abs(i)) {
                    exp = 1;
                    st.pop();
                    break;
                } else {
                    exp = 1;
                    break;
                }
            }
            if (!exp)
                st.push(i);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};