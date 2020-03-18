/*
 *  Problem: https://leetcode.com/problems/unique-morse-code-words/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::string> morse_codes = {".-","-...","-.-.","-..",".","..-.","--.",
                                        "....","..",".---","-.-",".-..","--","-.",
                                        "---",".--.","--.-",".-.","...","-","..-",
                                        "...-",".--","-..-","-.--","--.."};    
    
    std::string decode(std::string cipher) {
        std::string text;
        for(auto c: cipher) {
            text += morse_codes[c-'a'];
        }
        return(text);
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        std::vector<std::string> texts;
        for(auto word: words) {
            std::string text = decode(word);
            if(std::find(texts.begin(), texts.end(), text) == texts.end()) {
                texts.push_back(text);    
            }
        }
        
        return(texts.size());
        
    }
};