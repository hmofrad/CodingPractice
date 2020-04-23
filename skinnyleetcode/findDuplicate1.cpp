/*
 *  https://leetcode.com/problems/find-duplicate-file-in-system/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::unordered_map<std::string, std::string> fs;
    std::unordered_map<std::string, std::vector<std::string>> fs1;
    
    void add_path(std::string path) {
        int len = path.length();
        
        std::string directory;
        std::vector<std::string> files;
        std::vector<std::string> contents;
        int i = 0;
        int j = 0;
        while(i < len) {
            if(path[i] == ' ' and path[i-1] != ')') {
                int len = i-j;
                directory = path.substr(j, i);
                j=i+1;
            }
            else if(path[i] == '(') {
                int len = i-j;
                std::string file = path.substr(j, len);
                files.push_back(file);
                j=i+1;
            }
            else if(path[i] == ' ' and path[i-1] == ')') {
                int len = i-j-1;
                std::string content = path.substr(j, len);
                contents.push_back(content);
                j=i+1;
            }
            else if(i==len-1 and path[i] == ')') {
                int len = i-j;
                std::string content = path.substr(j, len);
                contents.push_back(content);
            }
            i++;
        }
        
        int nfiles = files.size();
        /*
        for(int i = 0; i < nfiles; i++) {
            fs[directory+'/'+files[i]] = contents[i];
        }
        */
        for(int i = 0; i < nfiles; i++) {
            fs1[contents[i]].push_back(directory+'/'+files[i]);
        }
        
        
        /*
        printf("%s:\n ", directory.c_str());
        for(int i = 0; i < files.size(); i++) {
            printf("%s %s\n", files[i].c_str(), contents[i].c_str());
        }
        */
        
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        /*
        for(std::string path: paths) {
            printf("%s\n", path.c_str());
        }
        */
        
        
        for(std::string path: paths) {
            //printf("%s\n", path.c_str());
            add_path(path);
           // break;
        }
        
        //for(auto f: fs) {
        //    printf("%s %s\n", f.first.c_str(), f.second.c_str());
        //}
        /*
        vector<vector<string>> ans;
        while(not fs.empty()) {
            auto it = fs.begin(); 
            std::string str = it->second;
            std::vector<std::string> keys;
            int i = 0;
            for(auto f: fs) {
                if(f.second == str) keys.push_back(f.first);
            }
            
            for(std::string key: keys) fs.erase(key);
            if(keys.size()>1) ans.push_back(keys);
        }
        */
        vector<vector<string>> ans;
        for(auto f: fs1) {
            if(f.second.size()>1) ans.push_back(f.second);
        }
        
        
        return ans;
        
    }
};