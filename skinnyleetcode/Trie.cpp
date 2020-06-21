/*
 * https://leetcode.com/problems/implement-trie-prefix-tree/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Trie {
public:
    /** Initialize your data structure here. */
    Trie* trie=nullptr;
    std::vector<Trie*> children;
    bool is_leaf;
    Trie() {
        children.resize(26);
        is_leaf = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(trie==nullptr) trie=new Trie();
        Trie* curr = trie;
        for(char c: word) {
            int j = c-'a';
            if(curr->children[j] == nullptr) curr->children[j]=new Trie();
            curr=curr->children[j];
        }
        curr->is_leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(trie==nullptr) return false;
        
        Trie* curr = trie;
        for(char c: word) {
            int j = c-'a';
            if(curr->children[j]==nullptr) return false;
            curr=curr->children[j];
        }
        return curr->is_leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(trie==nullptr) return false;
        Trie* curr = trie;
        for(char c: prefix) {
            int j = c-'a';
            if(curr->children[j]==nullptr) return false;
            curr=curr->children[j];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */