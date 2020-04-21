/*
 *  https://leetcode.com/problems/index-pairs-of-a-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
    
struct Trie {
    public:
    Trie() {trie.resize(26); isLeaf = false;}
    ~Trie(){}
    std::vector<struct Trie*> trie;
    bool isLeaf;
};

void put(struct Trie* head, std::string word) {
    struct Trie* curr = head;
    int length = word.length();
    for(int i = 0; i < length; i++) {
        int j = word[i]-'a';
        if(not curr->trie[j]) {
            curr->trie[j] = new Trie();
        }
        curr = curr->trie[j];
    }
    curr->isLeaf = true;
}

std::vector<std::vector<int>> find(struct Trie* head, std::string text, int k) {
    std::vector<std::vector<int>> temp;
    struct Trie* curr = head;
    int length = text.length();
    for(int i = k; i < length; i++) {
        int j = text[i]-'a';
        //printf("1.%d %c\n", j, text[i]);
        if(not curr->trie[j]) {break;}
        //printf("2.%d %c\n", j, text[i]);
        curr = curr->trie[j];
        //printf("3.%d %c\n", j, text[i]);
        if(curr->isLeaf) {temp.push_back({k, i});}
        //printf("4.%d %c %d\n", j, text[i], curr->isLeaf);
    }
    return temp;
}

vector<vector<int>> indexPairs(string text, vector<string>& words) {
    struct Trie* head = new Trie();
    
    for(std::string word: words) {
        put(head, word);
    }
    
    std::vector<std::vector<int>> anses;
    int length = text.length();
    
    for(int i = 0; i < length; i++) {
    //    printf("%s: %c %lu\n", text.c_str(), text[i], anses.size());
        std::vector<std::vector<int>> temp = find(head, text, i);
        if(not temp.empty()) anses.insert(anses.end(),temp.begin(), temp.end());
        //break;
    }
    
    return anses;
}
//[[0,1],[0,2],[2,3],[2,4]]
int main() {
    std::string text = "ababa";
    std::vector<std::string> words = {"aba","ab"};
    std::vector<std::vector<int>> anses = indexPairs(text, words);
    for(std::vector<int> ans: anses) {
        printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}
