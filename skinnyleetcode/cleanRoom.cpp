/*
 * https://leetcode.com/problems/robot-room-cleaner/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    std::set<std::pair<int,int>> visited;
    std::vector<std::vector<int>> directions = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};
    void go_back(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void backtrack(Robot& robot, int row, int col, int dir) {
        visited.insert({row,col});
        robot.clean();
        
        for(int i = 0; i < 4; i++) {
            int j = (dir+i)%4;
            int r = row + directions[j][0];
            int c = col + directions[j][1];
            
            if(visited.count({r,c}) == 0 and robot.move()) {backtrack(robot, r, c, j); go_back(robot);}
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
};