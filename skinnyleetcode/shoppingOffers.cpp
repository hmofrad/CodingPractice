/*
 *  https://leetcode.com/problems/shopping-offers/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dfs(vector<int> needs, vector<int>& prices, vector<vector<int>>& specials) {
        int cost = 0;
        int nitems = needs.size();
        for(int i = 0; i < nitems; i++) cost += needs[i]* prices[i];
        int j = 0;
        for(std::vector<int>& special: specials) {
            std::vector<int> needs0(needs);
            for(j = 0; j < nitems; j++) {
                int diff = needs0[j]-special[j];
                if(diff<0) break;
                needs0[j]=diff;
            }
            if(j==nitems) cost = min(cost, special[j]+dfs(needs0, prices, specials));
        }
        return cost;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(needs, price, special);
    }
};