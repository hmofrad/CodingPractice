/*
 * https://leetcode.com/explore/interview/card/google/66/others-4/3097/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        std::vector<int> left2right(size,1);
        std::vector<int> right2left(size,1);
        
        for(int i=1; i<size; i++) {
            if(ratings[i]>ratings[i-1]) {left2right[i]=left2right[i-1]+1;}
        }
        
        for(int i = size-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {right2left[i] = right2left[i+1]+1;}
        }
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += max(left2right[i], right2left[i]);
        }
        
        return sum;
    }
    int candy2(vector<int>& ratings) {
        int size = ratings.size();
        std::vector<int> candies(size,1);
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < size; i++) {
                if(i<size-1 and ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]) {
                    candies[i] = candies[i+1]+1; flag = true;
                }
                if(i>0 and ratings[i]>ratings[i-1] and candies[i]<=candies[i-1]) {
                    candies[i]=candies[i-1]+1; flag = true;
                }
            }
        }
        int c = std::accumulate(candies.begin(), candies.end(), 0);
        return c;
    }
    int candy1(vector<int>& ratings) {
        int size = ratings.size();
        int prev_rating = 0;
        for(int i = 0; i < size; i++) {
            if(i==0) {
                prev_rating = ratings[i];
                ratings[i] = ratings[i] > ratings[i+1] ? 2 : 1;
            }   
            else if(i==size-1) {
                ratings[i] = prev_rating >= ratings[i-1] ? 1 : prev_rating+1;
            }
            else {
                int r = min({prev_rating, ratings[i], ratings[i+1]});
                prev_rating = ratings[i];
                ratings[i] = r>=ratings[i] ? 1 : prev_rating+1;
            }
        }
        int c = std::accumulate(ratings.begin(), ratings.end(), 0);
        return c;
    }
};