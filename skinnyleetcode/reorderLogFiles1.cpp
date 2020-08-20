/*
 * https://leetcode.com/problems/reorder-data-in-log-files/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool is_digit(std::string& s) {
        int len = s.length();
        int i = 0;
        while(i<len and (s[i]==' ' or (s[i]>='0' and s[i]<='9'))) { i++; }
        return i==len;
    }
    std::pair<std::string, std::string> parse(std::string& s) {
        int len = s.length();
        int i = 0;
        while(i<len and s[i] != ' ') { i++; }
        std::string key = s.substr(0,i);
        while(i<len and s[i]==' ') { i++; }
        std::string value = s.substr(i);
        return {key, value};
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<std::pair<std::string, std::string>> letter_logs;
        std::vector<std::pair<std::string, std::string>> digit_logs;
        for(std::string& log: logs) {
            std::string key;
            std::string value;
            std::tie(key, value) = parse(log);
            //printf("%s] [%s\n", key.c_str(), value.c_str());
            if(is_digit(value)) { digit_logs.push_back({key, value}); }
            else { letter_logs.push_back({key, value}); }
        }
        
        std::sort(letter_logs.begin(), letter_logs.end(), [](std::pair<std::string, std::string>& a, std::pair<std::string, std::string>& b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });
            
        std::vector<std::string> ans;
        for(std::pair<std::string, std::string> log: letter_logs) { ans.push_back(log.first + " " + log.second); }
        for(std::pair<std::string, std::string> log: digit_logs) { ans.push_back(log.first + " " + log.second); }
        return ans;
    }

};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
class Solution0 {
public:
    std::pair<std::string, std::string> parse(std::string word) {
        int len = word.size();
        int i = 0;
        while(word[i] != ' ') i++;
        std::string key = word.substr(0, i);
        std::string value = word.substr(i+1);
        return(std::make_pair(key, value));
        
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int size = logs.size();
        std::vector<std::pair<std::string, std::string>> letter_logs;
        std::vector<std::pair<std::string, std::string>> digit_logs;
        for(int i = 0; i < size; i++) {
            std::string word = logs[i];
            std::string key, value;
            std::tie(key, value) = parse(word);
            if(not value.empty() and (value.front() >= '0' and value.front() <= '9')) digit_logs.push_back(std::make_pair(key, value));
            else letter_logs.push_back(std::make_pair(key, value));
            //printf("k=%s v=%s\n", key.c_str(), value.c_str());
        }
        
        //for(auto d: digit_logs) printf("%d %s %s\n", d.first, d.second.first.c_str(), d.second.second.c_str());
        //for(auto l: letter_logs) printf("%s %s\n", l.first.c_str(), l.second.c_str());
        std::sort(letter_logs.begin(), letter_logs.end(), [](std::pair<std::string, std::string> a, std::pair<std::string, std::string> b) {return a.second == b.second ? a.first < b.first : a.second < b.second;});
        //for(auto l: letter_logs) printf("%s %s\n", l.first.c_str(), l.second.c_str());
        
        std::vector<std::string> ans;
        for(std::pair<std::string, std::string>& l: letter_logs) {
            std::string key = l.first;
            std::string value = l.second;
            ans.push_back(key + ' ' + value);
        }
        
        for(std::pair<std::string, std::string>& d: digit_logs) {
            std::string key = d.first;
            std::string value = d.second;
            ans.push_back(key + ' ' + value);
        }
            
        return ans;
            
    }
};