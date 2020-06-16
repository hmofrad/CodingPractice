/*
 * https://leetcode.com/problems/find-and-replace-in-string/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        std::vector<std::pair<int, int>> indices;
        for(int i = 0; i < indexes.size(); i++) indices.push_back({i, indexes[i]});
        std::sort(indices.begin(), indices.end(), [](std::pair<int, int> a, std::pair<int, int> b)
                  { return a.second > b.second; });
        
        for(std::pair<int, int> index: indices) {
            int i = index.first;
            int idx = index.second;
            std::string& src = sources[i];
            std::string& dst = targets[i];
            if(S.substr(idx, src.length()) == src) {
                S = S.substr(0, idx) + dst + S.substr(idx+src.length());
            }
        }
        
        return S;
    }
    
    
    
    std::string replace(std::string str, int index, std::string src, std::string dst) {
        std::string t;
        int len = str.length();
        if(index >= len or index + src.length()>len) return t;
        for(int i = index; i < src.size(); i++) {
            if(str[i] != src[i]) return t;
        }
        t = str.substr(0, index) + dst + str.substr(index+src.length());
        return t;
    }
    
    string findReplaceString1(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        std::vector<std::string> temp;
        int size = indexes.size();
        for(int i = 0;  i < size; i++) {
            std::string t = replace(S, indexes[i], sources[i], targets[i]);
            if(not t.empty()) temp.push_back(t);
        }
        
        for(auto t: temp) printf("%s\n", t.c_str());
        return std::string();
    }
};