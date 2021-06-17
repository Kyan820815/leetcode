//--- Q: 151. Reverse Words in a String

//--- method 1: in place reverse
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, ri = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            int start = ri;
            while (i < s.size() && s[i] != ' ') {
                s[ri++] = s[i++];
            }
            s[ri++] = ' ';
            reverse(s.begin()+start, s.begin()+ri-1);
        }
        string res = s.substr(0, ri-1);
        reverse(res.begin(), res.end());
        return res;
    }
};

//--- method 2: built-in function
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string str, res = "";
        while (ss >> str) {
            res = str + " " + res;
        }
        if (res.size()) {
            res.pop_back();
        }
        return res;
    }
};