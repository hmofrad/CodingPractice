/*
 *	https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int len(vector<int>& nums) {
        int max_len = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = 31; j>= 0; j--) {
                int mask = 1 << j;
                int bit = nums[i] & mask;
                if(bit) {max_len=max(max_len, j+1); break;}
            }
        }
        return max_len;
    }
    int findMaximumXOR(vector<int>& nums) {
        int size = nums.size();
        int max_len = len(nums);
        
        int max_xor = 0;
        int cur_xor = 0;
        for(int i = max_len; i>=0; i--) {
            std::unordered_set<int> prefixes;
            max_xor <<= 1; cur_xor = max_xor | 1;
            
            for(int& num: nums) prefixes.insert(num>>i);
            
            for(auto prefix: prefixes) {
                if(prefixes.count(cur_xor^prefix)) {max_xor=cur_xor; break;}
            }
        }
        
        return max_xor;
    }
    int findMaximumXOR1(vector<int>& nums) {
        int max_val = 0;
        for(uint32_t i = 0; i < nums.size()-1; i++) {
            for(uint32_t j = i+1; j < nums.size(); j++) {    
                int xor_val = nums[i] ^ nums[j];
                if(xor_val > max_val) {
                max_val = xor_val;
                }
            }
        }        
        return(max_val);
    }
};