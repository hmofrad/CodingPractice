/*
 *  https://leetcode.com/problems/groups-of-special-equivalent-strings/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isSpecialEquivalent(std::string a, std::string b, int index) {
        //printf("%s %s %d %d\n", a.c_str(), b.c_str(), a ==b, index);
        int m = a.size();
        if(index > m-2) return false;
        
        if(a == b) return true;
        
        std::string c = a;
        std::swap(c[index], c[index+2]);
        
        return(isSpecialEquivalent(a, b, index+1) or isSpecialEquivalent(c, b, index+1));
    }
    int numSpecialEquivGroups1(vector<string>& A) {
        int m = A.size();
        std::unordered_map<std::string, std::vector<std::string>> eqs;
        for(int i = 0; i < m-1; i++) {
            for(int j = i+1; j < m; j++){
                bool r = isSpecialEquivalent(A[i], A[j], 0);
                if(r) {
                    if(eqs.count(A[i])) {
                        std::vector<std::string>& vec = eqs[A[i]];
                        if(std::find(vec.begin(), vec.end(), A[j]) == vec.end()) {
                            bool tf = true;
                            for(std::string v: vec) {
                                if(not isSpecialEquivalent(v, A[j],0)) {
                                    tf = false;
                                    break;
                                }
                            }
                            if(tf) vec.push_back(A[j]);
                        }
                    }
                    else {
                        eqs[A[i]].push_back(A[j]);
                    }
                }
                //printf("A[%d]=%s, B[%d]=%s --> %d\n", i, A[i].c_str(), j, A[j].c_str(), r); //break;
            }
        }
        int mx = 0;
        for(auto eq: eqs) {
            if(mx < eq.second.size()) mx = eq.second.size();
        }
        return(mx+1);
    }
    
    int numSpecialEquivGroups(vector<string>& A) {
    set<string> seen;
        for (auto S: A) {
            std::vector<int> count(52);
            for (int i = 0; i < S.length(); ++i)
                count[S[i] - 'a' + 26 * (i % 2)]++;
            std::string str;
            for(int i = 0; i < 52; i++) str.push_back('0'+count[i]);
            printf("%s ", str.c_str());
            seen.insert(str);
            printf("%d\n\n", seen.size());
        }
        
        for(auto a: seen) {
            printf("%s\n", a.c_str());
        }
        
        
        return seen.size();
    }
    
    
    int numSpecialEquivGroups2(vector<string>& A) {
        std::set<std::string> ans;
        
        int m = A.size();
        
        for(int i = 0; i < m; i++) {
            std::string odd;
            std::string even;
            int n = A[i].size();
            for(int j = 0; j < n; j++) {
                if(j%2) {
                    odd.push_back(A[i][j]);
                }
                else {
                    even.push_back(A[i][j]);
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            ans.insert(even+odd);
            printf("%s+%s\n", even.c_str(), odd.c_str());
        }
        
        for(auto a: ans) {
            printf("%s\n", a.c_str());
        }
        
        return(ans.size());
    }
    
    
    
    
    
};