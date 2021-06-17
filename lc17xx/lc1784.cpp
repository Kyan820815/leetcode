//--- Q: 1784. Check if Binary String Has at Most One Segment of Ones

//--- method 1: find 01 pattern
class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0' && i+1 < s.size() && s[i+1] == '1') {
                return false;
            }
        }
        return true;
    }
};
//--- method 2: from last to start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int idx = s.size()-1;
        while (idx >= 0 && s[idx] == '0') {
            --idx;
        }
        while (idx >= 0 && s[idx] == '1') {
            --idx;
        }
        return idx == -1;
    }
};

//--- method 3: general method for finding boundary
class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (!i || s[i-1] == '0') {
                    ++cnt;
                }
                if (i == s.size()-1 || s[i+1] == '0') {
                    ++cnt;
                }
            }
        }
        return cnt == 2;
    }
};