/*
 * https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    int ptr = 0;
    int len = 0;
    bool end = false;
    char buffer[5];
    
    void cpy(char** buf, char* buffer, int& len, int& ptr, int& n, int& count) {
        if(len==0) return;
        
        while(ptr<len and n>0) {
            **buf=buffer[ptr++];
            *buf+=1;
            n--;
            count++;
        }
        if(ptr==len) {len=ptr=0;}
    }
   
    int read(char *buf, int n) {
        int count = 0;
        cpy(&buf, buffer, len, ptr, n, count);
        if(n==0 or end) {return count;}
        
        while(n-4>=0) {
            int read = min(read4(buf), 4);
            buf+=read;
            count+=read;
            n-=read;
            if(read<4) {end = true; return count;}
        }
        
        len = read4(buffer);
        if(len<4) {end = true;}
        cpy(&buf, buffer, len, ptr, n, count);

        return count;
    }
    
    int read1(char *buf, int n) {
        int i = 0;
        while(i<n) {
            if(ptr==len) {
                ptr=0;
                len=read4(buffer);
                if(len==0) break;
            }
            buf[i++]=buffer[ptr++];
        }
        return i;
    }
     
};