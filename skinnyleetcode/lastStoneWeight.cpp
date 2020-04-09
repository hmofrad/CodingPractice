/*
 *  https://leetcode.com/problems/last-stone-weight/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> queue(stones.begin(), stones.end());
        while(queue.size() >= 2) {
            int first = queue.top();
            queue.pop();
            int second = queue.top();
            queue.pop();
            queue.push(first-second);
        }
        return(queue.top());
    }
    
    
    int lastStoneWeight1(vector<int>& stones) {
        std::sort(stones.begin(), stones.end(), [](int a, int b) {return(a>b);});
        //for(int s: stones) printf("%d ", s); printf("\n");
        std::priority_queue<int> queue;
        int size = stones.size();
        int s = 0;
        int i = 0;
        while(i < size) {
            int s1 = stones[i++];
            int s2 = 0;
            if(not queue.empty() and queue.top() >= s1) {
                s1 = queue.top();
                queue.pop();
                s2 = stones[i-1];
                if(not queue.empty() and queue.top() >= s2) {
                    i--;
                    s2 = queue.top();
                    queue.pop();
                }
                //printf("0 ");
            }
            else if(i < size) {
                s2 = stones[i++];
                //printf("1 ");
            }
            s = s1-s2;
            if(s) queue.emplace(s);
            //printf("%d: %d %d %d\n", i, s1, s2, s, );
        }
        
        while(not queue.empty()) {
            int s1 = queue.top();
            queue.pop();
            int s2 = 0;
            if(not queue.empty()) {
                s2 = queue.top();
                queue.pop();
            }
            s=s1-s2;
            if(s) queue.emplace(s);
            if(queue.size() == 0) break;
            else if(queue.size() == 1) {s = queue.top(); queue.pop(); break;}
        }
        
        return(s);
    }
};