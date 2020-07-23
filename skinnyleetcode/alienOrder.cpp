/*
 * https://leetcode.com/problems/alien-dictionary/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool is_prefix(std::string& word1, std::string& word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 > len2) {
            for(int i = 0; i < len2; i++) {
                if(word1[i]!=word2[i]) { return false; }
            }
            return true;
        }
        return false;
    }
    string alienOrder(vector<string>& words) {
        std::unordered_map<char, std::vector<char>> adj;
        std::unordered_map<char, int> counts;
        
        for(std::string& word: words) {
            for(char& c: word) {
                counts[c]=0;
            }
        }
        
        
        int size = words.size();
        for(int i = 0; i < size-1; i++) {
            std::string word1 = words[i];
            int len1 = word1.length();
            std::string word2 = words[i+1];
            int len2 = word2.length();
            if(is_prefix(word1, word2)) { return std::string(); }
            for(int j = 0; j < min(len1, len2); j++) {
                char u = word1[j];
                char v = word2[j];
                if(u != v) {
                    adj[u].push_back(v);
                    counts[v]++;
                    break;
                }
            }
        }
        
        /*
        for(auto m: adj) {
            printf("%c: ", m.first);
            for(auto v: m.second) printf("%c ", v);
            printf("\n");
        }
        
        for(auto c: counts) {
            printf("[%c %d]\n", c.first, c.second);
        }
        */
        
        std::queue<char> queue;
        for(auto count: counts) {
            char c = count.first;
            int  f = count.second;
            if(f==0) { queue.push(c); }
        }
        

        std::string ans;
        while(not queue.empty()) {
            char c = queue.front(); queue.pop();
            ans.push_back(c);
            std::vector<char> next = adj[c];
            for(char n: next) {
                counts[n]--;
                if(counts[n]==0) { queue.push(n); }
            }
        }

        return ans.size()>=counts.size() ? ans : std::string();
    }
};