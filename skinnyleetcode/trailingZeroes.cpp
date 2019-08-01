/*
 *  URL: https://leetcode.com/problems/factorial-trailing-zeroes/
 *  Compile & Execute: g++ -o trailingZeroes trailingZeroes.cpp -std=c++11 && ./trailingZeroes
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 50000 
class Solution {
public:


  
// This function finds factorial of large numbers 
// and prints them 
    
  
// This function multiplies x with the number  
// represented by res[]. 
// res_size is size of res[] or number of digits in the  
// number represented by res[]. This function uses simple  
// school mathematics for multiplication. 
// This function may value of res_size and returns the  
// new value of res_size 
    static int multiply(int x, int res[], int res_size) 
    { 
        int carry = 0;  // Initialize carry 
      
        // One by one multiply n with individual digits of res[] 
        for (int i=0; i<res_size; i++) 
        { 
            int prod = res[i] * x + carry; 
      
            // Store last digit of 'prod' in res[]   
            res[i] = prod % 10;   
      
            // Put rest in carry 
            carry  = prod/10;     
        } 
      
        // Put carry in res and increase result size 
        while (carry) 
        { 
            res[res_size] = carry%10; 
            carry = carry/10; 
            res_size++; 
        } 
        return res_size; 
    } 

    static int factorial(int n) 
    { 
        int res[MAX]; 
      
        // Initialize result 
        res[0] = 1; 
        int res_size = 1; 
      
        // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
        for (int x=2; x<=n; x++) 
            res_size = multiply(x, res, res_size); 
      /*
        std::cout << "Factorial of given number is \n"; 
        
        for (int i=res_size-1; i>=0; i--) {
            std::cout << res[i]; 
            if(res[i] == 0)
                m++;
            
        }
        */
        int m = 0;
        for (int i = 0; i < res_size; i++) {
            if(res[i] == 0)
                m++;
            else
                break;
            
        }
        
        return(m);
    } 


/*
    static unsigned long long int factorial(int n) {
        if(n <= 1)
            return(1);
        unsigned long long int fact = 1;
        for(int i = 1; i <= n; i++)
            fact *= i;
        
        std::cout << fact <<std::endl;
        return(fact);
        
        //if (n > 1) {
          //  n *= factorial(n-1);
        //}
        //printf("n=%d\n", n);
        //return(n);
    }
    */
    static int trailingZeroes(int n) {
        //int m = 0;
        int m = factorial(n);
        //
        /*
        unsigned long  long int nn = factorial(n);
        std::cout << nn <<std::endl;
        //printf("n=%lu\n", nn);
        //if(not n)
          //  return 1;
    // int m = 0;
      
        //printf("n=%d\n", n);
        std::string seq = std::to_string(nn);
        int m = 0;
        //for(auto c: seq) {
        int len = seq.size();    
        for(int i = len - 1 ; i > 0; i--) {   
        
            //printf("<%c>\n", seq[i]);    
            if(seq[i] == '0')
                m++;
            else 
                break;
        }
        */
        //printf("%s\n", seq.c_str());
        return(m);
    }

};
int main(int argc, char **argv) {
    int m = 3186;
    int n = Solution::trailingZeroes(m);
    printf("\n%d\n", n);
    return(0);
}    
