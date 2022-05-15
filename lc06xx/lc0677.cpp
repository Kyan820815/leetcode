//--- Q: 0677. Map Sum Pairs

//--- method 1: prefix sum trie
class TNode {
public:
    TNode() {
        next.resize(26, nullptr);
        val = 0;
    };
    vector<TNode *> next;
    int val;
};
class MapSum {
public:
    TNode *root;
    unordered_map<string, int> map;
    MapSum() {
        root = new TNode();
    }
    
    void insert(string key, int val) {
        auto now = root;
        int lastv = map.find(key) != map.end() ? map[key] : 0;
        for (auto &ch: key) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
            now->val = now->val - lastv + val;
        }
        map[key] = val;
    }
    
    int sum(string prefix) {
        auto now = root;
        for (auto &ch: prefix) {
            if (!now->next[ch-'a']) {
                return 0;
            }
            now = now->next[ch-'a'];
        }
        return now->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */