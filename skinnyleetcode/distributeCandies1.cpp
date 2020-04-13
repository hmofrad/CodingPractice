/*
 *  https://leetcode.com/problems/distribute-candies-to-people/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> dist(num_people);
        int n = 0;
        while(candies>0) {
            for(int i = 0; i < num_people; i++) {
                int c = n+i+1;
                //printf("%d %d %d %d\n", i,n,  c, candies);
                candies -= c;
                if(candies>=0) dist[i] += c;
                else {dist[i] += (candies+c); break;}
                //candies -= c;
            }
            n+=num_people;
        }
        return dist;
    }
};