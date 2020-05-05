/*
 *	https://leetcode.com/problems/longest-repeating-substring/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    bool search(std::string S, int len) {
        std::unordered_set<std::string> seen;
        int length = S.length();
        bool found = false;
        for(int i=0; i <=length-len; i++) {
            std::string temp = S.substr(i, len);
            //printf("%d %s\n", i, temp.c_str());
            if(seen.count(temp)) {found = true; break;}
            seen.insert(temp);
        }
        return found;
    }
    
    int longestRepeatingSubstring(string S) {
        int len = S.length();
        int start = 1;
        int end = len-1;
        int max_len = 0;
        while(start<=end) {
            int mid = start + (end-start)/2;
                       // printf("%d %d %d %d\n", start, end, mid, max_len);
            if(search(S, mid)) {max_len=mid; start=mid+1;}
            else end=mid-1;
        }
        return max_len;
    }
    
    int longestRepeatingSubstring2(string S) {
        if(S.empty()) return 0;
        
        int len = S.length();
        std::vector<std::vector<int>> dp(len+1, std::vector<int>(len+1));
        int max_len = 0;
        for(int i = 1; i <= len; i++) {
            for(int j = i+1; j <= len; j++) {
                if(S[i-1]!=S[j-1]) continue;
                dp[i][j]=dp[i-1][j-1]+1;
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
    int longestRepeatingSubstring1(string S) {
        std::unordered_map<std::string, int> substrings;
        int len = S.length();
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                int l = j-i+1;
                std::string s = S.substr(i, l);
                //printf("i=%d j=%d l=%d s=%s\n", i, j, l, s.c_str());
                substrings[s]++;
            }
        }
        int longest = 0;
        int length = 0;
        for(auto s: substrings) {
            std::string k = s.first;
            int v = s.second;
            int l = k.length();
            if(v>1 and l>longest) longest = l;
            //printf("%s %d\n", key.c_str(), value);
        }
        
        return longest;
    }
};