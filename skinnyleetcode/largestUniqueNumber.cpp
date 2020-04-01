/*
 *  https://leetcode.com/problems/largest-unique-number/submissions/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        A.push_back(INT_MAX);
        A.push_back(INT_MIN);
        std::sort(A.begin(), A.end());
        int m = A.size();
        for(int i = m-2; i > 0; i--) {
            if(A[i] == A[i-1]) continue;
            if(A[i] == A[i+1]) continue;
            return A[i];
        }
        
        return(-1);
    }
    int largestUniqueNumber1(vector<int>& A) {
        int num = -1;
        std::map<int, int> my_map;
        for(int a: A) {
            my_map[a]++;
        }
        for(auto rit = my_map.rbegin(); rit != my_map.rend(); rit++) {
            //printf("%d %d\n", rit->first, rit->second);
            if(rit->second == 1) {num = rit->first; break;}
        }
        return(num);
    }
};