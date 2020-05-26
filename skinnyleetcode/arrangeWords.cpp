/*
 *	https://leetcode.com/problems/rearrange-words-in-a-sentence/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::pair<std::string, int>> str2vec(std::string text) {
        std::vector<std::pair<std::string, int>> vec;
        int len = text.length();
        int j = 0;
        int k = 0;
        for(int i = 0; i < len; i++) {
            char c = text[i];
            if(c == ' ') {
                int l = i-j;
                std::string t = text.substr(j, l);
                vec.push_back(std::make_pair(t, k));
                k++;
                j=i+1;
            }
        }
        std::string t = text.substr(j);
        vec.push_back(std::make_pair(t, k));
        return vec;
    }
    
    std::string vec2str(std::vector<std::pair<std::string, int>>& vec) {
        std::string text;
        int size = vec.size();
        for(int i = 0; i < size; i++) {
            std::string& t = vec[i].first; 
            //printf("%s\n", t.c_str());
            text += t + " ";
        }
        //printf("%s\n", text.c_str());
        text.pop_back();
        //text[0]=toupper(text[0]);
        text[0] = text[0]-'a'+'A';
        return text;
    }
    
    string arrangeWords(string text) {
        if(text.empty()) return std::string();
    
            
        
        text[0] = text[0] -'A' + 'a';
        //text[0]=tolower(text[0]);
        std::vector<std::pair<std::string, int>> vec = str2vec(text);
        
        std::sort(vec.begin(), vec.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
            return a.first.length()==b.first.length() ? a.second < b.second : a.first.length()<b.first.length();});

        return vec2str(vec);
    }
};