//--- Q: 1845. Seat Reservation Manager

//--- method 1: heap
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> que;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            que.push(i);
        }
    }
    
    int reserve() {
        auto top = que.top();
        que.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        que.push(seatNumber);
    }
};

//--- method 2: set
class SeatManager {
public:
    set<int> set;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            set.insert(i);
        }
    }
    
    int reserve() {
        int res = *set.begin();
        set.erase(set.begin());
        return res;
    }
    
    void unreserve(int seatNumber) {
        set.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
