//--- Q: 0824. Goat Latin

//--- method 1: linear processing
class Solution {
public:
    string toGoatLatin(string sentence) {
        istringstream ss(sentence);
        string str, astr = "a", res = "";
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        while (ss >> str) {
            if (set.find(str[0]) != set.end() || set.find(str[0]^32) != set.end()) {
                res += str + "ma" + astr + " ";
            } else {
                res += str.substr(1) + str[0] + "ma" + astr + " ";
            }
            astr += 'a';
        }
        res.pop_back();
        return res;
    }
};