/*
 *  https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
         std::priority_queue<int, std::vector<int>, std::greater<int> >  queue(A.begin(), A.end());
        while(K--){int f = queue.top(); queue.pop(); queue.push(-f);}
        int s = 0;
        while(not queue.empty()) {s += queue.top(); queue.pop();}
        return s;
    }
    int largestSumAfterKNegations1(vector<int>& A, int K) {
        std::map<int, int> negatives;
        std::map<int, int> positives;
        bool zero = false;
        int s = 0;
        for(int a: A) {
            if(a<0) negatives[a]++;
            else if(a>0)positives[a]++;
            else zero = true;
            s+=a;
        }
        
        while(K) {
            if(not negatives.empty()) {
                auto it = negatives.begin();
                positives[-it->first]++;
                s-=2*it->first;
                negatives[it->first]--;
                if(negatives[it->first]==0) negatives.erase(it->first);
                
            }    
            else if(not zero and not positives.empty()) {
                auto it = positives.begin();
                negatives[-it->first]++;
                s-=2*it->first;
                positives[it->first]--;
                if(positives[it->first]==0) positives.erase(it->first);
            } 
            K--;
        }
        //for(auto n: negatives) printf("%d %d\n", n.first, n.second);
        //printf("\n");
        //for(auto n: positives) printf("%d %d\n", n.first, n.second);
        //int s = 0;
        //for(auto n: negatives) s += n.first*n.second;
        //for(auto p: positives) s += p.first*p.second;
        
        return s;
    }
};