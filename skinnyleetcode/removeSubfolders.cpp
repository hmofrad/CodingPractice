/*
 *  https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*So here is an algo:

sort folders
check each folder with the last valid
the folder is valid (not a sub-folder) if
it is shorter than the previous, e.g. /x vs. /a/b
it is equal to previous, but the next symbol is '/', e.g. comaring /a/b vs. /a
it doesn't start with a previous, e.g. /b/c vs. /a
add valid to the answer
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if(folder.empty()) return std::vector<std::string>();
        std::sort(folder.begin(), folder.end());
        std::vector<std::string> ans{folder[0]};
        int size = folder.size();
        for(int i = 1; i < size; i++) {
            std::string& path = folder[i];
            std::string& last_path = ans.back();
            if(path.size()> last_path.size() and 
               path[last_path.size()]=='/' and 
               path.compare(0, last_path.size(), last_path)==0) continue;
            ans.push_back(path);
        }
        return ans;
    }
};

class Solution2 {
public:
    struct TrieNode {
        public:
        TrieNode(){isLeaf=false;}
        ~TrieNode(){}
        bool isLeaf;
        std::map<std::string, struct TrieNode*> children;
    };
    
    class Trie {
        public:
        Trie(){root=new TrieNode();}
        ~Trie(){delete root;}
        struct TrieNode* root;
        std::vector<std::string> folders;
        
        
        void put(std::vector<std::string> path) {
            struct TrieNode* head = root;
            int size = path.size();
            for(int i = 0; i < size; i++) {
                std::string& key = path[i];
                if(not head->children.count(key)) head->children[key] = new TrieNode();
                head=head->children[key];
            }
            head->isLeaf=true;
        }
        
        bool search(std::vector<std::string> path) {
            struct TrieNode* head = root;
            int size = path.size();
            for(int i = 0; i < size; i++) {
                std::string& key = path[i];
                head=head->children[key];
            }
            return head->isLeaf;
        }
        
        void search1() {dfs(root, "");}
        
        void dfs(struct TrieNode* head, std::string path) {
            if(head->isLeaf) folders.push_back(path);
            else {
                for(auto child: head->children) {
                    dfs(child.second, path+"/"+child.first );
                }
            }
        }
    };
    
    
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* tree = new Trie();
        
        for(std::string& dir: folder) {
            std::vector<std::string> path;
            std::string temp;
            for(char c: dir) {
                if(c!='/') temp.push_back(c);
                else {path.push_back(temp); temp.clear();}
            }
            path.push_back(temp);
            for(std::string s: path) printf("%s ", s.c_str());
            tree->put(path);
            printf("%d: \n", tree->search(path));
        }
        tree->search1();
        for(std::string& path: tree->folders) path.erase(path.begin());
        return tree->folders;
    }
};


class Solution1 {
public:
    
    struct Trie{
        Trie(){next.resize(26); isLeaf=false;};
        ~Trie(){};
        std::vector<struct Trie*> next;
        bool isLeaf;
    };
    
    void put(struct Trie** tree, std::string path) {
        if(path.empty()) return;
        struct Trie* head = *tree;
        int len = path.size();
        for(int i = 0; i < len; i++) {
            int j = path[i]-'a';
            if(not head->next[j]) head->next[j] = new Trie();
            if(i+1==len) {head->next[j]->isLeaf = true; break;}
            head=head->next[j];
        }
    }
    
    bool find(struct Trie* tree, std::string path) {
        if(path.empty()) return false;
        struct Trie* head = tree;
        
        int len = path.size();
        for(int i = 0; i < len; i++) {
            int j = path[i]-'a';
            if(head->next[j]) {
                if(i+1==len) {return (head->next[j]->isLeaf) ? true : false;}    
                else head=head->next[j];
            }
            else return false;
        }
        
        return false;
    }
    
    bool find1(struct Trie* tree, std::string path) {
        if(path.empty()) return false;
        struct Trie* head = tree;
        
        int first = -1;
        int second = -1;
        int len = path.size();
        for(int i = 0; i < len; i++) {
            int j = path[i]-'a';
            if(head->next[j]) {
                if(head->next[j]->isLeaf) {
                    if(first == -1) first = i;
                   // else 
                    
                } 
                
                if(i+1==len) {return (head->next[j]->isLeaf) ? true : false;}    
                head=head->next[j];
            }
            else return false;
        }
        
        return false;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        struct Trie* fs = new Trie();
        
        vector<string> paths;
        for(std::string& path: folder) {
            int len = path.size();
            std::string temp;
            for(int i = 1; i < len; i+=2) temp.push_back(path[i]);
            paths.push_back(temp);
            put(&fs, temp);
        }
        //paths.push_back("cow");
        //for(std::string& path: paths) printf("%s %d\n", path.c_str(), find(fs, path));
        
        return std::vector<std::string>();
    }
};