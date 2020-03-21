/*
 *  https://leetcode.com/problems/partition-labels/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    vector<int> partitionLabels(string S) {
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