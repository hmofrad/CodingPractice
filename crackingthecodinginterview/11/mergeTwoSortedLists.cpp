/*
 *  Cracking the coding interview: Problem 11.1: Merge two sorted lists
 *  Compile & run: g++ -o mergeTwoSortedLists mergeTwoSortedLists.cpp -g -Wall && ./mergeTwoSortedLists
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

void mergeTwoSortedLists(std::vector<int>& A, std::vector<int> B) {
    int i = 0;
    int k = 0;
//    for(auto b: B) {
    for(k = 0; k < B.size(); k++) {    
        auto b = B[k];
        while(A[i] < b and i < A.size()) i++;
        if(i < A.size()) {
            for(int j = A.size()-1; j > i; j--) {
                A[j] = A[j-1];
            }
            printf("%d %d\n", k, i);
            A[i] = b;
        }
        else
            break;
    }
    for(;k<B.size();k++){
        
        A[(A.size()-1) - (B.size()-k-1)] = B[k];
    }
}


void merge(std::vector<int>& A, std::vector<int> B, int lastA, int lastB) {
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int indexM  = lastA + lastB - 1;
    
    while(indexB >= 0) {
        if(indexA >= 0 and A[indexA] > B[indexB]) {
            A[indexM] = A[indexA];
            indexA--;
        }
        else {
            A[indexM] = B[indexB];
            indexB--;
        }
        indexM--;
    }
}


int main(int argc, char** argv) {
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0};
    int lastA = 7;
    std::vector<int> B = {0, 2, 5, 8, 10};
    int lastB = B.size();
    for(auto& a: A) printf("%d ", a); printf("\n");
    for(auto& b: B) printf("%d ", b); printf("\n");
    //mergeTwoSortedLists(A,B);
    merge(A,B, lastA, lastB);
    for(auto& a: A) printf("%d ", a); printf("\n");
    for(auto& b: B) printf("%d ", b); printf("\n");
    return(0);
}