/*
 * https://leetcode.com/problems/sentence-screen-fitting/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        std::string s;
        for(std::string word:sentence) { s += word + ' '; }
        int len = s.length();
        std::vector<int> map(len);
        for(int i=1; i < len; i++) { map[i] = s[i] == ' ' ? 1 : map[i-1]-1; }
        for(int i: map) printf("%d ", i); printf("\n");
        int j = 0;
        for(int i = 0; i < rows; i++) {
            j += cols; 
            printf("%d %d\n", j, map[j%len]);
            j += map[j%len];
            printf("%d\n", j);
        }
        return j/len;
    }
    int wordsTyping1(vector<string>& sentence, int rows, int cols) {
        std::string s;
        for(std::string& word: sentence) { s += word + ' '; }
        
        int j = 0;
        int len = s.length();
        for(int i = 0; i < rows; i++) {
            j+=cols; 
            if(s[j%len] == ' ') { j++; }
            else {
                while(j>0 and s[(j-1)%len] != ' ') { j--; }
            }
        }
        return j/len;
    }
};

/*
xxxxx
I-had
apple
pie--
*/