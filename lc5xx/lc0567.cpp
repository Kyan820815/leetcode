//--- Q: 567. Permutation in String

//--- method 1: sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (s1.size() > s2.size())
            return false;
        vector<int> res(26, 0), tmp(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++res[s1[i]-'a'];
            ++tmp[s2[i]-'a'];
        }
        if (res == tmp)
            return true;
        for (int i = n1; i < n2; ++i) {
            ++tmp[s2[i]-'a'];
            --tmp[s2[i-n1]-'a'];
            if (res == tmp)
                return true;
        }
        return false;
    }
};

//--- method 2: sliding window, better
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        if (s1.size() > s2.size())
            return false;
        vector<int> res(26, 0);
        for (int i = 0; i < s1.size(); ++i)
            ++res[s1[i]-'a'];
        for (int i = 0; i < n2; ++i) {
            if (--res[s2[i]-'a'] < 0)
                while (++res[s2[left++]-'a'] !=0);
            else if (!res[s2[i]-'a'])
                if (i-left+1 == n1)
                    return true;
        }
        return false;
    }
};

