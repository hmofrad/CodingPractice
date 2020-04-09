/*
 *  https://leetcode.com/problems/uncommon-words-from-two-sentences/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    std::unordered_map<std::string, int> freq;
    void tokenize(std::string str) {
        int size = str.length();
        int i = 0;
        int j = 0;
        while(i < size) {
            char c= str[i];
            if(c == ' ') {
                int len = i-j;
                std::string temp = str.substr(j, len);
                //printf("%d %d %s\n", i, j, temp.c_str());
                freq[temp]++;
                j=i+1;
            }
            i++;
        }
        int len = i-j+1;
        
        std::string temp = str.substr(j, len);
        //printf("%d %d %s\n", i, j, temp.c_str());
        freq[temp]++;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        tokenize(A); tokenize(B);
        
        std::vector<std::string> ans;
        for(auto f: freq) {
            if(f.second==1) ans.push_back(f.first);
        }
        return(ans);
    }
};