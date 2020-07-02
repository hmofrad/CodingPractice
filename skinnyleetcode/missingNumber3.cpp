/*
 * https://leetcode.com/problems/missing-number/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            nums[i]++;
        }
        for(int i = 0; i < size; i++) {
            int j = abs(nums[i])-1;
            if(j<size) { nums[j]=-nums[j]; }
        }
        for(int i = 0; i < size; i++) {
            if(nums[i]>0) return i;
        }
        return size;
    }
        
        
    int missingNumber5(vector<int>& nums) {
        int missed = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            missed ^= i^nums[i];
        }
        return missed;
    }
    int missingNumber4(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i]+1!=nums[i+1]) return nums[i]+1;
        }
        return nums[0]==0 ? nums.size() : 0;
    }
    int missingNumber3(vector<int>& nums) {
        std::vector<int> nums1(nums.size()+1);
        for(int i = 0; i < nums.size(); i++) nums1[nums[i]]=1;
        for(int i = 0; i < nums1.size(); i++) if(nums1[i]==0) return i;
        return -1;
        //for(int i = 0; i < nums.end()-1; i++) {if(nums[i]+1!=nums[i+1]) return nums[i]+1;}
        //return 0;
    }
    int missingNumber2(vector<int>& nums) {
        int s = std::accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(); int ss = (n*(n+1))/2;
        return ss-s;
    }
    
    int missingNumber1(vector<int>& nums) {
        int min = 2147483647;
    int max = 0;
    int sum = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] < min) {
            min = nums[i];
        }
        if(nums[i] > max) {
            max = nums[i];
        }
        sum += nums[i];
    }
    /*
    if(min != 0)
        return(0);
    else if(max != n) {
        return(n);
    }
    else {
        */
        int accu = (n * (n + 1)) / 2;
        return(accu - sum);
    //}
    
    }
};