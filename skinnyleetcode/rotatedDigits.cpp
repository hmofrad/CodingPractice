/*
 *  https://leetcode.com/problems/rotated-digits/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
Using a int[] for dp.
dp[i] = 0, invalid number
dp[i] = 1, valid and same number
dp[i] = 2, valid and different number
*/
class Solution {
public:
    int rotatedDigits(int N) {
        std::vector<int> dp(N+1);
        int count = 0;
        for(int i = 0; i <= N; i++) {
            if(i<10) {
                if(i==0 or i==1 or i==8) dp[i]=1;
                else if(i==2 or i==5 or i==6 or i==9) {dp[i]=2; count++;}
            }
            else {
                int r=dp[i%10]; int q=dp[i/10]; 
                if(r==1 and q==1)  dp[i]=1;
                else if(r>=1 and q>=1) {dp[i]=2; count++;}
            }
        }
        return count; 
    }
    
    
    std::vector<int> getDigits(int N) {
        std::vector<int> digits;
        while(N) {
            digits.push_back(N%10);
            N/=10;
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    }
    bool check(std::vector<int>& digits) {
        if(digits.empty()) return false;
        bool d013 = false;
        bool d2569 = false;
        for(int& d: digits) {
            if(d==3 or d==4 or d==7) return false;
            //if(d==0 or d==1 or d==8) d013=true;
            if(d==2 or d==5 or d==6 or d==9) d2569=true;
        }
        
        return d2569;
    }
    int rotatedDigits1(int N) {
        
        int count = 0;
        for(int i = 1; i <= N; i++) {
            std::vector<int> digits = getDigits(i);
            //printf("%d %d %d\n", i, digits.size(), check(digits));
            count += check(digits) ? 1 : 0;
        }
        return count; 
    }
};