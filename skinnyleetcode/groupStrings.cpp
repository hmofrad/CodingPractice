/*
 *	https://leetcode.com/problems/group-shifted-strings/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    std::pair<std::string, std::string> encode(std::string& str) {
        std::string s;
        std::string s1;
        for(char c: str) {
            s += to_string(c-'a')+',';
            s1 += to_string(('z'-c))+',';
        }
        return std::make_pair(s,s1);
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for(std::string& str: strings) {
            std::pair<std::string, std::string> shifted = encode(str);
            printf("%s %s %s\n", str.c_str(), shifted.first.c_str(), shifted.second.c_str());
        }
        std::vector<std::vector<std::string>> ans;
        return ans;
    }
    
    vector<vector<string>> groupStrings2(vector<string>& strings) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::string& str: strings) {
            char c0 = str[0];
            std::string key;
            for(char& c: str) key += to_string((c+26-c0)%26)+',';
            map[key].push_back(str);
        }
        
        std::vector<std::vector<std::string>> ans;
        for(auto m: map) {
            std::vector<std::string>& vec = m.second;
            std::sort(vec.begin(), vec.end());
            ans.push_back(vec);
        }
        return ans;
    }
    
    bool check(std::string& a, std::string& b) {
        printf("%s %s ", a.c_str(), b.c_str());
        int len_a = a.length();
        int len_b = b.length();
        if(len_a != len_b) return false;
        //int d1 = a[0]-b[0];
        int d1 = (a[0]-b[0]+26)%26;
        for(int i = 1; i < len_a; i++) {
            //int d = a[i]-b[i];
            int d = (a[i]-b[i]+26)%26;
            printf("[%d %d]\n", d1, d);
            if(d1!=d) return false;
            //if(d1!=d and d1!=26-d) return false;
        }
        return true;
    }
    vector<vector<string>> groupStrings1(vector<string>& strings) {
        std::vector<std::string> strs = {"lpt", "txb"};
        bool c =check(strs[1], strs[0]);
        printf("%d\n", c);
        exit(0);
        vector<vector<string>> ans;
        if(strings.empty()) return ans;
        //std::sort(strings.begin(), strings.end(), [](std::string a, std::string b) {return a.length() < b.length();});
        std::sort(strings.begin(), strings.end(), [](std::string a, std::string b) {return a.length() < b.length();});
        
        //int dd =check(strings[2], strings[3]);
        //printf("%d\n", dd);
        //exit(0);
        int size = strings.size();
        
        ans.push_back(std::vector<std::string>());
        ans[0].push_back(strings[0]);
        for(int i = 1; i < size; i++) {
            std::string& str = strings[i];
            std::vector<std::string>& current = ans.back();
            std::string& str1 = current.back();
            //printf("%s %s %d\n", str1.c_str(), str.c_str(), check(str1, str));
            if(check(str1, str)) {
                current.push_back(str);
            }
            else {
                //std::sort(ans.back().begin(), ans.back().end());
                ans.push_back(std::vector<std::string>());
                ans.back().push_back(str);
            }
        }
        
        /*
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::string& str: strings) {
            std::string key = encode(str);
            printf("%s %s\n", str.c_str(), key.c_str());
            
        }
        */
         
        return ans;
    }
};