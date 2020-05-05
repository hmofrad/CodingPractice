/*
 *	https://leetcode.com/problems/camelcase-matching/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check1(std::string& query, std::string& pattern) {
        int size_q = query.size();
        int size_p = pattern.size();
        int j = 0;
        for(int i = 0; i < size_q; i++) {
            if(j < size_p and query[i] == pattern[j]) j++;
            else if(query[i] >= 'A' and query[i] <= 'Z') return false;
        }
        return j==size_p;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int size = queries.size();
        std::vector<bool> ans(size);
        for(int i = 0; i < size; i++) {
            std::string& query = queries[i];
            ans[i] = check1(query, pattern);
        }
        return ans;
    }
    
    
    
    std::unordered_map<char, int> lower_case;
    std::unordered_map<char, int> upper_case;
    bool check(std::string& query, std::string& pattern) {
        std::unordered_map<char, int> lower_case_t;
        std::unordered_map<char, int> upper_case_t;
        int sum_t = 0;
        for(char c: query) {
            if(c>='a' and c<='z') lower_case_t[c]++;
            if(c>='A' and c<='Z') {upper_case_t[c]++; sum_t++;}
        }   
        int sum = 0;
        for(auto u: upper_case) {
            if(upper_case_t.count(u.first) != u.second) {
                return false;
            }
            sum+=u.second;
        }
        if(sum != sum_t) return false;

        for(auto l: lower_case) {
            if(lower_case_t.count(l.first)==0 or (lower_case_t.count(l.first) and l.second > lower_case_t[l.first])) return false;
        }
       
        
        int idx_q = 0;
       int len_q = query.size();
       int idx_p = 0;
       int len_p = pattern.size();
        while(idx_q < len_q and idx_p < len_p) {
            if(query[idx_q]==pattern[idx_p]) idx_p++;
            idx_q++;
        }

        if(idx_p < len_p) return false;

               
               
        return true;
    }
    vector<bool> camelMatch1(vector<string>& queries, string pattern) {
    
        for(char c: pattern) {
            if(c>='a' and c<='z') lower_case[c]++;
            if(c>='A' and c<='Z') upper_case[c]++;
        }
        int size = queries.size();
        std::vector<bool> ans(size);
        for(int i = 0; i < size; i++) {
            std::string& query = queries[i];
            ans[i] = check(query, pattern);
        }
        return ans;
    }
};

int main() {
	vector<string> queries = {"CompetitiveProgramming","CounterPick","ControlPanel"};
	std::string pattern = "CooP";
	vector<bool> v = camelMatch(queries, pattern);
	for(auto vv: v) printf("%d ", vv!=0); printf("\n");
		
	return 0;
}