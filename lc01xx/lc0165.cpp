//--- Q: 0165. Compare Version Numbers

//--- method 1: two pointer
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        while (i < n1 || j < n2) {
            int cnt1 = 0, cnt2 = 0;
            while (i < n1 && version1[i] != '.') {
                cnt1 = cnt1*10 + (version1[i++]-'0');
            }
            while (j < n2 && version2[j] != '.') {
                cnt2 = cnt2*10 + (version2[j++]-'0');
            }
            if (cnt1 > cnt2) {
                return 1;
            } else if (cnt1 < cnt2) {
                return -1;
            }
            ++i, ++j;
        }
        return 0;
    }
};