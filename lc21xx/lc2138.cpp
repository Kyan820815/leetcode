//--- Q: 2138. Divide a String Into Groups of Size k

//--- method 1: string processing
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int i = 0, n = s.size();
        for (i = 0; i+k < n; i += k) {
            res.push_back(s.substr(i,k));
        }
        int left = n-i, right = k-left;
        res.push_back(s.substr(i,left));
        res.back() += string(right, fill);
        return res;
    }
};

//--- method 2: find location
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res((n-1)/k+1, string(k, fill));
        for (int i = 0; i < n; ++i) {
            res[i/k][i%k] = s[i];
        }
        return res;
    }
};