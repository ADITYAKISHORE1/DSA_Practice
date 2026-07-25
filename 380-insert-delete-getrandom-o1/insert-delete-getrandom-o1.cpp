class RandomizedSet {
    int n;
    unordered_set<int> st;
public:
    RandomizedSet() {
        n=0;
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end()) return false;
        st.insert(val);
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val)==st.end()) return false;
        st.erase(val);
        n--;
        return true;
    }
    
    int getRandom() {
        vector<int> v(st.begin(),st.end());
        int r=rand()%n;
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */