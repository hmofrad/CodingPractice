/*
 *	https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favs) {
	for (auto &comps : favs) sort(begin(comps), end(comps));
	vector<int> res;
	for (auto i = 0; i < favs.size(); ++i) {
		bool notSubset = true;
		for (auto j = 0; j < favs.size() && notSubset; ++j) {
			if (i == j) continue;
			notSubset = !includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
		}
		if (notSubset) res.push_back(i);
	}
        
	return res;
}
    void set_bit(int& num, int index) {
        int mask = 1 << index;
        num |= mask;
    }
    int get_bit(int num, int index) {
        int mask = 1 << index;
        int bit = num & mask;
        return bit != 0;
    }
    vector<int> peopleIndexes2(vector<vector<string>>& favoriteCompanies) {
        std::unordered_map<std::string, int> names;
        int size = favoriteCompanies.size();
        int k = 0;
        for(int i = 0; i < size; i++) {
            int size1 = favoriteCompanies[i].size();
            for(int j = 0; j < size1; j++) { 
                if(not names.count(favoriteCompanies[i][j])) { names[favoriteCompanies[i][j]]=k; k++; }
            }
        }
        
        std::vector<int> masks(size);
        for(int i = 0; i < size; i++) {
            int size1 = favoriteCompanies[i].size();
            for(int j = 0; j < size1; j++) { int index = names[favoriteCompanies[i][j]]; set_bit(masks[i], index); }
        }
        /*
        for(int j = 0; j < size; j++) {
            for(int i = 31; i >= 0; i--) {
                printf("%d ", get_bit(masks[j], i));
            }
            printf("\n");
        }
*/
        std::vector<int> ans;
        for(int i = 0; i < size; i++) {
            bool subset = true;
            for(int j = 0; j < size; j++) { if(i!=j and (masks[i] & masks[j]) == masks[i]) subset = false; }
            if(subset) ans.push_back(i);
        }

        return ans;
    }
    
    
    
    //A is a subset of B if and only if A^B=A
    bool isSubset(std::vector<int>& A, std::vector<int>& B) {
        int size = A.size();
        std::vector<int> intersection(size);
        for(int i = 0; i < size; i++) { if(A[i] and B[i]) intersection[i]=1; }
        
        for(int i = 0; i < size; i++) { if(A[i]!=intersection[i]) return false; }
        return true;
    }
    vector<int> peopleIndexes1(vector<vector<string>>& favoriteCompanies) {
        std::unordered_map<std::string, int> names;
        int size = favoriteCompanies.size();
        int k = 0;
        for(int i = 0; i < size; i++) {
            int size1 = favoriteCompanies[i].size();
            for(int j = 0; j < size1; j++) { 
                if(not names.count(favoriteCompanies[i][j])) { names[favoriteCompanies[i][j]]=k; k++; }
            }
        }
        
        std::vector<std::vector<int>> masks(size, std::vector<int>(names.size()));
        for(int i = 0; i < size; i++) {
            int size1 = favoriteCompanies[i].size();
            for(int j = 0; j < size1; j++) {  int index = names[favoriteCompanies[i][j]]; masks[i][index]=1; }
        }
        std::vector<int> ans;
        
        for(int i = 0; i < size; i++) {
            bool subset = true;
            for(int j = 0; j < size; j++) { if(i!=j and isSubset(masks[i], masks[j])) subset = false; }
            if(subset) ans.push_back(i);
        }

        return ans;
    }
};
