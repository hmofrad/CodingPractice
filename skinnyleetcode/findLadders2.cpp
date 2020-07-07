/*
 * https://leetcode.com/problems/word-ladder-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    vector<vector<string>> bfs(std::unordered_map<std::string, std::vector<std::string>>& map, string beginWord, string endWord) {
        std::vector<std::vector<std::string>> ans;
        //std::vector<std::string> path;
        std::queue<std::pair<std::string, std::vector<std::string>>> queue; queue.push({beginWord,{}});
//        std::unordered_set<std::string> visited; visited.insert(beginWord);
        int count = 1;
        while(not queue.empty()) {
            int size =queue.size();
            std::unordered_set<std::string> visited;
            while(size){
                std::pair<std::string, std::vector<std::string>> front = queue.front();
                queue.pop();
                front.second.push_back(front.first);
                visited.insert(front.first);
                //path.push_back(front);
                if(front.first == endWord) { 
                    ans.push_back(front.second);
                }
                
                    
                int len = front.first.length();
                for(int i = 0; i < len; i++) {
                    std::string key = front.first; key[i]='*';
                    std::vector<std::string>& values = map[key];
                    for(std::string& value: values) {
                        if(visited.insert(value).second) { queue.push({value,front.second}); }
                    }
                }
                size--;
            }
            //if(not ans.empty()) break;
        }
        return ans;
    }
    
    vector<vector<string>> bfs(string beginWord, string endWord, std::unordered_set<std::string>& wordList) {
        std::vector<std::vector<std::string>> ans;
        std::queue<std::vector<std::string>> paths;
        //wordList.insert(endWord);
        paths.push({beginWord});
        int level = 1;
        int min_level = INT_MAX;
        std::unordered_set<std::string> visited;
        
       while(not paths.empty()) {
           std::vector<std::string> path = paths.front(); paths.pop();
           int size = path.size();
           if(size>level) {
               for(std::string v: visited) { wordList.erase(v); }
               visited.clear();
               if(size>min_level) break;
               else level=size;
           }
           std::string last = path.back();
           int len = last.length();
           for(int i = 0; i < len; i++) {
               std::string t = last;
               for(char c = 'a'; c <= 'z'; c++) {
                   t[i]=c;
                   if(wordList.count(t)) {
                       std::vector<std::string> new_path=path;
                       new_path.push_back(t);
                       visited.insert(t);
                       if(t == endWord) {
                           min_level = level;
                           ans.push_back(new_path);
                       }
                       else { paths.push(new_path); }
                   }
               }
           }
       } 
        return ans;
    }
    
        vector<vector<string>> bfs1(string beginWord, string endWord, std::unordered_set<std::string>& wordList) {
        std::vector<std::vector<std::string>> ans;
        std::queue<std::vector<std::string>> paths;
        //wordList.insert(endWord);
        paths.push({beginWord});
        int level = 1;
        int min_level = INT_MAX;
        int s = 0;
        
       while(not paths.empty()) {
           std::unordered_set<std::string> visited;
           int size = paths.size();
           while(size) {
               std::vector<std::string> path = paths.front(); paths.pop();
               s = path.size();
               //if(s>min_level) break;
               
               std::string last = path.back();
               int len = last.length();
               for(int i = 0; i < len; i++) {
                   std::string t = last;
                   for(char c = 'a'; c <= 'z'; c++) {
                       t[i]=c;
                       if(wordList.count(t)) {
                           std::vector<std::string> new_path=path;
                           new_path.push_back(t);
                           visited.insert(t);
                           if(t == endWord) {
                               min_level = level;
                               ans.push_back(new_path);
                           }
                           else { paths.push(new_path); }
                       }
                   }
               }
               size--;
           }
           if(s>min_level) break;
           for(std::string v: visited) { wordList.erase(v); }
       }
        return ans;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //wordList = {"hot","dot","dog","lot","log"};
        /*
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::string& word: wordList) {
            int len = word.length();
            for(int i = 0; i < len; i++) {
                std::string t = word; t[i]='*';
                map[t].push_back(word);
            }
        }

        return bfs(map, beginWord, endWord);
        */
        std::unordered_set<std::string> wordList0(wordList.begin(), wordList.end());
        return bfs1(beginWord, endWord, wordList0);
    }
};