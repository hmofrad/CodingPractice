/*
 *  https://leetcode.com/problems/shortest-word-distance/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int size = words.size();
        int min_dist = size;
        int i1 = -1;
        int i2 = -1;
        for(int i = 0; i < size; i++) {
            std::string& word = words[i];
            i1 = (word == word1) ? i : i1;
            i2 = (word == word2) ? i : i2;
            
            if(i1 != -1 and i2 != -1) min_dist = min(min_dist, abs(i1-i2));
        }
        return min_dist;
    }
    int shortestDistance1(vector<string>& words, string word1, string word2) {
        std::unordered_map<std::string, std::vector<int>> map;
        int size = words.size();
        for(int i = 0; i < size; i++) {
            map[words[i]].push_back(i);
        }
        std::vector<int> p1 = map[word1];
        std::vector<int> p2 = map[word2];
        int min_dist = INT_MAX;
        int i1 = 0;
        int s1 = p1.size();
        int i2 = 0;
        int s2 = p2.size();
        while(i1 < s1 and i2 < s2) {
            int d = abs(p1[i1]-p2[i2]);
            min_dist = (d < min_dist) ? d : min_dist;
            if(p1[i1]<p2[i2]) i1++;
            else if(p1[i1]>p2[i2]) i2++;
            else break;
        }
        return min_dist;
    }
};