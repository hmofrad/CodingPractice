/*
 *	https://leetcode.com/problems/rank-teams-by-votes/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        std::string ans=votes[0];
        int n = votes[0].length();
        std::vector<std::vector<int>> ranks(26, std::vector<int>(n));
        for(std::string& vote: votes) {
            for(int i = 0; i < vote.length(); i++) {
                char c = vote[i]-'A';
                ranks[c][i]++;
            }
        }
        
        std::sort(ans.begin(), ans.end(), [&](char a, char b){return ranks[a-'A'] == ranks[b-'A'] ? a < b : ranks[a-'A']>ranks[b-'A'];});
        
        return ans;
    }
    
    string rankTeams2(vector<string>& votes) {
        std::vector<std::vector<int>> count(26, std::vector<int>(27));
        for(char& c: votes[0]) count[c-'A'][26]=c;

        for(std::string& vote: votes) {
            for(int i = 0; i < vote.length(); i++) { char c=vote[i]; --count[c-'A'][i]; } 
        }
        std::sort(count.begin(), count.end());
        std::string ans;
        for(int i = 0; i < votes[0].length(); i++) { ans += count[i][26];}
        
        for(auto c: count) {
            for(auto cc: c) {
                printf("%d", cc);
            }
            printf("\n");
        }
        
        
        return ans;
    }
    
    
    /*
    char tie_breaker(std::unordered_map<int, std::vector<char>>& map, 
                     std::unordered_map<char, std::unordered_map<int, int>>& feed, int n, int index) {
        
        for(auto m: map) {
            printf("%d: ", m.first);
            for(char c: m.second) printf("%c ", c);
            printf("\n");
        }
        printf("\n");
        
        int highest = 0;
        for(auto m: map) {
            int key = m.first;
            std::vector<char>& values = m.second;
            highest = max(highest, key);
        }
        
        char c = '\0';
        if(map[highest].size()>1) {
            std::vector<char>& values = map[highest];
            while(index<n) {
                std::vector<int> pos(values.size());
                int i = 0;
                for(char v: values) {
                    p = feed[v][index+1];
                    pos[i] = p;
                }
                
                index++;
            } 
            for()
            for(int )
            feed[]
            printf("AA\n");
            exit(0);
        }
        else { c = map[highest][0];}
        return c;
    }
    */
    string rankTeams1(vector<string>& votes) {
        votes = {"WXYZ","XYZW"};
        int n = votes.size();
        std::unordered_map<char, std::unordered_map<int, int>> feed;
        for(std::string vote: votes) {
            for(int i = 0; i < vote.length(); i++) {
                char c = vote[i];
                feed[c][i]++;
                //if(not feed.count(c) or not feed[c].count(i)) {feed[c]={i, 1};}
                //else {feed[c][i]++;}
            }
        }
        
        for(auto f: feed) {
            printf("%c: ", f.first);
            for(auto v: f.second) printf("[%d %d]", v.first, v.second);
            printf("\n");
        }
        
        std::string ans;
        int len = votes[0].length();
        for(int i = 0; i < len; i++) {
            std::unordered_map<char, int> temp;
            for(int j = 0; j < n; j++) temp[votes[j][i]]++;
            std::unordered_map<int, std::vector<char>> map;
            for(auto t: temp) map[t.second].push_back(t.first);
            //char c = tie_breaker(map, feed, n, i);
            //ans.push_back(c);
        }
        
        return ans;
    }
};