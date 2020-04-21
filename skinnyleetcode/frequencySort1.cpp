/*
 *  https://leetcode.com/problems/sort-characters-by-frequency/solution/    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string frequencySort(string s) {
        std::map<char, int> freq;
        std::map<int, std::vector<char>> groups;
        for(char c: s) {
            freq[c]++;
        }
        
        for(auto f: freq) {
            char character = f.first;
            int count = f.second;
            if(count) groups[count].push_back(character);
        }
        
        std::string t;
        for(auto g: groups) {
            int count = g.first;
            auto& vec = g.second;
            for(auto v: vec) {
                std::string t1(count, v);
                t += t1;
            }
        }
        
        std::reverse(t.begin(), t.end());

        return t;
    }
    
    
    string frequencySort2(string s) {
        std::vector<int> freq(52);
        std::map<int, std::vector<char>> groups;
        int maxFreq = 0;
        for(char c: s) {
            if(c >= 'a' and c <= 'z') {
                int i = c-'a';
                freq[i]++;
            }
            else {
                int i = c-'A'+26;
                freq[i]++;
            }
        }
        
        for(int i = 0; i < 52; i++) {
            if(i >= 0 and i <= 25) {
                char c = i+'a';
                int count = freq[i];
                if(count) groups[count].push_back(c);
            }
            else {
                char c = i+'A'-26;
                int count = freq[i];
                if(count) groups[count].push_back(c);
            }
        }
        
        std::string t;
        for(auto g: groups) {
            int count = g.first;
            auto& vec = g.second;
            for(auto v: vec) {
                std::string t1(count, v);
                t += t1;
            }
        }
        
        std::reverse(t.begin(), t.end());

        return t;
    }
    
    
    
    
    
    
    string frequencySort1(string s) {
        std::string t;
        std::unordered_map<char, int> frequencies;
        for(uint32_t i = 0; i < s.size(); i++) {
            char& c = s[i];
            frequencies[c]++;
        }

        while(!frequencies.empty()) {
            char max_char = frequencies.begin()->first;
            int max_freq = frequencies.begin()->second;
            for(auto f: frequencies) {
                if(max_freq < f.second) {
                    max_char = f.first;
                    max_freq = f.second;
                }
            }
            frequencies.erase(max_char);
            for(int i = 0; i < max_freq; i++) {
                t += max_char;
            }
        }        
        return(t);    
    }
};