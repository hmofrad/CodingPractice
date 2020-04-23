/*
 *  https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int func(std::string str) {
        std::vector<int> map(26);
        
        for(char c: str) {
            map[c-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(map[i]) {return map[i];}
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        std::vector<int> ans;
        int w_size = words.size();
        std::vector<int> w_funcs(w_size);
        for(int i = 0; i < w_size; i++) {
            w_funcs[i] = func(words[i]);
        }
        
        int q_size = queries.size();
        for(int i = 0; i < q_size; i++) {
            int q_func = func(queries[i]);
            int count = 0;
            for(int j = 0; j < w_size; j++) {
                if(q_func < w_funcs[j]) {count++;}
            }
            ans.push_back(count);
        }
        return ans;
    }
};