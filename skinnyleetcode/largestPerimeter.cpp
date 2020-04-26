/*
 *  https://leetcode.com/problems/largest-perimeter-triangle/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        std::sort(A.begin(), A.end());
        int size = A.size();
        for(int i = size-3; i >= 0; i--) {
            if(A[i]+A[i+1] > A[i+2]) return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
    int largestPerimeter2(vector<int>& A) {
        std::sort(A.begin(), A.end(), [](const int a, const int b) {return a > b;});
        int size = A.size();
        //int max_perimeter = 0;
        std::vector<int> I = {0, 1, 2};
        while(I[2]<size) {
            int a = A[I[0]];
            int b = A[I[1]];
            int c = A[I[2]];
            if(a+b>c and a+c>b and b+c>a) return a+b+c;
            for(int& i: I) i++;
        }
        return 0;
    }
    
    
    
    bool valid(int a, int b, int c) {
        return a+b>c and a+c>b and b+c>a;
    }
    int dfs(vector<int>& A, std::vector<int> triangle, int index) {
        //printf("%d %d\n", indices.size(), index);
        if(triangle.size() == 3){
            int a = triangle[0];
            int b = triangle[1];
            int c = triangle[2];
            //printf("%d %d %d %d\n", a, b, c, valid(a, b, c));
            return valid(a, b, c) ? a+b+c : 0;
        }
        int size = A.size();
        if(index == size) return 0;
        
        std::vector<int> triangle1 = triangle;
        triangle.push_back(A[index]);
        return max(dfs(A, triangle, index+1), dfs(A, triangle1, index+1));
        
    }
    int largestPerimeter1(vector<int>& A) {
        std::vector<int> triangle;
        return dfs(A, triangle, 0);
    }
};