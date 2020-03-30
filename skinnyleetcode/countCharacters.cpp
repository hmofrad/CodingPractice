/*
 *  https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> letters;
    int countCharacters(vector<string>& words, string chars) {
        letters.resize(26);
        for(auto c: chars) {
            letters[c-'a']++;
        }
        return(countCharacters(words, letters, 0));
    }
    
    int countCharacters(vector<string>& words, std::vector<int> letters1, int i) {
        if(i >= words.size()) return 0;
        //if(words.empty()) return 0;
        

        int currentlen = 0;
        std::string word = words[i];
        //std::string word = words.front();
        std::vector<int> letters2(letters1);
        bool formed = true;
        for(auto w: word){
            if(not letters2[w-'a']) {
                formed = false;
                currentlen = 0;
                break;
            }
            letters2[w-'a']--;
            currentlen++;
        }
        /*
        std::vector<string> words1;
        for(auto w: words) {
            if(w != word) words1.push_back(w);
        }
        */    
        //std::string chars1;
        //int currentlen = 0;
        //if(formed) {
            /*
            for(int i = 0; i < 26; i++) {
                while(letters[i]) {
                    chars1 += 'a'+i;
                    letters[i]--;
                }
            }
            */
           // currentlen = word.size();
        //}
        //printf("%s [%d %d] %d %s %s\n", word.c_str(), words.size(), words1.size(), currentlen, chars.c_str(), chars1.c_str());
        
       int nextlen = countCharacters(words, letters1, i+1);
       // printf("%s %d %d %d\n", word.c_str(), i, currentlen, nextlen);
        return(formed ? max(currentlen + nextlen, nextlen) : nextlen);
        
    }
};