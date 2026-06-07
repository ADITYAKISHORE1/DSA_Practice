class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> st,st2;
        for (auto i : arr) {
            if (i >= 0)
                st.insert(i);
            else st2.insert(i);
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

        while (!st2.empty()) {
            int a = *prev(st2.end());
            st2.erase(prev(st2.end()));
            auto lb = st2.lower_bound(2 * a);
            // cout << *lb << " " << 2 * a << endl;
            if(st2.empty()) return false;
            if (*lb != 2 * a)
                return false;
            st2.erase(lb);
        }
        return true;
    }
};