/*
 *	https://leetcode.com/problems/clumsy-factorial/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int clumsy(int N) {
       // N=10;
        std::stack<int> stack; stack.push(N);
        for(int i = N-1; i >= 1; i--) {
            int t = 0;
            //printf("%d %d %d\n", i, (N-i+1)%4, stack.size());
            switch((N-1-i)%4) {
                case 0: t = stack.top(); stack.pop(); stack.push(t*i); break;
                case 1: t = stack.top(); stack.pop(); stack.push(t/i); break;
                case 2: stack.push(i); break;
                case 3: stack.push(-i); break;
            }
        }
        int ans = 0;
        while(not stack.empty()) {ans +=stack.top(); stack.pop();}
        return ans;
    }
};
