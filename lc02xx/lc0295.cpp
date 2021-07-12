//--- Q: 0295. Find Median from Data Stream

//--- method 1: double priority queue
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        while (left.size() >= right.size()) {
            right.push(-left.top());
            left.pop();
        }
        if (left.size() < right.size()) {
            left.push(-right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        return left.size() > right.size() ? left.top() : (double)(left.top()-right.top())/2;
    }
    priority_queue<int> left, right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */