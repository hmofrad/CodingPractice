/*
 * https://leetcode.com/problems/perfect-squares/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int numSquares(int n) {
        if(n<=0) { return 0; }
        std::vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
       // for(auto d: dp) printf("%d ", d); printf("\n");
        return dp[n];
    }
    
    
    bool is_divisible_by(std::set<int> set, int n, int count) {
        if(count == 1) { return set.count(n) != 0; }
        
        for(int square: set) {
            if(is_divisible_by(set, n-square, count-1)) { return true; }
        }
        return false; 
    }
    
    int numSquares1(int n) {
        //n = 1;
        std::set<int> set;
        for(int i = 1; i <= n; i++) {
            set.insert(i*i);
        }
        int count = 1;
        for(; count <= n; count++) {
            if(is_divisible_by(set, n, count)) { return count; }
        }
        return count;
    }
    
    
    
    int numSquares0(int n) {
        //if(n == 43) return(3);
        //if(n == 67) return(3);
            int ret = 0;
    int smallest_sq = 1;
    int sq = std::sqrt(n);
    std::vector<int> rets;
    for(int i = sq; i >= 1; i--) {
        int largest_sq = (i * i);
        int v = 0;
        ret = 0;
        int j = i;
        while(v != n) {
            //printf("%d %d %d\n", v, largest_sq, ret);
            int t = v + largest_sq;
            if(t > n) {
                j--;
                largest_sq = j * j; 
            }
            else if(t < n) {
                v += largest_sq;
                ret++;
            }
            else {
                v += largest_sq;
                ret++;
                break;
            }
        }
        rets.push_back(ret);
        //printf("v=%d ret = %d\n", v, ret);
    }
    ret = *std::min_element(rets.begin(), rets.end());
    return(ret);    
    }
};