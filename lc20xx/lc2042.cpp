//--- Q: 2042. Check if Numbers Are Ascending in a Sentence

//--- method 1: just check if all numbers are increasing
class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size(), last = -1;
        string str = "";
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (isdigit(str[0])) {
                    int cur = stoi(str);
                    if (last >= cur) {
                        return false;
                    }
                    last = cur;
                }
                str = "";
            } else {
                str += s[i];
            }
        }
        return true;
    }
};