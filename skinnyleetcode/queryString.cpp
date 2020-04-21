/*
 *  https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isSubstr(std::string S, std::string T) {
        int len_S = S.length();
        int len_T = T.length();
        bool found = false;
        for(int i = 0; i < len_S; i++) {
            int j = 0;
            if(S[i] == T[j]) {
                for(j = 0; j < len_T; j++) {
                    if(S[i+j] != T[j]) break; 
                }
                if(j == len_T and S[i+len_T-1] == T[len_T-1]) {found = true; break;}
            }
        }
        return found;
    }
    int get_bit(int num, int i) {
        int mask = 1 << i;
        int bit = num&mask;
        return bit != 0;
    }
    std::string toString(int num) {
        std::string bits;
        int i = 31;
        while(not get_bit(num, i)) i--;
        for(; i >= 0; i--) {
            bits.push_back('0'+get_bit(num, i));
        }
        return bits;
    }
    bool queryString(string S, int N) {
        int length = S.length();
        for(int i = 1; i <= N; i++) {
            std::string T = toString(i);
            //printf("%d: S=%s T=%s\n", i, S.c_str(), T.c_str());
            if(not isSubstr(S, T)) return false;
        }
        return true;
    }
    
    bool queryString1(string S, int N) {
        std::set<int> nums;
        int length = S.length();
        int i = 0;
        //while(S[i]=='0') i++;
        int num;
        for(int i = length-1; i >= 0; i--) {
            int s = S[i]-'0';
            int p = (length-1)-i;
            num += s*pow(2, p);
            int num1 = num;
            while(num1) {
                num1&=num1-1;
                nums.insert(num1);
                
            }
            nums.insert(num);    
        }
        
        for(auto num: nums) {
            printf("%d ", num);
        }
        printf("\n");
        
        for(int i = 1; i < N; i++) {
            if(not nums.count(i)) return false;
        }
        
        return true;
    }
};