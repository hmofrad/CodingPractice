/*
 *  https://leetcode.com/problems/string-matching-in-an-array/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool isSubstr(std::string t, std::string s) {
        int len_t = t.length();
        int len_s = s.length();
       // printf("%s %s\n", t.c_str(), s.c_str());
        if(len_t < len_s) return false;
        
        bool found = false;
        for(int i = 0; i < len_t; i++) {
            int j = 0;
            for(j = 0; j < len_s; j++) {
                if(t[i+j] != s[j]) break;
            }
            
            if(j==len_s) {found = true; break;}
            //printf("%d %d %d %d\n", i, j, len_s, found);
        }

        return found;
    }
    vector<string> stringMatching(vector<string>& words) {
        std::vector<std::string> ans;
        int size = words.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                std::string t = words[i];
                int len_t = words[i].length();
                std::string s = words[j];
                int len_s = words[j].length();
                //printf("%s %s %d/%d\n", s.c_str(), t.c_str(), isSubstr(s,t), isSubstr(t,s));
               // break;
                if(len_t < len_s and
                   isSubstr(s, t) and 
                   (std::find(ans.begin(), ans.end(), t) == ans.end())) ans.push_back(t);
                else if(len_s <= len_t and isSubstr(t, s) and 
                   (std::find(ans.begin(), ans.end(), s) == ans.end())) ans.push_back(s);
                
            }
        }
        return ans;
    }
};