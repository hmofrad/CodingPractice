/*
 * https://leetcode.com/problems/course-schedule/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool dfs(std::unordered_map<int, std::vector<int>>& courses, int index, std::unordered_set<int>& visited) {
        if(not visited.insert(index).second) return false;
        
        int ret = true;
        for(int i: courses[index]) {
            ret &= dfs(courses, i, visited);
            if(not ret) return false;
        }
        visited.erase(index);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //numCourses = 3;
        //prerequisites = {{0,1},{0,2},{1,2}};
        std::unordered_map<int, std::vector<int>> courses(numCourses);
        for(std::vector<int> prerequisite: prerequisites) {
            courses[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            std::unordered_set<int> visited;
            bool ret = dfs(courses, i, visited);
            if(not ret) return false;
        }
        return true;
    }
    
    
    int union_find(std::vector<int>& U, int i) {
        return U[i]==-1 ? i : union_find(U, U[i]);
    }
    bool union_merge(std::vector<int>& U, int i, int j) {
        int parent_i = union_find(U, i);
        int parent_j = union_find(U, j);
        bool ret = true;
        if(parent_i != parent_j) {U[parent_i] = parent_j; ret = false;}
        return ret;
    }
    
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        
        std::vector<int> U(numCourses, -1);
        for(std::vector<int>& prerequisite: prerequisites) {
            int u_i = union_find(U, prerequisite[0]);
            int u_j = union_find(U, prerequisite[1]);
            bool ret = union_merge(U, u_i, u_j);
            if(ret) return false;
        }
        return true;
    }
    
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        bool ret = true;
        for(int i = 0; i < prerequisites.size(); i++){
            int src = prerequisites[i][0];
            for(int j = i+1; j < prerequisites.size(); j++) {
                int dst = prerequisites[j][1];
                if(src == dst) {
                    ret = false;
                    break;
                }
            }
            if(not ret) break;
        }
        return(ret);
    }
};

/*
 2 --> 0 <--1
^           |
|-----------

*/