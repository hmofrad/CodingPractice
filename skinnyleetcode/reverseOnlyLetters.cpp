/*
 *  https://leetcode.com/problems/reverse-only-letters/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string reverseOnlyLetters(string S) {
        std::stack<char> stack;
        for(char c: S) {
            if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')) 
                stack.push(c);
        }
        std::string T;
        for(char c: S) {
            if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')) {
                char c1 = stack.top(); stack.pop(); T.push_back(c1);
            }
            else {
                T.push_back(c);
            }
        }
        return T;
    }
    string reverseOnlyLetters1(string S) {
        int len = S.size();
        int left = 0;
        int right = len-1;
        int i = 0;
        //printf("%d %d %d %d\n", 'a', 'z', 'A', 'Z');
        
        while(true) {
        //while(i < len) {
            //printf("%c %d\n", S[i], not ((S[i] >= 'a' and S[i] <= 'z') or (S[i] >= 'A' and S[i] <= 'Z')) );
            //i++;
            
            while(left < right and not ((S[left] >= 'a' and S[left] <= 'z') or
                  (S[left] >= 'A' and S[left] <= 'Z'))) left++;
            while(right > left and not ((S[right] >= 'a' and S[right] <= 'z') or
                  (S[right] >= 'A' and S[right] <= 'Z'))) right--;
            if(left < right) {std::swap(S[left], S[right]); left++; right--;}
            else break;
            //printf("%d %d\n", left, right);
            //break;
        }
        
        return S;
    }
};