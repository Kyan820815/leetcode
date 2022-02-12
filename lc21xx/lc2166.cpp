//--- Q: 2166. Design Bitset

//--- method 1: string processing
class Bitset {
public:
    Bitset(int size) {
        pos.resize(size, '0');
        neg.resize(size, '1');
        onec = 0;
    }
    
    void fix(int idx) {
        if (pos[idx] == '0') {
            ++onec;
        }
        pos[idx] = '1';
        neg[idx] = '0';
    }
    
    void unfix(int idx) {
        if (pos[idx] == '1') {
            --onec;
        }
        pos[idx] = '0';
        neg[idx] = '1';
    }
    
    void flip() {
        onec = pos.size()-onec;
        swap(pos, neg);
    }
    
    bool all() {
        return onec == pos.size();
    }
    
    bool one() {
        return onec > 0;    
    }
    
    int count() {
        return onec;
    }
    
    string toString() {
        return pos;
    }
    string pos, neg;
    int onec;
};

//--- method 2: set processing
class Bitset {
public:
    Bitset(int size) {
        sz = size;
        for (int i = 0; i < size; ++i) {
            zeros.insert(i);
        }
    }
    
    void fix(int idx) {
        ones.insert(idx);
        zeros.erase(idx);
    }
    
    void unfix(int idx) {
        zeros.insert(idx);
        ones.erase(idx);
    }
    
    void flip() {
        swap(zeros, ones);
    }
    
    bool all() {
        return ones.size() == sz;
    }
    
    bool one() {
        return ones.size() > 0;    
    }
    
    int count() {
        return ones.size();
    }
    
    string toString() {
        string res = "";
        for (int i = 0; i < sz; ++i) {
            if (ones.find(i) != ones.end()) {
                res += '1';
            } else {
                res += '0';
            }
        }
        return res;
    }
    unordered_set<int> ones, zeros;
    int sz;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
