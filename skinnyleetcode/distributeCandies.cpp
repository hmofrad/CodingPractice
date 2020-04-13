/*
 *  https://leetcode.com/problems/distribute-candies/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::set<int> candy_types;
        int size2 = candies.size()/2;
        for(int candy: candies) {
            candy_types.insert(candy);
        }
        //printf("%d %d\n", candy_types.size(), size);
        //return(candy_types.size() > size2 ? size2 : candy_types.size());
        return(std::min((int)candy_types.size(), size2));
    }
};