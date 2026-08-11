class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n), pse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();
            
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (nse[i] - pse[i] - 1) * heights[i]);
        }
        return maxArea;
    }
};