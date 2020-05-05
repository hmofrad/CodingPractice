/*
 *	https://leetcode.com/problems/replace-words/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    
    struct Trie {
        Trie(){children.resize(26); isLeaf = false;}
        ~Trie(){}
        std::vector<struct Trie*> children;
        bool isLeaf;
    };
    
    void put(std::string str) {
        int size = str.length();
        struct Trie* head = tree;
        for(int i = 0; i < size; i++) {
            int j = str[i] - 'a';
            if(not head->children[j]) head->children[j] = new Trie();
            head = head->children[j];
        }
        head->isLeaf = true;
    }
    
    std::string search(std::string str) {
        bool found = false;
        int size = str.length();
        struct Trie* head = tree;
        int i = 0;
        for(; i < size; i++) {
            int j = str[i]-'a';
            if(head->isLeaf) {found = true; break;}
            if(head->children[j]) head = head->children[j];
            else {found = false; break;}
        }
        
        found |= (i==size);
        std::string t;
        if(found) t = str.substr(0, i);
        else t = str;
        
        return t;
    }
    
    std::vector<std::string> str2vec(string sentence) {
        int len = sentence.length();
        std::vector<std::string> strs;
        int j = 0, i =0;
        for(; i < len; i++) {
            char c = sentence[i];
            if(c==' ') {
                int l = i-j;
                std::string t = sentence.substr(j, l);
                strs.push_back(t);
                j=i+1;
            }
        }
        int l = i-j;
        std::string t = sentence.substr(j, l);
        strs.push_back(t);
        return strs;
    }
    
    std::string vec2str(std::vector<std::string>& strs) {
        std::string sentence;
        //printf("xxxx\n");
        for(std::string& str: strs) {
            sentence += (str + ' ');
            //sentence.push_back(str);
        }
        //printf("<%s>\n", sentence.c_str());
        //sentence.erase(sentence.end()-1);
        //printf("<%s>\n", sentence.c_str());
        sentence.pop_back();
        return sentence;
    }
    
    struct Trie* tree;
    string replaceWords(vector<string>& dict, string sentence) {
        tree = new Trie();
        for(std::string& root: dict) {
            put(root);
        }
        std::vector<std::string> strs = str2vec(sentence);
        
        for(std::string& str: strs) {
            //printf("%s -->", str.c_str());
            str = search(str);
            //printf("%s\n", str.c_str());
        }
        
        sentence = vec2str(strs);
        
        return sentence;
    }
};