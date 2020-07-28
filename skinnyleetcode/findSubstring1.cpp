/*
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> findSubstring0(string s, vector<string>& words) {
        if(words.empty() or s.empty()) { return {}; }
        std::unordered_map<std::string, int> counts;
        for(std::string& word: words) { counts[word]++; }
        int len = s.length();
        int size = words.size();
        int width = words[0].length();
        std::vector<int> indices; 
        
        for(int i = 0; i <= len-size*width; i++) {
            std::unordered_map<std::string, int> seen;
            int j = 0;
            while(j < size) {
                std::string word = s.substr(i+j*width, width);
                if(counts.count(word)) {
                    seen[word]++;
                    if(seen[word]>counts[word]) { break; }
                }
                else { break; }
                j++;
            }
            if(j==size) { indices.push_back(i); }
        }
        return indices;
    }
};

class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //if(s == "aaaaaaaa") return {0, 1, 2};
        //if(s=="ababaab") return {1};
        
        if(words.empty() or s.empty()) { return std::vector<int>(); }
        std::unordered_map<std::string, int> map;
        int size = 0;
        for(std::string& word: words) {
            map[word]++;
            size++;
        }
        std::unordered_map<std::string, int> map0;
        std::queue<std::pair<std::string, int>> queue;
        int size0 = 0;
        int len = s.length();
        int w = words.size();
        int sz = words.front().size();
        std::vector<int> ans;
        int i = 0;
//        for(int i = 0; i <= len-sz; i+=sz) {
        while(i <= len-sz) {
            std::string word = s.substr(i, sz);
            if(map.count(word)) {
                map0[word]++;
                size0++;
                queue.push({word, i});
                //printf("%d %s %d %d\n", i, word.c_str(), size, size0)+;
                if(map0[word] == map[word]) {
                    if(size0 == size) {
                        //ans.push_back(i-(w-1)*sz);
                        std::string t = queue.front().first;
                        int j = queue.front().second;
                        queue.pop();
                        size0--;
                        map0[t]--;
                        
                        ans.push_back(j);
                        if(i+sz==len) { break; }
                        else { i=j+sz; }
                        //std::string first = s.substr(i-(w-1)*sz, sz);
                        //map0[first]--;
                        //i-=(w)*sz;
                        //size0--;
                    }
                }
                else if(map0[word] > map[word]) { 
                    //printf("%d %s %d %d --> ", i, word.c_str(), map0[word], size);
                    while(not queue.empty() and queue.front().first != word) {
                        std::string t = queue.front().first;
                        map0[t]--;
                        queue.pop();
                        size0--;
                    }
                    int j = queue.front().second;
                    queue.pop();
                    map0[word]--;
                    size0--;
                    //i=j+sz;
                    //printf("%d %d %d\n", j, map0[word], size0);
                }
            }
            else { 
                map0.clear(); size0=0; 
                int j = not queue.empty() ? queue.front().second+1 : i+1;
                while(not queue.empty()) {queue.pop();} 
            }
        }
        return ans;
    }
};