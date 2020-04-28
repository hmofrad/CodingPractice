/*
 *  https://leetcode.com/problems/smallest-common-region/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string, std::string> universe;
        for(std::vector<std::string>& region: regions) for(int i=1; i<region.size(); i++) universe[region[i]]=region[0];
        
        std::unordered_set<std::string> visited;
        std::vector<std::string> vec1;
        while(not region1.empty()) {vec1.push_back(region1); visited.insert(region1); region1=universe[region1];}
        std::vector<std::string> vec2;
        while(not region2.empty()) {vec2.push_back(region2); if(visited.count(region2)) return region2;  region2=universe[region2];}
        
        return "";
    }
    string findSmallestRegion3(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string, std::string> universe;
        for(std::vector<std::string>& region: regions) for(int i=1; i<region.size(); i++) universe[region[i]]=region[0];
        
        std::vector<std::string> vec1;
        while(not region1.empty()) {vec1.push_back(region1); region1=universe[region1];}
        std::vector<std::string> vec2;
        while(not region2.empty()) {vec2.push_back(region2); region2=universe[region2];}
        
        for(std::string& v: vec1) printf("%s ", v.c_str()); printf("\n");
        for(std::string& v: vec2) printf("%s ", v.c_str()); printf("\n");
        
        for(std::string v1: vec1) for(std::string v2: vec2) if(v1==v2) return v1;
        
        return "";
    }
    string findSmallestRegion2(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string, std::string> universe;
        for(std::vector<std::string> region: regions) for(int i =region.size()-1; i >0; i--) universe[region[i]]=region[0];
        
        unordered_set<string> visited;
        while(universe.count(region1)) {
            if(region1==region2) return region1;
            visited.insert(region1);
            region1=universe[region1];
        }
        
        while(universe.count(region2)) {
            if(visited.count(region2)) return region2;
            region2=universe[region2];
        }
        return region1;
    }
    
    
    string findSmallestRegion1(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string, std::vector<std::string>> universe;
        for(std::vector<std::string> region: regions) {
            int region_size = region.size();
            std::string first = region[0];
            for(int i = 1; i < region_size; i++) universe[first].push_back(region[i]);
        }
        
        std::unordered_map<std::string, std::vector<std::string>> regions2universe;   
        for(std::vector<std::string> region: regions) {
            int region_size = region.size();
            std::string first = region[0];
            for(int i = 1; i < region_size; i++) regions2universe[region[i]].push_back(first);
        }
        
        
        
        while(true) {
            auto& key1_vec=regions2universe[region1];
            auto& key2_vec=regions2universe[region2];
            //while(key1_vec)
            
            
        }
        
        
        
        std::string s;
        return s;
    }
};