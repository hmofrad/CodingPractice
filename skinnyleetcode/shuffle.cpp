/*
 *	https://leetcode.com/problems/shuffle-an-array/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> nums_original;
    Solution(vector<int>& nums) {
        nums_original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        /*
        int size = nums_original.size();
        std::vector<int> aux = nums_original;
        std::vector<int> arr = nums_original;
        for(int i = 0; i < size; i++) {
            int index = rand()%(size-i);
            arr[i]=aux[index];
            aux.erase(aux.begin()+index);
        }
        return arr;
        */
        
        std::vector<int> arr = nums_original;
        int size = nums_original.size();
        for(int i = 0; i < size; i++) {
            int index = rand()%(size-i);
            std::swap(arr[i], arr[i+index]);
        }
        return arr;
        /*
        std::vector<int> indices(size);
        std::iota(indices.begin(), indices.end(), 0);
        for(int i = 0; i < size; i++) {
            int index = rand()%(size-i);
            std::swap(indices[i], indices[index]);
        }
        for(int i = 0; i < size; i++) {
            nums_shuffled[i]=nums_original[indices[i]];
        }
        return(nums_shuffled);
        */
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */