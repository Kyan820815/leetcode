//--- Q: 165. Compare Version Numbers

//--- method 1: two pointer
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, cnt1, cnt2;
        while (i < version1.size() || j < version2.size()) {
            cnt1 = cnt2 = 0;
            while (i < version1.size() && version1[i] != '.') {
                cnt1 = cnt1*10 + version1[i++]-'0';
            }
            while (j < version2.size() && version2[j] != '.') {
                cnt2 = cnt2*10 + version2[j++]-'0';
            }
            ++i, ++j;
            if (cnt1 > cnt2) {
                return 1; 
            } else if (cnt1 < cnt2) {
                return -1;
            }
        }
        return 0;
    }
};