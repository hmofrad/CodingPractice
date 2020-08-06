/*
 * https://leetcode.com/problems/word-break/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    struct Trie {
        Trie(){ children.resize(26); is_leaf = false;}
        ~Trie(){}
        std::vector<struct Trie*> children;
        bool is_leaf;
        std::string word;
    };
    struct Trie* trie;
    void put(struct Trie* trie, std::string& word) {
        for(char c: word) {
            int j = c-'a';
            if(trie->children[j] == nullptr) trie->children[j] = new Trie();
            trie=trie->children[j];
        }
        trie->word = word;
        trie->is_leaf = true;
    }
    
    bool find(struct Trie* trie, std::string& word) {
        for(char c: word) {
            int j = c-'a';
            if(trie->children[j] == nullptr) return false;
            trie = trie->children[j];
        }
        return trie->is_leaf;
    }
    
    bool dfs(struct Trie* trie, std::string word, int index, std::string temp) {
        if(word == temp) return true;
        
        int len = word.length();
        if(index == len) return false;
        struct Trie* trie1 = trie;
        for(int i = index; i < len; i++) {
            char c = word[i];
            int j = c-'a';
            if(trie->children[j]) { trie = trie->children[j]; }
            else { return false;}
            if(trie->is_leaf) { 
                std::string temp0 = temp + trie->word;
                bool ret = dfs(trie1, word, temp0.length(), temp0);
                if(ret) {  return true; }
            }    
        }
        return trie->is_leaf;
    }
    
    bool wordBreak0(string s, vector<string>& wordDict) {
        trie = new Trie();
        for(std::string& word: wordDict) { put(trie, word);}
        return dfs(trie, s, 0, std::string());
    }
    
    bool wordBreak1(string s, vector<string>& wordDict) {
        trie = new Trie();
        for(std::string& word: wordDict) { put(trie, word);}
        int len = s.length();
        std::vector<bool> dp(len+1);
        dp[0]=true;
        for(int i = 0; i < len; i++) {
            if(dp[i]==false) continue;
            int j = i;
            struct Trie* curr = trie;
            while(j<len and curr->children[s[j]-'a']) {
                curr=curr->children[s[j++]-'a'];
                if(curr->is_leaf) dp[j]=true;
            }
        }
        return dp[len];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
        std::queue<int> queue; queue.push(0);
        int len = s.length();
        std::vector<bool> visited(len, false);
        while(not queue.empty()) {
            int front = queue.front(); queue.pop();
            if(visited[front] == false) {
                for(int i = front+1; i <= len; i++) {
                    std::string t = s.substr(front, i-front);
                    if(set.count(t)) { 
                        queue.push(i); 
                        if(i == len) { return true; }
                    }
                }
                visited[front] = true;
            }
            
        }
        return false;
    }
};