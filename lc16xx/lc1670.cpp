//--- Q: 1670. Design Front Middle Back Queue

//--- method 1: O(1) operation list
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }

    void pushFront(int val) {
        ll.push_front(val);
        if (ll.size() == 1) {
            mid = ll.begin();
        } else if (!(ll.size() & 1)) {
            --mid;
        }
    }
    
    void pushMiddle(int val) {
        if (!ll.size())  {
            ll.push_back(val);
            mid = ll.begin();
        } else if (!(ll.size()&1)) {
            ll.insert(next(mid), val);
            ++mid;
        } else {
            ll.insert(mid, val);
            --mid;
        }
    }
    
    void pushBack(int val) {
        ll.push_back(val);
        if (ll.size() == 1) {
            mid = ll.begin();
        } else if ((ll.size() & 1)) {
            ++mid;
        }
    }
    
    int popFront() {
        if (!ll.size()) {
            return -1;
        }
        auto val = ll.front();
        if (ll.size() == 1) {
            mid = ll.begin();
        } else if (!(ll.size()&1)) {
            ++mid;
        }
        ll.pop_front();
        return val;
    }
    
    int popMiddle() {
        if (!ll.size()) {
            return -1;
        }
        auto val = *mid;
        auto tmp = mid;
        if (ll.size() == 1) {
            mid = ll.begin();
        } else if (ll.size()&1) {
            --mid;
        } else {
            ++mid;
        }
        ll.erase(tmp);
        return val;
    }
    
    int popBack() {
        if (!ll.size()) {
            return -1;
        }
        auto val = ll.back();
        if (ll.size() == 1) {
            mid == ll.begin();
        } else if (ll.size()&1) {
            --mid;
        }
        ll.pop_back();
        return val;
        
    }
    list<int> ll;
    list<int>::iterator mid;
};

//--- method 2: O(1) operation deque
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left.push_front(val);
        left2right();
    }
    
    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }
    
    void pushBack(int val) {
        right.push_back(val);
        right2left();
    }
    
    int popFront() {
        if (!left.size() && !right.size()) {
            return -1;
        }
        int val = left.front();
        left.pop_front();
        right2left();
        return val;
    }
    
    int popMiddle() {
        if (!left.size() && !right.size()) {
            return -1;
        }
        int val = left.back();
        left.pop_back();
        right2left();
        return val;
    }
    
    int popBack() {
        if (!left.size() && !right.size()) {
            return -1;
        }
        int val;
        if (!right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.back();
            right.pop_back();
        }
        left2right();
        return val;
    }
    void left2right() {
        while (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
    void right2left() {
        while (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
    deque<int> left, right;
};


/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */