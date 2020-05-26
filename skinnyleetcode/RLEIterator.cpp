/*
 *	https://leetcode.com/problems/rle-iterator/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class RLEIterator {
public:
    std::vector<int> seq;
    int size = 0;
    int index = 0;
    RLEIterator(vector<int>& A) {
        seq=A;
        size=seq.size();
        index = 0;
    }
    
    int next(int n) {
        while(index<size and n>seq[index]) { n-=seq[index]; index+=2; }
        if(index>=size) return -1;
        seq[index]-=n;
        return seq[index+1];
    }
};



class RLEIterator2 {
public:
    std::vector<int> seq;
    int size = 0;
    int index = 0;
    RLEIterator2(vector<int>& A) {
        seq=A;
        size=seq.size();
        index= 0;
    }
    
    int next(int n) {
        //printf("n=%d: ", n); for(int s: seq) printf("%d ", s); printf("\n");
        int m = -1;
        std::vector<int> temp;
        while(index<size and n) {
            if(seq[index]-n >= 0) {
                temp.push_back(seq[index]-n);
                seq[index]-=n;
                n=0;
                m = seq[index+1];
                //index = (seq[index]==0 and index+2==size) ? index+2 : index;
                index = (seq[index]==0) ? index+2 : index;
            }
            else {
                temp.push_back(seq[index]);
                n-=seq[index];
                seq[index]=0;
                index += 2;
            }
        }
        //printf("m=%d, fallback=%d index=%d\n", m, temp.size(), index);
        if(m==-1) {
            if(index==size and not temp.empty()) index-=2;
            while(not temp.empty()) {
                int t = temp.back(); temp.pop_back();
                //printf("t=%d index=%d\n", t, index);
                seq[index] += t;
                index -= 2;
            }
        }
        //if(index<size) printf("m=%d n=%d s[%d]=%d\n", n, m, index, seq[index]);
       // else printf("m=%d n=%d s[%d]\n", n, m, index);
        return m;   
    }
};


class RLEIterator1 {
public:
    std::vector<int> seq;
    int size = 0;
    int index = 0;
    RLEIterator1(vector<int>& A) {
        for(int i = 0; i < A.size(); i+=2) {
            for(int j = A[i]; j>0; j--) {
                seq.push_back(A[i+1]);
            }
        }
        size = seq.size();
    }
    
    int next(int n) {
        int m = -1;
        if((index+n)<=size) {
            m=seq[index+n-1];
            index+=n;
        }
        return m;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */