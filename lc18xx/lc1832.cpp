//--- Q: 1832. Check if the Sentence Is Pangram

//--- method 1: count times
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> set;
        for (auto &ch: sentence) {
            set.insert(ch);
        }
        return set.size() == 26;
    }
};

//--- method 2: bit manipulation
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int res = 0, valid = (1 << 26)-1;
        for (int i = 0; i < sentence.size() && res != valid; ++i) {
            res |= 1 << (sentence[i]-'a');
        }
        return res == valid;
    }
};