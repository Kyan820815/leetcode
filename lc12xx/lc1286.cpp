//--- Q: 1286. Iterator for Combination

//--- method 1: precomputation using bit
class CombinationIterator {
public:
    list<string> ll;
    list<string>::iterator iter;
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size(), mask = 1<<n;
        auto countLen = [&characters](int bit) {
            int cnt = 0, idx = characters.size()-1;
            string selection = "";
            while (bit) {
                if (bit&1) {
                    selection += characters[idx];
                }
                --idx;
                bit >>= 1;
            }
            reverse(selection.begin(), selection.end());
            return selection;
        };
        for (int i = 1; i < mask; ++i) {
            string selection = countLen(i);
            if (selection.size() == combinationLength) {
                ll.push_front(selection);
            }
        }
        iter = ll.begin();
    }
    
    string next() {
        string cur = *(iter++);
        return cur;
    }
    
    bool hasNext() {
        return iter != ll.end();
    }
};

//--- method 2: precomputation using recursion
class CombinationIterator {
public:
    vector<string> res;
    int idx = 0;
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        dfs(0, characters, cur, combinationLength);
    }
    
    string next() {
        return res[idx++];
    }
    
    bool hasNext() {
        return idx != res.size();
    }
    
    void dfs(int idx, string &characters, string &cur, int len) {
        for (int i = idx; i < characters.size(); ++i) {
            cur += characters[i];
            if (cur.size() == len) {
                res.push_back(cur);
            }
            dfs(i+1, characters, cur, len);
            cur.pop_back();
        }
    }
};

//--- method 3: calculation on the fly
class CombinationIterator {
public:
    int state, hnext, len, nlen;
    string str;
    CombinationIterator(string characters, int combinationLength) {
        nlen = characters.size();
        state = 0, hnext = 1, len = combinationLength;
        str = characters;
        for (int i = 0; i < len; ++i) {
            state |= 1<<(nlen-i-1);
        }
    }
    
    string next() {
        string res = "";
        for (int i = 0; i < nlen; ++i) {
            if (state & (1<<(nlen-i-1))) {
                res += str[i];
            }
        }
        update();
        return res;
    }
    
    void update() {
        int right_con_bits = 0;
        while (state & (1<<right_con_bits)) {
            state ^= (1<<right_con_bits);
            right_con_bits++;
        }
        if (right_con_bits == len) {
            hnext = 0;
            return;
        }
        if (right_con_bits) {
            int rightmost = state & (~state+1);
            state ^= rightmost;
            rightmost >>= 1;
            state |= rightmost;
            while (right_con_bits--) {
                rightmost >>= 1;
                state |= rightmost;
            }
        } else {
            int rightmost = state & (~state+1);
            state ^= rightmost;
            state |= (rightmost>>1);
        }
    }
    
    bool hasNext() {
        return hnext;    
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */