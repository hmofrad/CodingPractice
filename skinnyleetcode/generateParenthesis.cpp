/*
 *  Problem: Generate parentheses (https://leetcode.com/problems/generate-parentheses/description/)
 *  Compile: g++ -o generateParenthesis generateParenthesis.cpp && ./generateParenthesis -g -Wall -Werror
 *  Execute: ./generateParenthesis
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#include <stdio.h>

using namespace std;

class Solution
{
    public:
        vector<string> generateParenthesis(int n);
};

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> pair(n * 2);
    pair[0] = "(";
    pair[1] = ")";
    return(pair);
}

int main(int argc, char **argv)
{
    Solution sol;
    vector<string> ret = sol.generateParenthesis(1);
    cout << ret[0] << " " << ret[1] << endl;
    return(0);
}