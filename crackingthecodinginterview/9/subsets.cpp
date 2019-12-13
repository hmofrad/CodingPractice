/*
 *  Cracking the coding interview: Problem 9.4: Return all subsets of a set
 *  Compile & run: g++ -o subsets subsets.cpp -g -Wall -std=c++11 -fsanitize=address  && ./subsets
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>   

std::vector<std::vector<int32_t>> get_subsets(std::vector<int32_t> set, uint32_t index) {
    std::vector<std::vector<int32_t>> all_subsets;
    if(set.size() == index) {
        all_subsets.push_back({});
    }
    else {
        all_subsets = get_subsets(set, index+1);
        
        for(auto set: all_subsets) {
            for(auto s: set) {
                printf("%d ", s);
            }
            printf("\n");
        }
        printf("<%lu %d>\n", all_subsets.size(), index);
        
        
        
        std::vector<std::vector<int32_t>> more_subsets;
        for(auto& subset: all_subsets) {
            std::vector<int32_t> new_subset = subset;
            new_subset.push_back(set[index]);
            more_subsets.push_back(new_subset);
        }
        all_subsets.insert(all_subsets.begin(), more_subsets.begin(), more_subsets.end());
    }
    return(all_subsets);
}


int main(int argc, char** argv) {
    std::vector<int32_t> set = {0, 1, 2, 3};
 
    
    std::vector<std::vector<int32_t>> subs = get_subsets(set, 0);
    
    for(auto set: subs) {
        for(auto s: set) {
            printf("%d ", s);
        }
        printf("\n");
    }
    printf(" %lu\n", subs.size());
    
    return(0);
}