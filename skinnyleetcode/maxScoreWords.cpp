/*
 *  https://leetcode.com/problems/maximum-score-words-formed-by-letters/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    //
    //std::vector<int> my_letters(26);
    /*
    vector<int> my_score;
    
    int evaluate(std::string word, std::vector<int> letters) {
        int s = 0;
        for(auto w: word) {
            if(letters[w-'a']) {
                s += my_score[w-'a'];
                letters[w-'a']--;
            }
            else {
                break;
            }
        }
        return(s);
    }
    
    int maxScoreWords2(vector<string> words, vector<char> letters, int index) {
        //printf("0. sz=%d %d\n", index, words.size());
        //int m = words.size();
        if(words.empty() or index >= words.size()) return 0;
        //printf("0.<%d, %d>\n", index, words.size());
        std::string my_word = words[index];
        
        std::vector<int> my_letters(26);
        for(auto l: letters) {
            my_letters[l-'a']++;
        }
        //printf("1.\n");
        int s = evaluate(my_word, my_letters);
        //if(s == -1) return -1;
        //printf("2.\n");
        
        std::vector<string> words1;
        for(auto word: words) {
            if(word != my_word) {
                words1.push_back(word);
            }
        }
        std::vector<char> letters1;
        if(s) {
            //printf("3.\n");
            for(auto w: my_word) {
                my_letters[w-'a']--;
            }
            //printf("4.\n");

            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < my_letters[i]; j++) {
                    letters1.push_back('a'+i);
                }
            }
        }
        else {
            letters1 = letters;
        }
    //printf("5.\n");
        printf("1. index=%d sz=%d,%d s=%d\n", index, words.size(), words1.size(), s);
        
        //if(words1.empty()) return(s);
        
        if(s == 0)
            return(maxScoreWords1(words1, letters, 0));
        else
            return(max(maxScoreWords1(words1, letters1, 0)+s, maxScoreWords1(words, letters, index+1)));
    }
    
    
    
    int maxScoreWords1(vector<string>& words, vector<char>& letters, vector<int>& score) {
        my_score = score;
        //std::vector<int> 
        return(maxScoreWords1(words, letters, 0));
        
    }
    */
    
    
    int dfs(std::vector<std::string> words, std::vector<int> count, std::vector<int>& score, int i) {
        if(i >= words.size()) return 0;
        //int skip = dfs(words, count, score, i+1);
        int gain = 0;
        int formed = 1;
        std::vector<int> count1(count);
        
        for(auto c: words[i]) {
            count1[c-'a']--;
            if(count1[c-'a'] < 0) {
                formed = 0;
            }
            gain += score[c-'a'];
        }
        return max(dfs(words, count, score, i+1), formed ? gain + dfs(words, count1, score, i+1) : 0);
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::vector<int> count(26);
        for(auto l: letters) {
            count[l-'a']++;
        }
        return(dfs(words, count, score, 0));
    }
    
    
};