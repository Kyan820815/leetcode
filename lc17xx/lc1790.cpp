//--- Q: 1790. Check if One String Swap Can Make Strings Equal

//--- method 1: O(1) space tracing
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), i;
        for (i = 0; i < n && s1[i] == s2[i]; ++i);
        if (i == n) {
            return true;
        }
        int last = i++;
        for (; i < n && s1[i] == s2[i]; ++i);
        if (i == n) {
            return false;
        }
        if (!(s1[last] == s2[i] && s2[last] == s1[i])) {
            return false;
        }
        for (i++; i < n && s1[i] == s2[i]; ++i);
        return i == n;
    }
};

//--- method 2: O(n) space tracing
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<array<int,2>> arr;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (!arr.size()) {
                    arr.push_back({s1[i],s2[i]});
                } else {
                    arr.push_back({s2[i],s1[i]});
                }
            }
        }
        return !arr.size() || arr.size() == 2 && arr[0] == arr[1];
    }
};