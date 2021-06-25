//--- Q: 901. Online Stock Span 

//--- method 1: stack operation
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
    	while (sk.size() && price >= sk.top().first)
    	{
    		res += sk.top().second;
    		sk.pop();
    	}
    	sk.push({price, res});
    	return res;
    }
private:
	stack<pair<int,int>> sk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */