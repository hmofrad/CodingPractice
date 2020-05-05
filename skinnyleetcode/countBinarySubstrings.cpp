/*
 *	https://leetcode.com/problems/count-binary-substrings/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        std::vector<int> groups;
        groups.push_back(1);
        int len = s.length();
        for(int i = 1; i < len; i++) {
            if(s[i-1] == s[i]) groups.back()++;
            else groups.push_back(1);
        }
        //for(int g: groups) printf("%d ", g); printf("\n");
        int size = groups.size();
        int count = 0;
        for(int i = 1; i < size; i++) {
            count += min(groups[i-1], groups[i]);
        }
        return count;
    }
    
    
    int search(std::string s, int len) {
        if(len%2) return 0;
        int length = s.length();
        int count = 0;
        for(int i = 0; i <= length-len; i++) {    
            int left = 0;
            int right = 0;
            for(int j = 0; j < len/2; j++) {    
                left += s[i+j]-'a';
                right += s[i+len-1-j]-'a';
            }
            count += (abs(left-right) == len/2) ? 1 : 0;
        }
        return count;
    }
    
    int countBinarySubstrings1(string s) {
        int len = s.length();
        int count = 0;
        for(int i = len; i >= 2; i--) {
            //printf("%d %d\n", i, search(s, i));
            count += search(s, i);
        }
        
        //for(int i = 1; i <= len; i++) {
            //for(int j = i+1; j <= len; j++) {
                
          //  }
        //}
        return count;
    }
};