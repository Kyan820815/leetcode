//--- Q: 0170. Two Sum III - Data structure design

//--- method 1: map operation
class TwoSum {
public:
    using ll = long long;
    TwoSum() {
        
    }
    
    void add(int number) {
        ++map[number];
    }
     
    bool find(int value) {
        for (auto &num: map) {
            if (map.find(value-num.first) != map.end()) {
                if (value == num.first*2 && num.second > 1 || value != num.first*2) {
                    return true;
                }
            }
        }
        return false;
    }
    unordered_map<ll,int> map;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
