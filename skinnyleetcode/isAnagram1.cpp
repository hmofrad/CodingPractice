/*
 *	https://leetcode.com/problems/valid-anagram/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return t==s;
    }
    bool isAnagram2(std::string s, std::string t) {
        if(s.size()!= t.size()) return false;
        
        std::unordered_map<char, int> m;
        for(char c: s) m[c]++;
        for(char c: t) {
            if(m.count(c)==0) return false;
            else {
                m[c]--; 
                if(m[c]<0)return false;
            }
        }
        return true;
    }
    bool isAnagram1(std::string s, std::string t) {
    int n = s.size();
    int m = t.size();
    
    if((n == 0) or (m == 0)) return(true);
    if(n != m) return(false);
    
    std::vector<int> uniq(26);
    
    for(int i = 0; i < n; i++) {
        //char& c = s[i];
        uniq[s[i] - 'a']++;
        uniq[t[i] - 'a']--;
    }

   for(auto& i: uniq) {
       if(i != 0)
           return(false);
   }
   return(true);
}
};