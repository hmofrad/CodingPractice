/*
 *  https://leetcode.com/problems/construct-quad-tree/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:


    Node* construct10 (vector<vector<int>>& grid, std::vector<int> topLeft, std::vector<int> bottomRight, int n) {
        int startRow = topLeft[0];
        int endRow = bottomRight[0];
        int startCol = topLeft[1];
        int endCol = bottomRight[1];
        std::vector<int> count(2);
        for(int i = startRow; i <= endRow; i++) {
            for(int j = startCol; j <= endCol; j++) {
                count[grid[i][j]]++;
            }
        }
        
        if(not (count[0] * count[1])) return new Node((count[0]) ? 0 : 1, 1);
        
        if(n==1) return new Node(grid[topLeft[0]][topLeft[1]],1);
        
        Node* node = new Node(1, 0);
        
        //node->topLeft = construct1(grid, {startRow, startCol}, {endRow/2, endCol/2}, n/2);
        //node->topRight = construct1(grid, {startRow, endCol/2}, {endRow/2,endCol},n/2);
        //node->bottomLeft = construct1(grid, {endRow/2,startCol}, {endRow,endCol/2},n/2);
        //node->bottomRight = construct1(grid, {endRow/2, endCol/2},{endRow, endCol},n/2);

        
        node->topLeft = construct10(grid, topLeft, {bottomRight[0]-n/2, bottomRight[1]-n/2}, n/2);
        node->topRight = construct10(grid, {topLeft[0], topLeft[1]+n/2}, {bottomRight[0]-n/2, bottomRight[1]},n/2);
        node->bottomLeft = construct10(grid, {topLeft[0]+n/2, topLeft[1]}, {bottomRight[0], bottomRight[1]-n/2}, n/2);
        node->bottomRight = construct10(grid, {topLeft[0]+n/2, topLeft[1]+n/2}, bottomRight,n/2);
        
        return node;
    }
    
    
    Node* construct(vector<vector<int>>& grid) {
        int nrows = grid.size();
        if(nrows == 1) return new Node(grid[0][0],1);
        
        return construct10(grid, {0,0}, {nrows-1,nrows-1}, nrows);
    }
    
    
    
    bool verify(vector<vector<int>>& grid, std::vector<int> topLeft, std::vector<int> bottomRight) {
        
        int startRow = topLeft[0];
        int endRow = bottomRight[0];
        int startCol = topLeft[1];
        int endCol = bottomRight[1];
        //printf("1.%d %d %d %d\n", startRow, endRow, startCol, endCol);
        int gridSum = 0;
        for(int i = startRow; i < endRow; i++) {
            for(int j = startCol; j < endCol; j++) {
                gridSum += grid[i][j];
            }
        }
        //printf("%d %d\n", gridSum, ((endRow-startRow) * (endCol-startCol)));
        return gridSum ? (gridSum - ((endRow-startRow) * (endCol-startCol))) == 0 : true;
    }
    //int i = 0;
    Node* construct1(vector<vector<int>>& grid, std::vector<int> topLeft, std::vector<int> bottomRight, int n) {
        //if(n==0) return nullptr;
        //if()
        Node* node = nullptr;
        if(verify(grid, topLeft, bottomRight)) {
            int startRow = topLeft[0];
            int endRow = bottomRight[0];
            int startCol = topLeft[1];
            int endCol = bottomRight[1];
            //printf("done:%d %d %d %d\n", startRow, endRow, startCol, endCol);
            //printf("Done\n" );
            return new Node(grid[startRow][startCol], true, nullptr, nullptr, nullptr, nullptr); 
            //i++;
            //if(i == 5)  std::exit(0);
        }
        else {
            int startRow = topLeft[0];
            int endRow = bottomRight[0];
            int startCol = topLeft[1];
            int endCol = bottomRight[1];
            
            if(n==0) return new Node(grid[startRow][startCol], 1);
            
            //printf("%d %d %d %d\n", startRow, endRow, startCol, endCol);
            /*
            printf("%d %d %d %d\n", startRow, endRow, startCol, endCol);
            printf("%d %d %d %d\n", startRow, startCol, endRow/2, endCol/2);
            printf("%d %d %d %d\n", startRow, endCol/2, endRow/2,endCol);
            printf("%d %d %d %d\n", endRow/2,startCol, endRow, endCol/2);
            printf("%d %d %d %d\n", endRow/2, endCol/2, endRow, endCol);
            //std::exit(0);
            */
            //Node* topLeft1 = nullptr;
            //Node* topRight1 = nullptr;
            //Node* bottomLeft1 = nullptr;
            //Node* bottomRight1 = nullptr;
            //node = (0, false, topLeft1, topRight1, bottomLeft1, bottomRight1);
            
            
            
            Node* topLeft1 = construct1(grid, {startRow, startCol}, {endRow/2, endCol/2}, n/2);
            Node* topRight1 = construct1(grid, {startRow, endCol/2}, {endRow/2,endCol},n/2);
            Node* bottomLeft1 = construct1(grid, {endRow/2,startCol}, {endRow,endCol/2},n/2);
            Node* bottomRight1 = construct1(grid, {endRow/2, endCol/2},{endRow, endCol},n/2);
            node = new Node(1, false, topLeft1, topRight1, bottomLeft1, bottomRight1);
            /*node = new Node(false, false, construct1(grid, {startRow, startCol}, {endRow/2, endCol/2}),
                                  construct1(grid, {startRow, endCol/2}, {endRow/2,endCol}), 
                                  construct1(grid, {endRow/2,startCol}, {endRow,endCol/2}), 
                                  construct1(grid, {endRow/2, endCol/2},{endRow, endCol}));*/
            //printf("%p\n", topLeft1);
        }

        return(node);
    }
    Node* construct2(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        /*
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
        Node* qtree = construct1(grid, {0,0}, {nrows, ncols}, nrows);
        return qtree;
    }
};