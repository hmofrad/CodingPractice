/*
 *  Problem: https://leetcode.com/problems/find-anagram-mappings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        std::vector<int> out;
        if((A.size() != B.size()) or (A.empty() or B.empty())) return(out);
        
        std::unordered_map<int, std::vector<int>> map;
        for(int i = 0; i < B.size(); i++) {
            map[B[i]].push_back(i);
        }
        for(int i = 0; i < A.size(); i++) {
            auto& m = map.find(A[i])->second;
            out.push_back(m.back());
            m.pop_back();
        }
        return(out);    
    }
};