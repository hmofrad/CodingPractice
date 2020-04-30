/*
 *  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
The intuition for this problem, stems from the fact that

a) Without considering the limiting limiting days D, if we are to solve, the answer is simply max(a)
b) If max(a) is the answer, we can still spend O(n) time and greedily find out how many partitions it will result in.

[1,2,3,4,5,6,7,8,9,10], D = 5

For this example, assuming the answer is max(a) = 10, disregarding D,
we can get the following number of days:
[1,2,3,4] [5] [6] [7] [8] [9] [10]

So by minimizing the cacpacity shipped on a day, we end up with 7 days, by greedily chosing the packages for a day limited by 10.

To get to exactly D days and minimize the max sum of any partition, we do binary search in the sum space which is bounded by [max(a), sum(a)]

Binary Search Update:
One thing to note in Binary Search for this problem, is even if we end up finding a weight, that gets us to D partitions, we still want to continue the space on the minimum side, because, there could be a better minimum sum that still passes <= D paritions.

In the code, this is achieved by:

if res <= d:
     hi = mid
With this check in place, when we narrow down on one element, lo == hi, we will end up with exactly the minimum sum that leads to <= D partitions.
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights,  int D) {
        int right = std::accumulate(weights.begin(), weights.end(), 0); // largest_capacity
        int left = *std::max_element(weights.begin(), weights.end()); //  max(right/D, ..) smallest_capacity
        
        while(left < right) {
            int mid = (left+right)/2;
            
            int total=0, days=1;
            for(int& w: weights) {
                if(total+w>mid) days++, total=w;
                else total+=w;
            }
            if(days<=D) right=mid;
            else left=mid+1;
            //if(countDays(weights, mid) <= D) right=mid;
            //else left=mid+1;
        }
        
        return left;
    }
    
    int countDays(std::vector<int>& weights, int total_capacity) {
        int count = 1;
        int current_capacity = 0;
        for(int& w: weights) {
            current_capacity += w;
            if(current_capacity>total_capacity) count++, current_capacity=w;
        }
        return count;
    }
    
    
    /*
    int least_capacity;
    int dfs(std::vector<int>& weights, int least_capacity, int index, int D) {
        if(index>D) return;
        if(weights.empty()) {
            return;
            //if(index==D) return;
            //else return INT_MAX;
        }
        
        least_capacity += weights[0];
        weights.erase(weights.begin());
        return min(dfs(weights, index, D), dfs(weights, 0, index+1, D));
        
    }
    
    int shipWithinDays1(vector<int>& weights,  int D) {
        least_capacity = INT_MAX;
        dfs(weights, 0, 0, D);
        return least_capacity;
    }
    */
};