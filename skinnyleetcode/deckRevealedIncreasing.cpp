/*
 *  https://leetcode.com/problems/reveal-cards-in-increasing-order/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int m = deck.size();
        std::deque<int> indices;
        for(int i = 0; i < m; i++) {
            indices.push_back(i);
        }
        
        std::vector<int> out(m);
        std::sort(deck.begin(), deck.end());
        for(auto card: deck) {
            out[indices.front()] = card;
            indices.pop_front();
            if(not indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        return(out);
    }
};