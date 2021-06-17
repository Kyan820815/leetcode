//--- Q: 187. Repeated DNA Sequences

//--- method 1: set and find
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> set, cnt;
        string str = "";
        for (int i = 0; i < 10; ++i) {
            str += s[i];
        }
        cnt.insert(str);
        for (int i = 10; i < s.size(); ++i) {
            str += s[i];
            str = str.substr(1);
            if (cnt.find(str) != cnt.end()) {
                set.insert(str);
            }
            cnt.insert(str);
        }
        return vector<string>(set.begin(), set.end());
    }
};

//--- method 2: set with bit operation
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return {};
        }
        unordered_map<char, int> map = {{'A',0}, {'C',1}, {'T',2}, {'G',3}};
        unordered_set<string> res;
        unordered_set<int> repeated;
        int tag = 0;
        for (int i = 0; i < 10; ++i) {
            tag = (tag << 2) | (map[s[i]]);
        }
        repeated.insert(tag);
        for (int i = 10; i < s.size(); ++i) {
            tag = 0xFFFFF & ((tag << 2) | (map[s[i]]));
            if (repeated.find(tag) != repeated.end()) {
                res.insert(s.substr(i-9, 10));
            }
            repeated.insert(tag);
        }
        return vector<string>(res.begin(), res.end());
        
                                    
    }
};