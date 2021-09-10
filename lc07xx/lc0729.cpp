//--- Q: 0729. My Calendar I

//--- method 1: O(n) find
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        ++calendar[start];
        --calendar[end];
        int event = 0;
        for (auto &m: calendar) {
            event += m.second;
            if (event > 1) {
                --calendar[start];
                ++calendar[end];
                return false;
            }
        }
        return true;
    }
    map<int,int> calendar;
};

//--- method 2: O(n) find
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &date: calendar) {
            if (max(date.first, start) < min(date.second, end)) {
                return false;
            }
        }
        calendar.push_back({start, end});
        return true;
    }
    vector<pair<int,int>> calendar;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */