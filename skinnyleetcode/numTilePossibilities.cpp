/*
 *  https://leetcode.com/problems/letter-tile-possibilities/
 *  Compile & run: g++ -o numTilePossibilities numTilePossibilities.cpp -g -Wall -std=c++11 -fsanitize=address  && ./numTilePossibilities
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>  
#include<bits/stdc++.h>  
using namespace std;  

std::string insert_char_at(std::string str, int index, char c_char) {
    std::string first = str.substr(0, index);
    std::string second = str.substr(index, str.size()-index);
    return(first + c_char + second);
}

std::vector<std::string> permutations(std::string str) {
    std::vector<std::string> perms;
    if(str.empty()) {
        perms.push_back("");
        return(perms);
    }    
    
    char first = str[0];
    str.erase(str.begin());
    
    std::vector<std::string> words = permutations(str);
    for(auto word: words) {
        for(uint32_t i = 0; i <= word.size(); i++) {
            std::string s = insert_char_at(word, i, first);
            perms.push_back(s);
        }
    }    
    return(perms);
}

//char data[]
void combinationUtil(std::string str, std::string& data, std::vector<std::string>& combs,  int start, int end,  int index, int r)  {  
    if (index == r)  {  
        /*
        std::string t;
        for (int j = 0; j < r; j++) {
            t += data[j];
            
        }
        combs.push_back(t);
        */
        
        combs.push_back(data.substr(0,r));
        data.clear();
        /*
        for (int j = 0; j < r; j++)  
            cout << data[j] << " ";  
        cout << endl;  
        */
        return;  
    }  
 
    for (int i = start; i <= end and end - i + 1 >= r - index; i++) {  
        //data[index] = str[i]; 
        data += str[i];        
        combinationUtil(str, data, combs, i+1, end, index+1, r);  
    }  
}  

std::vector<std::string> printCombination(std::string str, int n, int r) {  
    std::vector<std::string> combs;
    std::string data;
    //char data[r];  
    combinationUtil(str, data, combs, 0, n-1, 0, r); 
    return(combs);    
}  
  
// Driver code  
int main()  
{  
    int arr[] = {1, 2, 3, 4, 5};  
    std::string tiles = "AAABBC";
    int n = tiles.length();
    //int r = 3;
    //int r = 3;  
    //int n = sizeof(arr)/sizeof(arr[0]);  
    std::vector<std::string> combs;
    for(int r = 1; r <= n; r++) {
        std::vector<std::string> comb = printCombination(tiles, n, r);  
        combs.insert(combs.end(), comb.begin(), comb.end()); 
    }
    //for(auto c: combs) {
    //    printf("1.<%s>\n", c.c_str());
    ///}
    
    std::vector<std::string> perms;
    for(auto c: combs) {
        std::vector<std::string> perm = permutations(c);
        perms.insert(perms.end(), perm.begin(), perm.end());
    }
    
    //for(auto p: perms) {
     //   printf("2.<%s>\n", p.c_str());
   // }
    printf("%d\n", perms.size());
    sort(perms.begin(), perms.end());
    perms.erase(unique(perms.begin(), perms.end()), perms.end());
printf("%d\n", perms.size());
 for(auto p: perms) {
        printf("3.<%s>\n", p.c_str());
    }
    
}  
  
int numTilePossibilities(string tiles) {
        std::unordered_map<char, int> count;
        for(auto c: tiles) {
            count[c]++;
        }
        
        std::vector<char> letters;
        for(auto c: count) {
            letters.push_back(c.first);
        }
        
        std::vector<std::vector<int>> dp(letters.size()+1, std::vector<int>(tiles.size()+1));
        dp[0][0] = 1;
        
        for(int i = 1; i <= letters.size(); i++) {
            for(int j = 0; j <= tiles.size(); j++) {
                int c = count[letters[i-1]];
                for(int k = min(c, j); k >= 0; k--) {
                    dp[i][j] += dp[i-1][j-k] * combine(j,k);
                }
            }
        }
        
        int rst = 0;
        for(int i = 1; i <= tiles.size(); i++) {
            rst += dp[letters.size()][i];
        }
        return(rst);
    
    }