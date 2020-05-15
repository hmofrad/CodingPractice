/*
 *	https://leetcode.com/problems/html-entity-parser/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::string> parse1(std::string text) {
        std::vector<std::string> tokens;
        int len = text.length();
        int j = 0;
        for(int i = 0; i < len; i++) {
            char c = text[i];
            if(c==' ') {
                int len = i-j;
                std::string temp = text.substr(j, len);
                tokens.push_back(temp);
                j=i+1;
            }
        }
        std::string temp = text.substr(j);
        tokens.push_back(temp);
        return tokens;
    }
    
    std::vector<std::string> parse(std::string text) {
        std::vector<std::string> tokens;
        int len = text.length();
        int j = 0;
        for(int i = 0; i < len; i++) {
            char c = text[i];
            if(c==';') {
                int k = j;
                while(j<=i and text[j] != '&') j++;
                int len = j-k;
                std::string temp = text.substr(k, len);
                if(not temp.empty()) tokens.push_back(temp);
                len = i-j+1;
                temp = text.substr(j, len);
                tokens.push_back(temp);
                j=i+1;
            }
        }
        std::string temp = text.substr(j);
        if(not temp.empty()) tokens.push_back(temp);
        return tokens;
    }
    
    
    string entityParser(string text) {
        std::unordered_map<std::string, std::string> codes({{"&quot;", "\""}, 
                                                     {"&apos;", "\'"}, 
                                                     {"&amp;", "&"},
                                                     {"&gt;", ">"},
                                                     {"&lt;", "<"},
                                                     {"&frasl;","/"}});
        
        std::string ans;
        std::vector<std::string> tokens = parse(text);
        for(std::string& token: tokens) {
            printf("<%s>", token.c_str());
            std::string temp;
            if(codes.count(token)) { temp = codes[token]; }
            else { temp = token; }
            ans += temp;
        }
        
        return ans;
    }
};