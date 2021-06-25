//--- Q: 731. My Calendar II

//--- method 1: map count
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++calendar[start];
        --calendar[end];
        int event = 0;
        for (auto &p: calendar) {
            event += p.second;
            if (event == 3) {
                --calendar[start];
                ++calendar[end];
                return false;
            }
        }
        return true;
    }
    map<int, int> calendar;
};

//--- method 2: two vector
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
            int st = max(p.first, start), ed = min(p.second, end);
            if (st < ed) {
                two.push_back({st, ed});
            }
        }
        one.push_back({start, end});
        return true;
    }
    vector<pair<int, int>> one, two;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
