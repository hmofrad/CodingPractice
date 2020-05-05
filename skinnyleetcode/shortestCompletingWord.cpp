/*
 *	https://leetcode.com/problems/shortest-completing-word/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        std::vector<std::vector<int>> w(words.size(), std::vector<int>(26));
        for(int i = 0; i < words.size(); i++) {
            std::string& word = words[i];
            for(char c: word) {
                if(c>='a' and c <='z') w[i][c-'a']++;
                else if(c>='A' and c <='Z') w[i][c-'A']++;
            }
        }
        
        int index = INT_MAX;
        int len = INT_MAX;
        for(int i = 0; i < words.size(); i++) {
            for(char c: licensePlate) {
                if(c>='a' and c <='z') w[i][c-'a']--;
                else if(c>='A' and c <='Z') w[i][c-'A']--;
            }
            
            bool matched = true;
            for(int j = 0; j < 26; j++) {
                if(w[i][j]<0) {matched = false; break;}
            }
            if(matched) {
                if(words[i].length() < len) {
                    index = i;
                    len = words[i].length();
                }
            }
        }
        return words[index];            
    }
};