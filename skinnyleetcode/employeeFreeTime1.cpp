/*
 * https://leetcode.com/problems/employee-free-time/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        if(schedule.empty()) { return std::vector<Interval>(); }
        
        int nemployees = schedule.size();
        
        std::vector<Interval> flat_intervals; 
        for(std::vector<Interval>& s: schedule) { for(Interval& interval: s) { flat_intervals.push_back(interval); } }
        
        std::sort(flat_intervals.begin(), flat_intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        
        std::vector<Interval> ans;
        Interval temp = flat_intervals.front();
        for(Interval interval: flat_intervals) {
            if(temp.end < interval.start) {
                ans.push_back({temp.end, interval.start});
                temp = interval;
            }
            else if(temp.end < interval.end) { temp=interval; }
        }
        return ans;
    }
    
    
    
    
    std::vector<Interval> merge(std::vector<std::vector<Interval>> schedule) {
        std::vector<Interval> flat;
        for(int i = 0; i < schedule.size(); i++) {
            for(int j = 0; j < schedule[i].size(); j++) {
                flat.push_back(schedule[i][j]);
            }
        }
        
        std::sort(flat.begin(), flat.end(), [](Interval a, Interval b) {return(a.start < b.start);});
        
        int j = 0;
        for(int i = 0; i < flat.size(); i++) {
            if(flat[j].end >= flat[i].start) {
                if(flat[j].end < flat[i].end) flat[j].end = flat[i].end;
            }
            else {
                j++;
                std::swap(flat[j], flat[i]);
            }
        }
        //printf("%d %d\n", flat.size(), j);
        flat.resize(j+1);
        return(flat);
    }
    
    
    vector<Interval> employeeFreeTime0(vector<vector<Interval>> schedule) {
        if(schedule.empty()) return std::vector<Interval>();
        
        int m = schedule.size();
        std::vector<Interval> merged = merge(schedule);
        
        for(auto mm: merged) printf("%d %d\n", mm.start, mm.end);
        
        int j = 0;
        for(int i = 1;  i < merged.size(); i++) {
            if(merged[i-1].end < merged[i].start) {
                merged[j].start = merged[i-1].end;
                merged[j].end = merged[i].start;
                j++;
            }
        }
        merged.resize(j);
        return merged;
    }
    
    /*
    vector<Interval> employeeFreeTime1(vector<vector<Interval>> schedule) {
        int m = schedule.size();
        std::vector<int> indices(m);
        
        std::vector<Interval> ranges;
        while(true) {
            int al = 0;
            int ar = 0;
            int bl = 0;
            int br = 0;
            for(int i = 0; i < m-1; i++) {
                int j = indices[i];
                int n = schedule[i].size();
                if(j > n) continue;
                int start = schedule[i][j].start;
                int end = schedule[i][j].end;
                
            }

            int c = 0;
            for(int i = 0; i < m; i++) {
                int j = indices[i];
                int n = schedule[i].size();
                if(j == n) c++;
            }
            printf("%d ? %d\n", c, m);
            if(c==m) break;
            break;
        }
        
        for(auto r: ranges) {
            printf("%d %d\n", r.start, r.end);
        }
        
        return(ranges);
    }
    */
};

/*
        while(ia < ma and ib < mb) {
            int al = A[ia][0];
            int ar = A[ia][1];
            int bl = B[ib][0];
            int br = B[ib][1];
            //printf("A[%d]={%d,%d}, B[%d]={%d,%d} ? %d\n", ia, al, ar, ib, bl, br, ar < bl);
            //if((al >= bl and al <= br) or (ar >= bl and ar <= br) or (bl >= al and bl <= ar) or (br >= al and br <= ar)) {
                //std::vector<int> temp = {al, bl, ar, br};
                //std::sort(temp.begin(), temp.end());
                
                int l = max(al, bl);
                int r = min(ar, br);
                if(l<=r)
                    ans.push_back({l, r});
            //}
            
            if(ar < br) ia++;
            else ib++;
        }
*/



/*
[[[1,2],[5,6]],
 [[1,3]],
 [[4,10]]]
e3             -------------------
e2    ------
e1    ---         ---
   0  1  2  3  4  5  6  7  8  9  10
*/        