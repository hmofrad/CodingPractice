/*
 * https://leetcode.com/problems/rectangle-overlap/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       return not(rec1[0] >= rec2[2] or rec2[0] >= rec1[2] or rec1[1] >= rec2[3] or rec2[1] >= rec1[3]); 
       
    }
};
/*
x1,y1            x1,y1

    x2,y2               x2,y2
*/