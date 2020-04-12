/*
 *  https://leetcode.com/problems/minimum-cost-to-connect-sticks/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    
    int connectSticks(vector<int>& sticks) {
        //if(sticks.size() <= 1) return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue(sticks.begin(), sticks.end());
        int cost = 0;
        while(queue.size() > 1) {
            int s1 = queue.top();
            queue.pop();
          //  int s2 = 0;
            //if(not queue.empty()) {
              int  s2 = queue.top(); queue.pop();
        //}
            //printf("%d %d\n", s1, s2);
            int s = s1 + s2;
            cost += s;
            queue.push(s);
            //if(not queue.empty()) queue.push(s);
            //else break;
        }
        return(cost);
    }
};


