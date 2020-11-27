//--- Q: 1188. Design Bounded Blocking Queue

//--- method 1: unique lock, shared lock, condition_variable
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        c = capacity;
    }
    
    void enqueue(int element) {
        {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, [this](){return que.size() < c;});
            que.push(element);
        }
        cv.notify_one();
    }
    
    int dequeue() {
        int now;
        {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, [this](){return que.size() > 0;});
            now = que.front();
            que.pop();
        }
        cv.notify_one();
        return now;
    }
    
    int size() {
        shared_lock<shared_mutex> sl(smtx);
        int qsize = que.size();
        return que.size();
    }
private:
    queue<int> que;
    mutex mtx;
    shared_mutex smtx;
    condition_variable cv;
    int c;
};