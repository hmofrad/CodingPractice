/*
 *	https://leetcode.com/problems/greatest-common-divisor-of-strings/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if(str2.empty()) return str1;
        if(str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
    string gcdOfStrings2(string str1, string str2) {
        return str1+str2 == str2+str1 ? str1.substr(0, gcd(str1.size(), str2.size())) : std::string();
    }
    string gcdOfStrings1(string str1, string str2) {
        std::vector<int> map1(26); for(char c: str1) map1[c-'A']++;
        std::vector<int> map2(26); for(char c: str2) map2[c-'A']++;
        for(int i = 0; i < 26; i++) {
            int m1 = map1[i] ? 1 : 0;
            int m2 = map2[i] ? 1 : 0;
            //printf("i=%d 1=%d 2=%d 1^2=%d\n",i , m1, m2, m1^m2);
            if(m1^m2) return std::string();
        }
        
        int size1 = str1.size();
        int size2 = str2.size();
        int i = 0;
        int j = 0;
        while(i<min(size1, size2)) {
            if(str1[i]==str2[i]) i++;
            else break;
        }
        while(i and (size1%i != 0 or size2%i != 0)) i--; 
        i = (i==1) ? 0 : i;
        std::string ans = str1.substr(0, i);
        return ans;
    }
};