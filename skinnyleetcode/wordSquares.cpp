/*
 *  https://leetcode.com/problems/word-squares/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    struct Trie{
        Trie(){children.resize(26);};
        ~Trie();
        std::vector<struct Trie*> children;
        bool is_leaf = false;
        std::vector<int> indices;
    };
    
    void populate_trie(struct Trie* trie, std::string& word, int index) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            char c = word[i];
            int j = c-'a';
            if(trie->children[j]==nullptr) trie->children[j] = new Trie();
            trie->children[j]->indices.push_back(index);
            trie = trie->children[j];
            //trie->indices.push_back(index);
        }
        trie->is_leaf = true;
    }
    
   
    bool find(struct Trie* trie, std::string& word) {
        int len = word.length();
        
        for(int i = 0; i < len; i++) {
            char c = word[i];
            int j = c-'a';
            if(trie->children[j]==nullptr) return false;
            trie=trie->children[j];
        }
        return trie->is_leaf;
    }
    std::vector<std::vector<std::string>> results;
    std::vector<std::string> res;
    
    void backtrack(std::vector<std::string>& words, int level, int length, struct Trie* trie) {
        if(level==length) {results.push_back(res); return;}
        
        std::string prefix;
        for(int i = 0; i < level; i++) prefix += res[i][level];
       // printf("%s\n", prefix.c_str());
        struct Trie* temp = trie;
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            int j = c-'a';
            //if((temp=temp->children[j])==nullptr) return;
            if(temp->children[j]==nullptr) return;
            temp=temp->children[j];
        }
        
       for(int index: temp->indices) {
           res[level]=words[index];
           backtrack(words, level+1, length, trie);
       }
        
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
       struct Trie* trie = new Trie();
        for(int i = 0; i < words.size(); i++) populate_trie(trie, words[i], i);
        int len = words[0].length();
        res.resize(len);
        
        for(std::string& word: words) {
            res[0]=word;
            backtrack(words, 1, len, trie);
        }
        
        
        return results;
    }
    
    /* ----------------*/
    
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::vector<std::string> square;
    std::vector<std::vector<std::string>> squares;
    vector<vector<string>> wordSquares2(vector<string>& words) {
        int length = words[0].length();
        square.resize(length);
        for(std::string& word: words) {
            for(int i = 0; i < length; i++) { map[word.substr(0, i)].push_back(word); }
        }
        
        recur(0, length);
        return squares;
    }
    
    void recur(int i, int length) {
        if(i==length) { squares.push_back(square);  return; }
        std::string prefix;
        for(int k = 0; k < i; k++) prefix += square[k][i];
        for(std::string& word: map[prefix]) { square[i]=word; recur(i+1, length);}
    }
    
    std::set<vector<string>> ans;
    bool check(std::vector<std::string>& words) {
        int nrows = words.size();
        int ncols = nrows ? words[0].size() : 0;
        for(int i = 0; i < nrows-1; i++) {
            for(int j = i+1; j < ncols; j++) {
                if(words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
    
    void dfs(vector<string> words, vector<string> temp, int length) {
        if(temp.size() == length) {
            if(check(temp) and ans.count(temp)==0) 
                ans.insert(temp); 
            return;
        }
        
        for(std::string word: words) {
            if(not temp.empty()) {
                int r = temp.size();
                if(word[r-1]!=temp.back()[r]) continue;
            } 
            temp.push_back(word);
            dfs(words, temp, length);
            temp.pop_back();
        }
        return;
    }
    vector<vector<string>> wordSquares1(vector<string>& words) {
        int length = words[0].size();
        dfs(words, std::vector<std::string>(), length);
        vector<vector<string>>r(ans.begin(), ans.end());
        return r;
    }
};