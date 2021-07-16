//--- Q: 0344. Reverse String

//--- method 1: change with n-i-1
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};