//--- Q: 0901. Online Stock Span 

//--- method 1: decreasing stack operation
class StockSpanner {
public:
    StockSpanner() {
        idx = 0;
        sk.push_back(-1);
    }
    
    int next(int price) {
        while (sk.back() != -1 && arr[sk.back()] <= price) {
            sk.pop_back();
        }
        int days = idx-sk.back();
        arr.push_back(price);
        sk.push_back(idx++);
        return days;
    }
    vector<int> arr, sk;
    int idx;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */