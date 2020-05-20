/*
 *	https://leetcode.com/problems/degree-of-an-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        std::unordered_map<int, std::pair<int,int>> indices;
        
        int size = nums.size();
        int max_count = 0;
        for(int i = 0; i < size; i++) {
            int j = nums[i];
            if(counts.count(j) == 0) {counts[j]++; indices[j]={i,i};}
            else {counts[j]++; indices[j].second=i;}
            
            max_count = max(max_count, counts[j]);
        }
        
        int min_len = INT_MAX;
        for(auto c: counts) {
            int key = c.first;
            int value = c.second;
            if(value == max_count) {
                int len = indices[key].second- indices[key].first+1;
                min_len = min(min_len, len);
            }
        }
        return min_len;
    }
    int findShortestSubArray2(std::vector<int>& nums) {
        int size = nums.size();
        int degree = 0;
        std::unordered_map<int, int> map;
        for(int i = 0; i < size; i++) {
            int v = nums[i];
            map[v]++;
            if(map[v]>degree){degree = map[v];}
        }
        std::vector<int> values;
        for(auto m: map) {
            if(m.second==degree)values.push_back(m.first);
        }
        
        int min_len = INT_MAX;
        for(int i = 0; i < values.size(); i++) {
            //printf("[%d]=%d, %d\n",i, values[i], min_len);
            int left = 0;
            int right = size-1;
            int len = -1;
            while(left<right) {
                if((nums[left]!=values[i]) and (nums[right]!=values[i])) {left++; right--;}
                else if(nums[left]!=values[i]) left++;
                else if((nums[right]!=values[i])) right--;
                else {len = right-left+1; break;}
            }
            if(len==-1) min_len=1;
            else if(len<min_len) min_len=len;
        }
        
        return min_len;
    }
    
    
    
    
     int degree(std::vector<int> nums, uint32_t l, uint32_t r) {
        std::unordered_map<int, int> map;
        for(uint32_t i = l; i <= r; i++) {
            map[nums[i]]++;
        }
        int d = 0;
        for(auto m: map) {
            if(m.second > d) {
                d = m.second;
            }
        }
        return(d);
    }

    int findShortestSubArray1(std::vector<int>& nums) {
        std::unordered_map<int, uint32_t> left;
        std::unordered_map<int, uint32_t> count;
        uint32_t max_c = 0;
        uint32_t max_i = 0;
        uint32_t max_l = 0;
        for(uint32_t i = 0; i < nums.size(); i++) {
            int j = nums[i];

            count[j]++;  
            if(count[j] == 1) {
                left[j] = i;  
            }

            if(count[j] > max_c) {
                max_c = count[j];
                max_l = i - left[j] + 1;
            }
            else if((count[j] == max_c) and (i - left[j] + 1 < max_l)){
                max_l = i - left[j] + 1;
            }
        }
        return(max_l);
    }
};