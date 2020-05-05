/*
 *	https://leetcode.com/problems/group-anagrams/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        std::unordered_map<std::string, std::vector<std::string>> my_map;
        for(int i = 0; i < strs.size(); i++) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            my_map[str].push_back(strs[i]);
        }
        
        std::vector<std::vector<std::string>> ans;
        
        for(auto& temp: my_map) {
            std::vector<std::string> t;
            for(auto& str: temp.second) t.push_back(str);
            ans.push_back(t);
        }
        
        return ans;
    }
    
    struct anagram{
        std::string str;
        std::unordered_map<char, int> map;
        int size = 0;
    };
    bool comapre_anagram(struct anagram& a, struct anagram& b) {
        bool matched = true;
        if(a.size != b.size) matched = false;
        else {
            for(const auto& i: a.map) {
                int key = i.first;
                int value = i.second;
               if(b.map[key]!=value) {matched = false; break;} 
            }
        }
        return matched;
    }
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        int size = strs.size();
        std::vector<struct anagram> anagrams(size);
        std::vector<std::vector<std::string>> ans;
        for(int i = 0; i < size; i++) {
            std::string& str = strs[i];
            anagrams[i].str = str;
            for(char& c: str) {
                anagrams[i].map[c]++;
                anagrams[i].size++;
            }
        }
        
 
        std::vector<bool> valid(size, true);
        for(int i = 0; i < size; i++) {
            if(valid[i]) {
                valid[i]=false;
                std::vector<int> matched={i};
                for(int j = i+1; j < size; j++) {
                    if(valid[j] and comapre_anagram(anagrams[i], anagrams[j])) {matched.push_back(j); valid[j]=false;}
                }
                std::vector<std::string> temp;
                for(int m: matched) temp.push_back(strs[m]);
                ans.push_back(temp);
            }
        }
        
        
        return ans;
    }
};