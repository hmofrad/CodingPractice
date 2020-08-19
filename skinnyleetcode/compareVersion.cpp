/*
 * https://leetcode.com/problems/compare-version-numbers/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> parse(std::string& s) {
        if(s.empty()) { return std::vector<int>(); }
        std::vector<int> v;
        int len = s.length();
        std::string t;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(c != '.') { t.push_back(c); }
            else { v.push_back(stoi(t)); t.clear(); }
        }
        if(not t.empty()) { v.push_back(stoi(t)); }
        return v;
    }
    int compareVersion(string version1, string version2) {
        std::vector<int> v1 = parse(version1);
        std::vector<int> v2 = parse(version2);
        for(int v: v1) printf("%d ", v); printf("\n");
        for(int v: v2) printf("%d ", v); printf("\n");
        int s1 = v1.size();
        int s2 = v2.size();
        for(int i = 0; i < max(s1,s2); i++) {
            int i1 = i<s1 ? v1[i] : 0;
            int i2 = i<s2 ? v2[i] : 0;
            if(i1 != i2) { return i1>i2 ? 1 : -1; }
        }
        
        return 0;
    }
};