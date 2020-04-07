/*
 *  https://leetcode.com/problems/number-of-ships-in-a-rectangle/submissions/   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    /*
    bool binarySearch(Sea sea, int row, int rowStart, int rowEnd) {
        int low = rowStart;
        int high = rowEnd;
        bool found = false;
        std::vector<int> bottomLeft(2);
        bottomLeft[0] = row;
        std::vector<int> topRight(2);
        topRight[0] = row;
        while(low <= high) {
            int mid = low + (high-low)/2;
            bottomLeft[1] = low;
            topRight[1] = mid;
            if(sea.hasShips(topRight, bottomLeft)) {
                if(low == mid and mid == high) {found = true; break;}
                high = mid-1;
                continue;
            }
            bottomLeft[1] = mid;
            topRight = high;
            if(sea.hasShips(topRight, bottomLeft)) {
                if(low == mid and mid == high) {found = true; break;}
                low = m
            }
                topRight[1] = mid-1;
                if(sea.hasShips(topRight, bottomLeft)) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                found = true;
                break;
            }
        }
        return(found);
    }
    int countShips1(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        std::vector<int> topLeft = {bottomLeft[0],topRight[1]};
        std::vector<int> bottomRight = {topRight[0],bottomLeft[1]};
        int count = 0;
        for(int i = bottomLeft[1]; i <= topRight[1]; i++) {
            count += binarySearch(sea, i, bottomLeft[0], topRight[0]);
        }
        
        return(count);
    }
    */

int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    int x1 = bottomLeft[0];
    int y1 = bottomLeft[1];
    int x2 = topRight[0];
    int y2 = topRight[1];
    
    if(x1 > x2 or y1 > y2 or not sea.hasShips(topRight, bottomLeft)) return 0;
    
    if(topRight == bottomLeft) return 1;
    
    int ans = 0;
    int midx = (x1+x2)/2;
    int midy = (y1+y2)/2;
    
    /*
    y2 --- ---
      | 1 | 2 |
 midy ---- ----
      | 3 | 4 |
    y1---- ----
      x1  midx x2
    */
    
    ans += countShips(sea, {midx, y2}, {x1, midy+1}); //1
    ans += countShips(sea, topRight, {midx+1, midy+1}); //2
    ans += countShips(sea, {midx, midy}, bottomLeft); //3
    ans += countShips(sea, {x2, midy}, {midx+1, y1}); //4
    
    return(ans);
}


};