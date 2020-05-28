/*
 *	https://leetcode.com/problems/shortest-word-distance-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class WordDistance {
public:
    std::unordered_map<std::string, std::vector<int>> map;
    WordDistance(vector<string>& words) {
        int size = words.size();
        for(int i = 0; i < size; i++) map[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        std::vector<int>& w1 = map[word1];
        std::vector<int>& w2 = map[word2];
        int i1 = 0;
        int i2 = 0;
        int min_d = INT_MAX;
        while(i1 < w1.size() and i2 < w2.size()) {
            min_d = min(min_d, abs(w1[i1]-w2[i2]));
            if(w1[i1] <= w2[i2]) i1++;
            else i2++;
        }
        return min_d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */

class WordDistance1 {
public:
    std::unordered_map<std::string,int> dists;
    WordDistance1(vector<string>& words) {
        std::unordered_map<std::string, std::vector<int>> map;
        int size = words.size();
        for(int i = 0; i < size; i++) map[words[i]].push_back(i);
        
        for(int i = 0; i < size; i++) {
            std::string& src = words[i];
            for(int j = 0; j < size; j++) {
                std::string& dst = words[j];
                if(i!=j and not dists.count(src+dst) and not dists.count(dst+src)) {
                    std::vector<int>& di = map[src];
                    std::vector<int>& dj = map[dst];
                    int ii = 0;
                    int jj = 0;
                    int min_d = INT_MAX;
                    while(ii < di.size() and jj < dj.size()) {
                        min_d = min(min_d, abs(di[ii]-dj[jj]));
                        if(di[ii] <= dj[jj]) ii++;
                        else jj++;
                    }
                    dists[src+dst] = min_d;
                }
            }
        }
        
        //for(auto d: dists) printf("%s %d\n", d.first.c_str(), d.second); printf("\n");
        
    }
    
    int shortest(string word1, string word2) {
        int d1 = dists[word1+word2];
        int d2 = dists[word2+word1];
        return d1 ? d1 : d2; 
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */