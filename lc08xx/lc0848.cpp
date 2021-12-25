//--- Q: 0848. Shifting Letters

//--- method 1: one pass
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = shifts.size()-1; i >= 0; --i) {
            shifts[i] %= 26;
            s[i] = ((s[i]-'a')+shifts[i])%26+'a';
            if (i) {
                shifts[i-1] += shifts[i];
            }
        }
        return s;
    }
};