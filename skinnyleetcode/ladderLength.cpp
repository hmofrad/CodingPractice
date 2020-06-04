/*
 *  https://leetcode.com/problems/word-ladder/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_map<std::string, std::vector<std::string>> dict;
        for(std::string& word: wordList) {
            for(int i = 0; i < word.size(); i++) {
                std::string t = word; t[i]='*';
                dict[t].push_back(word);
            }
        }
        
        std::queue<std::string> queue; queue.push(beginWord);
        std::unordered_set<std::string> visited; visited.insert(beginWord);
        int count = 1;
        while(not queue.empty()) {
            
            int s = queue.size();
            while(s) {
                std::string front = queue.front(); queue.pop();
                //printf("%s: ", front.c_str());
                if(front == endWord) {return count;}
                
                for(int i = 0; i < front.length(); i++) {
                    char c = front[i]; front[i]='*';
                    //std::string t = front; t[i]='*';
                    //printf("[");
                    for(std::string v: dict[front]) {
                        if(visited.insert(v).second) {queue.push(v);}// printf("%s ", v.c_str());}
                    }
                    front[i]=c;
                    //printf("]");
                }
                s--;
            }
            count++;
            //printf("\n");
        }

        return 0;
    }
};



class Solution1 {
public:
    struct Trie {
        Trie(){children.resize(26, nullptr);}
        ~Trie(){}
        std::vector<struct Trie*> children;
        bool is_leaf = false;
        std::vector<int> indices;
    };
    
    void put(struct Trie* trie, std::string word, int index) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            char c = word[i]; int j = c-'a';
            if(trie->children[j] == nullptr) trie->children[j]=new Trie();
            trie->indices.push_back(index);
            trie=trie->children[j];
            
        }
        trie->is_leaf = true;
    }
    
    bool find(struct Trie* trie, std::string word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            char c = word[i]; int j = c-'a';
            if(trie->children[j] == nullptr) return false;
            trie = trie->children[j];
        }
        return trie->is_leaf;
    }
    
    std::vector<std::string> find1(struct Trie* trie, std::string word) {
        std::vector<std::string> matches;
        std::string prefix;
        std::vector<int> indices;
        int len = word.length();
        for(int i = 0; i < len; i++) {
            char c = word[i]; 
            if(c=='0') {
                indices = trie->indices;
                break;
                /*
                for(int i = 0; i < 26; i++) {
                    if(trie->children[i] != nullptr) {
                        std::string str = prefix + 
                        placeholders.push_back(c);
                    }
                }
                */
            }
            else {
                prefix.push_back(c);
            }

            int j = c-'a';
            //if(trie->children[j] == nullptr) return false;
            trie = trie->children[j];
        }
        
        for(int index: indices) printf(">%d\n", index);
        
        
        return matches;
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        struct Trie* trie = new Trie();
        for(int i = 0; i < wordList.size(); i++) {put(trie, wordList[i], i);}
        //for(std::string word: wordList) printf("%s %d\n", word.c_str(), find(trie, word));
        std::string w = "0ot";
        printf("%s\n", w.c_str());
        std::vector<std::string> www = find1(trie, w);
        for(std::string ww: www) printf("%s\n", ww.c_str());
        
        
        return 0;
    }
};