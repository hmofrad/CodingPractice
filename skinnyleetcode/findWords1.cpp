/*
 * https://leetcode.com/problems/word-search-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    struct Trie{
        public:
        Trie(){children.resize(26);}
        ~Trie(){}
        std::vector<struct Trie*> children;
        bool is_leaf = true;
        std::string word;
    };
    
    void put(struct Trie* trie, std::string word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i] - 'a'; 
            if(trie->children[j] == nullptr) { trie->children[j]=new Trie();}
            trie=trie->children[j];
        }
        trie->is_leaf=true;
        trie->word=word;
    }
    
    void dfs(vector<vector<char>>& board, struct Trie* trie, std::vector<std::string>& ans, int row, int col) {
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols) return;
        
        char c = board[row][col];  
        if(c=='#' or trie->children[c-'a']==nullptr) return;
        trie=trie->children[c-'a'];
        if(trie->is_leaf and not trie->word.empty()) { ans.push_back(trie->word); trie->word.clear();}
        
        board[row][col]='#';
        
        std::vector<int> rr = {0,0,1,-1};
        std::vector<int> cc = {1,-1,0,0};
        for(int i = 0; i < 4; i++) {
            dfs(board, trie, ans, row+rr[i], col+cc[i]);
        }
        board[row][col]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct Trie* trie = new Trie();
        for(std::string word: words) {put(trie, word);}
        vector<string> ans;
        
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                dfs(board, trie, ans, i, j);
            }
        }
        return ans;
    }
};
































class Solution1 {
public:
    
    bool dfs(vector<vector<char>>& board, std::string& word, std::vector<std::pair<int,int>> path, std::vector<std::pair<int,int>>& path_, int index, int row, int col) {
        if(index == word.size()) {path_=path; return true;}
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or board[row][col]!=word[index]) return false;
        
        board[row][col]='#';
        path.push_back({row, col});
        bool ret = false;
        std::vector<int> r = {0, 0, 1,-1};
        std::vector<int> c = {1,-1, 0, 0};
        
        for(int i = 0; i < 4; i++) {
            ret = dfs(board, word, path, path_, index+1, row+r[i], col+c[i]);
            if(ret) break;
        }
        board[row][col]=word[index];
        return ret;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        std::sort(words.begin(), words.end());
        std::unordered_set<std::string> temp;
        std::unordered_map<std::string, std::vector<std::vector<std::pair<int,int>>>> pathes;

        vector<string> ans;
        int nrows = board.size();
        int ncols = nrows ? board[0].size() : 0;
        for(std::string word: words) {
            bool br = false;
            for(int i = 0; i < nrows; i++) {
                for(int j = 0; j < ncols; j++) {
                    if(temp.count(word)) {br=true; continue;}
                    std::string t, s;
                    for(int k = word.size()-2; k>0; k--) {
                        t = word.substr(0, k+1);
                        if(pathes.count(t)) {
                            s = word.substr(k+1);
                            std::vector<std::vector<std::pair<int, int>>>& pathes_v = pathes[t];
                            for(std::vector<std::pair<int, int>>& path_: pathes_v) {
                                for(int l = 0; l < path_.size()-1; l++) {board[path_[l].first][path_[l].second]='#'; }
                                std::vector<std::pair<int,int>> path0(path_.begin(), path_.end());
                                std::vector<std::pair<int,int>> path0_;
                                bool ret = dfs(board, word, path0, path0_, k, path0.back().first, path0.back().second);
                                for(int l = 0; l < path_.size()-1; l++) { board[path_[l].first][path_[l].second]=word[l]; }                                   
                                if(ret) {
                                    temp.insert(word);
                                    ans.push_back(word); 
                                    pathes[word].push_back(path0_);
                                    br=true;
                                }
                            }
                            if(br) break;
                        }
                        if(br) break;
                    }
                    if(br) break;
                    
                    std::vector<std::pair<int,int>> path;
                    std::vector<std::pair<int,int>> path_;
                    bool ret = dfs(board, word, path, path_, 0, i, j);
                    if(ret) { 
                        temp.insert(word);
                        ans.push_back(word); 
                        pathes[word].push_back(path_);
                        br=true;
                    }
                    if(br) break;
                }
                if(br) break;
            }
        }
        return ans;
    }
};