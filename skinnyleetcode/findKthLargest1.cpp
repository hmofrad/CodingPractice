/*
 *	https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int partition(std::vector<int>& nums, int left, int right, int pivot_i) {
        int pivot = nums[pivot_i];
        std::swap(nums[pivot_i], nums[right]);
        int store_i = left;
        
        for(int i = left; i <= right; i++) {
            if(nums[i] < pivot) { std::swap(nums[i], nums[store_i]); store_i++; }
        }
        std::swap(nums[store_i], nums[right]);
        return store_i; 
    }
    int quickselect(std::vector<int>& nums, int left, int right, int n_k) {
        if(left==right) return nums[left];
        
        int pivot_i = left + rand()%(right-left);
        pivot_i = partition(nums, left, right, pivot_i);
        
        if(n_k==pivot_i) return nums[n_k];
        else if(n_k<pivot_i) return quickselect(nums, left, pivot_i-1, n_k);
        else return quickselect(nums, pivot_i+1, right, n_k);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        return quickselect(nums, 0, size-1, size-k);
    }
    
    int findKthLargest3(vector<int>& nums, int k) {
        //std::priority_queue<int> heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for(int& n: nums) {
            heap.push(n);
            if(heap.size()>k) heap.pop();
        }
        //int r = heap.top();
        //while(not heap.empty()) {printf("%d ", heap.top()); heap.pop();} printf("\n");
        
        return heap.top();
    }
    
    int findKthLargest2(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < size; j++) {
                if(nums[i]<nums[j]) std::swap(nums[i], nums[j]);
            }
        }
        return nums[k-1];
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) {
            int l = i;
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[l] < nums[j]) {
                    l = j;
                }
            }
            if(l != i)
                std::swap(nums[i], nums[l]);
        }
        return(nums[k-1]);
        //std::sort(nums.begin(),nums.end());
        //return(nums[nums.size()-k]);    
    }
};