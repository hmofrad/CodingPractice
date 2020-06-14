/*
 * https://leetcode.com/problems/minimum-window-substring/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string minWindow(string s, string t) {
        //s="aa";t="aa";
        if(s.empty() or t.empty()) return std::string();
        std::string ans;
        std::map<char, int> map_t;
        for(char c: t) map_t[c]++;
        std::map<char, int> map_s;
        int left = 0, right = 0;// begin = 0, end = 0;
        int size = map_t.size(); int formed=0;
        while(right<s.length()) {
            map_s[s[right]]++;
            if(map_t.count(s[right]) and map_t[s[right]]==map_s[s[right]]) formed++;
            //printf("%d %d %d %d\n", left, right, map_s.count(s[right]), map_t.count(s[right]));
            while(formed==size and left<=right) {
                std::string temp = s.substr(left, right-left+1); 
                //printf("%s\n", temp.c_str());
                if(ans.empty() or temp.size()<ans.size()) ans=temp;
                char c = s[left];
                map_s[c]--;
                if(map_s[c]<map_t[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        
        
        return ans;
    }
    string minWindow1(string s, string t) {
        int i = 0, len_s = s.length();
        int j = 0, len_t = t.length();
        std::string ans;
        std::map<char, int> map_t;
        for(char c: t) map_t[c]++;
        std::map<char, int> map = map_t;
        int begin = 0; bool first = true;
        while(i<len_s) {
            if(map.count(s[i])) {
                if(first){begin=i; first=false;}
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                if(map.empty()) {
                    int end = i;
                    std::string temp = s.substr(begin,end-begin+1);
                    if(ans.empty() or temp.size()<ans.size()) ans=temp;
                    map = map_t;
                    begin++;
                    i=begin;
                    first=true;
                    continue;
                }
            }
            i++;
        }
        return ans;
    }
};