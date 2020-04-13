/*
 *  https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    /*
    std::pair<int, int> vec2string(std::vector<int> vec) {
        int ncols = vec.size();
        int value = 0;
        int value_ = 0;
        for(int i=ncols-1; i>=0; i--) {
            value += vec[i]*pow(2,i);
            value_ += (not vec[i])*pow(2,i);
        }
        
        return(std::make_pair(value, value_));
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = (nrows) ? matrix[0].size() : 0;
        
        std::unordered_map<int, int> map;
        for(std::vector<int> row: matrix) {
            int value;
            int value_;
            std::tie(value, value_) = vec2string(row);
            map[value]+=1;
            map[value_]+=1;
           // printf("%d %d\n", value, value_);
        }
        
        int maxflips = 0;
        for(auto m: map) {
            maxflips = max(maxflips, m.second);
        }
        
        return(maxflips);
    }
    */
    std::pair<std::string, std::string> vec2string(std::vector<int> vec) {
        int ncols = vec.size();
        std::string str;
        std::string str_;
        for(int i=0; i<ncols; i++) {
            str  += '0' + vec[i];
            str_ += '0'+ not vec[i];
        }
        
        return(std::make_pair(str, str_));
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = (nrows) ? matrix[0].size() : 0;
        
        std::unordered_map<std::string, int> map;
        for(std::vector<int> row: matrix) {
            std::string str;
            std::string str_;
            std::tie(str, str_) = vec2string(row);
            map[str]+=1;
            map[str_]+=1;
        }
        
        int maxflips = 0;
        for(auto m: map) {
            maxflips = max(maxflips, m.second);
        }
        
        return(maxflips);
    }
};
