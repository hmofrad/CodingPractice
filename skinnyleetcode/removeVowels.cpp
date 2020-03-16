/*
 *  Problem:https://leetcode.com/problems/remove-vowels-from-a-string/
 *  Compile: g++ -o removeVowels removeVowels.cpp -std=c++11 -g -Wall -fsanitize=address && ./removeVowels
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    string removeVowels(string S) {
        std::map<char, bool> map;
        map['a'] = true;
        map['e'] = true;
        map['i'] = true;
        map['o'] = true;
        map['u'] = true;
        std::string P;
        int k = 0;
        for(int i = 0; i < S.length(); i++) {
            if(map.find(S[i]) == map.end()) {
                P += S[i];
            }
        }
        return(P);
    }
};