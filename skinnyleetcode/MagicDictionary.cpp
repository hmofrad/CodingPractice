/*
 *	https://leetcode.com/problems/implement-magic-dictionary/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MagicDictionary {
public:
    
    struct Trie {
        Trie() {children.resize(26); is_leaf = false;}
        ~Trie() {}
        bool is_leaf;
        std::vector<struct Trie*> children;
    };
    struct Trie* trie = nullptr;
    void put(std::string word) {
        //printf("%s\n", word.c_str());
        int len = word.length();
        struct Trie* head = trie;
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            //printf("%d %c %d %p\n", i, word[i], j, head);
            if(not head->children[j]) { head->children[j] = new Trie(); }
            head=head->children[j];
        }
        //printf("%p\n", head);
        head->is_leaf = true;
    }
    
    bool get(std::string word) {
        int len = word.length();
        struct Trie* head = trie;
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            if(not head->children[j]) {return false;}
            else head = head->children[j];
        }
        //printf("%s %d\n", word.c_str(), head->is_leaf);
        return head->is_leaf;
    }
    
    bool get_1(std::string word) {
        //printf("%s\n", word.c_str());
        bool one = true;
        int len = word.length();
        struct Trie* head = trie;
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            ///printf("%d %c %d %p\n", i, word[i], j, head->children[j]);
            if(not head->children[j]) {
                if(one and i<len-1) {
                    int j1 = word[i+1]-'a';
                    for(int k = 0; k < 26; k++) {
                        if(head->children[k] and head->children[k]->children[j1]) {
                            head = head->children[k];
                            one = false;
                            //printf("k=%d %d\n", k, j1);
                            break;
                        }
                    }
                    if(one) break;
                }
            }
            else head = head->children[j];
        }
       // printf("[%s %d %d]\n ", word.c_str(), one, head->is_leaf);
        return not one and head->is_leaf;
    }
    
    //std::vector<std::vector<std::string>> db;
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        //for(std::string& word: dict) {
          //  std::sort(word.begin(), word.end());
        //}
        
        for(std::string& word: dict) put(word);
        
        //printf("%d\n", get("leetcodea"));
          //exit(0);
        /*
        db.resize(26);
        for(std::string& value: dict) {
            int key = value[0]-'a';
            db[key].push_back(value);
        }
        */
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        
        
        for(int i = 0; i < word.size(); i++) {
            for(int j = 0; j < 26; j++) {
                char c = j+'a';
                if(word[i]==c) continue;
                char t = word[i];
                word[i]=c;
                if(get(word)) return true;
                word[i]=t;
            }
        }
        
        return false;
        
        
        
        //std::sort(word.begin(), word.end());
        //return get_1(word);
        /*
        int key = word[0]-'a';
        std::vector<std::string>& keys = db[key];
        auto it = std::find(keys.begin(), keys.end(), word);
        return it != keys.end() ? true : false;
        */
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */