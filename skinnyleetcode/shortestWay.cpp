/*
 *  https://leetcode.com/problems/shortest-way-to-form-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool valid(std::string source, std::string target) {
        std::vector<int> alphas(26);
        for(char& c: source) alphas[c-'a']++;
        for(char& c: target) if(alphas[c-'a']==0) return false;
        return true;
    }
    
    
    int shortestWay1(string source, string target) {
        int i = 0;
        int j = 0;
        int r = 0;
        while(i < target.size() and r <= i) {
            while(target[i] != source[j] and j < source.size()) j++;
            if(j==source.size()) {j=0; r++;}
            else {i++; j++;}
        }
        return r <= i ? r+1:-1;
    }
    
    int shortestWay(string source, string target) {
        int count = 0;
        while(not target.empty()) {
            int i = 0;
            int j = 0;
            char c = target[i];
            //int cut = 0;
            //char c = target[cut];
            int len = source.length();
            for(int k = 0; k < len; k++) {
                if(c==source[k]) {
                    if(++i==target.length()) break;
                    c=target[i];
                }
            }
            
            if(i==0) return -1;
            //target = target.substr(cut);
            int l = target.length()-i;
            target = target.substr(i, l);
            count++;
        }
        return count;
    }
};