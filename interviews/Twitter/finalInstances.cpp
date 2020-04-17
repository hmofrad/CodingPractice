/*
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


int finalInstances(int instances, std::vector<int> averageUtil) {
    if(averageUtil.empty() or instances == 0) return 0;
    const int maxInstances = 2 * 1e8;
    const int high =60;
    const int low = 25;
    const int sz = averageUtil.size();
    int i = 0;
    while(i < sz) {
        int load = averageUtil[i++];
        if(load > high and instances < maxInstances) {
            int newInstances = instances*2;
            instances = (newInstances <= maxInstances) ? newInstances : instances;
            i = (newInstances <= maxInstances) ? i+10 : i;
        }
        else if(load < low and instances > 1) {
            instances = (instances + 2 -1)/2;
            i = (instances > 1) ? i+10 : i;
        }
    }

    return instances; 
}

int main() {
    int n = 46;
    std::vector<int> a = {73,77,53,75,22,55,84,45,40,80,66,54,39,68,23,54,22,11,91,47,56,91,97,5,44,62,73,26,99,96,74,4,0,8,56,3,21,37,94,83,68,91,83,41,22,81,59,37,29,93,8,88,41,94,62,63,97,73,46,80,91,65,69,52,31,35,81,60,44,8,80,75,94,16,45,12,29,22,59,88,87,55,43,67,8,15,26,31,99,35,99,1,98};
    //std::vector<int> a = {30, 5, 4, 8, 19, 89};//{5, 10, 80};
    int r = finalInstances(n, a);
    printf("\n>>>%d\n", r);
}