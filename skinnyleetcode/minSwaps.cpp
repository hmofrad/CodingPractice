/*
 *  https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
Count the number of ones - numOnes variable. Then for each range [i..j] calculate the number of ones inside it - inside variable. If the size of a window is equal to the numOnes that means that we can swap all zeros from the window to the outside world. The number of swaps is the number of ones outside or numOnes - inside. And move the window accordingly.

*/

class Solution {
public:
    int minSwaps1(vector<int>& data) {
        int size = data.size();
        int numones = 0;
        for(int d: data) numones += d ? 1 : 0;
        if(numones == 0) return 0;
        int inside = 0;
        int i = 0;
        int count = INT_MAX;
        for(int j = 0; j < size; j++) {
            inside += data[j] ? 1 : 0;
            if(j-i+1 == numones) {
                count = min(count, numones-inside);
                inside -= data[i++] ? 1 : 0;
            }
        }
        return count; 
    }
    
    int minSwaps(vector<int>& data) {
        int size = data.size();
        int numones = 0;
        for(int d: data) numones += d ? 1 : 0;
        if(numones <= 1) return 0;
        int maxones = 0;
        int index = -1;
        int j = 0;
        int ones = 0;
        for(int i = 0; i < size; i++) {
            if(data[i]) ones++;
            if(i-j+1 == numones) {
                if(ones > maxones) maxones = ones;
                
                if(data[j++]) ones--;
            }
        }
        //printf("%d %d\n", maxones, numones);
        return maxones==numones ? 0 : numones-maxones;
    }
};