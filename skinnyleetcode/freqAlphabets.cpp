/*
 *  Problem: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string freqAlphabets1(string s) {
        std::unordered_map<std::string, char> map;
        char k = 1;
        char l = 'a';
        for(char i = 'a'; i <= 'z'; i++) {
            std::string t = to_string(k);
            if(i >= 'j' and i <= 'z') {
                t += '#';
            }
            map[t] = l;
            //printf("%s %c\n", map.find(t)->first.c_str(), map.find(t)->second);
            k++;
            l++;
        }
        std::string out;
        int i = 0;
        //for(int i = 0; i < s.length(); i++) {
        while(i < s.length()) {    
            std::string token;
            if(i+2 <= s.length()-1 and s[i+2] == '#') {
                token = s.substr(i,3);
                i += 3;
            }
            else {
                token = s[i];
                i++;
            }
            out += map.find(token)->second;
            //printf("%d %s %c\n", i, token.c_str(), map.find(token)->second );
        }
        
        return(out);
    }
    
    
    string freqAlphabets(string s) {
        std::string out;
        int i = s.length()-1;
        while(i >= 0) {    
            if(s[i] == '#') {
                std::string token = s.substr(i-2, 2);
                out += 'a'+(stoi(token)-1);
                i -= 3;
            }
            else {
                out += 'a'+(s[i]-'0'-1);
                i--;
            }
           // printf("%d %s\n", i, out.c_str());
            //printf("%d %s %c\n", i, token.c_str(), map.find(token)->second );
        }
        std::reverse(out.begin(), out.end());
        return(out);
    }
    
    
};