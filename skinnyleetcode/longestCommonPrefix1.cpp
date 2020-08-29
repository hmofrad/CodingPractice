/*
 * https://leetcode.com/problems/longest-common-prefix/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    struct Trie {
        public:
        Trie() { children.resize(26); is_leaf = false; };
        ~Trie();
        std::vector<struct Trie*> children;
        bool is_leaf;
    };
    
    void put(struct Trie* trie, std::string word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i] - 'a';
            if(trie->children[j] == nullptr) { trie->children[j] = new Trie(); }
            trie = trie->children[j];
        }
        trie->is_leaf = true;
    }
    
    std::string lcp(struct Trie* trie) {
        std::string prefix;
        while(not trie->is_leaf) {
            int j = -1;
            for(int i = 0; i < 26; i++) {
                if(trie->children[i] and j==-1) { j=i; }
                else if(trie->children[i]) { return prefix; }
            }
            if(j!=-1) {
                prefix.push_back('a'+j);
                trie = trie->children[j];
            }
            else { break; }
        }
        return prefix;
    }
    
    
    
    struct Trie* trie = nullptr;
    string longestCommonPrefix(vector<string>& strs) {
       // if(strs.empty() or strs.front().empty()) { return std::string(); }
        trie = new Trie();
        for(std::string& str: strs) { put(trie, str); }
        
        return lcp(trie); 
    }
};














class Solution0 {
public:
    
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty() or strs.front().empty()) { return std::string(); }
        
        std::string prefix = strs.front();
        int size = strs.size();
        for(int i = 1; i < size; i++) {
            int len = min(prefix.length(), strs[i].length());
            int j = 0;
            while(j<len) { 
                if(prefix[j]!=strs[i][j]) { break; }
                else { j++; }
            }
            prefix = strs[i].substr(0,j);
        }
        return prefix;
    }
    
    string longestCommonPrefix1(vector<string>& strs) {
        if(strs.empty() or strs.front().empty()) { return std::string(); }
        int len = INT_MAX;
        for(std::string& str: strs) { len = min(len, (int) str.length()); }
        
        int size = strs.size();
        int k = 0;
        for(int i = 0; i < len; i++) {
            bool b = true;
            char c = strs[0][i];
            for(int j = 1; j < size; j++) {
                if(c != strs[j][i]) { b=false; break; }
            }
            if(b) { k++; }
            else { break; }
        }
        return strs[0].substr(0,k);
    }
    
    string longestCommonPrefix0(vector<string>& strs) {
        if(strs.empty()) { return std::string(); }
        int size = strs.size();
        int ans = 0;
        int i = 0, j = 0;
        while(j < strs[0].size()) {
            bool b = false;
            char c = strs[i][j];
            for(int i = 1; i < size; i++) {
                if(j>strs[i].size() or strs[i][j] != c) { b=true; } 
            }
            if(b) { break; }
            else { j++; }
        }
        return strs[0].substr(0, j);
    }
};