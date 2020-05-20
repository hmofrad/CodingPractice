/*
 *	https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly_, int maxPrice_, int maxDistance_) {
        
        std::vector<std::vector<int>> temp;
        int size = restaurants.size();
        for(int i = 0; i < size; i++) {
            std::vector<int> resturant = restaurants[i];
            int& id = resturant[0];
            int& rating = resturant[1];
            int& veganFriendly = resturant[2];
            int& price = resturant[3];
            int& distance = resturant[4];
            
            if(((veganFriendly == veganFriendly_) or (veganFriendly_ == 0 and veganFriendly == 1))  and (price <= maxPrice_) and (distance <= maxDistance_)) temp.push_back(resturant);
            
        }
        
        //for(std::vector<int> t: temp) printf("%d ", t[0]); printf("\n");
        
        std::sort(temp.begin(), temp.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[1] == b[1] ? a[0]>b[0] : a[1]>b[1];});
        
        //for(std::vector<int> t: temp) printf("%d ", t[0]); printf("\n");
        
        std::vector<int> ids;
        for(std::vector<int>& t: temp) ids.push_back(t[0]);
        
        return ids;
    }
};