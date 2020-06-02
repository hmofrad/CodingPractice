/*
 *  https://leetcode.com/problems/koko-eating-bananas/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool valid(std::vector<int>& piles, int H, int K) {
        int time = 0;
        for(int i = 0; i < piles.size(); i++) {
            //printf("%d %d <%d>\n",  (piles[i] - 1) / K + 1, ((piles[i]+K-1)/K), 5+2-1/2);
            time += (piles[i]+K-1)/K;
            //    time += (piles[i] - 1) / K + 1;
        }
        //printf(">>%d %d %d\n", time, H, K);
        return time<=H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());//pow(10,9);
        while(low<=high) {
            
            int mid = low + (high-low)/2;
            //printf("low=%d mid=%d high=%d\n", low, high, mid);
            if(valid(piles, H, mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};