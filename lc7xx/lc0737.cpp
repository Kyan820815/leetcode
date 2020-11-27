//--- Q: 737. Sentence Similarity II

//--- method 1: union find
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, string> parent;
        for (int i = 0; i < pairs.size(); ++i) {
            string ap = findp(pairs[i][0], parent);
            string bp = findp(pairs[i][1], parent);
            if (ap != bp) {
                parent[ap] = bp;
            }
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) {
                continue;
            }
            string ap = findp(words1[i], parent);
            string bp = findp(words2[i], parent);
            if (ap != bp) {
                return false;
            }
        }
        return true;
    }
    string findp(string &now, unordered_map<string, string> &parent) {
        if (parent.find(now) == parent.end()) {
            parent[now] = now;
        } else if (parent[now] != now) {
            return parent[now] = findp(parent[now], parent);
        }
        return parent[now];
    }
};