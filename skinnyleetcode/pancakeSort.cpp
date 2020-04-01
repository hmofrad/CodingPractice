/*
 *  https://leetcode.com/problems/pancake-sorting/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isSorted(std::vector<int> arr) {
        bool sorted = true;
        int m = arr.size();
        for(int i = 0; i < m-1; i++) {
            if(arr[i] > arr[i+1]) {
                sorted = false;
                break;
            }
        }
        return sorted;
    }
    std::vector<int> flip(std::vector<int> arr, int k) {
        std::vector<int> arr1(arr);
        for(int i = 0; i < k/2; i++) {
            std::swap(arr1[i], arr1[k-1-i]);
        }
        return(arr1);
    }
    
    bool pancakeSort1(vector<int> A, int k) {
        if(isSorted(A)) return(true);
        int m = A.size();
        if(k <= m) {
            printf("%d %d\n", k, m);
            std::vector<int> B(A);
            
            flip(B, k);
            bool r1 = pancakeSort1(B, k+1);
            
            bool r2 = pancakeSort1(A, k+1);
            return(r1 or r2);
        }
        return(false);
        
    }
    std::vector<int> flips;
vector<int> pancakeSort(vector<int>& A) {
        pancakeSort3(A);
        return(flips);
    }
    
    void pancakeSort3(vector<int>& A) {
        std::map<int, int> my_map;
        int m = A.size();
        for(int i = 0; i < m; i++){
            my_map[A[i]] = i;
        }
        std::vector<int> pos(m);
        int i = 0;
        for(auto rit = my_map.rbegin(); rit != my_map.rend(); rit++, i++) {
            pos[i] = rit->second;
        }
        
        //for(int a: A) {
         //   printf("%d ", a);
        //}
        //printf("\n");

        int f = 0;        
        //for(int i = 0; i < m; i++) {
            i = 0;
            if(pos[i]>=1) {
               // printf("%d>>\n ", pos[i]);
                //f += pos[i];
                flips.push_back(pos[i]+1);
                std::reverse(A.begin(), A.begin()+pos[i]+1);
            } 
            
            if(m-i> 1) {
                //f += m-1;
                flips.push_back(m);
                std::reverse(A.begin(), A.begin()+m-i);
            }
          //  break;
        //}
        
        for(int a: A) {
            printf("%d ", a);
        }
        printf("\n");
        if(A.size()>1) {
            A.pop_back();
            pancakeSort3(A);
        }
        
    
        
        
        //std::vector<int> sorted(A);
        //std::sort(sorted.begin(), sorted.end());

        
        
        //for(int i = m-1; i >= 0; i--) {
          //  pos[i-m-1] = 
        //}
    //return(A);
        
    }
};
