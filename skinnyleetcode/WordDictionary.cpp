/*
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class WordDictionary {
public:
    
    struct Trie {
        public:
            Trie(){ children.resize(27); }
            ~Trie(){}
            std::vector<struct Trie*> children;
            std::string word;
    };
    struct Trie* root;
    void insert(struct Trie* root, std::string& word) {
        if(word.empty()) { return; }
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            if(root->children[j] == nullptr) { root->children[j] = new Trie(); }
            root = root->children[j];
        }
        root->word = word;
    }
    
    bool search(struct Trie* root, std::string& word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            if(root->children[j]) { root = root->children[j]; }
            else { return false; }
        }
        return root->word == word;
    }
    
    
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(root, word);
    }
    
    bool dfs(struct Trie* root, std::string& word, int index) {
        int len = word.length();
        if(index == len) { return not root->word.empty(); }
        
        if(word[index] != '.') { 
            int j = word[index]-'a';
            return(root->children[j] and dfs(root->children[j], word, index + 1)); 
        }
        else {
            for(int i = 0; i < 26; i++) {
                if(root->children[i] and dfs(root->children[i], word, index+1)) { return true; }
            }    
        }
        
        return false;
    }
    
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */ 