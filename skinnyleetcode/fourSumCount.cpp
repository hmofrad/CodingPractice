/*
 *	https://leetcode.com/problems/4sum-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::map<int, int> map;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) { int sum = A[i]+B[j]; map[sum]++; }
        }
        int counts = 0;
        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) { int sum = -C[i]-D[j]; counts += (map.count(sum)) ? map[sum] : 0; }
        }
        return counts;
    }
    int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int counts = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                for(int k = 0; k < C.size(); k++) {
                    for(int l = 0; l < D.size(); l++) {
                        if(A[i]+B[j]+C[k]+D[l]==0) counts++;
                    }
                }
            }
        }
        return counts;
    }
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        std::sort(C.begin(), C.end());
        std::sort(D.begin(), D.end());
        int counts = 0;
        std::vector<int> indices(4);
        std::vector<size_t> sizes = {A.size(), B.size(), C.size(), D.size()};
        std::vector<std::vector<int>> values = {A, B, C, D};
        while(true) {
            int sum = 0;
            int min_index = 0;
            int min_value = INT_MAX;
            int count = 0;
            for(int i = 0; i < 4; i++) {
                int value = 0;
                if(indices[i]<sizes[i]) {value=values[i][indices[i]]; count++;}
                if(value<min_value) {min_value=value; min_index=i;}
                sum+=value;
            }
            if(count < 4) break;
            indices[min_index]++;
            if(sum==0) counts++;
        }
        return counts;
    }
};