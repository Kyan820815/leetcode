//--- Q: 0731. My Calendar II

//--- method 1: two vector
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto &p: two) {
            if (max(p.first, start) < min(p.second, end)) {
                return false;
            }
        }
        for (auto &p: one) {
            if (max(p.first, start) < min(p.second, end)) {
                two.push_back({max(p.first, start), min(p.second, end)});
            }
        }
        one.push_back({start, end});
        return true;
    }
    vector<pair<int,int>> one, two;
};

//--- method 2: map count
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++count[start];
        --count[end];
        int times = 0;
        for (auto &event: count) {
            times += event.second;
            if (times > 2) {
                --count[start];
                ++count[end];
                return false;
            }
        }
        return true;
    }
    map<int,int> count;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
