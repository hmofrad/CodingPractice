/*
 *  https://leetcode.com/problems/design-log-storage-system/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class LogSystem {
public:
    std::map<std::string, int> db;
    
    LogSystem() {}

    
    void put(int id, string timestamp) {
        db[timestamp]=id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        std::vector<int> ids;
        
        while(1) {
            if (gra == "Second") break;
            s[17] = '0'; s[18] = '0'; e[17] = '5'; e[18] = '9';
            if (gra == "Minute") break;
            s[14] = '0'; s[15] = '0'; e[14] = '5'; e[15] = '9';
            if (gra == "Hour") break;
            s[11] = '0'; s[12] = '0'; e[11] = '2'; e[12] = '3';
            if (gra == "Day") break;
            s[8] = '0'; s[9] = '0'; e[8] = '3'; e[9] = '1';
            if (gra == "Month") break;
            s[5] = '0'; s[6] = '0'; e[5] = '1'; e[6] = '2';
            break;
        }
        
        
        auto it1 = db.lower_bound(s);
        if(it1 == db.end()) return ids;
        auto it2 = db.upper_bound(e);
        for(; it1 != it2; it1++) ids.push_back(it1->second);
        
        return ids;
    }
};



 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


    std::map<long, int> db;
    std::map<std::string, long> aux;
    const int nmonthes = 12;
    const int ndays = 31;
    const int nhours = 24;
    const int nminutes = 60;
    const int nseconds = 60;
    
    void put(int id, string timestamp);
    vector<int> retrieve(string s, string e, string gra);
    long to_int(string timestamp);
    void LogSystem() {
        aux["Year"]=0;
        aux["Month"]=-nmonthes*ndays*nhours*nminutes*nseconds+1;
        aux["Day"]=-ndays*nhours*nminutes*nseconds+1;
        aux["Hour"]=-nhours*nminutes*nseconds+1;
        aux["Minute"]=-nminutes*nseconds+1;
        aux["Second"]=-nseconds+1;
        
        std::vector<std::string> logs = {"2017:01:01:23:59:59", "2017:01:01:22:59:59", "2016:01:01:00:00:00"};
        std::vector<int> ids = {1,2,3};
        std::vector<std::string> test1 = {"2016:01:01:01:01:01","2017:01:01:23:00:00","Year"};
        std::vector<std::string> test2 = {"2016:01:01:01:01:01","2017:01:01:23:00:00","Year"};
        /*
        for(int i = 0; i< logs.size(); i++) {
            
            put(ids[i], logs[i]);
            printf("2.%d\n", i);
        }
        printf(">>\n");
        */
        std::string s1 = "2017:01:01:23:59:59";
        long t1 = to_int(s1);
        
        std::string s2 = "2017:01:00:00:00:00";
        long t2 = to_int(s2);
        
        printf("%s %lu | %s %lu\n", s1.c_str(), t1, s2.c_str(), t2);
        printf("%lu\n", t1+aux["Day"]);
        
        
        //retrieve(test1[0], test1[1], test1[2]);

    }
    long to_int(string timestamp) {
        int year = stoi(timestamp.substr(2,2))+1;
        int month = stoi(timestamp.substr(5,2));
        int day = stoi(timestamp.substr(8,2));
        int hour = stoi(timestamp.substr(11,2));
        int minute = stoi(timestamp.substr(14,2));
        int second = stoi(timestamp.substr(17,2));
        return year*nmonthes*ndays*nhours*nminutes*nseconds +
               month*ndays*nhours*nminutes*nseconds +
               day*nhours*nminutes*nseconds +
               hour*nminutes*nseconds +
               minute*nseconds +
               second;
    }
    
    void put(int id, string timestamp) {
        long time = to_int(timestamp);
        db[time]=id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        long from = to_int(s);
        long from1 = to_int(s) + aux[gra];
        long to = to_int(e);
        long to1 = to_int(e) + aux[gra];
        
        std::vector<int> ids;
        auto from2 = db.lower_bound(from) == db.end() ? db.begin() : db.lower_bound(from);
        auto to2 = db.upper_bound(to) == db.end() ? db.end() : db.upper_bound(to);
        printf("%s %lu %lu | %s %lu %lu\n", s.c_str(), from, from1,  e.c_str(), to, to1);
        
        for(auto it: db) {
            printf("%lu %d %d\n", it.first, it.second, it.first >= from1 and it.first < to1);
            if(it.first >= from1 and it.first < to1) ids.push_back(it.second);
        }
        printf("\n");
        
        //for(auto it = from2; it != to2; it++) {
        //    printf("%lu %d\n", it->first, it->second);
        //    if(it->first >= from1 and it->first < to1) ids.push_back(it->second);
        //}
        //printf("\n");
        return ids;
    }



int main() {
    LogSystem();
    return 0;
}




/*
class LogSystem {
public:
    const int startyear=2000;
    const int nyears = 18;//2017 - 2000 + 1;
    const int nmonthes = 12;
    const int ndays = 31;
    const int nhours = 24;
    std::vector<std::vector<std::vector<std::tuple<int,int,int,int>>>> db;
    LogSystem() {
        db.resize(nyears);
        for(int i = 0; i < nyears; i++) {
            db[i].resize(nmonthes);
            for(int j = 0; j < nmonthes; j++) {
                db[i][j].resize(ndays);
            }
        }
    }
    
    std::tuple<int, int, int, int, int, int> tokenize(string timestamp) {
        int year = stoi(timestamp.substr(2,2));
        int month = stoi(timestamp.substr(5,2));
        int day = stoi(timestamp.substr(8,2));
        int hour = stoi(timestamp.substr(11,2));
        int minute = stoi(timestamp.substr(14,2));
        int second = stoi(timestamp.substr(17,2));
        return make_tuple(year, month, day, hour, minute, second);
    }
    
    void put(int id, string timestamp) {
        int year, month, day, hour, minute, second;
        std::tie(year, month, day, hour, minute, second) = tokenize(timestamp);
        printf("%s: %d %d %d %d %d %d\n", timestamp.c_str(), year, month, day, hour, minute, second);
        
        db[year][month][day] = {hour, minute, second, id};
        
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int year1, month1, day1, hour1, minute1, second1;
        std::tie(year1, month1, day1, hour1, minute1, second1) = tokenize(s);
        int year2, month2, day2, hour2, minute2, second2;
        std::tie(year2, month2, day2, hour2, minute2, second2) = tokenize(e);
        std::vector<int> ids;
        
        for(int i = year1; i <= year2; i++) {
            int month = (i==year1) ? month1 : (i==year2) ? month2 : 0;
            for(int j = month; j < nmonthes; j++) {
                int day = (i==year1 and j==month1) ? day1 : (i==year2 and j==month2) ?  day2 : 0;
                for(int k = day; k < ndays; k++) {
                    //fuck
                }
                
            }
        }
        
        return ids;
    }
};

*/
/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
 
 
 