class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, pair<int,int>>> mp; 
    // str_end_<sum, cnt>
    unordered_map<int, pair<string, int>> id_strt;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_strt[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [s, ts] = id_strt[id];
        int time = t - ts;
        auto [sum, cnt] = mp[s][stationName];
        sum += time;
        cnt++;
        mp[s][stationName] = {sum, cnt};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [time, cnt] = mp[startStation][endStation];
        return 1.0 * time / cnt;        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */