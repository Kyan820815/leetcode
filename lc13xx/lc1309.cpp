//--- Q: 1309. Decrypt String from Alphabet to Integer Mapping

//--- method 1: string processing
class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (i+2 < s.size() && s[i+2] == '#') {
                res += 'a' + (stoi(s.substr(i,2))-1);
                i += 2;
            } else {
                res += 'a' + (s[i]-'0'-1);
            }
        }
        return res;
    }
};