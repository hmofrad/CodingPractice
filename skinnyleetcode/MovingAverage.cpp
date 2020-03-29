/*
 *  https://leetcode.com/problems/moving-average-from-data-stream/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    std::vector<int> queue;
    int size = 0;
    int head = 0;
    int tail = 0;
    int count = 0;
    float sum = 0;
    MovingAverage(int size_) {
        size = size_;
        queue.resize(size);
    }
    
    double next(int val) {
        count++;
        tail = (head+1) % size;
        sum +=  (val - queue[tail]);
        head = (head+1) % size;
        queue[head] = val; 
        //printf("%f\n", sum);
        return(sum * 1. / ((count < size) ? count : size));
    }
};


/*
class MovingAverage {
public:

    std::deque<int> queue;
    int size = 0;
    int sum = 0;;
    MovingAverage(int size_) {
        size = size_;
        while(queue.size() > size) {
            sum -= queue.front();
            queue.pop_front();
        }
    }
    
    double next(int val) {
        if(queue.size() == size) {
            sum -= queue.front();
            queue.pop_front();

        }
        queue.push_back(val);
        sum += val;
        return((double) sum/queue.size());
        
    }
};
*/
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */