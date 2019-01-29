/*
 *  Problem: numMagicSquaresInside
 *  Compile & excute: g++ -o numMagicSquaresInside numMagicSquaresInside.cpp -std=c++11 && ./numMagicSquaresInside
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
    int w = 3;
    int nysubgrids = 0;
    int nxsubgrids = 0;
    if(grid.size()) {
        nysubgrids = grid.size() - w + 1;
        nxsubgrids = grid[0].size() - w + 1;
    }
    int num = 0;
    bool unique = true;
    bool equal = true;
    
    //printf("%d %d\n", nxsubgrids, nysubgrids);
    
    for(int i = 0; i < nysubgrids; i++) {
        for(int j = 0; j < nxsubgrids; j++) {
            int ii0 = i;
            int ii1 = i + w;
            int jj0 = j;
            int jj1 = j + w;
            printf("%d %d %d %d\n", ii0, ii1, jj0, jj1);
            for(int k = i; k < i + w; k++) {
                for(int l = j; l < j + w; l++) {    
                    int number = grid[k][l];
                    printf("number=%d %d %d\n", number, i, j);
                    if((number > 9) or (number < 1)) {
                        printf("num=%d\n", number);
                        //unique = false;
                        //break;
                    }
                    for(int m = i; m < i + w; m++) {
                        for(int n = j; n < j + w; n++) {    
                            if(number == grid[m][n]) {
                                if((k != m) and (l != n)) {
                                    unique = false;
                                    break;
                                }
                            }
                        }
                        if(not unique) {
                            break;
                        }
                    }
                    if(not unique)
                        break;
                }
                if(not unique)
                    break;
            }
            if(unique) {
                std::vector<int> sRow(w);
                std::vector<int> sCol(w);
                std::vector<int> sDia(w-1);
                //int sumRow = 0;
                //int sumCol = 0;
                //int sDiag = 0;
                //printf("xxxxx %d %d %d %d %d\n", num, unique, equal, i, j);
                for(int k = i; k < i + w; k++) {
                    for(int l = j; l < j + w; l++) {    
                        sRow[k-i] += grid[k][l];
                        sCol[l-j] += grid[k][l];
                    }
                }
                /*
                int d = 0;
                sDia[d] += grid[i+0][j+0];
                sDia[d] += grid[i+1][j+1];
                sDia[d] += grid[i+2][j+2];
                d = 1;
                sDia[d] += grid[i+w-1][j+w-3];
                sDia[d] += grid[i+w-2][j+w-2];
                sDia[d] += grid[i+w-3][j+w-1];
                */
                int d = 0;
                int di = 0;
                int dj = 0;
                for(int k = i; k < i + w; k++) {    
                    sDia[d] += grid[k][j+dj];
                    dj++;
                    sDia[d+1] += grid[k][j+w-dj];
                    //dj++;
                    
                }
                
                for(int k = 0; k < w - 2; k++) {
                    if(sDia[k] != sDia[k+1]) {
                        equal = false;
                        break;
                    }
                }
                printf("Dia: %d %d\n", sDia[0], sDia[1]);
                printf("Row: %d %d %d\n", sRow[0], sRow[1], sRow[2]);
                printf("Col: %d %d %d\n", sCol[0], sCol[1], sCol[2]);
                if(equal) {                
                    
                    for(int k = 0; k < w - 1; k++) {
                        if(sRow[k] != sRow[k+1]) {
                            equal = false;
                            break;
                        }
                    }
                    if(equal) {
                        for(int l = 0; l < w - 1; l++) {
                            if(sCol[l] != sCol[l+1]) {
                                equal = false;
                                break;
                            }
                        }
                        if(equal) {
                            for(int k = 0; k < w; k++) {
                                if(sRow[k] != sCol[k]) {
                                    equal = false;
                                    break;
                                }
                            }
                            /*
                            if(equal) {
                                for(int k = 0; k < w; k++) {
                                
                            }
                            */
                        }
                    }
                    if(equal)
                        num++;
                    else 
                        equal = true;
                }
            }
            else
                unique = true;
            
        }
            
    }
    
    
    return(num);
}
int main(int argc, char** argv) {
    //std::vector<std::vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    std::vector<std::vector<int>> grid = {{8,0,7,4,3,2},{1,10,4,4,3,8},{8,5,2,9,5,1},{6,0,9,2,7,6},{9,0,6,9,5,1},{4,2,1,4,3,8}};
    //std::vector<std::vector<int>> grid = {{7, 0, 5}, {2, 4, 6}, {3,8 , 1}};
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {    
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("numMagicSquaresInside? %d\n", numMagicSquaresInside(grid));
    return(0);
}