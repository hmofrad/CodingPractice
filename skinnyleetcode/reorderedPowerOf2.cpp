/*
 *	https://leetcode.com/problems/reordered-power-of-2/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        std::vector<int> A = count(N);
        for(int i = 0; i < 31; i++) { if(A==count(1<<i)) return true; }
        return false; 
    }
    
    std::vector<int> count(int N) {
        std::vector<int> ans(10);
        while(N) {
            ans[N%10]++;
            N/=10;
        }
        return ans;
    }
    
     bool reorderedPowerOf234(int N) {
        long c = counter(N);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }

    long counter(int N) {
        long res = 0;
        for (; N; N /= 10) res += pow(10, N % 10);
        return res;
    }
    
    
    
    bool backtrack1(std::string& S, std::string T, std::vector<bool>& visited, std::unordered_set<std::string>& set) {
        if(not set.insert(T).second) return false;
        if(S.length()==T.length()) {
            if(T[0]=='0') return false;
            int t = stoi(T);
            if(isPowerof2(t)) return true;
            return false;
        }
        
        for(int i = 0; i < S.length(); i++) {
            if(visited[i]) continue;
            visited[i]=true;
            if(backtrack1(S, T+S[i], visited, set)) return true;
            visited[i]=false;
        }
        return false;
    }
    bool reorderedPowerOf23(int N) {
        std::string S = to_string(N);
        std::vector<bool> visited(S.length());
        std::unordered_set<std::string> set;
        return backtrack1(S, std::string(), visited, set);
    }
    
    
    
    std::vector<int> int2vec(int n) {
        std::vector<int> v;
        while(n) {
            int r = n%10;
            n/=10;
            v.push_back(r);
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
    
    int vec2int(std::vector<int>& v) {
        int n = 0;
        int size = v.size();
        for(int i = size-1; i >= 0; i--) {
            n += v[i]*pow(10,(size-1-i));
        }
        return n;
    }
    
    bool isPowerof2(int n) {
        return n and not (n & (n - 1));
    }
    
    std::vector<std::vector<int>> combinations(std::vector<int>& V, std::vector<int> T, int n) {
        std::vector<std::vector<int>> ans;
        if(V.empty() or T.size()==n) { ans.push_back(T); return ans; }
        int front = V[0];
        V.erase(V.begin());
        std::vector<std::vector<int>> temps = combinations(V, T, n);
        for(std::vector<int>& temp: temps) {
            int size = temp.size();
            for(int i = 0; i <= size; i++) {
                std::vector<int> t(temp.begin(), temp.begin()+i);
                t.push_back(front);
                t.insert(t.end(), temp.begin()+i, temp.end());
                std::vector<std::vector<int>> t0 = combinations(V, t, n);
                ans.insert(ans.end(), t0.begin(), t0.end());
            }
        }
        return ans;
    }
    
    bool reorderedPowerOf21(int N) {
        std::vector<int> V = int2vec(N);
        std::vector<std::vector<int>> combs = combinations(V, std::vector<int>(), V.size());
        for(std::vector<int>& comb: combs) {
            if(comb[0]==0) continue;
            int v = vec2int(comb);
            if(isPowerof2(v)) return true;
        }
        return false;
    }
    bool found = false;
    std::vector<std::vector<int>> combinations1(std::vector<int>& V, std::vector<int> T, int n) {
        std::vector<std::vector<int>> ans;
        if(V.empty() or T.size()==n) { ans.push_back(T); return ans;}
        int front = V[0];
        V.erase(V.begin());
        std::vector<std::vector<int>> temps = combinations1(V, T, n);
        for(std::vector<int>& temp: temps) {
            int size = temp.size();
            for(int i = 0; i <= size; i++) {
                std::vector<int> t(temp.begin(), temp.begin()+i);
                t.push_back(front);
                t.insert(t.end(), temp.begin()+i, temp.end());
                std::vector<std::vector<int>> t0 = combinations1(V, t, n);
                if(not t0.empty()) {
                    for(std::vector<int>& t1: t0) {
                        ans.push_back(t1);
                        if(t1[0] and t0[0].size() == n and isPowerof2(vec2int(t1))) {found=true; break;}
                    }
                }
                if(found) break;
                //ans.insert(ans.end(), t0.begin(), t0.end());
            }
            if(found) break;
        }
        return ans;
    }
    
    bool reorderedPowerOf222(int N) {
       // N=4609;
        std::vector<int> V = int2vec(N);
        std::vector<std::vector<int>> combs = combinations1(V, std::vector<int>(), V.size());
        //for(auto comb: combs) {
        //    for(auto c: comb) printf("%d ", c); printf(" %d\n", isPowerof2(vec2int(comb)));
        //}
        //printf("%d %d\n", found, isPowerof2(vec2int(combs[0])));
        return found;
    }
    
    
    
    void backtrack(std::vector<int>& V, std::vector<int> T, int index, int n) {
        if(T.size()==n) {
            printf("index=%d sz=%d n=%d\n", index, T.size(), vec2int(T));    
            return ;
            //    isPowerof2(vec2int(T));
        }
        
        //if(index==0 and V[index]==0) return false;
        
        for(int i = index; i < n; i++) {
            T.push_back(V[i]);
            backtrack(V, T, i, n);
            //if(backtrack(V, T, i+1, size)) return true;
            T.pop_back();
        }
        //return false;
    }
    
    bool reorderedPowerOf22(int N) {
        N=46;
        std::vector<int> V = int2vec(N);
        for(int v: V) printf("%d ", v); printf("\n");
        backtrack(V, std::vector<int>(), 0, V.size());
        return false;
        //return backtrack(V, std::vector<int>(), 0, V.size());
    }
};