//--- Q: 0187. Repeated DNA Sequences

//--- method 1: set with bit operation
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_map<char, int> map = {{'A',0}, {'T',1}, {'C',2}, {'G',3}};
        unordered_set<int> set;
        int tag = 0;
        for (int i = 0; i < 10; ++i) {
            tag = (tag << 2) | map[s[i]];
        }
        set.insert(tag);
        for (int i = 10; i < s.size(); ++i) {
            tag = ((tag & 0x3FFFF) << 2) | map[s[i]];
            if (set.find(tag) != set.end()) {
                res.insert(s.substr(i-9, 10));
            }
            set.insert(tag);
        }
        return vector<string>(res.begin(), res.end());
    }
};