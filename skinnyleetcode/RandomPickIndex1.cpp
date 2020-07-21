/*
 * https://leetcode.com/problems/random-pick-index/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> vec;
    Solution(std::vector<int>& nums) {
        vec = nums;
    }
    int pick(int target) {
        int ans = -1;
        int count = 0;
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == target) {
                if(rand()%++count == 0) { ans = i; }  
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    std::unordered_map<int, std::vector<int>> map;
    Solution1(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
    }
    int pick(int target) {
        std::vector<int>& vec = map[target];
        return vec[rand()%vec.size()];
    }
};

class Solution0 {
public:
    std::unordered_map<int, std::vector<int>> map;
    Solution0(std::vector<int>& nums) {
        srand(time(NULL));
        //std::sort(nums.begin(), nums.end());
        for(uint32_t i = 0; i < nums.size(); i++) {
            int& n = nums[i];
        //    printf("%d-->%d\n", i, n);
            if(map.find(n) == map.end()) {
                map[n].push_back(i);
            }
            else {
                map[n].push_back(i);
            }
        }
        /*
        for(auto m: map) {
            printf("%d: ", m.first);
            for(auto v: m.second) {
                printf("%d ", v);
            }
            printf("\n");
        }
        */
        
    }
    
    int pick(int target) {
        return(map[target][rand_gen(map[target].size())]);
    }
    
    int rand_gen(uint32_t range) {
        return((rand() % range));
    }
    
};