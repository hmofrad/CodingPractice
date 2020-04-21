/*
 *  https://leetcode.com/problems/airplane-seat-assignment-probability/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        std::vector<double> dp(n);
        dp[0] = 1.0;
        for(int i = 1; i < n; i++){
            dp[i] = 1.0/(i+1) + dp[i-1]*(i+1-2.0)/(i+1);
        }
        return dp[n-1];
    }
    
    
    double nthPersonGetsNthSeat2(int n) {
        if(n==1) return 1;
        std::vector<double> dp(2, 0);
        dp[0]=1./n;
        for(int i = 3; i <= n; i++) {
            dp[0] = dp[1] = dp[0] + dp[0]/(n-i+2);
        }
        return 1 - dp[0];
    }
};

/*
dp pattern is dp[i] = 1.0 / (i+1) + 0.0 / (i+1) + dp[i-1] X (i-1) / (i+1), with dp[0]=1 for the case there's only one person. If you manually calculate it you'll find dp[i] is always 1/2 except the base condition.
*/


/*
DP solution: O(n) time and O(1) space. I defined my DP array as dp[i] is the probability that the ith person needs to random (they didn't get their assigned seat). It is clear from this that dp[i] = dp[1]/n + dp[2]/(n-1) + dp[3]/(n-2) ... + dp[i-1]/(n-i+2). This is because the probability of a ith seat being taken is the probability that the 1st person has to random (which is 1) multiplied by the probability that the ith seat was chosen (1/n), plus the probability that the 2nd person has to random (dp[1]), multiplied by the probability that the ith seat was chosen (1/(n-1)), since only n-1 seats left, etc. We are just adding up all the probabilities of previous people taking the ith seat. Once we find probability of nth person having to random, we can subtract that from 1 to get probability of the nth person getting to stay in his assigned seat.

For the starting conditions, by definition dp[1] = 1. First person has to random.

This result in an O(n^2) solution initially. However, if we do some math, we can see the following:

dp[i] = dp[1]/n + dp[2]/(n-1) ... + dp[i-2]/(n-i+3) + dp[i-1]/(n-i+2).
dp[i-1] = dp[1]/n + dp[2]/(n-1) ... + dp[i-2]/(n-i+3).

This shows that actually dp[i] = dp[i-1] + dp[i-1]/(n-i+2). This automatically makes the solution O(n), and allows space optimization to make space O(1) as well, which creates the following solution. Because this recurrence relation only works for i > 2, we need to start at 3. Thus I handled n = 1 by a check, and initialize with dp[2] = 1/n.

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        vector<double> dp(2, 0); dp[0] = 1.0/n;
        for(int i = 3; i <= n; ++i)
            dp[0] = dp[1] = dp[0] + dp[0]/(n-i+2);
        return 1 - dp[0];
    }
};
The math solution basically takes the previous analysis a step further.

From before, we have the formula dp[i] = dp[i-1] + dp[i-1]/(n-i+2). If we substitute i = n, we get:
dp[n] = dp[n-1] + dp[n-1]/2 = (3/2)dp[n-1].
Similarly for i = n-1,
dp[n-1] = dp[n-2] + dp[n-2]/3 = (4/3)dp[n-2].
This shows a pattern. Basically dp[n] = (3/2)dp[n-1] = (3/2)(4/3)dp[n-2] = (3/2)(4/3)(5/4)dp[n-3] ......
It is clear that the numerator in each fraction always cancels out with the denominator of the next. If we look at the end by trying i = 3, we get:
dp[3] = dp[2] + dp[2]/(n-1) = n/(n-1)dp[2].

If we combine everything, we get: dp[n] = (3/2)(4/3)(5/4)...n/(n-1)dp[2] = (n/2) * dp[2] = (n/2) * (1/n) = 1/2. This shows that the solution is always 1 - 1/2 = 1/2 for n > 2. But this happens to also apply to n = 2 as well, since dp[2] = 1/n = 1/2 for n = 2. However, this is not the same logic that was used to prove for n >= 3.
*/
