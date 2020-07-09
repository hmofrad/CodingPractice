/*
 * https://leetcode.com/problems/design-snake-game/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class SnakeGame {
public:
    int index = 0;
    int score = 0;
    int width = 0;
    int height = 0;
    vector<vector<int>> food;
    std::unordered_set<int> set;
    std::deque<int> snake;
    SnakeGame(int width_, int height_, vector<vector<int>>& food_) {
        width = width_;
        height = height_;
        food = food_;
        set.insert(0);
        snake.push_back(0);   
    }
    int move(string direction) {
        if(score == -1) { return score; }
        
        int row  = snake.back()/width; 
        int col  = snake.back()%width; 
        int r = snake.front()/width;
        int c = snake.front()%width;
        set.erase(snake.front());
        snake.pop_front();
        
        if(direction == "U")      { row--; }
        else if(direction == "D") { row++; }
        else if(direction == "L") { col--; }
        else if(direction == "R") { col++; }
        int pos = row*width + col;
        
        if(row<0 or row>=height or col<0 or col>=width or set.count(pos)) { score = -1; return score; }
        
        
        if(index < food.size() and food[index][0] == row and food[index][1] == col) {
            index++;
            score++;
            int p = r*width + c;
            set.insert(p);
            snake.push_front(p);
        }
        
        snake.push_back(pos);
        set.insert(pos);
        
        return score;
    }
    };
class SnakeGame0 {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int width = 0;
    int height = 0;
    int index = 0;
    deque<pair<int,int>> snake;
    vector<vector<int>> food;
    std::vector<std::vector<char>> grid;
    SnakeGame0(int width_, int height_, vector<vector<int>>& food_) {
        width = width_;
        height = height_;
        grid.resize(height);
        for(std::vector<char>& row: grid) { row.resize(width, '\0'); }
        grid[0][0] = 's';
        snake.push_back({0, 0});
        food = food_;
        if(not food.empty()) {
            int r = food[0][0];
            int c = food[0][1];
            grid[r][c] = 'f';
        }
        
    }
    
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    bool check(int r, int c) {
        if(r<0 or r>=height or c<0 or c>=width or grid[r][c] == 's' ) { return false; }
        return true;
    }
    
    void scavenge(int row_prev, int col_prev, int row_curr, int col_curr) {
        if(grid[row_curr][col_curr] == 'f') {
            index++;
            if(index < food.size()) {
                int r = food[index][0];
                int c = food[index][1];
                grid[r][c] = 'f';
            }
        }
        else {
            int r = snake.front().first;
            int c = snake.front().second;
            grid[r][c]='\0';
            snake.pop_front();
        }
        grid[row_curr][col_curr] = 's';
        snake.push_back({row_curr, col_curr});
    }
    
    int move(string direction) {
        
        int row = snake.back().first;
        int col = snake.back().second;
        printf("move %s %d [%d %d] %c\n", direction.c_str(), index, row, col, grid[row][col]);
        if(direction == "U") {
            if(check(row-1, col)) { scavenge(row, col, row-1, col); }
            else return -1;
        }
        else if(direction == "L") {
            if(check(row, col-1)) { scavenge(row, col, row, col-1); }
            else return -1;
        }
        else if(direction == "R") {
            if(check(row, col+1)) { scavenge(row, col, row, col+1); }
            else return -1;
        }
        else if(direction == "D") {
            if(check(row+1, col)) { scavenge(row, col, row+1, col); }
            else return -1;
        }

        return index;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */