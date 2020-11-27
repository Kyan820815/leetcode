//--- Q: 1119. Remove Vowels from a String

//--- method 1: one time pass
class Solution {
public:
    string removeVowels(string S) {
        int now = -1;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u') {
                swap(S[++now], S[i]);
            }
        }
        return S.substr(0, now+1);
    }
};