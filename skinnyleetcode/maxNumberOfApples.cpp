/*
 *  https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
public:
    int WEIGHT = 5000;
    
    
    int maxNumberOfApples(vector<int>& arr, int& count) {
        if(arr.empty()) return 0;
        
        vector<int> arr1;
        arr1.insert(arr1.begin(), arr.begin()+1, arr.end());
        
        int gain = arr.front();
        
        int next_gain = maxNumberOfApples(arr1, count);
        int this_gain = ((gain + next_gain) > WEIGHT) ? gain : gain + next_gain;
        if(max(this_gain, next_gain) == this_gain) count++;
        return(max(this_gain, next_gain));
    }
    
    int maxNumberOfApples1(vector<int>& arr) {
        int c = 0;
        int weight = maxNumberOfApples(arr, c);
        return(c);
    }
    
    int maxNumberOfApples(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int count = 0;
        int weight = 0;
        for(auto a: arr) {
            weight += a;
            if(weight <= WEIGHT) count++;
            else break;
        }
        return(count);
    }
    /*
    int maxNumberOfApples(vector<int>& arr) {
        int m = arr.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(WEIGHT+1));
        
        for(int i=1; i <= m; i++) {
            for(int j=1; j <= WEIGHT; j++) {
                dp[i][j]=dp[i-1][j];
                int weight = arr[i-1];
                if(j-weight >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-weight]+1);
                }
            }
        }
        return(dp[m][WEIGHT]);
    }
    */
    
};