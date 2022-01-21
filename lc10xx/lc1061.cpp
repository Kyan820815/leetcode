//--- Q: 1061. Lexicographically Smallest Equivalent String

//--- method 1: union find, better
class Solution {
public:
    vector<int> parent;
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        parent.resize(26, -1);
        for (int i = 0; i < n; ++i) {
            int ap = findp(s1[i]-'a');
            int bp = findp(s2[i]-'a');
            if (ap != bp) {
                if (ap < bp) {
                    parent[bp] = ap;
                } else {
                    parent[ap] = bp;
                }
            }
        }
        string res = "";
        for (auto &ch: baseStr) {
            res += findp(ch-'a')+'a';
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};