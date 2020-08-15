/*
 * https://leetcode.com/problems/partition-labels/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.empty()) { return std::vector<int>(); }
        std::vector<int> ans;
        std::unordered_map<char,int> map;
        int len = S.length();
        for(int i = 0; i < len; i++) { map[S[i]]=i; }
        
        int j = 0;
        int a = 0;
        for(int i = 0; i < len; i++) {
            char c = S[i];
            a = max(a, map[c]);
            if(i==a) { ans.push_back(i-j+1); j = i+1; }
        }
        return ans;
    }
    
    
    vector<int> partitionLabels0(string S) {
        std::vector<int> last(26);
        for(int i = 0; i < S.length(); i++) {
            last[S[i]-'a'] = i;
        }
        
        int j = 0;
        int anchor = 0;
        std::vector<int> parts;
        for(int i = 0; i < S.length(); i++) {
            char c = S[i];
            j = (j < last[c-'a']) ? last[c-'a'] : j;
            if(i == j) {
                parts.push_back(i - anchor + 1);
                anchor = i+1;
            }       
        }
        
        return(parts);
        
    }
};