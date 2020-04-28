/*
 *  https://leetcode.com/problems/escape-the-ghosts/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dist(std::vector<int> a, std::vector<int> b) {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        std::vector<int> source = {0, 0};
        //int rs = source[0];
        //int cs = source[1];
        //int rt = target[0];
        //int ct = target[1];
        int nghosts = ghosts.size();
        for(int i = 0; i < nghosts; i++) {
            std::vector<int> ghost = ghosts[i];
            //int rg = ghosts[i][0];
            //int cg = ghosts[i][1];
            //if((rg==rt and abs(cg-ct) <=1) or (cg==ct and abs(rg-rt) <=1)) return false;
            if(dist(ghost, target) <= dist(source, target)) return false;
        }
        return true;
    }
};