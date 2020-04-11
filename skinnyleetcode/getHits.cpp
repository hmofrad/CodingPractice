/*
 *  https://leetcode.com/problems/design-hit-counter/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class HitCounter {
public:
    /** Initialize your data structure here. */
    std::deque<int> queue;
    /*
    std::vector<int> queue;
    
    int size;
    int front;
    int rar;
    int len;
    int count;
*/
    HitCounter() {
        /*
        len = 300;
        queue.resize(len);
        front = -1;
        rear = -1;
        size = 0;
        count = 0;
        */
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp%300;
        queue.push_back(timestamp);
        /*
        if((front == 0 and rear == size-1) or (rear == (front-1)%(rear-1))) {
            
        }
        else if(head == -1) {head = 0; tail = 0; queue[rear] = ;}
        else if((read == size-1) and (front != 0)) {rear = 0; queue[rear] = timestamp%300;}
        else {rear++; queue[rear] = timestamp%300;}
        count++;
        */
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(not queue.empty() and timestamp - queue.front() >= 300 ) queue.pop_front();
        return(queue.size());
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */