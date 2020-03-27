/*
 *  https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        std::vector<int> path; 
        int temp = label;
        while(temp>1){
            path.push_back(temp%2);
            temp /= 2;
        }
        
        std::vector<std::vector<int>> values(2);
        values[0].resize(path.size()+1);
        values[1].resize(path.size()+1);
        values[0][0] = 1;
        values[1][0] = 1;
        
        int i = 1;
        while(not path.empty()) {
            int dir = path.back();
            values[0][i] = values[0][i-1]*2 + (dir == 0 ? 1 : 0);
            values[1][i] = values[1][i-1]*2 +dir;
            path.pop_back();
            i++;
        }
        
        int index = i%2;
        for(int j = 0; j < i; j++) path.push_back(values[(index+j)%2][j]);
        
        return(path);
    }
};