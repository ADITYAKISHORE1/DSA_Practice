class RandomizedCollection {
    vector<pair<int, int>> v;
    unordered_map<int, vector<int>> mpp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool chk = !mpp.count(val);
        mpp[val].push_back(v.size());
        v.push_back({val, mpp[val].size() - 1});
        return chk;
    }

    bool remove(int val) {
        bool chk = mpp.count(val);
        if (chk) {
            pair<int, int> last = v.back();
            mpp[last.first][last.second] = mpp[val].back();
            v[mpp[val].back()] = last;
            mpp[val].pop_back();
            if (mpp[val].empty())
                mpp.erase(val);
            v.pop_back();
        }
        return chk;
    }

    int getRandom() { return v[rand() % v.size()].first; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */