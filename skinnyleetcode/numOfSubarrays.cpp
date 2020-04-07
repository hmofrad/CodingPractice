/*
 *  https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int C;
    int K;
    int T;
    std::vector<int> A;
    int M;
    double explore(std::vector<int>& b, int i) {
        if (i >= M) return 0;
        
        if(b.size() == T) {
            printf("%d\n", i);
            double avg = std::accumulate(b.begin(), b.end(), 0)/K;
            if(avg >= (double) T) C++;
            return(avg);
        }
        std::vector<int> c = b;
        b.push_back(A[i]);
        return(max(explore(b, i+1), explore(c, i+1)));
        
        //double loss = explore(b, i+1);
        
        //
        //double gain = explore(b, i+1);
        
        //if(loss >= (double) T) C++;
        //if(gain >= (double) T) C++;
        
        //return(gain > loss ? loss + explore(b, i+1) : gain);
    }
    
    int numOfSubarrays1(vector<int>& arr, int k, int threshold) {
        A = arr;
        M = arr.size();
        C = 0;
        K = k;
        T = threshold; 
        std::vector<int> b;
        int i = 0;
        int r = explore(b, i);
        return(C);
    }
    
    
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        int count = 0;
        int size = arr.size();
        int sum = 0;
        int j = 0;
        for(int i = 0; i < size; i++) {
            sum += arr[i];
            if(i-j+1==k){
               // printf("%d %d %d\n", i, j, sum/k);
                count += sum/k >= threshold;
                sum -= arr[j];
                j++;
            }
        }
        return(count);
    }
    
   int numOfSubarrays2(std::vector<int>& arr, int k, int threshold) {
        int size = arr.size();
        int count = 0;
        int sum = 0;
        for(int i = -1, j = 0; j < size; j++) {
            sum += arr[j];
            if(j-i == k) {
                count += sum/k >= threshold;
                sum -= arr[++i];
            }
        }
        return count;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};