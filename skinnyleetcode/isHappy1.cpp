/*
 * https://leetcode.com/problems/happy-number/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int sum_of_digits(int n) {
        int s = 0;
        
        while(n) {
            int r = n%10;
            s += r*r;
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        if(n<=0) return false;
        bool happy = false;
        std::unordered_set<int> set;
        while(n) {
            n=sum_of_digits(n);
            if(n==1) {happy = true; break;}
            else if(set.insert(n).second == false) {happy = false; break; }
        }
        return happy;
    }
};

class Solution0 {
public:
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
    
    bool isHappy(int n) {
        bool tf = false;
		int m = n;
		int i = 0;
		std::vector<int> nums;
		do{
			m = squareSumOfDigits(m);
			if(std::find(nums.begin(), nums.end(), m) == nums.end())
				nums.push_back(m);
			else
				break;
		} while(m != 1);
		if(m == 1)
			tf = true;
        return(tf);
    }
};