/*
 *  https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int ds_find(std::vector<int>& ds, int p) {
        return(ds[p] == -1 ? p : ds[p] = ds_find(ds, ds[p]));
    }
    
    void ds_merge(std::vector<int>& ds, int p1, int p2) {
        p1 = ds_find(ds, p1);
        p2 = ds_find(ds, p2);
        if(p1 != p2) {
            ds[max(p1, p2)] = min(p1, p2);
        }
    }
    
    void ds_print(std::vector<int> ds) {
        for(int i = 0; i < 26; i++) {
            printf("%3c ", 'a'+i);
        }
        printf("\n");
        
        for(int i = 0; i < 26; i++) {
            if(ds[i]>=0)
                printf("%3c ", 'a'+ds[i]);
            else 
                printf("%3d ", ds[i]);
        }
        printf("\n");
    }
    
    string smallestEquivalentString(string A, string B, string S) {
        std::vector<int> ds(26, -1);
        for(int i = 0; i < A.size(); i++) {
            ds_merge(ds, A[i]-'a', B[i]-'a');
            ds_print(ds);
        }
        
        for(int i = 0; i < S.size(); i++) {
            S[i] = 'a' + ds_find(ds, S[i]-'a');
        }
        
        return(S);
    }
    
    
    
    std::vector<std::vector<int>> map;
    void update(int row, int col, std::vector<int>& visited) {
       // printf("%d %d\n", row, col);
        //if(map[row][col] and map[col][row]) return;
        

        for(int j = 0; j < 26; j++) {
            if(map[row][j] and not visited[j]) {visited[j] = 1; update(j, col, visited); }
            if(map[col][j] and not visited[j]) {visited[j] = 1; update(j, row, visited); }
        }
        
        map[row][row] = 1;
        map[row][col] = 1;
        map[col][col] = 1;
        map[col][row] = 1;
    }
    string smallestEquivalentString1(string A, string B, string S) {
        map.resize(26);
        for(int i = 0; i < 26; i++) {map[i].resize(26);}
        
        
        int m = A.size();
        for(int i = 0; i < m; i++) {
            std::vector<int> visited(26);
            if(A[i] >= 'a' and A[i] <= 'z')
            update(A[i]-'a', B[i]-'a', visited);
        }
        /*
        printf("  ");
        for(int i = 0; i < 26; i++) {
            printf("%c ", 'a'+i);
        }
        printf("\n");
        for(int i = 0; i < 26; i++) {
            printf("%c ", 'a'+i);
            for(int j = 0; j < 26; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        */
        std::string out;
        
        for(char& c: S) {
            for(int j = 0; j < 26; j++) { 
                if(map[c-'a'][j]) {
                    char c1 = 'a'+j; 
                    std::swap(c, c1);
                    break;
                }
            }
        }
        
        return(S);
    }
};