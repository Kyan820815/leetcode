//--- Q: 1188. Design Bounded Blocking Queue

//--- method 1: unique lock, shared lock, condition_variable
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        cap = capacity;        
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [this]() {
            return que.size() < cap;
        });
        que.push(element);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [this]() {
            return que.size() > 0;
        });
        int val = que.front();
        que.pop();
        cv.notify_all();
        return val;
    }
    
    int size() {
        shared_lock<shared_mutex> slock(stx);
        return que.size();
    }
    condition_variable cv;
    mutex mtx;
    shared_mutex stx;
    queue<int> que;
    int cap;
};