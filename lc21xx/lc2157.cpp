//--- Q: 2157. Groups of Strings

//--- method 1: dfs
class Solution {
public:
    unordered_map<int,int> map;
    vector<int> groupStrings(vector<string>& words) {
        for (auto &word: words) {
            int mask = 0;
            for (auto &ch: word) {
                mask |= (1 << (ch-'a'));
            }
            ++map[mask];
        }
        int maxsize = 0, cnt = 0;
        while (map.size()) {
            int mask = map.begin()->first;
            int size = dfs(mask);
            maxsize = max(maxsize, size);
            ++cnt;
        }
        return {cnt, maxsize};
    }
    int dfs(int mask) {
        if (map.find(mask) == map.end()) {
            return 0;
        }
        int res = map[mask];
        map.erase(mask);
        for (int i = 0; i < 26; ++i) {
            if (map.find(mask ^ (1<<i)) != map.end()) {
                res += dfs(mask ^ (1<<i));
            }
            for (int j = i+1; j < 26; ++j) {
                if (((mask >> i) & 1) != ((mask >> j) & 1)) {
                    res += dfs(mask ^ (1<<i) ^ (1<<j));
                }
            }
        }
        return res;
    }
};

//--- method 2: union find
class Solution {
public:
    vector<int> parent;
    unordered_map<int, int> map;
    vector<int> groupStrings(vector<string>& words) {
        parent.resize(words.size(), -1);
        for (int i = 0; i < words.size(); ++i) {
            int mask = 0;
            for (auto &ch: words[i]) {
                mask |= (1 << (ch-'a'));
            }
            merge(i, mask);
            for (int j = 0; j < 26; ++j) {
                if (mask & (1<<j)) {
                    merge(i, mask^(1<<j));
                }
            }
        }
        int group = 0, maxsize = 0;
        for (int i = 0; i < words.size(); ++i) {
            group += parent[i] < 0;
            maxsize = max(maxsize, -parent[i]);
        }
        return {group, maxsize};
    }
    void merge(int i, int mask) {
        if (map.find(mask) == map.end()) {
            map[mask] = i;
        } else {
            int ap = findp(i);
            int bp = findp(map[mask]);
            if (ap != bp) {
                if (-parent[ap] < -parent[bp]) {
                    swap(ap, bp);
                }
                parent[ap] += parent[bp];
                parent[bp] = ap;
            }
        }
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};