/*
 *  https://leetcode.com/problems/remove-covered-intervals/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool isCovered(std::vector<int> a, std::vector<int> b) {
        return (b[0] <= a[0] and a[1] <= b[1]) or (a[0] <= b[0] and b[1] <= a[1]);
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int size = intervals.size();
        int count = 0;
        int end = intervals[0][1];
        for(int i = 1; i < size; i++) {
            if(intervals[i][1] <= end) count++;
            else end = intervals[i][1];
        }
        return(size-count);
    }
    
    int removeCoveredIntervals1(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            if(a[0] < b[0]) return true;
            else if(a[0] == b[0]) return a[1] > b[1];
            else return false;
        });
        
        /*
        int size = intervals.size();
        for(int i = 0; i < size; i++) {
            printf("[%d %d) ", intervals[i][0], intervals[i][1]);
        }
        printf("\n");
        */
        /*
        int size = intervals.size();
        std::set<int> indices;
        for(int i = 0; i < size-1; i++) {
            std::vector<int> a = intervals[i];
            for(int j = i+1; j < size; j++) {
                std::vector<int> b = intervals[j];
                if(isCovered(a, b)) {
                    indices.insert(j);
                }
                //printf("[%d %d), [%d %d) ? %d\n", a[0], a[1], b[0], b[1], isCovered(a, b));
            }
        }
        */
       // printf("%d %d\n", size, indices.size());
        int count = 0;
        int end = 0;
        int prev_end = 0;
        for(std::vector<int> interval: intervals) {
            end = interval[1];
            if(prev_end < end) {count++; prev_end = end;}
        }
        
        return count; 
        //return(size-indices.size());
        
    }
};