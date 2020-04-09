/*
 *  https://leetcode.com/problems/synonymous-sentences/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


bool find1(std::vector<std::string> str1, std::vector<std::string> str2) {
    bool matched = false;
    std::set<std::string> s(str1.begin(), str1.end());
    for(std::string str: str2) {
        if(s.count(str)) {matched = true; break;} 
    }
    return(matched);
}

void merge(std::vector<std::vector<std::string>>& synonyms1, std::vector<std::vector<string>> synonyms, std::vector<int> merges) {
    std::vector<std::string> synonym1;
    for(int index: merges) {
        for(std::string synonym: synonyms[index]) {
            if(std::find(synonym1.begin(), synonym1.end(), synonym) == synonym1.end()) synonym1.push_back(synonym);
        }
    }
    synonyms1.push_back(synonym1);
}

std::vector<std::string> tokenize(std::string text) {
    int size = text.length();
    std::vector<std::string> text1;
    int i = 0;
    int j = 0;
    while(i < size) {
        char c = text[i];
        if(c == ' ') {
            int len = i-j;
            std::string str = text.substr(j, len);
            text1.push_back(str);
            j=i+1;
        }
        i++;
    }
    
    int len = i-j+1;
    std::string str = text.substr(j, len);
    text1.push_back(str);
    return(text1);
}

//void permutation(std::vector<std::string>& ans, std::vector<std::vector<std::string>> synonyms1, std::vector<string> text1, std::string str, int index, int index1);


void permutation(std::vector<std::string>& ans, std::vector<std::vector<std::string>> synonyms1, std::vector<string> text1, std::vector<string> text2, int index1, int index2, std::string str) {
    int size = text1.size();
        //printf("%s %d %d %d\n", str.c_str(), index, index1, size);
    if(index1 == size) {
        ans.push_back(str);
        return;
    }
    std::string space = (index1) ? " " : "";
    if(not text1[index1].empty()) {
        str += space + text1[index1];
        permutation(ans, synonyms1, text1, text2, index1+1, index2, str);
    }
    else {
        int index3 = 0;
        for(int j = 0; j < synonyms1.size(); j++) {
            if(std::find(synonyms1[j].begin(), synonyms1[j].end(), text2[index2]) != synonyms1[j].end()) {
                index3 = j;
                break;
            }
        }
        
        
        for(int i = 0; i < synonyms1[index3].size(); i++) {
            std::string str1 = str +  space + synonyms1[index3][i];
            permutation(ans, synonyms1, text1, text2, index1+1, index2+1, str1);
        }
    }
}


std::vector<std::string> generateSentences(std::vector<std::vector<std::string>>& synonyms, string text) {
    
    vector<vector<string>> synonyms1;
    while(not synonyms.empty()) {
        std::vector<int> merges;
        int size = synonyms.size();
        
        merges.push_back(0);
        for(int j = 1; j < size; j++) {
            if(find1(synonyms[0], synonyms[j])) {
                //printf("%d\n",  j);
                merges.push_back(j);
            }
        }
        
        //printf("0.%d %d\n", synonyms.size(), merges.size());
        merge(synonyms1, synonyms, merges);
        //printf("1.%d %d\n", synonyms.size(), merges.size());
        for(int i = 0; i < merges.size(); i++) {
            int j = merges[i]-i;
            synonyms.erase(synonyms.begin()+j);
        }
        //printf("2.%d %d\n", synonyms.size(), merges.size());
    }
    
    for(std::vector<std::string>& sys: synonyms1) {
        std::sort(sys.begin(), sys.end());
    }
    
    /*
    for(std::vector<std::string> synonyms: synonyms1) {
        for(std::string synonym: synonyms) {
            printf("%s ", synonym.c_str());
        }
        printf("\n");
    }
    */
    
    std::vector<std::string> text1 = tokenize(text);
    
    /*
    for(std::string txt: text1) {
        printf("%s ", txt.c_str());
    }
    printf("\n");
    
    
      for(std::vector<std::string> synonyms: synonyms1) {
        for(std::string synonym: synonyms) {
            printf("%s ", synonym.c_str());
        }
        printf("\n");
    }
    */
    
    std::vector<int> indices1(synonyms1.size(),-1);
    std::vector<std::string> text2;
    //std::vector<std::vector<int>> indices(synonyms1.size());
    for(int i = 0; i < text1.size(); i++) {
        for(int j = 0; j < synonyms1.size(); j++) {
            if(std::find(synonyms1[j].begin(), synonyms1[j].end(), text1[i]) != synonyms1[j].end()) {
                text2.push_back(text1[i]);
               text1[i].clear();
                
                //indices[j].push_back(i);  
                indices1[j] = i;
                //printf("%d\n", j);
                //indices1.push_back(j);
            }
        }
    }
    
    
    for(int i = 0; i < synonyms1.size()-1; i++) {
        for(int j = i+1; j < synonyms1.size(); j++) {
            if(indices1[i] > indices1[j]) {std::swap(synonyms1[i],synonyms1[j]); std::swap(indices1[i], indices1[j]);}
        }
    }
    
    int index1=0;
    for(int i = 0; i < indices1.size(); i++) {
        if(indices1[i] == -1) index1++;
        else break;
    }
    
    /*
    for(std::vector<std::string> synonyms: synonyms1) {
        for(std::string synonym: synonyms) {
            printf("%s ", synonym.c_str());
        }
        printf("\n");
    }
    
    
    for(int index: indices1) {
        printf("%d ", index);
    }
    printf("\n");
    for(std::string txt: text1) {
        printf("%s ", txt.c_str());
    }
    printf("\n");
    */

    
    
    /*
    for(int i = 0; i < indices.size(); i++) {
        printf("%d ", i);
        for(int j = 0; j < indices[i].size(); j++) {
            printf("%d", indices[i][j]);
        }
        printf("\n");
    }
    */
    /*
    int n = synonyms1[0].size();
    for(int i = 1; i < synonyms1.size(); i++) {
        n *= synonyms1[i].size();
    }
    //printf("%d\n", n);
    std::vector<std::vector<std::string>> temps(n);
    
    for(int i = 0; i < n; i++) {
        int k = 0;
        for(int j = 0; j < text1.size(); j++) {
            if(k < indices1.size() and j == indices1[k]) {std::string empty; temps[i].push_back(empty);k++;}
            else temps[i].push_back(text1[j]);
        }
    }
    
    for(int i = 0; i < temps.size(); i++) {
        for(int j = 0; j < temps[i].size(); j++) {
            printf("<%s> ", temps[i][j].c_str());
        }
        printf("\n");
    }
    
    
    
    
    
    for(int i = 0; i < synonyms1.size(); i++) {
        printf("[");
        for(int j = 0; j < synonyms1[i].size(); j++) {
            printf("%s ", synonyms1[i][j].c_str());
        }
        printf("]\n");
    }
    */
    std::vector<std::string> ans;
    //printf(">>>>>>\n");
    permutation(ans, synonyms1, text1, text2, 0, 0, "");
    //printf("<<<<<<<<<<<<<\n");
    
    for(std::string a: ans) {
        printf("<%s>\n", a.c_str());
    }
    
    return(ans);
}

int main() {
    //std::vector<std::vector<std::string>> synonyms = {{"honey", "bee"}, {"happy","joy"},{"sad","sorrow"},{"joy","cheerful"},{"cow","donkey"}};
    //std::string text = "I am happy today but was sad yesterday";
    
    std::vector<std::vector<std::string>> synonyms = {{"v","yr"}};
      std::string text =  "v v v v yZ";
    
    
    std::vector<string> out = generateSentences(synonyms, text);
    return(0);
}
