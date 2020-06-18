/*
 * https://leetcode.com/problems/single-number-iii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for(int n: nums) bitmask ^= n;
        int diff = bitmask & (-bitmask);
        int x = 0;
        for(int n: nums) { if(n&diff) {x^=n;}}
        return std::vector<int>({x, bitmask^x});
    }
    vector<int> singleNumber3(vector<int>& nums) {
        
        std::unordered_set<int> set;
        for(int n: nums) {
            if(not set.insert(n).second) set.erase(n);
        }
        std::vector<int> ans(set.begin(), set.end());
        return ans;
    }
    vector<int> singleNumber2(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for(int num: nums) {
            auto it = map.find(num);
            if(it == map.end()) {
                map[num]++;
            }
            else {
                map.erase(it);
            }
            
        }
        std::vector<int> ret;
        for(auto m: map) ret.push_back(m.first);
        return ret;
    }
    
    vector<int> singleNumber1(vector<int>& nums) {
        std::vector<int> nums1;
    std::map<int, int> tmp;
    
    //std::map<int,int>::iterator it;
    for(auto& n: nums) {
        //it = tmp.find(n);
        //if (it != tmp.end())
        //if(
        tmp[n]++;
    }
    for(auto& t: tmp) {
    //tmp.find('a')->second
//        printf("%d %d\n", t.first, t.second);
        if(t.second == 1) {
            nums1.push_back(t.first);
        }
    }

    return(nums1);    
    }
};