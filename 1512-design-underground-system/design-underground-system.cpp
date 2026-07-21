class UndergroundSystem {
    unordered_map<int,pair<string,int>> ci;
    unordered_map<string,pair<long long,int>> travel;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ci[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [srcStation,t1]=ci[id];
        string s=srcStation+"#"+stationName;
        travel[s].first+=(t-t1);
        travel[s].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s=startStation+"#"+endStation;
        auto [diff,cnt]=travel[s];
        return (double)diff/cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */