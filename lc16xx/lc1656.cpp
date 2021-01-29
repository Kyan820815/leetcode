//--- Q: 1656. Design an Ordered Stream

//--- method 1: linear add to res
class OrderedStream {
public:
    OrderedStream(int n) {
        arr.resize(n, "");
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        arr[id-1] = value;
        while (ptr < arr.size() && arr[ptr] != "") {
            res.push_back(arr[ptr++]);
        }
        return res;
    }
    vector<string> arr;
    int ptr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */