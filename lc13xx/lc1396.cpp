//--- Q: 1396. Design Underground System

//--- map
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        // edge case: check if in the people or not
        if (people.find(id) != people.end()) {
            return;
        }
        people[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // edge case: check if in the people or not
        string path = people[id].first + "_" + stationName;
        if (people.find(id) == people.end()) {
            return;
        }
        // edge case: check in time:
        if (t < people[id].second) {
            return;
        }
        ++station[path].first;
        station[path].second += t - people[id].second;
        people.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "_" + endStation;
        return (double)station[path].second / station[path].first;
    }
    unordered_map<string, pair<int, int>> station; // path, <count, totol time>
    unordered_map<int, pair<string, int>> people; // id, <station, time>
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */