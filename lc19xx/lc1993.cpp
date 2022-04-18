//--- Q: 1993. Operations on Tree

//--- method 1: dfs
class LockingTree {
public:
    vector<vector<int>> rel;
    vector<int> state, pt;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        rel.resize(n);
        state.resize(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                rel[parent[i]].push_back(i);
            }
        }
        pt = parent;
    }
    
    bool lock(int num, int user) {
        if (state[num]) {
            return false;
        }
        state[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (state[num] != user) {
            return false;
        }
        state[num] = 0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (state[num]) {
            return false;
        }
        int p = pt[num];
        while (p != -1) {
            if (state[p]) {
                return false;
            }
            p = pt[p];
        }
        if (haveLock(num)) {
            state[num] = user;
            return true;
        }
        return false;
    }
    
    int haveLock(int now) {
        int res = 0;
        if (state[now]) {
            res = 1;
            state[now] = 0;
        }
        for (auto &child: rel[now]) {
            res |= haveLock(child);
        }
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */