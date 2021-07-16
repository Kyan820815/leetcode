//--- Q: 0346. Moving Average from Data Stream

//--- method 1: O(1) time
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0, sz = size;                
    }
    
    double next(int val) {
        que.push_back(val);
        sum += val;
        if (que.size() > sz) {
            sum -= que.front();
            que.pop_front();
        }
        return (double)sum/que.size();
    }
    deque<int> que;
    int sum, sz;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */