/*
 *  https://leetcode.com/problems/odd-even-jump/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int size = A.size();
        std::vector<int> lower(size); lower[size-1]=1;
        std::vector<int> higher(size); higher[size-1]=1;
        std::map<int, int> map; map[A[size-1]]=size-1;
        int count = 1;
        for(int i = size-2; i >= 0; i--) {
            auto high = map.lower_bound(A[i]);
            auto low = map.upper_bound(A[i]);
            if(high != map.end()) higher[i]=lower[high->second];
            if(low != map.begin()) lower[i]=higher[(--low)->second];
            if(higher[i]) count++;
            map[A[i]]=i;    
        }
        return count;
    }
};