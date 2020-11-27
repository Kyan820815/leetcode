//--- Q: 1433. Check If a String Can Break Another String

//--- method 1-1: bucket sort, better
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt1[s1[i]-'a'];
            ++cnt2[s2[i]-'a'];
        }
        int i = 0, j = 0;
        bool smaller = true, bigger = true;
        while (i < 26 && j < 26) {
            while (i < 26 && !cnt1[i]) {
                ++i;
            }
            while (j < 26 && !cnt2[j]) {
                ++j;
            }
            if (i < 26 && j < 26) {
                smaller &= (i <= j);
                bigger &= (i >= j);
                --cnt1[i];
                --cnt2[j];
            }
        }
        return smaller || bigger;
    }
};

//--- method 1-2: bucket sort
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i]-'a'];
            ++cnt2[s2[i]-'a'];
        }
        string ss1, ss2;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i]) {
                for (int j = 0; j < cnt1[i]; ++j) {
                    ss1.push_back(i+'a');
                }
            }
            if (cnt2[i]) {
                for (int j = 0; j < cnt2[i]; ++j) {
                    ss2.push_back(i+'a');
                }
            }
        }
        bool b1 = false, b2 = false;
        for (int i = 0; i < n; ++i) {
            if (ss1[i] > ss2[i]) {
                b1 |= true;
            } else if (ss1[i] < ss2[i]) {
                b2 |= true;
            }
        }
        return b1 ^ b2;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool win1 = false, win2 = false;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] > s2[i]) {
                win1 |= true;
            } else if (s1[i] < s2[i]) {
                win2 |= true;
            }
        }
        return win1 ^ win2;
    }
};