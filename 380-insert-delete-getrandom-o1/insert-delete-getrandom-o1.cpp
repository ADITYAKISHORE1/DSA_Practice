class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mpp;
    int n;
public:
    RandomizedSet() {
        n=0;
    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        mpp[val]=n;
        v.push_back(val);
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        v[mpp[val]]=v[n-1];
        mpp[v[n-1]]=mpp[val];
        v.pop_back();
        n--;
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */