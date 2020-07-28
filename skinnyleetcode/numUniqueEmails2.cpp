/*
 * https://leetcode.com/problems/unique-email-addresses/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    std::string parse(std::string& s) {
        if(s.empty()) { return std::string(); }
        std::string t;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(c=='+') {
                while(i<len and s[i]!='@') {i++;}
                t += s.substr(i); break;
            }
            else if(c=='@') { t += s.substr(i); break; }
            else if(c != '.') { t.push_back(c); }
        }
        return t;
    }
    int numUniqueEmails(vector<string>& emails) {
        if(emails.empty()) { return 0; }
        std::unordered_set<std::string> set;
        for(std::string& email: emails) {
            set.insert(parse(email));
            //printf("%s %s\n", email.c_str(), parse(email).c_str());
            
        }
        //std::string s;
        return set.size();
    }
};

class Solution0 {
public:
    std::string filter(std::string email) {
        std::string raw;
        int m = email.length();
        int i = 0;
        int j = 0;
        bool end = false;
        for(i = 0; i < m; i++) {
            if(email[i] == '@') {i++; break;}
            else if(email[i] == '.') {
                int len = i-j;
                raw += email.substr(j, len);
                j = i+1;
            }
            else if(email[i] == '+') {
                int len = i-j;
                raw += email.substr(j, len);
                i++;
                while(email[i] != '@') i++;
                //while(email[i] != '+' and email[i] != '@') i++;
                j = i+1;
                //printf("%d %d %c\n", i, j, email[i]);
                if(email[i] == '@') {end = true; break;}
            }            
        }
        
        //printf("%d %d\n", i, j);
        if(not end) {
            int len = i-j;
            raw += email.substr(j, len);
        }
        
        raw += email.substr(i, m-i);
        return(raw);
    }
    
    std::string filter1(std::string email) {
        int m = email.length();
        std::vector<bool> status(m);
        int i = 0;
        while(i<m) {
            if(email[i] == '@') {
                while(i<m) {
                    status[i++] = 1;
                }
                break;
            }
            else if(email[i] == '.') {
                status[i] = 0;
                i++;
            }
            else if(email[i] == '+') {
                status[i++] = 0;
                while(email[i] != '@') {
                //while(email[i] != '+' and email[i] != '@') {
                        status[i++] = 0;
                    }
 
                //if(email[i] == '+') {
                //    status[i++] = 0;
               // }
                
                //j = i+1;
                //printf("%d %d %c\n", i, j, email[i]);
                //if(email[i] == '@') {i++; end = true; break;}
            }
            else {
                status[i] = 1;
                i++;
            }
        }
        std::string raw;
        for(i = 0; i < m; i++) {
            if(status[i])
                raw += email[i];
        }
        
        return(raw);
    }
    
    
    int numUniqueEmails1(vector<string>& emails) {
        std::unordered_map<std::string, int> my_map;
        for(auto email: emails) {
            my_map[filter(email)]++;
        }
        
        //for(auto m: my_map) {
        //    printf("%s %d\n", m.first.c_str(), m.second);
        //}
        
        return(my_map.size());
    }
    
    
    
    std::string parse(std::string email) {
        std::string parsed_email;
        int j = 0;
        int len = email.length();
        for(int i = 0; i < len; i++) {
            char c = email[i];
            if(c=='+') {
                int len = i-j;
                std::string t0 = email.substr(j,len);
                while(email[i]!='@')i++;
                std::string t1 = email.substr(i);
                parsed_email += t0 + t1;
                break;
            }
            else if(c == '.') {
                int len = i-j;
                std::string t = email.substr(j,len);
                parsed_email += t;
                j=i+1;
            }
            else if(c == '@') {
                std::string t = email.substr(j);
                parsed_email += t;
                break;
            }
        }
        
        return parsed_email;
    }
    
    
    int numUniqueEmails(vector<string>& emails) {
        //emails = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};
        std::set<std::string> set;
        for(std::string email: emails) {
            std::string e = parse(email);
           // printf("%s %s\n", email.c_str(), e.c_str());
            set.insert(e);
        }
        return set.size();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};