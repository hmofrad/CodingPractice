/*
 *	https://leetcode.com/problems/exclusive-time-of-functions/submissions/	
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::vector<int> t(n);
        std::stack<std::pair<int, std::pair<int, std::string>>> stack;
        for(std::string& log: logs) {
            int id, timestamp;
            char state_t[6]; memset(state_t, '\0', 6);
            std::sscanf(log.c_str(), "%d:%[^:]:%d", &id, state_t, &timestamp);
            std::string state(state_t);
            if(state == "start") { stack.push({id, {timestamp, state}}); }
            else {
                int id0 = stack.top().first; 
                int timestamp0 = stack.top().second.first;
                std::string state0 = stack.top().second.second;
                stack.pop();
                t[id] += time;
                if(not stack.empty()) { t[stack.top().first] -= time; }
            }
            
        }
        return t;
    }
};