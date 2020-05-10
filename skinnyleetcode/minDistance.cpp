/*
 *	https://leetcode.com/problems/squirrel-simulation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
Proof: Let the minimum distance from each nut to the tree be a_1, ..., a_n and let the minimum distance from each nut to the initial squirrel position be b_1, ..., b_n. 
Note that the minimum distance between two positions in the matrix is determined by their Manhattan distance.

Then, if the squirrel were to start at the tree, then the minimum total distance required to collect all the nuts is 2a_1 + ... + 2a_n. 
However, since the squirrel starts elsewhere, we just need to substitute one of the 2a_i terms with a_i + b_i. 
Or equivalently, we replace one of the a_i terms in the sum with b_i. 
To minimize the total sum value at the end, we choose i that maximizes a_i - b_i.
*/

class Solution {
public:
    int distance(std::vector<int> a, std::vector<int> b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minDistance1(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int mindist = INT_MAX;
        std::vector<int> nut1(2);
        for(std::vector<int>& nut: nuts) {
            int dist = distance(squirrel, nut);
            if(dist < mindist) {
                mindist = dist; 
                nut1 = nut;
            }
            else if((dist == mindist) and (distance(nut, tree) > distance(nut1, tree))) {
                    nut1=nut;
            }
        }
        mindist += distance(nut1, tree);
        for(std::vector<int>& nut: nuts) {
            if(nut != nut1) mindist += (distance(nut, tree)*2);
        }
        return mindist;
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int mindist = INT_MIN;
        int totaldist = 0;
        for(std::vector<int>& nut: nuts) {
            totaldist += (distance(nut, tree)*2);
            mindist = max(mindist, distance(nut,tree)-distance(nut, squirrel));
        }
        
        return totaldist-mindist;
    }
};