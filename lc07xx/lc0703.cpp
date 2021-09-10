//--- Q: 0703. Kth Largest Element in a Stream

//--- method 1: priority queue
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for (auto &num: nums) {
            que.push(num);
            if (que.size() > k) {
                que.pop();
            }
        }
    }
    
    int add(int val) {
        que.push(val);
        if (que.size() > sz) {
            que.pop();
        }
        return que.top();
    }
    int sz;
    priority_queue<int, vector<int>, greater<int>> que;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */