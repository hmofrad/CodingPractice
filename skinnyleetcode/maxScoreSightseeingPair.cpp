/*
 *	https://leetcode.com/problems/best-sightseeing-pair/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
What we are interested in is maximize the value of A[i] + A[j] + i - j for i < j.

Let's iterate the array from the left to the right and let's say we are at index j at some moment.
We can easily calculate the value of A[j] - j. What we now need is to find out is what is the maximum value of A[i] + i where i was passed on some previous step. In order to do so, we can keep that previous maximum in a variable, which we will update at every iteration step:
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int best_prev = 0;
        int result = 0;
        int size = A.size();
        for(int i = 0; i < size; i++) {
            result = max(A[i]-i+best_prev, result);
            best_prev = max(best_prev, A[i]+i);
        }
        return result;
    }
    int maxScoreSightseeingPair1(vector<int>& A) {
        std::vector<std::pair<int, int>> P;
        int size = A.size();
        for(int i = 0; i < size; i++) {P.push_back({A[i], i});}
        std::sort(P.begin(), P.end(), [](std::pair<int, int> a, std::pair<int, int> b){
            return a.first==b.first ? a.second>b.second : a.first>b.first;});
        for(auto p: P) printf("%d %d\n", p.first, p.second); printf("\n");
        
        int max_v = 0;
        int prev_i = 0;
        for(int i = 1; i < size; i++) {
            std::pair<int, int> a = P[i-1];
            std::pair<int, int> b = P[i];
            int v = (a.second<b.second) ? a.first+b.first+a.second-b.second
                                        : a.first+b.first+b.second-a.second; 

            if(max_v) {
                std::pair<int, int> c = P[prev_i];
                int v1 = (c.second<a.second) ? a.first+c.first+a.second-c.second
                                             : a.first+c.first+c.second-a.second;
                max_v=max({v, v1, max_v});
            }
            else {
                max_v = v;
            }
            prev_i = (a.second>b.second) ? i-1 : i;
        }
        
        
        return max_v;
    }
};