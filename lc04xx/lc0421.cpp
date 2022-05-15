//--- Q: 0421. Maximum XOR of Two Numbers in an Array

//--- method 1: prefix shift
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxxor = 0;
        for (int i = 30; i >= 0; --i) {
            maxxor <<= 1;
            int nmaxxor = maxxor | 1;
            unordered_set<int> prefix;
            for (auto &num: nums) {
                prefix.insert(num>>i);
            }
            for (auto &p: prefix) {
                if (prefix.find(p^nmaxxor) != prefix.end()) {
                    maxxor = nmaxxor;
                    break;
                }
            }
        }
        return maxxor;
    }
};

//--- method 2: prefix mask
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxxor = 0, mask = 0;
        for (int i = 30; i >= 0; --i) {
            int nmaxxor = maxxor | (1<<i);
            mask |= (1<<i);
            unordered_set<int> candidate;
            for (auto &num: nums) {
                candidate.insert((nmaxxor^num)&mask);
            }
            for (auto &num: nums) {
                if (candidate.find(num&mask) != candidate.end()) {
                    maxxor = nmaxxor;
                    break;
                }
            }
        }
        return maxxor;
    }
};

//--- method 3: trie tree
class TNode {
public:
    TNode() {
        next.resize(2, nullptr);
    }
    vector<TNode *> next;
};
class Solution {
public:
    TNode *root;
    int findMaximumXOR(vector<int>& nums) {
        root = new TNode();
        for (auto &num: nums) {
            insert(num);
        }
        int res = 0;
        for (auto &num: nums) {
            res = max(res, search(num));
        }
        return res;
    }
    void insert(int num) {
        auto now = root;
        for (int i = 30; i >= 0; --i) {
            int bit = ((num>>i)&1);
            if (!now->next[bit]) {
                now->next[bit] = new TNode();
            }
            now = now->next[bit];
        }
    }
    int search(int num) {
        int sum = 0;
        auto now = root;
        for (int i = 30; i >= 0; --i) {
            int bit = ((num>>i)&1);
            if (now->next[bit^1]) {
                sum += (1<<i);
                now = now->next[bit^1];
            } else {
                now = now->next[bit];
            }
        }
        return sum;
    }
};