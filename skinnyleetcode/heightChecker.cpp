/*
 *  https://leetcode.com/problems/height-checker/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    std::pair<int, int> my_min_max(vector<int> arr, int left, int right){
        int m = arr.size();
        if(not m ) return make_pair(-1,-1);
        
        int max_value = arr[left];
        int max_index = left;
        int min_value = arr[left];
        int min_index = left;
        for(int i = left; i <= right; i++) {
            if(arr[i] > max_value) {
                max_value = arr[i];
                max_index = i;
            }
            if(arr[i] < min_value) {
                min_value = arr[i];
                min_index = i;
            }
        }
        return make_pair(min_index, max_index);
    }
    int heightChecker1(vector<int>& heights) {
        int m = heights.size();
        int l = 0;
        int r = m - 1;
        int c = 0;
        int i = 0;
                while(l < r) {
            std::pair<int, int> mimx = my_min_max(heights, l, r);
            printf("%d %d %d, H[%d]=%d H[%d]=%d\n", l, r, c, mimx.first, heights[mimx.first], mimx.second, heights[mimx.second]);
            //if(mimx.first != mimx.second){
                if(mimx.first != l) {
                    std::swap(heights[l], heights[mimx.first]);
                    c++;

                }
                    l++;            
                //if((mimx.first != mimx.second) and (mimx.second != l-1) and (mimx.second != r)) {
                    //std::swap(heights[r], heights[mimx.second]);
                   // r--;
                  //  c++;
                //}
            //l++;
            //r--;
            //}
            //if(i == 5) break;
            //i++;
            for(auto h: heights){printf("%d ", h);} printf("\n"); 
        }
       for(auto h: heights){printf("%d ", h);} printf("\n"); 
       
        return(c);
    }
    
    int heightChecker2(vector<int>& heights) {
        int m = heights.size();
        std::vector<int> temp = heights;
        std::sort(temp.begin(), temp.end());
        int c = 0;
        for(int i = 0; i < m; i++) {
            if(temp[i] != heights[i]) {
                c++;
            }
        }
        return(c);
    }
    
    int heightChecker(vector<int>& heights) {
        int m = heights.size();
        int c = 0;
        std::map<int, int> map;
        for(int i = 0; i < m; i++) {
            map[heights[i]]++;
        }
        
        for(auto pp: map) {
            printf("%d %d\n", pp.first, pp.second);
        }
        
        
        auto p = map.begin();
        int i = 0;
        while(i < m) {
            if(p->second) {
                p->second--;
                if(heights[i] != p->first) {
                    c++;
                }
                i++;
            }
            else {
                p++;
            }
            //printf("%d %d %d %d\n", heights[i], p->first, p->second, c);
        }
        return(c);
    }
    
    
};


    
