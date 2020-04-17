/*
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;


int calculateHeight( int dist, int height1, int height2 )
{
    int  minH = min( height1, height2);
    int  maxH = max( height1, height2 );
    
    if( dist == 0 ) return 0;
    if( dist == 1 ) return minH + 1;
    
    // if both heights are same then meet in middle
    if(minH == maxH )
    {
        int add = ( dist%2 == 0 ) ? dist/2 : dist/2+1;
        return minH + add;
    }
        
    // See if we can make the height same 
    int delta = maxH-minH;
    if( delta < dist )
    {
        dist -= delta;
        minH += delta;
        int add = ( dist%2 == 0 ) ? dist/2 : dist/2+1;
        return minH+add;
    }
    
    // for all cases where delta >= dist
    return minH+dist;    
}

int maxHeight2( const vector<int>& positions, const vector<int>& heights )
{
    if( positions.empty() || heights.empty() || positions.size() != heights.size() )
    {
        return 0;
    }
    
    int result = 0;
    for(int i=1; i<positions.size(); ++i )
    {
        int currMax = calculateHeight( positions[i]-positions[i-1]-1, heights[i], heights[i-1] );
        result = max( result, currMax);
    }
    return result;
}


void mySort(vector<int>& tablePositions, vector<int>& tableHeights) {
    int sz = tablePositions.size();
    for(int i = 0; i < sz-1; i++) {
        for(int j = i+1; j < sz; j++) {
            if(tablePositions[i] > tablePositions[j]) {
                std::swap(tablePositions[i], tablePositions[j]);
                std::swap(tableHeights[i], tableHeights[j]);
            }
        }
    }
}

int maxHeight1(vector<int> tablePositions, vector<int> tableHeights) {
    if((tableHeights.size() != tableHeights.size()) or
       (tableHeights.empty() and tableHeights.empty())) return 0;
    //mySort(tablePositions, tableHeights);
    int sz = tableHeights.size();
    int maxH = 0;
    for(int i = 1; i < sz; i++) {
        int table1P = tablePositions[i-1];
        int table1H = tableHeights[i-1];
        int table2P = tablePositions[i];
        int table2H = tableHeights[i];
        printf("i=%d [%d %d] [%d %d]", i, table1P, table1H, table2P, table2H);
        int diff = table2P-table1P-1;
        if(table2P-table1P > 0) {    
            int hashtagH = INT_MAX;
            for(int j = 0; j < diff; j++) {
                printf("[(%d %d) %d ", j, hashtagH, diff);
                if(table1P+j==table1P and table1P+j+1==table2P) {
                    hashtagH = min(table1H, table2H)+1; 
                }
                else if(table1P+j==table1P) {
                    hashtagH = min(hashtagH, table1H)+1;
                }
                else if (table1P+j+1==table2P) {
                    hashtagH = min(hashtagH, table2H)+1;
                }
                else {printf("--"); hashtagH++;}
                printf("(%d %d) ]", j, hashtagH);
                if(hashtagH != INT_MAX and hashtagH > maxH) maxH = hashtagH;
            }
        }
        printf("-> %d\n", maxH);
    }
    return maxH;
}


int maxHeight(vector<int> tablePositions, vector<int> tableHeights) {
    if((tableHeights.size() != tableHeights.size()) or
       (tableHeights.empty() and tableHeights.empty())) return 0;
    //mySort(tablePositions, tableHeights);
    int sz = tableHeights.size();
    int maxH = 0;
    for(int i = 1; i < sz; i++) {
        int diff = tablePositions[i]-tablePositions[i-1]-1;
        if(diff > 1) {
            int maxC = 0;
            int low = min(tableHeights[i], tableHeights[i-1]);
            int high = max(tableHeights[i], tableHeights[i-1]);
            if(high >= low+diff) {
                maxC = low+diff;
            }
            else {
                int low1 = high+1;
                int high1 = diff+low;
                maxC = (low1+high1)/2;
            }
            maxH = max(maxH, maxC);
        }
    }
    
    return maxH;
}

int main() {
    //std::vector<int> tablePositions = {1, 2, 4 , 7};
    //std::vector<int> tableHeights = {4, 5, 7, 11};
    std::vector<int> tablePositions = {1, 10};
    std::vector<int> tableHeights = {1, 5};
    //std::vector<int> tablePositions = {1, 3, 7};
    //std::vector<int> tableHeights = {4, 3, 3};
    int r = maxHeight(tablePositions, tableHeights);
    printf("\n>>>%d\n", r);
}