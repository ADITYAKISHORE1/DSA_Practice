class StockPrice {
    int latestTime = 0, latestPrice = 0;
    unordered_map<int, int> mp;
    set<pair<int, int>> st;

public:
    StockPrice() {}

    void update(int timestamp, int price) {
        if (mp.find(timestamp) != mp.end()) {
            st.erase({mp[timestamp], timestamp});
        }
        mp[timestamp] = price;
        st.insert({price, timestamp});
        if (timestamp >= latestTime) {
            latestTime = timestamp;
            latestPrice = price;
        }
    }

    int current() { return latestPrice; }

    int maximum() {
        auto it = *prev(st.end());
        return it.first;
    }

    int minimum() {
        auto it = *st.begin();
        return it.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */