/*
 * https://leetcode.com/problems/design-file-system/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class FileSystem {
public:
    struct Trie {
        public:
        Trie(){}
        ~Trie(){}
        std::unordered_map<std::string, struct Trie*> children;
        bool isLeaf = false;
        int value = 0;
    };
    struct Trie* tree;
    
    std::vector<std::string> tokenize(std::string path) {
        std::vector<std::string> dirs;
        int len = path.size();
        int i = 1;
        int j = 1;
        while(i < len) {
            char& c = path[i];
            if(c=='/') {
                int len = i-j;
                if(len==0) return std::vector<std::string>();
                dirs.push_back(path.substr(j,len));
                j=i+1;
            }
            i++;
        }
        len = i-j;
        dirs.push_back(path.substr(j,len));
        
        //for(std::string& d: dirs) printf("%s ", d.c_str()); printf("\n");
        
        return dirs;
    }
    
    bool put(std::string path, int value) {
        if(path.size()<=1 or path[0] != '/') return false;
        
        std::vector<std::string> dirs = tokenize(path);
        if(dirs.empty()) return false;
        
        struct Trie* head = tree;
        struct Trie* prev = tree;
        int size = dirs.size();
        for(int i = 0; i < size; i++) {
            //prev=head;
            if(head->children.count(dirs[i])) {
                head=head->children[dirs[i]];
            }
            else {
                if(size-i<=1) {
                    head->children[dirs[i]]= new Trie();
                    head=head->children[dirs[i]];
                }
                else return false;
            }
        }
        if(head->isLeaf) return false;
        head->isLeaf = true;
        head->value = value;
        return true;
    }
    
    int search(std::string path) {
        std::vector<std::string> dirs = tokenize(path);
        if(dirs.empty()) return -1;
        
        struct Trie* head = tree;
        int size = dirs.size();
        for(int i = 0; i < size; i++) {
            if(head->children.count(dirs[i])) {
                head=head->children[dirs[i]];
            }
            else return -1;
        }
        return size ? head->value : -1;
    }
    
    FileSystem() {
        tree = new Trie();
    }
    
    bool createPath(string path, int value) {
        return put(path, value);
    }
    
    int get(string path) {
        return search(path);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */