/*
 *  https://leetcode.com/problems/construct-k-palindrome-strings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
Explanation: If you think about the pallindrome, you'll eventually come at the conclusion that a pallindrome can hold atmost single, odd-occurrence alphabet. So, k pallindrome can hold at most k odd-occurrence alphabet and if the count of odd-occurrence alphabet will be more than k then it's impossible to create k pallindrome.

*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.length();
        if(len < k) return false;
        std::vector<int> alpha(26);
        for(char c: s) {
            alpha[c-'a']++;
        }
        
        int odds = 0;
        for(int i = 0; i < 26; i++) {
            odds += alpha[i]%2 ? 1 : 0;
        }
        if(odds > k) return false;
        
        return true;
    }
};