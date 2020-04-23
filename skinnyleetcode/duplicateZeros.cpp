/*
 *  https://leetcode.com/problems/duplicate-zeros/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int numzeros = 0;
        for(int a: arr) numzeros += a ? 0 : 1;
        
        for(int i = size-1; i >= 0; i--) {
            if(arr[i]==0) {
                if(i+numzeros<size) arr[i+numzeros]=0;
                if(i-1+numzeros<size) arr[i-1+numzeros]=0;
                numzeros--;
            }
            else {
                if(i+numzeros < size) arr[i+numzeros]=arr[i];
            }
        }
    }
    void duplicateZeros2(vector<int>& arr) {
        std::deque<int> queue;
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            if(arr[i] == 0) queue.push_back(0);
            if(not queue.empty()) {
                queue.push_back(arr[i]);
                arr[i]=queue.front();
                queue.pop_front();
            }
        }
    }
    void duplicateZeros1(vector<int>& arr) {
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            if(arr[i] == 0) {
                for(int j = size-1; j > i; j--) {
                    arr[j] = arr[j-1];
                }
                arr[i++]=0;
            }
        }
    }
    void duplicateZeros17(vector<int>& arr) {
        int size = arr.size();
        int numzeros = 0;
        
        
        
        std::vector<int> zeros(size);
        for(int i = 1; i < size; i++) {
            //while(i < size and arr[i] == 0) {i++; numzeros;}
            numzeros += (arr[i-1] == 0) ? 1 : 0;
            zeros[i-1] = numzeros;
            
        }
        for(int z: zeros) printf("%d ", z); printf("\n");
        
        
        int j = size-1;
        while(j>=0 and arr[j]==0) j--;
        int size1 = j;
        printf("%d %d\n", size1, size-1);
        for(int i = size1; i >= 0; i--) {
            if(i+zeros[i] <= size-1) arr[i] = arr[i-zeros[i]];
        }
        for(int a: arr) printf("%d ", a); printf("\n");
        for(int i = size1; i >= 0; i--) {
            if(arr[i] == 0 and i+1 < size) arr[i+1] = 0;
        }
        
        
    }
};