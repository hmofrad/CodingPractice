/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::string> ans;
    
    void backtrack1(std::string& digits, int index, std::vector<std::string>& keypad, std::string temp) {
        if(temp.length()==digits.length()) {ans.push_back(temp); return;}
        if(index==digits.length()) {return;}
        
        int digit = digits[index]-'0'; 
        std::string letters = keypad[digit];
        for(char letter: letters) {
            temp.push_back(letter);
            backtrack1(digits, index+1, keypad, temp);
            temp.pop_back();
        }
    }
    
    void backtrack(std::string digits, std::vector<std::string>& keypad, std::string temp) {
        if(digits.empty()) {ans.push_back(temp); return;}
        
        int digit = digits.front()-'0'; digits.erase(digits.begin());
        std::string letters = keypad[digit];
        for(char letter: letters) {
            temp.push_back(letter);
            backtrack(digits, keypad, temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return std::vector<std::string>();
        
        std::vector<std::string> keypad = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //backtrack1(digits, 0, keypad, std::string());
       backtrack(digits, keypad, std::string());
       return ans;
    }
};