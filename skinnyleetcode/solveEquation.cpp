/*
 * https://leetcode.com/problems/solve-the-equation/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    string solveEquation(string equation) {
        int len = equation.length();
        int sign = 1;
        int coeff = 0;
        int sum = 0;
        int j = 0;
        for(int i = 0; i < len; i++) {
            if(equation[i] == '+' or equation[i] == '-') {
                if(i>j) { sum += sign * stoi(equation.substr(j,i-j)); }
                j=i;
            }
            else if(equation[i] == 'x') {
                if(i==j or equation[i-1]=='+') { coeff += sign; }
                else if(equation[i-1]=='-') { coeff -= sign; }
                else { coeff += sign*stoi(equation.substr(j,i-j)); }
                j=i+1;
            }
            else if(equation[i] == '=') {
                if(i>j) { sum += sign * stoi(equation.substr(j, i-j)); }
                sign = -1;
                j=i+1;
            }
        }
        
        if(j<len) { sum += sign * stoi(equation.substr(j)); }
        
        if(coeff == 0 and sum == 0) { return "Infinite solutions"; }
        else if(coeff == 0 and sum) { return "No solution"; }
        int ans = -sum/coeff; 
        
        return "x="+to_string(ans);
    }
};