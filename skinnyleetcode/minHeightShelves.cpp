/*
 *  https://leetcode.com/problems/filling-bookcase-shelves/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
For every subsequence of books from 0 to the current book, try to find the bookcase height for the scenario where as many of the most recently added books as possible fit onto the newest shelf.

Check this scenario by adding books from i-1 to 0 until a shelf is filled, and add this shelf height to the height of the bookcase excluding the books in this shelf--store this value if it is less than previous calculations when new shelves were started after more books were placed onto earlier shelves.

This algorithm ensures that the bookcase height for the most optimal points of starting new shelves (optimal in the sense that a minimum total height is obtained) is stored.
*/


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int nbooks = books.size();
        std::vector<int> dp(nbooks+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= nbooks; i++) {
            int width = 0;
            int height = 0;
            
            for(int j = i-1; j >= 0; j--) {
                width += books[j][0];
                if(width > shelf_width) break;
                height = max(height, books[j][1]);
                dp[i] =  min(dp[i], dp[j]+height);
            }
        }
        return dp[nbooks];
    }
};