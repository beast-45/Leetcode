class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> mp;
    unordered_map<string,pair<int,int>> avgMp;
    UndergroundSystem() {
        
    }
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    void checkOut(int id, string stationName, int t) {
        string startStation = mp[id].first;
        int startTime = mp[id].second;
        int time = t - startTime;
        string key = startStation+"-"+stationName;
        avgMp[key].first += time;;
        avgMp[key].second += 1;
        mp.erase(id);
    }
    double getAverageTime(string startStation, string endStation) {
        auto [totalTime,count] = avgMp[startStation+"-"+endStation];
        return (double)totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */