//--- Q: 1352. Product of the Last K Numbers

//--- method 1: prefix product
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        arr = {1};
    }
    
    void add(int num) {
        if (num) {
            arr.push_back(arr.back()*num);
        } else {
            arr = {1};
        }
    }
    
    int getProduct(int k) {
        return k < arr.size() ? arr.back()/arr[arr.size()-k-1] : 0;
    }
    vector<int> arr;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */