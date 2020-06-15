/*
 * https://leetcode.com/problems/cracking-the-safe/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */



class Solution {
public:
    std::string password;
    void dfs(std::vector<std::vector<int>>& visited, int u, int v, int n, int k) {
        //printf("%d %d [%d %d]\n", u, v, visited.size(), visited[0].size());
        for(int i=0; i<k; i++) {
            if(not visited[u][i]){
                visited[u][i]=true;
                dfs(visited, ((u*k+i)%v), v, n, k);
                //password += to_string(i);
                password.push_back(i+'0');
            }
        }
    }
    string crackSafe(int n, int k) {
        //n=3, k=2;
        if(k==1) return std::string(n,'0');
        int v = 1;
        for(int i = 0; i < n-1; i++) v*=k;
        std::vector<std::vector<int>> visited(v, std::vector<int>(k, false));
        dfs(visited, 0, v, n, k);
        
        return password + password.substr(0, n-1);
    }
};

class Solution1 {
public:
    std::vector<std::string> ans;
     void backtrack(std::string temp, int m, int n, int k) { 
        if(temp.size()==n) {ans.push_back(temp); return;}
         if(m==n) return;
        for(int i = 0; i < k; i++) {
            std::string t = to_string(i);
            temp += t;
            backtrack(temp, m+1, n, k);
            temp.erase(temp.end()-t.size());
        } 
    }
    
    int is_suffix(std::string a, std::string b) {
        int len_a = a.length();
        int len_b = b.length();
        int i = len_a-1;
        int j = len_b-1;
        int size = 0;
        while(i>=0 and j>=0) {
            if(a[i]==b[j]) {
                int k = j;
               while(i>=0 and j>=0 and a[i]==b[j]) { i--; j--; } 
               if(j==-1) { return k+1;} 
               else {i=size-1; j=k;}
            }
            j--;
        }
        return 0;
    }
    
    string crackSafe(int n, int k) {
        n=2,k=2;
        backtrack(std::string(), 0, n, k);
        
        //std::sort(ans.begin(), ans.end(), [](std::string a, std::string b){return a<b;});
        std::string password;
        
        for(std::string& a: ans) {
            int s = is_suffix(password, a);
            password += a.substr(s);
        }
        return password;
    }
};