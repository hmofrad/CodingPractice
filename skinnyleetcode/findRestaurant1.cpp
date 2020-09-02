/*
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<std::string, int> map;
        int len1 = list1.size();
        for(int i = 0; i < len1; i++) { map[list1[i]]=i; }
        
        int least_sum = INT_MAX;
        std::vector<int> indices;
        int len2 = list2.size();
        for(int i = 0; i < len2; i++) { 
            if(map.count(list2[i])) { 
                if(map[list2[i]]+i < least_sum) {
                    indices.clear();
                    least_sum = map[list2[i]]+i;
                }
                if(map[list2[i]]+i == least_sum) { indices.push_back(map[list2[i]]); }
            }
        }
        
        std::vector<std::string> ans;
        
        for(int index: indices) { ans.push_back(list1[index]); }
        
        return ans;
    }
};


class Solution1 {
public:
    vector<string> findRestaurant1(vector<string>& list1, vector<string>& list2) {
        std::vector<std::string> list;
        int len = -1;
        for(uint32_t i = 0; i < list1.size(); i++) {
            for(uint32_t j = 0; j < list2.size(); j++) { 
                if(not list1[i].compare(list2[j])) {
                    if(len == -1) {
                        list = {list1[i]};
                        len = i+j;
                    }
                    else {
                        int l = i+j;
                        if(l == len) {
                            list.push_back(list1[i]);
                        }
                    }
                }
            }
        }
        return(list);
    }
    
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::vector<std::string> list;
    
    std::unordered_map<std::string, int> m1;
    std::unordered_map<std::string, int> map;
    
    for(uint32_t i = 0; i< list1.size(); i++) {
        m1[list1[i]] = i;
    }
    
    for(uint32_t i = 0; i< list2.size(); i++) {
        if(m1.find(list2[i]) != m1.end()) {
            map[list2[i]] = i + m1[list2[i]];
        }
    }
    
    int min = INT_MAX;
    for(auto m: map) {
        if(m.second < min) {
            min = m.second;
        }
    }
    
    for(auto m: map) {
        if(m.second == min) {
            list.push_back(m.first);
        }
    }
    
    return(list);
}
    
    
};