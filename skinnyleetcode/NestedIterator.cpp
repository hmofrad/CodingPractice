/*
 *	https://leetcode.com/problems/flatten-nested-list-iterator/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class NestedIterator {
public:
    std::stack<NestedInteger> stack;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i>=0; i--) {stack.push(nestedList[i]);}
    }
    
    void update() {
        
    }
    
    int next() {
        int v = stack.top().getInteger(); stack.pop();
        return v;
    }

    bool hasNext() {
        while(not stack.empty() and not stack.top().isInteger()) {
            std::vector<NestedInteger> nestedList = stack.top().getList(); stack.pop();
            for(int i = nestedList.size()-1; i >= 0; i--) {
                stack.push(nestedList[i]);
            }
        }
        
        
        return not stack.empty();
    }
};


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator1 {
public:
    std::vector<int> vec;
    int index = 0;
    int size = 0;
    
    std::vector<int> myGetList(vector<NestedInteger>& nestedList) {
        std::vector<int> ans;
        for(NestedInteger& nestedList_: nestedList) {
            //printf("%d\n", nestedList_.isInteger());
            if(nestedList_.isInteger()) ans.push_back(nestedList_.getInteger());
            else {
                std::vector<int> temp = myGetList(nestedList_.getList());
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
        }
        return ans;
    }
    
    NestedIterator1(vector<NestedInteger> &nestedList) {
        vec = myGetList(nestedList);
        size = vec.size();
        //printf("size=%d\n", size);
    }

    int next() {
        index++;
        return vec[index-1];
    }

    bool hasNext() {
        return index<size;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */