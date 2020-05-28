/*
 *	https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for(int num: nums) map[num]++;
        
        for(int num: nums) {
            int start = num;
            while(map[start-1]) start--;
            if(map[start]) {
                for(int i = start; i < start+k; i++) {
                    map[i]--;
                    if(map[i]<0) return false;
                }
            }
        }
        return true;
    }
    
    
    bool isPossibleDivide2(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for(int num: nums) map[num]++;
        for(int num: nums) {
            int start = num;
            while(map[start-1]) start--;
            for(; start<=num;start++) {
                int times = map[start];
                if(times) {
                    for(int victim = start; victim < start+k; victim++) {
                        if(map[victim]<times) return false;
                        map[victim]-=times;
                    }
                }
            }
        }
        
        return true;
    }
    bool isPossibleDivide1(vector<int>& nums, int k) {
        int m = nums.size();
        if(m%k) return false;
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> s;
        int n = m/k;
        int o = 1;
        std::vector<std::set<int>> ss;
        for(int i = 0; i < m; i++) {
            printf("%d %d\n", o, ss.size());
            s[nums[i]]++;
            if(s[nums[i]]<o) {
                o++;
                if(o>n) return false;
            }
            if(ss.size() < o) {
                ss.push_back({nums[i]});
            }
            else {
                bool invalid = true;
                for(std::set<int>& s0 : ss) {
                    auto it = s0.end();
                    //printf(">>%d %d %d \n", *it, nums[i], *it+1==nums[i]);
                    if(s0.size()<k and *it+1==nums[i]) {s0.insert(nums[i]); invalid = false; break;}
                }
                //if(invalid) break; //return false;
            }
          //  printf("o=%d ", o);
        //    printf("%d %d:", i,nums[i]);
        
        }
        
            for(auto& s0: ss) {
                printf("sz=%d: ", s0.size());
                for(auto i: s0) printf("%d ", i); 
                printf("\n");
            }
        
        
        return true;
    }
};