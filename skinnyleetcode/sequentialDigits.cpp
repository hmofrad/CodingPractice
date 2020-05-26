/*
 *	https://leetcode.com/problems/sequential-digits/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int num_digits(int num) {
        return num ? num_digits(num/10) + 1 : 0;
    }
    int most_significant_digit(int num) {
        return num/10 ? most_significant_digit(num/10) : num;
    }
    int least_significat_digit(int num) {
        return num%10;
    }
    int max_digit(int num) {
        int max = 0;
        while(num) {
            int r = num%10;
            max= (max<r) ? r : max;
            num/=10;
        }
        return max;
    }
    int min_digit(int num) {
        int min = INT_MAX;
        while(num) {
            int r = num%10;
            min= (min>r) ? r : min;
            num/=10;
        }
        return min;
    }
    
    bool has_seq_digits(int num) {
        bool has = true;
        while(num) {
            int r = num%10;
            num /= 10;
            int r1 = num%10;
            if(r-r1!=1) {has = false; break;};
        }
        return has;
    }
    
    vector<int> toVec(int num) {
        std::vector<int> vec;
        while(num) {
            int r = num%10;
            vec.push_back(r);
            num/=10;
        }
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
    
    bool valid(std::vector<int> nums) {
        bool tf = true;
        int size = nums.size();
        for(int i = 0; i < size-1; i++) {
            if(nums[i+1]-nums[i] != 1) {tf = false; break;}
        }
        return tf;
    }
    
    
    vector<int> sequentialDigits(int low, int high) {
        std::string base = "123456789";
        int n = 10;
        std::vector<int> integers;
        int min_digits = num_digits(low);
        int max_digits = num_digits(high);
        
        for(int i = min_digits; i <= max_digits; i++) {
            //printf("i=%d:", i);
            for(int j = 0; j < n - i; j++) {
              //  printf("[%d-", j);
                std::string str = base.substr(j, i);
                int num = stoi(str);
                ///printf("%d]", num);
                if(num>=low and num <= high) integers.push_back(num);
            }
            //printf("\n");
        }
        
        return integers;
        
        /*
        low = 3454, high = 23674;
        
        std::vector<int> low0 = toVec(low);
        std::vector<int> high0 = toVec(low);
        int size0 = low0.size();
        int size1 = high0.size();
        
        if(not valid(low0)) {
            for(int i = size0-1; i >= 0; i--) {
                std::vector<int> t = low0;
                for(int j = t; j <= 9; j++) {
                    low0
                }
                    
            }
        }
        
        */
        
        
        
        /*
        int min_digits = num_digits(low);
        int max_digits = num_digits(high);
        int msd = most_significant_digit(low);
        int lsd = least_significat_digit(high);
        //printf("[%d %d %d %d %d %d]\n", low, min_digits, msd, high, max_digits, lsd);
       // printf("%d\n",has_seq_digits(2)==true );
        
        
        if(not has_seq_digits(low)) {
            
        }
        
        
        for(int i = min_digits; i <= max_digits; i++) {
            int t = low;
            int mxd = max_digit(low);
            
            for(int j = msd; j <= i; j++) {
                
            }
        }
        */

    }
};