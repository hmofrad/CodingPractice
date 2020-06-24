/*
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    //"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    string originalDigits(string s) {   
        std::vector<int> counts(10);
        for(char c: s) {
            switch(c) {
                case 'z': counts[0]++; break;
                case 'w': counts[2]++; break;
                case 'x': counts[6]++; break;
                case 's': counts[7]++; break; //6,7
                case 'g': counts[8]++; break;
                case 'u': counts[4]++; break;
                case 'f': counts[5]++; break; //4,5
                case 'h': counts[3]++; break; //3,8
                case 'i': counts[9]++; break; //5,6,8,9
                case 'o': counts[1]++; break; //0,1,2,4
            }
        }
        counts[7]-=counts[6];
        counts[5]-=counts[4];
        counts[3]-=counts[8];
        counts[9]-=(counts[8]+counts[5]+counts[6]);
        counts[1]-=(counts[0]+counts[2]+counts[4]);
        std::string t;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j < counts[i]; j++) {t.push_back(i+'0');}
        }
        return t;
    }
};

class Solution1 {
public:
    struct Trie {
        public:
        Trie() { children.resize(27); is_leaf = false;};
        ~Trie();
        std::vector<struct Trie*> children;
        bool is_leaf;
        std::string word;
    };
    
    void put(struct Trie* trie, std::string& word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            if(trie->children[j] == nullptr) trie->children[j]=new Trie();
            trie=trie->children[j];
        }
        trie->is_leaf = true;
        trie->word = word;
    }
    
    bool search(struct Trie* trie, std::string word) {
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int j = word[i]-'a';
            if(trie->children[j] == nullptr) return false;
            trie = trie->children[j];
        }
        return trie->is_leaf;
    }
    
    std::vector<std::string> search(struct Trie* trie, char c) {
        std::vector<std::string> out;
        struct Trie* head = trie->children[c-'a'];
        if(head) {
            if(head->is_leaf) out.push_back(head->word);
            for(int i = 0; i < 26; i++) {
                std::vector<std::string> temp = search(head, i+'a');
                out.insert(out.end(), temp.begin(), temp.end());
            }
        }
        return out;
    }
    std::unordered_map<std::string,char> english2digit = {{"zero",'0'}, {"one",'1'}, {"two",'2'}, {"three",'3'}, {"four",'4'}, {"five",'5'}, {"six",'6'}, {"seven",'7'}, {"eight",'8'}, {"nine",'9'}};
    std::string dfs(std::unordered_map<char, int> letters, int index, struct Trie* trie, std::string ans) {
        printf("%d %d [%s]\n", letters.size(), index, ans.c_str());
        if(letters.empty()) return ans;
        if(index==letters.size()) return std::string();
        
        int index0 = index;
        std::unordered_map<char, int> letters0(letters);
        //printf("%c\n", letters.begin()->first);
        char c = std::next(letters.begin(),index)->first;
        //printf("c=%c\n" , c);
        std::vector<std::string> v = search(trie, c);
        //printf("%c\n", c);
        for(std::string& str: v) { 
            printf("%s\n", str.c_str());
            for(char c: str) {
                letters[c]--; 
                if(letters[c]==0) { letters.erase(c); index--; }
            } 
            ans.push_back(english2digit[str]); 
        }
        if(v.empty()) index++;
        else {
            char c0 = std::next(letters.begin(),index)->first;
            if(c==c0) index++;
        }
        std::string ans0 = dfs(letters, index, trie, ans);
        if(ans0.empty()) ans0 = dfs(letters0, index0+1, trie, ans);
        return ans0;
    }
    
    
    string originalDigits(string s) {    
        std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        struct Trie* trie = new Trie();
        for(std::string& digit: digits) {put(trie, digit);}
        //for(std::string& digit: digits) {printf("%s %d\n", digit.c_str(), search(trie, digit));}
        //std::vector<std::string> t = search(trie, 'b');
        //for(auto tt: t) printf("%s ", tt.c_str()); printf("\n");
        std::unordered_map<char, int> letters(26);
        for(char c: s) letters[c]++;
        
        
        
        return dfs(letters, 0, trie, std::string());
    }
};






















class Solution0 {
public:
    
string originalDigits(string s) {
        
std::vector<std::string> digits = {"zero", "one", "two", "three", "four",
                                   "five", "six", "seven", "eight", "nine"};    
    
    std::string t;
    
    std::unordered_map<char, std::vector<std::string>> map;
    
    for(std::string d: digits) {
        for(char c: d) {
            if(map.find(c) == map.end()) {
                map[c] = {d};    
            }
            else {
                if(std::find(map[c].begin(), map[c].end(), d) == map[c].end()) {
                    map[c].push_back(d);    
                }
            }
        }
    }
    /*
    for(auto m: map) {
        printf("%c: ", m.first);
        for(auto v: m.second) {
            printf("%s ", v.c_str());
        }
        printf("\n");
    }
    */
    
    std::vector<std::string> strs;
    for(auto it = s.begin(); it != s.end(); it++) {
        //uint32_t i = it - s.begin();
        //printf("%d %c\n", i, *it); 
        auto& vec = map[*it];
        for(auto v: vec) {
            //printf("%s ", v.c_str());
            std::vector<int> alphas(26);
            for(auto it1 = s.begin(); it1 != s.end(); it1++) {
                alphas[*it1 - 'a']++;
            }
            
            for(auto c: v) {
                alphas[c - 'a']--;
            }
            bool found = true;
            for(auto a: alphas) {
                if(a < 0) {
                    found = false;
                    break;
                }
            }
            
            if(found) {
                if(std::find(strs.begin(), strs.end(), v) == strs.end()) {
                    strs.push_back(v);
                }
            }
        }
        //printf("\n");
    }
    
    for(auto str: strs) {
        auto it = std::find(digits.begin(), digits.end(), str);
        uint32_t dist = it - digits.begin();
        //printf("%s %d\n", str.c_str(), dist);
        t += '0'+dist;
    }
    
    return(t);
    }
};