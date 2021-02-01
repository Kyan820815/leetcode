//--- Q: 151. Reverse Words in a String

//--- method 1: in place reverse
class Solution {
public:
    void reverseWord(int i, int j, string &s) {
        while (i < j) {
            swap(s[i], s[j]);
            ++i, --j;
        }
    }
    string reverseWords(string s) {
        int left = 0, right = 0, n = s.size();
        bool first = true;
        while (1) {
            while (right < n && s[right] == ' ') {
                ++right;
            }
            if (right == n) {
                break;
            }
            if (!first) {
                s[left++] = ' ';
            }
            int go = left;
            while (right < n && s[right] != ' ') {
                s[go++] = s[right++];
            }
            reverseWord(left, go-1, s);
            first = false;
            left = go;
        }
        s.resize(left);
        reverseWord(0, left-1, s);
        return s;
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