//--- Q: 1078. Occurrences After Bigram

//--- method 1: built-in function
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ss(text);
        string fstr = "", sstr = "", str;
        vector<string> res;
        while (ss >> str) {
            if (fstr == first && sstr == second) {
                res.push_back(str);
            }
            fstr = sstr;
            sstr = str;
        }
        return res;
    }
};

//--- method 2: direct processing
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string fstr = "", sstr = "", str = "";
        vector<string> res;
        for (int i = 0; i <= text.size(); ++i) {
            if (i == text.size() || text[i] == ' ') {
                if (fstr == first && sstr == second) {
                    res.push_back(str);
                }
                fstr = sstr;
                sstr = str;
                str = "";
            } else {
                str += text[i];
            }
        }
        return res;
    }
};

//--- method 3: string find
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string bigram = " " + first + " " + second + " ", t = " " + text;
        vector<string> res;
        int idx = t.find(bigram, 0);
        while (idx != string::npos) {
            auto p1 = idx + bigram.size();
            auto p2 = p1;
            while (p2 < t.size() && t[p2] != ' ') {
                ++p2;
            }
            res.push_back(t.substr(p1, p2-p1));
            idx = t.find(bigram, idx+1);
        }
        return res;
    }
};
