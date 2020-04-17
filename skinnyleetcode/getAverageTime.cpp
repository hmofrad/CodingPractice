/*
 *  https://leetcode.com/problems/design-underground-system/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class UndergroundSystem {
public:
    struct trip_info {
        int id;
        std::string startStation;
        std::string endStation;
        int startTime;
        int endTime;
    };
    
    //std::vector<struct trip_info> trips;
    std::unordered_map<int, trip_info> temp;
    std::unordered_map<std::string, std::pair<int, int>> stat;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        temp[id]={id, stationName, "", t, 0};
    }
    
    void checkOut(int id, string stationName, int t) {
        temp[id].endStation = stationName;
        temp[id].endTime = t;
        std::string key = temp[id].startStation + temp[id].endStation;
        stat[key].first+=temp[id].endTime-temp[id].startTime;
        stat[key].second++;
        //trips.push_back(temp[id]);
        temp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        std::string key = startStation + endStation;
        return (double) stat[key].first/stat[key].second;
        /*
        int count = 0;
        double time = 0;
        for(auto trip: trips) {
            if(trip.startStation == startStation and trip.endStation == endStation) {
                time += trip.endTime - trip.startTime;
                count++;
            }
        }
        return time ? time/count : 0;
        */
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */