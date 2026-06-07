class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> st;
        for (auto i : arr) {
            if (i >= 0)
                st.insert(i);
        }
        while (!st.empty()) {
            int a = *st.begin();
            st.erase(st.begin());
            auto lb = st.lower_bound(2 * a);
            // cout << *lb << " " << 2 * a << endl;
            if(st.empty()) return false;
            if (*lb != 2 * a)
                return false;
            st.erase(lb);
        }

        for (auto i : arr) {
            if (i < 0)
                st.insert(i);
        }

        while (!st.empty()) {
            int a = *prev(st.end());
            st.erase(prev(st.end()));
            auto lb = st.lower_bound(2 * a);
            // cout << *lb << " " << 2 * a << endl;
            if(st.empty()) return false;
            if (*lb != 2 * a)
                return false;
            st.erase(lb);
        }
        return true;
    }
};