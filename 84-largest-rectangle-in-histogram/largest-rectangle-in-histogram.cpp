class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);
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
        int pse=-1;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            pse =(!st.empty())?st.top():-1;
            maxArea = max(maxArea, (nse[i] - pse - 1) * heights[i]);
            st.push(i);
        }
        return maxArea;
    }
};