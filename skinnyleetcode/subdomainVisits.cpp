/*
 *  https://leetcode.com/problems/subdomain-visit-count/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::pair<std::string, int>> tokenize(std::string cpdomain) {
        int m = cpdomain.length();
        int len = 0;
        for(int i = 0; i < m; i++) {
            char& c = cpdomain[i];
            if(c != ' ') {
                len++;
            }
            else {
                break;
            }
        }
        int count = stoi(cpdomain.substr(0, len));
        //printf("%d %d\n", c, len);
        std::vector<std::pair<std::string, int>> domains;
        int b = len;
        for(int i = m-1; i >= b; i--){
            char& c = cpdomain[i];
            if(c == '.' or c == ' ') {
                len = m-i;
                std::string d = cpdomain.substr(i+1, len);
                //std::pair<std::string, int> p = {d, count}
                //auto p = make_pair(d, count);
                domains.push_back({d, count});
            }
        }
    
       // printf("%s: ", cpdomain.c_str());
        ///for(auto domain: domains) {
           // printf("[%s %d]", domain.first.c_str(), domain.second);
       // }
        //printf("\n");
        
        return(domains);
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<std::string, int> my_map;
        for(std::string& cpdomain: cpdomains) {
            std::vector<std::pair<std::string, int>> domains = tokenize(cpdomain);
            for(auto domain: domains) {
                my_map[domain.first] += domain.second;
            }
        }
        std::vector<std::string> out;
        for(auto m: my_map) {
            out.push_back(to_string(m.second) + " " + m.first);
        }
        
        return(out);
    }
};