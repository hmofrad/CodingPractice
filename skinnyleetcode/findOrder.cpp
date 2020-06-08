/*
 * https://leetcode.com/problems/course-schedule-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool dfs(std::unordered_map<int, std::vector<int>>& courses, int index, std::vector<bool>& visited, std::vector<bool>& visited0, std::vector<int>& path) {
        if(visited[index]) {return false;}
        if(visited0[index]) {return true;}
        
        visited[index]=true;
        visited0[index]=true;
        bool ret = true; 
        for(int i: courses[index]) {
            ret &= dfs(courses, i, visited, visited0, path);
            if(not ret) {return false;}
        }
        path.push_back(index);
        visited[index]=false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //numCourses = 3;
        //prerequisites = {{0,1},{0,2},{1,2}};
        //prerequisites = {{0,1}};
        std::unordered_map<int, std::vector<int>> courses(numCourses);
        for(std::vector<int>& prerequisite: prerequisites) {
            courses[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        std::vector<bool> visited(numCourses);
        std::vector<bool> visited0(numCourses);
        std::vector<int> path;
        for(int i = 0; i < numCourses; i++) {
            bool ret = dfs(courses, i, visited, visited0, path);
            
            if(not ret) return std::vector<int>();
        }
        for(int& p: path) printf("%d ", p); printf("\n");
        return path;
    }
};