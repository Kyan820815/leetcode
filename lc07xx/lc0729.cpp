//--- Q: 729. My Calendar I

//--- method 1: nlogn find
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto event = calendar.upper_bound(start);
        if (event != calendar.end() && end > event->first) {
            return false;
        }
        if (event != calendar.begin() && (--event)->second > start) {
            return false;
        }
        calendar[start] = end;
        return true;
    }
    map<int, int> calendar;
};

//--- method 2: n^2 find
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &p: calendar) {
            if (max(p.first, start) <  min(p.second, end)) {
                return false;
            }
        }
        calendar.push_back({start, end});
        return true;
    }
    vector<pair<int, int>> calendar;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */