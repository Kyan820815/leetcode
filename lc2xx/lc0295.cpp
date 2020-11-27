//--- Q: 0295. Find Median from Data Stream

//--- method 1: double priority queue
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        big.push(-small.top());
        small.pop();
        if (small.size() < big.size())
        {
            small.push(-big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        return (small.size() > big.size()) ? small.top() : (double)(small.top()-big.top())/2;
    }
    priority_queue<long> small, big;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */