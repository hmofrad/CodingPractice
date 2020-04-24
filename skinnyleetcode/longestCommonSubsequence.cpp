/*
 *  https://leetcode.com/problems/longest-common-subsequence/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1));
        
        for(int j = 1; j <= len2; j++) {
            for(int i = 1; i <= len1; i++) {
                dp[i][j] = (text1[i-1] == text2[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};

/*
The general DP algorithm is to consider a grid of width len(text1) and height len(text2).

  t   e   n   s
t +---+---+---+---+
  | \ | \ | \ | \ |
h +---+---+---+---+
  | \ | \ | \ | \ |
e +---+---+---+---+
  | \ | \ | \ | \ |
  +---+---+---+---+
Each column is associated to a letter in text1.
Each row is associated to a letter in text2.
Here, you can see an example with "tens" and "the".

The goal is to find the longest path from the top-left corner the the bottom right corner by going always down or right or diagonally.
Going right means "not taking a letter from text1". So, it counts as an edge of length 0 in the paths.
Going down means "not taking a letter from text2". So, it counts as an edge of length 0 in the paths.
Going diagonally (down-right) is only possible for two identical letters. It means "taking a letter in both texts". So, it counts as an edge of length 1 in the paths.

Here's the solution for the previous example.

  t   e   n   s
t +
    \
h     +
      |
e     +
        \
          +---+---+
This corresponds to "te" (diagonal links), the LCS of size 2.

My solution uses only O(n) memory. It relies on the fact that each value on a line can be computed with the current and previous line.
If we wanted the whole subsequence, we would need to keep the whole grid. for backtracking. But since we are only interested in the length of the LCS, two lines is all we need.
Here's the code:

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # To use less space, put the shortest string first
        if len(text1) > len(text2):
            text1, text2 = text2, text1
        prev = [0] * (len(text1) + 1)
        next = [0] * (len(text1) + 1)
        for i2 in range(len(text2)):
            for i1 in range(len(text1)):
                next[i1 + 1] = max(next[i1], prev[i1 + 1], prev[i1] + (text1[i1] == text2[i2]))
            prev, next = next, prev
        return prev[-1]
*/