/*
 *	https://leetcode.com/problems/ransom-note/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> m(26); for(char c: magazine) m[c-'a']++;
        for(char c: ransomNote) {
            m[c-'a']--;
            if(m[c-'a']<0) return false;
        }
        return true;
    }
    
    
    bool canConstruct1(string ransomNote, string magazine) {
            if((ransomNote.size() and magazine.size() == 0) or
       (magazine.size() < ransomNote.size())) {
           return(false);
    }
    
    std::sort(ransomNote.begin(), ransomNote.end());
    std::sort(magazine.begin(), magazine.end());
    uint32_t i = 0;
    uint32_t j = 0;
    
    while(i < ransomNote.size() and j < magazine.size()) {
        if(ransomNote[i] == magazine[j]) {
            i++;
            j++;
            
        }
        else {
            j++;
        }
    }
    return((i==ransomNote.size()));    
    }
};