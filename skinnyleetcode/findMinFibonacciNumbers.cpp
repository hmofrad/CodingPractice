/*
 *  https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
/*
We greedily subtract the biggest Fibonacci number x from k,
and recursive to find the result for k - x.
Then f(k) = f(k - x) + 1
*/
class Solution {
public:
    int dfs(std::vector<int>& fib, int index, int sum, int count, int target) {
        int size = fib.size();
        if(sum == target) return count;
        if(index >= size or sum > target) return INT_MAX;
        
        return min(dfs(fib, index+1, sum+fib[index], count+1, target), dfs(fib, index+1, sum, count, target));
    }
    int findMinFibonacciNumbers1(int k) {
        std::vector<int> fib(k+1);
        fib[1]=1; fib[2]=1;
        for(int i=3; i <= k; i++) {
            fib[i]=fib[i-1]+fib[i-2];
        }
        return dfs(fib, 0, 1,0, k);
        /*
        for(int i = 0; i <= k; i++) {
            printf("%d ", mem[i]);
        }
        printf("\n");
        */
       // return 0;
    }
    
    int findMinFibonacciNumbers(int k) {
        if (k < 2) return k;
        int a = 1, b = 1;
        while (b <= k) {
            //printf("1.a=%d b=%d k=%d\n", a, b, k);
            std::swap(a, b);
            b += a;
          //  printf("2.a=%d b=%d k=%d\n", a, b, k);
        }
        //printf("\n");
        return 1 + findMinFibonacciNumbers(k - a);
    }
    
    
};