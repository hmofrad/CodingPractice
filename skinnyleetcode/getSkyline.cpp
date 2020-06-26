/*
 * https://leetcode.com/problems/the-skyline-problem/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector<std::vector<int>> edges;
        
        for(std::vector<int>& building: buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            edges.push_back({left, -height});
            edges.push_back({right, height});
        }
        std::sort(edges.begin(), edges.end());
        std::vector<std::vector<int>> ans;
        std::multiset<int> set; set.insert(0);
        int prev = 0, curr = 0;
        for(std::vector<int>& edge: edges) {
            int x = edge[0];
            int h = edge[1];
            if(h<0) set.insert(-h);
            else set.erase(set.find(h));
            curr=*set.rbegin();
            if(curr!=prev) {
                ans.push_back({x, curr});
                prev=curr;
            }
        }
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<vector<int>> getSkyline0(vector<vector<int>>& buildings) {
        std::vector<std::vector<int>> skyline;
        if(buildings.empty()) return(skyline);
    int32_t length = 0;
    for(auto& building: buildings) {
        if(building[1] > length) length = building[1];
    }
    //printf("%d\n", length);
   
    for(int32_t i = buildings[0][0]; i <= length; i++) {
        std::vector<int> b;
        for(auto& building: buildings) {
            if((i >= building[0]) and (i <= building[1]-1)) {
                b.push_back(building[2]);
            }
        }
        int h = 0;
        if(!b.empty()) {
            //for(auto bb: b) {printf("%d ", bb);} printf("\n");
            h = *std::max_element(b.begin(), b.end());
        }
        if(!skyline.empty()) {
            auto& s = skyline.back();
            if(s[1] != h) skyline.push_back({i, h});
        //    if(i == length) skyline.push_back({i, 0});
        }
        else {
            skyline.push_back({i, h});
        }
        //printf("[%d %d] \n", i, h);
    }
        return(skyline);
    }
};