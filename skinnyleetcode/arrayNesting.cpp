/*
 *	https://leetcode.com/problems/array-nesting/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int arrayNesting2(vector<int>& nums) {
        int len = 0;
        int size = nums.size();
        //std::vector<bool> visited(size);
        for(int i = 0; i < size; i++) {
            //if(not visited[i]) {
            if(nums[i]!=-1) {
                int j = i;
                int c = 0;
                do {
                    int t = j;
                    j=nums[j]; 
                    c++;
                    nums[t]=-1;
                }while(j!=i);
                len = std::max(c, len);
              //  visited[i]=true;
            }
        }
        return len;
    }
   int arrayNesting(vector<int>& nums) {     
        int len = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int j = i;
            int c = 0;
            do {
                j=nums[j]; c++;
            }while(j!=i);
            len = std::max(c, len);
        }
        
        return len;
    }
        int arrayNesting1(vector<int>& nums) {
        
        int len = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int j = i;
            int l = 0;
            std::unordered_set<int> s;
            while(s.size() != size) {
                if(s.insert(nums[j]).second) j=nums[j];
                else {l=s.size(); break;}
            }
            len = std::max(l, len);
        }
        
        return len;
    }
};