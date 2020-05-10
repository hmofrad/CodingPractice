/*
 *	https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        

        int len = order.length();
        std::vector<int> order1(len);
        for(int i = 0; i < len; i++) order1[order[i]-'a']=i;
        int size = words.size();
        for(std::string& word: words) {
            for(char& c: word)
                c=order1[c-'a'];
            //printf("<%s>\n", word.c_str());
        }
        
        return is_sorted(words.begin(), words.end());
        
    }
    bool isAlienSorted3(vector<string>& words, string order) {
        bool ordered = true;
        int len = order.length();
        std::vector<int> order1(len);
        for(int i = 0; i < len; i++) order1[order[i]-'a']=i;
        int size = words.size();
        for(int i = 0; i < size-1; i++) {
            bool skip = true;
            std::string word1 = words[i];
            int len1 = word1.length();
            std::string word2 = words[i+1];
            int len2 = word2.length();
            for(int j = 0; j < min(len1, len2); j++) {
                int k1 = word1[j]-'a';
                int k2 = word2[j]-'a';
                if(order1[k1] != order1[k2]) {
                    if(order1[k1] > order1[k2]) ordered = false;
                    else skip = false;
                    break;
                }
            }
            
            if(skip and len1>len2) ordered = false;
            
            if(not ordered) break;
        }
        return ordered;
    }
    bool isAlienSorted1(vector<string>& words, string order) {
        std::unordered_map<char, int> order1;
        int len = order.length();
        for(int i = 0; i < len; i++) order1[order[i+1]-'a']=i;
        
        bool ordered = true;
        int size = words.size();
        std::vector<int> indices(size);
        std::vector<std::string> visited(size);
        while(true) {
            std::vector<int> initials(size);
            int c = 0;
            for(int i = 0; i < size; i++) {
                if(indices[i] < words[i].size()) {
                    char c = words[i][indices[i]];
                    int o = order1[c];
                    initials[i]=o;
                    indices[i]++;
                    visited[i].push_back(c);
                    c++;
                }
            }
            if(c==size) {
                for(int i = 0; i < size-1; i++) {
                    if(initials[i]>initials[i+1]) {ordered=false; break;}
                }
            } 
            else {
                break;
            }
            
        }
        return ordered;
    }
};