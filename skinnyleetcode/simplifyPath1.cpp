/*
 * https://leetcode.com/problems/simplify-path/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) return "/";
        
        std::string slash = std::string(1, '/');
        std::string dot = std::string(1, '.');
        std::string dotdot = std::string(2, '.');
        int len = path.length();
        std::stack<std::string> st;
        st.push(slash);
        std::string dir;
        for(int i = 1; i < len; i++) {
            char c = path[i];
            if(c == '/') {
                if(not dir.empty()) {
                    if(dir == dotdot) {
                        if(st.size()>1 and st.top()==slash) {st.pop(); st.pop(); }
                    }
                    else if(not (dir == dot)) { st.push(dir); st.push(slash); }
                    dir.clear();
                }
            }
            else if(c == '.') {
                while(i<len and path[i]=='.') {
                    dir.push_back('.'); i++;
                }  
                i--;
            }
            else {
                dir += c;
            }
            
        }
        if(not dir.empty()) { 
            if(dir==dotdot) { 
                if(st.size()>1 and st.top()==slash) {st.pop(); st.pop(); }
            }
            else if(dir != dot) { st.push(dir); }
        }
        if(st.size()>1 and st.top() == slash) { st.pop(); }
        std::string ans;
        while(not st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        printf("%s\n", ans.c_str());
        return ans;
    }
};