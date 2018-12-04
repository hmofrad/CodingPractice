/*
 *  Problem: Implement Pow(x, n)
 *  Compile: g++ -o merge merge.cpp -std=c++11 && ./merge
 *  Execute: ./merge
 *  (c) Mohammad Mofrad, 2018
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

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(const Interval &i1, const Interval i2)
{
    return((i2.start <= i1.end and i2.end >= i1.end) or (i1.start <= i2.end and i1.end >= i2.end));
}

bool compare(const Interval &i1, const Interval i2)
{    
    return((i1.start == i2.start) ? (i1.end < i2.end) : (i1.start < i2.start));
}

std::vector<Interval> merge(std::vector<Interval>& intervals) {
    int n = intervals.size();
    
    std::vector<bool> status(n);
    std::vector<Interval> merged;
    
    if(n == 0 or n == 1)
        return(intervals);
    
    std::sort(intervals.begin(), intervals.end(), compare);
    printf("\n");
    for(Interval &i: intervals)
    {
        std::cout << "[" << i.start << "," << i.end << "]" << std::endl;
    }
    printf("\n");
    
    //for(int i = 1; i < n; i++)
    int i = 0;    
    while(true)    
    {
        printf("i=%d, i+1=%d\n", i, i+1);
        //std::cout << "compareInterval(" << i << "):" << compareInterval(intervals[i], intervals[i+1]) << std::endl;
        if(compareInterval(intervals[i], intervals[i+1]))
        {
            Interval test = {intervals[i].start, intervals[i+1].end};
            merged.push_back(test);
            i = i + 2;
        }
        else
        {
            merged.push_back(intervals[i]);
            i++;
        }
        if(i == n)
            break;
    }
    
    return(merged);
    
        
}

int main(int argc, char **argv)
{
    //std::vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<Interval> intervals = {{0,2},{2,3},{4,4},{0,1},{5,7},{4,5},{0,0}};
    for(Interval &i: intervals)
    {
        std::cout << "[" << i.start << "," << i.end << "]" << std::endl;
    }
    printf("\n");
    std::vector<Interval> merged = merge(intervals);
    for(Interval &i: merged)
    {
        std::cout << "[" << i.start << "," << i.end << "]" << std::endl;
    }
    return(0);
}