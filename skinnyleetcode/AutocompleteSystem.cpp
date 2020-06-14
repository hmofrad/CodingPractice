/*
 * https://leetcode.com/problems/design-search-autocomplete-system/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

  

class AutocompleteSystem {
public:
    
    class Trie {
        public:
        Trie() : time(0) {}
        ~Trie(){}
        std::unordered_map<char, Trie*> children;
        std::string sentence;
        int time;
    };
    
    void put(Trie* trie, std::string& sentence, int time) {
        for(char c: sentence) {
            if(trie->children.count(c)==0) trie->children[c]=new Trie();
            trie=trie->children[c];
        }
        trie->sentence=sentence;
        trie->time+=time;
    }
    
    struct comp {
        bool operator()(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
            //return a.second<b.second || a.second==b.second && a.first>b.first;

        }
    };
    priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comp> queue;
    Trie* trie; Trie* curr;
    std::string query;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        for(int i = 0; i<sentences.size(); i++) {
            put(trie, sentences[i], times[i]);
        }
        curr=trie;
    }
    
    void dfs(Trie* trie) {
        if(not trie->sentence.empty()) queue.push({trie->sentence, trie->time});
        
        for(auto child: trie->children) dfs(child.second);
    }
    
    vector<string> input(char c) {
        
        queue = priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comp>();
        if(c=='#') {
            put(trie, query, 1);
            query.clear();
            curr=trie;
            return std::vector<std::string>();
        }
        
        query.push_back(c);
        
        if(curr and curr->children.count(c)) { curr=curr->children[c]; }
        else {curr=nullptr; return std::vector<std::string>();}
        
        if(not curr->sentence.empty()) queue.push({curr->sentence, curr->time});
        
        for(auto child: curr->children) {
            dfs(child.second);
        }
        
        vector<string> top3;
        while(not queue.empty() and top3.size()<3) {top3.push_back(queue.top().first); queue.pop();}
        
        return top3;
    }
};

/*
class Trie{
        public:
        Trie(){is_leaf = false;}
        std::unordered_map<char,Trie*> children;
        bool is_leaf;
        std::vector<std::pair<std::string, int>> degree;
        void put(Trie* trie, std::string sentence, int times){ 
            for(char c: sentence) {
                if(trie->children.count(c)==0) trie->children[c]=new Trie();
                trie->degree.push_back({sentence, times});
                trie=trie->children[c];
            }
            trie->degree.push_back({sentence,times});
            trie->is_leaf=true;
        }

        std::vector<std::pair<std::string, int>> find(Trie* trie, std::string sentence) {
            int length = sentence.length();
            for(int i = 0; i < length; i++) {
                char c = sentence[i];
                if(trie->children.count(c)) trie = trie->children[c];
                else return std::vector<std::pair<std::string, int>>();
            }
            std::vector<std::pair<std::string, int>> found;
            for(auto child: trie->children) {
                for(auto deg: child.second->degree){
                    std::string key = deg.first;
                    int value = deg.second;
                    found.push_back({key,value});
                }
            }
            return found;
        }

    };
    
    

class AutocompleteSystem {
public:
   
    std::string query;
    Trie* trie;
    std::unordered_map<std::string, int> db;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie=new Trie();
        for(int i = 0; i< sentences.size(); i++) { 
            trie->put(trie, sentences[i], times[i]);
            db[sentences[i]]=times[i];
        }
    }
    
    vector<string> input(char c) {
        std::vector<std::string> top3;
        if(c=='#') {
            trie->put(trie, query, 1);
            query.clear();
            //db[sentences[i]]=times[i];
        }
        else {
            query.push_back(c);
            std::vector<std::pair<std::string, int>> pairs = trie->find(trie, query);
            std::sort(pairs.begin(), pairs.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) { return a.second == b.second ? a.first<b.first : a.second>b.second; });
            for(int i = 0; i < min(3,(int)pairs.size()); i++) top3.push_back(pairs[i].first);
        }
        return top3;
    }
};
*/
/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */