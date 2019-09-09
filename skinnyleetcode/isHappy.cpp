/*
 *  Problem: https://leetcode.com/problems/happy-number/
 *  Compile: g++ -o isHappy isHappy.cpp -std=c++11 && ./isHappy
 *  Execute: ./isHappy
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

uint32_t squareSumOfDigits(uint32_t n) {
	int m = n;
	int r = 0;
	int s = 0;
	do{
		r = m % 10;
		m /= 10;
		s += (r*r);
	} while(m);
	return(s);
}

class Solution {
public:
    static bool isHappy(int n) {
		bool tf = false;
		int m = n;
		int i = 0;
		std::vector<int> nums;
		do{
			m = squareSumOfDigits(m);
			printf("%d: %d\n", i, m);
			if(std::find(nums.begin(), nums.end(), m) == nums.end())
				nums.push_back(m);
			else
				break;
			//i++;
			//if(i > 20) break;
		} while(m != 1);
		if(m == 1)
			tf = true;
		/*
		int m = n;
		int r = 0;
		int s = 0;
		//int multiplier = 0;
		//int remaining = 0;
		//int tens = 10;
		do{
			r = m % 10;
			m /= 10;
			s += (r*r);
			printf("multiplier=%d remaining=%d sum=%d\n", m, r, s);
			//multiplier = m / tens;
			//remaining = m % tens;
			//printf("m=%d, tens=%d, multiplier=%d remaining=%d\n", m, tens, multiplier, remaining);
			//tens = tens * tens; 
			//printf("T=%d\n", tens);
			//m = multiplier;
		} while(m);
		*/
		//printf("%d\n",squareSumOfDigits(n));
		
		
        return(tf);
    }
};

int main(int argc, char **argv)
{
	int n = 119;
    printf("isHappy(%d)=%d\n", n, Solution::isHappy(n));
    return(0);
}