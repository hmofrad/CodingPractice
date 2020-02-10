/*
 *  Problem: https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/
 *  Given a text txt[0..n-1] and a pattern pat[0..m-1], 
 *  write a function search(char pat[], char txt[]) that prints all occurrences of pat[]
 *  and its permutations (or anagrams) in txt[]. You may assume that n > m. Expected time complexity is O(n)
 *  Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
 *  Compile: gcc -o anagramSubstringSearch anagramSubstringSearch.c -g -Wall -fsanitize=address && ./anagramSubstringSearch    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
1) Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
   Output:   Found at Index 0
             Found at Index 5
             Found at Index 6
2) Input: txt[] =  "AAABABAA" pat[] = "AABA"
   Output:   Found at Index 0
             Found at Index 1
             Found at Index 4
*/

int search1(char txt[], int n, char pat[], int m, int index, int dic[], int l, int sum) {
    for(int j = index; j < index+m; j++) {
        if((--dic[txt[j]-'A']) < 0) {
            return(0);    
        }
        sum--;
    }
    return(sum == 0);
}


void search(char txt[], int n, char pat[], int m) {
    const int NUM_ALPHAS = 26;
    int dic[NUM_ALPHAS];
    int s = 0;
    memset(dic, 0, NUM_ALPHAS * sizeof(int));
    for(int i = 0; i < m; i++) {
        dic[pat[i]-'A']++;
        s++;
    }
    
    for(int i = 0; i < n-m+1; i++) {
        int dic1[NUM_ALPHAS];
        memcpy(dic1, dic, NUM_ALPHAS * sizeof(int));
        int r = search1(txt, n, pat, m, i, dic1, NUM_ALPHAS, s);
        printf("index=%d c=%c r=%d\n", i, txt[i], r);
    }
}

int main(int argc, char **argv){
    char txt[] = "BACDGABCDA";
    int n = strlen(txt);//sizeof(txt)/sizeof(txt[0]);
    char pat[] = "ABCD";
    int m = strlen(pat);//sizeof(pat)/sizeof(pat[0]);
    search(txt, n, pat, m);
    return(0);
}
