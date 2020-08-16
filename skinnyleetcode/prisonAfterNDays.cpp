/*
 * https://leetcode.com/problems/prison-cells-after-n-days/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    std::string next(std::string& s) {
        int len = s.length();
        std::string t(len,'0');
        for(int i = 1; i < len-1; i++) { 
            if(s[i-1] == s[i+1]) { t[i]='1'; } 
        }
        return t;
    }
    
    std::string vec2str(std::vector<int> v) {
        std::string s;
        for(int x: v) { s.push_back(x+'0'); }
        return s;
    }
    std::vector<int> str2vec(std::string& s) {
        int len = s.length();
        std::vector<int> v(len);
        for(int i = 0; i < len; i++) { 
            v[i] = s[i]-'0'; 
        }
        return v;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(cells.empty() or N < 1) { return cells; }
        bool has_cycle = false;
        int cycles = 0;
        std::unordered_set<std::string> set;
        std::string s = vec2str(cells);
        int len = s.length();
        for(int i = 0; i < N; i++) {
            std::string t = next(s);
            if(set.count(t)) { has_cycle = true; break; }
            else { set.insert(t); cycles++; }     
            s = t;
        }
        
        if(has_cycle) {
            N%=cycles;
            for(int i = 0; i < N; i++) { s=next(s); }
        }
        cells = str2vec(s);    
            
        return cells;
    }

    vector<int> prisonAfterNDays0(vector<int>& cells, int N) {
        if(cells.empty() or N < 1) { return cells; }
        std::vector<int> temp(cells.begin(), cells.end());
        int size = cells.size();
        for(int i = 0; i < N; i++) {
            std::vector<int>& A = (i%2==0) ? cells : temp;
            std::vector<int>& B = (i%2==0) ? temp : cells;
            std::fill(B.begin(), B.end(), 0);
            for(int j = 1; j < size-1; j++) { if(A[j-1] == A[j+1]) { B[j]=1; } }
        }
        return N%2 ? temp : cells;
    }
};