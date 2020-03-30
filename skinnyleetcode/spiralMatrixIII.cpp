/*
 *  https://leetcode.com/problems/spiral-matrix-iii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int direction = 90;
        int rlimit = 1;
        int rstep = 0;
        
        int dlimit = 1;
        int dstep = 0;
        
        int llimit = 2;
        int lstep = 0;
        
        int ulimit = 2;
        int ustep = 0;
        
        int r = r0;
        int c = c0;
        std::vector<std::vector<int>> ret; 
        while(ret.size() < R*C) {
            if(c>=0 and c<C and r>=0 and r<R) {
                ret.push_back({r,c});
            }
            switch(direction) {
                case 90:
                    c++; rstep++; if(rstep == rlimit) {direction = 180; rstep = 0; rlimit+=2;} break;
                case 180:
                    r++; dstep++; if(dstep == dlimit) {direction = 270; dstep = 0; dlimit+=2;} break;
                case 270:
                    c--; lstep++; if(lstep == llimit) {direction = 360; lstep = 0; llimit+=2;} break;
                case 360:
                    r--; ustep++; if(ustep == ulimit) {direction = 90; ustep = 0; ulimit+=2;} break;
            }
        }
        return(ret);
    }
};