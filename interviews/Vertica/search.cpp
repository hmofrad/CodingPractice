Given a sorted integer array A where every element occurs exactly twice except one. Our goal is to find the non repeating element and return its index.
                     *
A = [1,1,2,2,4,4,7,7,8,11,11] => 6 i.e A[6] which is 7 is the non repeating element
     0 1 2 3 4 5 6 7 8 9 10

             * 
A = [1,1,2,2,4,9,9,11,11]
         
left = 0, right = 10, mid = 5;
left = 7, right = 10, mid = 8;

// Return the index of non repeating element
int nonReapeating(int[] nums) {
    int size = nums.size();
    int left = 0;
    int right = size-1; 
    while(left < right) {
        int mid = left + (right-left)/2;
        
        if(mid+1<=size-1 and A[mid] == A[mid+1]) {
            if(mid+2<size and (right-mid+1)%2)) { left = mid+2;  }
            else { right = mid; }
        }
        else if(mid-1>=0 and A[mid-1] == A[mid]) {
            if(mid-2>=0 and (mid-left+1)%2)) { right = mid-2; } 
            else { left = mid; } 
        }
        else { return mid; }
        
        
        /*
        if((mid-left+1)%2) {  // move to left
            if(mid-2 >= 0 and A[mid-2]!=A[mid-1]) {
                return mid-1;
            }
            else { right = mid-1; }
        }
        else {// if((right-mid+1)%2) { // move to right
            if(mid+2 <= size-1 and A[mid+1]!=A[mid+2]) {
                return mid+1;
            }
            else {left = mid+1; }
         } 
         //else { return mid; }
         */
    }
    return left;
}



int nonReapeating(int[] nums) {
    int size = nums.size();
    int i = 0;
    for(; i < size-1; i+=2) {
        if(A[i] != A[i+1) { return i; }
    }
    return -1;
}
/*
i=0 1,1,
i=2 2,2
i=4 4,4
i=6 7,8
*/