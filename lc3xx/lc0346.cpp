//--- Q: 346. Moving Average from Data Stream

//--- method 1: O(1) time
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
        sum = 0;
    }
    
    double next(int val) {
        if (que.size() == window) {
            sum -= que.front();
            que.pop();
        }
        sum += val;
        que.push(val);
        return (double)sum/que.size();
    }
    int window, sum;
    queue<int> que;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */