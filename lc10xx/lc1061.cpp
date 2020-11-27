//--- Q: 1061. Lexicographically Smallest Equivalent String

//--- method 1: union find, better
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        vector<int> parent(26, -1);
        string res = "";
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < A.size(); ++i) {
            int ap = findp(A[i]-'a', parent);
            int bp = findp(B[i]-'a', parent);
            if (ap != bp) {
                parent[max(ap, bp)] = min(ap, bp);
            }
        }
        for (int i = 0; i < S.size(); ++i) {
            int ap = findp(S[i]-'a', parent);
            res.push_back(ap + 'a');
        }
        return res;
    }
    int findp(int now, vector<int> &parent) {
        if (now != parent[now]) {
            return parent[now] = findp(parent[now], parent);
        }
        return now;
    }
};

//--- method 2: union find
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        unordered_map<int, set<char>> group;
        vector<int> parent(26, -1);
        string res = "";
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
            group[i].insert(i+'a');
        }
        for (int i = 0; i < A.size(); ++i) {
            int ap = findp(A[i]-'a', parent);
            int bp = findp(B[i]-'a', parent);
            if (ap != bp) {
                if (group[ap].size() < group[bp].size()) {
                    parent[ap] = bp;
                    group[bp].insert(group[ap].begin(), group[ap].end());
                } else {
                    parent[bp] = ap;
                    group[ap].insert(group[bp].begin(), group[bp].end());
                }
            }
        }
        for (int i = 0; i < S.size(); ++i) {
            int ap = findp(S[i]-'a', parent);
            res.push_back(*group[ap].begin());
        }
        return res;
    }
    int findp(int now, vector<int> &parent) {
        if (now != parent[now]) {
            return parent[now] = findp(parent[now], parent);
        }
        return now;
    }
};
