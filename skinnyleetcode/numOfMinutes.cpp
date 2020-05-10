/*
 *	https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int dfs(int headID, vector<int>& informTime, std::unordered_map<int, std::vector<int>>& map) {
        int time = 0;
        if(map.count(headID) and not map[headID].empty()) {
            for(int& m: map[headID]) time = max(time, dfs(m, informTime, map));
        }
        return informTime[headID]+time;
    }
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        std::unordered_map<int, std::vector<int>> map;
        for(int i = 0; i < manager.size(); i++) {
            map[manager[i]].push_back(i);
        }
        
        return dfs(headID, informTime, map);
    }
    int numOfMinutes1(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int total = 0;//informTime[headID];
        std::queue<std::pair<int, int>> queue;
        unordered_map<int, std::vector<int>> map;
        for(int i = 0; i < manager.size(); i++) {
            map[manager[i]].push_back(i);
        }
        queue.push({headID,0});
        while(not queue.empty()) {
            //int time = 0;
            bool first = true;
            int size = queue.size();
            int s = 0;
            while(s < size) {
                std::pair<int, int> front = queue.front(); queue.pop();
                int id = front.first;
                int t = front.second;
                t += informTime[id];
                
                if(map.count(id) and not map[id].empty()) {
                    for(auto m: map[id]) queue.push({m, t});
                }
                else total=max(total, t);
                
                
                //printf("[%d %d] ", front, informTime[front]);
                //time += informTime[front];
                //bool found = false;
                //for(int i = 0; i < n; i++) {
                  //  if(manager[i]==id) {
                        //if(first) {
                        //time = max(time, t);// first = false;}
                    //    queue.push({i, t});
                      //  found = true;
                    //}
                //}
                //if(not found) total=max(total, t);
                s++;
            }
            
            //total += time; //2560
            //printf(" %d %d\n", time, total);
        }
        return total;
    }
};