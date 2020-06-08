/*
 * https://leetcode.com/problems/isomorphic-strings/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::vector<int> map_s(256);
        std::vector<int> map_t(256);
        for(int i = 0; i < s.size(); i++) {
            if(map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]]=i+1;
            map_t[t[i]]=i+1;
        }
        return true;
    }
    
    bool isIsomorphic2(string s, string t) {
       // s="ab";
        //t="aa";
        if(s.size() != t.size()) return false;
        std::map<int, std::vector<int>> map_s;
        for(int i = 0; i < s.size(); i++) {
            map_s[s[i]].push_back(i);
        }
        
        std::map<int, std::vector<int>> map_t;
        for(int i = 0; i < t.size(); i++) {
            map_t[s[i]].push_back(i);
        }
        std::unordered_set<char> visited;
        for(auto m: map_s) {
            int key_s = m.first;
            std::vector<int>& values_s = m.second;
            char c = t[values_s.front()];
            if(not visited.insert(c).second) return false;
            for(int v: values_s) {   
                if(t[v]!=c) return false;
            }
        }
        return true;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool isIsomorphic1(string s, string t) {
        std::unordered_map<unsigned char, unsigned char> r;
        bool ret = true;
        int m = s.size();
        int n = t.size();
        if(m != n) {
            ret = false;
        }
        else if(m > 0) {
            
            //std::string r;
            for(int i = 0; i < m; i++) {
                unsigned char k = s[i];
                unsigned char v = t[i];
                //printf("<%c, %c>\n", k, v);
                std::unordered_map<unsigned char, unsigned char>::const_iterator f1 = r.find (k);
                //std::unordered_map<unsigned char, unsigned char>::const_iterator f2 = r.find (v);
                //if((f1 == r.end()) and (f2 == r.end())) {
                if(f1 == r.end()) {
                    r[k] = v;
                    //printf("%c, %c %c %c\n", k, r[k], got->first, got->second);
                   // r[v] = k;
                }
                //else if(f1 != r.end()){
                else {
                    //printf("%d %d\n", f1 == r.end(), f2 == r.end());
                    //printf("%c, %c %c\n", k, r[k], f1->first);
                    if(f1->second != v) {
                      //  printf("xxxx\n");
                        ret = false;
                        break;
                    }
                }
                /*
                else {
                    if(f2->first!= k) {
                        //printf("kkkk\n");
                        ret = false;
                        break;
                    }
                }
                */
            }
                
        }
        /*
        for (auto const& pair: r) {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
        */
        return(ret); 
    }
};