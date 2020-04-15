/*
 *  https://leetcode.com/problems/search-suggestions-system/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    class TrieNode {
        std::vector<TrieNode*> links;
        bool is_end;
        public:
        TrieNode() {links.resize(26); is_end = false;}
        TrieNode* getlink(char c) {return links[c-'a'];}
        void createlink(char c) {links[c-'a'] = new TrieNode;}
        void setend() {is_end = true;}
        bool isend() {return is_end;}
        
        void insert(std::string& s) {
            TrieNode* it = this;
            
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {  
        std::sort(products.begin(), products.end());
        std::vector<std::vector<std::string>> outs;
        
        std::unordered_map<std::string, std::set<std::string>> map;
        
        for(std::string product: products) {
            int len = product.length();
            for(int i = 0; i < len; i++) {
                std::string key = product.substr(0, i+1);
                map[key].insert(product);
            }
        }
        
        int len = searchWord.size();
        for(int i = 1; i <= len; i++) {
            std::string key = searchWord.substr(0, i);
            std::vector<std::string> out;
            if(map[key].size() < 3)
                out = std::vector<std::string>(map[key].begin(), map[key].end());
            else 
                out = std::vector<std::string>(map[key].begin(), std::next(map[key].begin(),3));
            
                //std::vector<std::string>(map[key.begin()], map[key].size() < 3 ? map[key].end() : map[key].begin()+3);
             outs.push_back(out);
                        //res.push_back(vector<string>(mp[key].begin(), 
                         //mp[key].size()<3 ? mp[key].end() : next(mp[key].begin(), 3)));

        }
        
        
        
        return outs;
    }
    
    bool search(std::string product, std::string pattern) {
        bool found = true;
        int len = pattern.length();
        for(int i = 0; i < len; i++) {
            if(product[i] != pattern[i]) {found = false; break;}
        }
        return found;
    }
    
    vector<vector<string>> suggestedProducts1(vector<string>& products, string searchWord) {
        std::sort(products.begin(), products.end());
        std::vector<std::vector<std::string>> outs;
        int len_products = products.size();
        int len_search = searchWord.length();
        for(int i = 0; i < len_search; i++) {
            std::string pattern = searchWord.substr(0, i+1);
            std::vector<std::string> out;
            for(std::string product: products) {
                if(search(product, pattern)) out.push_back(product);
            }
            if(out.size()>3) out.erase(out.begin()+3,out.end());
            outs.push_back(out);
        }
        return outs;
    }
};