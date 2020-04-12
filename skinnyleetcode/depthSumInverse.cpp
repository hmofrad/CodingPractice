/*
 *  https://leetcode.com/problems/nested-list-weight-sum-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:

    
    int getDepth1(NestedInteger nestedList) {
        if(nestedList.isInteger()) return 1;
        int d = 0;
        for(NestedInteger list: nestedList.getList()) {
            d = max(d, getDepth1(list)+1);
        }
        return(d);
    }
    
    int getDepth(std::vector<NestedInteger> nestedList) {
        int d = 0;        
        for(NestedInteger list: nestedList) {
            d = max(d, getDepth1(list));
        }
        return d;
    }
    
    
    int sumList(NestedInteger list, int maxDepth, int depth) {
       // printf("%d %d\n", maxDepth, depth);
        if(list.isInteger()) return(list.getInteger() * abs(maxDepth - depth));
        int sum = 0;
        std::vector<NestedInteger> list1 = list.getList();
        for(NestedInteger l: list1) {
            if(not l.isInteger()) sum += list.getInteger() * abs(maxDepth - depth);
            else sum += sumList(l, maxDepth, depth+1);
        }
        //printf("sum-%d\n", sum);
        return(sum);
    }
    
    
    int getDepth3(vector<NestedInteger> nestedList) {
        int d = 1;
        for(NestedInteger list: nestedList) {
            if(not list.isInteger()) {
                d = max(d, getDepth3(list.getList())+1);
            }
        }
        return(d);
    }    
    
    int sumList(vector<NestedInteger> nestedList, int maxDepth, int depth) {
        int sum = 0;
        for(NestedInteger list: nestedList) {
            if(list.isInteger()) {
                sum += list.getInteger() * (maxDepth-depth+1);
            }
            else {
                sum += sumList(list.getList(), maxDepth, depth+1);
            }
        }
        return(sum);
    }
    
    
    
    
    
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        
        int d = getDepth3(nestedList);
        int s = sumList(nestedList, d, 1);
       // printf("Depth=%d\n", d);
      //  for(NestedInteger list: nestedList) {
         //   printf("%d\n", s);
        //    s += sumList(list, d, 0);
            
        //}

        //printf("depth=%d\n", d);
        return s;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
};