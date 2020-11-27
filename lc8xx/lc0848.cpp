//--- Q: 848. Shifting Letters

//--- method 1: one pass
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int cnt = 0;
        for (int i = shifts.size()-1; i >= 0; --i)
        {
            cnt += shifts[i]%26;
        	S[i] = 'a' + (S[i]+cnt-'a') % 26;
        }
        return S;
    }
};