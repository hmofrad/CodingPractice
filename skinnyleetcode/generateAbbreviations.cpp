/*
 *	https://leetcode.com/problems/generalized-abbreviation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
The idea is: for every character, we can keep it or abbreviate it. To keep it, we add it to the current solution and carry on backtracking. To abbreviate it, we omit it in the current solution, but increment the count, which indicates how many characters have we abbreviated. When we reach the end or need to put a character in the current solution, and count is bigger than zero, we add the number into the solution.
*/

class Solution {
public:
    
    void backtrack(std::vector<std::string>& ans, std::string& word, std::string temp, int index, int count) {
        int len = word.length();
        if(index == len) {
            temp += (count) ? to_string(count) : std::string();
            ans.push_back(temp);
            return;
        }
        backtrack(ans, word, temp, index+1, count+1);
        backtrack(ans, word, temp + ((count) ? to_string(count) : std::string()) + word[index], index+1, 0);
    }
    vector<string> generateAbbreviations(string word) {
        std::vector<std::string> ans;
        backtrack(ans, word, std::string(), 0, 0);
        return ans;
    }
};