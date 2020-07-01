/*
 * https://leetcode.com/problems/top-k-frequent-words/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    struct comp {
        bool operator()(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
       // words={"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
        //k=4;
        if(k==0) return std::vector<std::string>();
        std::unordered_map<std::string, int> counts;
        for(std::string word: words) { counts[word]++; }
        
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comp> pq;
        for(auto& c: counts) {
            std::string str = c.first;
            int count = c.second;
            std::pair<std::string, int> pair = {str, count};
            pq.push(pair);
            if(pq.size()>k) pq.pop();
            //printf("%s %d\n", pq.top().first.c_str(), pq.top().second);
        }
        
        std::vector<std::string> ans;
        while(not pq.empty()) {
            //printf("%s %d\n", pq.top().first.c_str(), pq.top().second);
            std::pair<std::string, int> pair = pq.top(); pq.pop();
            ans.push_back(pair.first);
            
        }
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
    vector<string> topKFrequent0(vector<string>& words, int k) {
        if(k==0) return std::vector<std::string>();
        //words={"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
        //k=4;
        std::unordered_map<std::string, int> counts;
        for(std::string word: words) {
            counts[word]++;
        }
        std::map<int, std::vector<std::string>> words2count;
        for(auto c: counts) {
            std::string key = c.first;
            int value = c.second;
            words2count[value].push_back(key);
        }
        
        std::vector<std::string> ans;
        for(auto it=words2count.rbegin(); it != words2count.rend(); it++) {
            //printf("xx %d\n", it->second.size());
            std::vector<std::string>& temp = it->second;
            std::sort(temp.begin(), temp.end());
            for(std::string& t: temp) {
                ans.push_back(t);
                k--;
                if(k==0) break;
            }
            if(k==0){ break; }
        }
        return ans;
    }
};