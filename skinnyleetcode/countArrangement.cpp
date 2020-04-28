/*
 *  https://leetcode.com/problems/beautiful-arrangement/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool check(std::vector<int> current) {
        int size = current.size();
        for(int i = 0; i < size; i++) if((current[i]%(i+1)) and ((i+1)%current[i])) return false;
        return true;
    }
    std::vector<std::vector<int>> generate(std::vector<int> nums, std::vector<int> current, int N) {
        std::vector<std::vector<int>> ans;
        if(nums.empty()) {ans.push_back(std::vector<int>()); return ans;}
        if(current.size() == N) {ans.push_back(current); return ans;}
        
        int first = nums.front();
        nums.erase(nums.begin());
        std::vector<std::vector<int>> temp = generate(nums, current, N);
        
        for(std::vector<int>& t: temp) {
            int size = t.size();
            for(int i = 0; i <= size; i++) {
                std::vector<int> t1(t.begin(), t.begin()+i);
                t1.push_back(first);
                t1.insert(t1.end(), t.begin()+i, t.end());
                if(t1.size() < N or check(t1)) ans.push_back(t1);
            }
        }
        return ans;
    }
    int countArrangement1(int N) {
        std::vector<int> nums(N); std:iota(nums.begin(), nums.end(), 1);
        std::vector<std::vector<int>> beautiful_people = generate(nums, std::vector<int>(), N);
        return beautiful_people.size();
    }
    
    void backtrack(std::vector<int>& visited, int& count, int index, int N) {
        if(index>N) count++;
        
        for(int i = 1; i <= N; i++) {
            if(not visited[i] and (index%i==0 or i%index==0)) {
                visited[i]=true;
                backtrack(visited, count, index+1, N);
                visited[i]=false;
            }
        }
    }
    int countArrangement(int N) {
        int count = 0;
        std::vector<int> visited(N+1);
        backtrack(visited, count, 1, N);
        return count;
    }
	
	
	std::vector<std::vector<int>> permutation(std::vector<int> nums, std::vector<int> current, int index, int N) {
        std::vector<std::vector<int>> ans;
        if(current.size()==N+1) {ans.push_back(current); return ans;}
        
        for(int i = 0; i <= N; i++) {
            current.push_back(i);
            std::vector<std::vector<int>> t = permutation(nums, current, index+1, N);
            current.pop_back();
            ans.insert(ans.end(), t.begin(), t.end());
        }
        return ans;
    }
	
};