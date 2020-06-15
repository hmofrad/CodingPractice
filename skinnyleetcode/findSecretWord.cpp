/*
 * https://leetcode.com/problems/guess-the-word/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(std::string& a, std::string& b) {
        int count = 0;
        int len = a.length();
        for(int i = 0; i < len; i++) {
            if(a[i]==b[i]) count++;
        }
        return count; 
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i = 0, x=0; i < 10 and x<6; i++) {
            int size = wordlist.size();
            std::string& word = wordlist[rand() % size];
            x = master.guess(word);
            std::vector<std::string> wordlist0;
            for(std::string& w: wordlist) {
                if(x == match(word, w)) {
                    wordlist0.push_back(w);
                }
            }
            wordlist = wordlist0;
        }
    }
};