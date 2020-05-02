/*
 *  https://leetcode.com/problems/design-a-leaderboard/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Leaderboard {
public:
    std::map<int, std::unordered_set<int>> scores2ids;
    std::unordered_map<int, int> ids2scores;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(ids2scores.count(playerId)) {
            int currentScore = ids2scores[playerId];
            auto& ids = scores2ids[currentScore];
            ids.erase(playerId);
            
            int newScore = currentScore+score;
            scores2ids[newScore].insert(playerId);
            ids2scores[playerId]=newScore;
        }
        else {
            ids2scores[playerId]=score;
            scores2ids[score].insert(playerId);
        }
    }
    
    int top(int K) {
        int sum = 0;
        int k = 0;
        
        
        for(auto it = scores2ids.rbegin(); it != scores2ids.rend() and k < K; it++){
            
            sum += (it->first * it->second.size());
            k += it->second.size();
            if(k>K) sum-= (it->first*(k-K));
            //printf("k=%d score=%d size=%d sum=%d\n", k, it->first, it->second.size(), sum);
        }
        //printf("\n");
        return sum;
    }
    
    void reset(int playerId) {
        int oldScore = ids2scores[playerId];
        ids2scores.erase(playerId);
        scores2ids[oldScore].erase(playerId);
        if(scores2ids[oldScore].size()==0) scores2ids.erase(oldScore);
        /*
        printf("Del-> id=%d score=%d\n", playerId, oldScore);
        for(auto i: ids2scores) {
            printf("id=%d secore=%d\n", i.first, i.second);
        }
        
        for(auto s: scores2ids) {
            printf("%d: ", s.first);
            for(auto ss: s.second) printf("%d ", ss);
            printf("\n");
        }
        
        */
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */