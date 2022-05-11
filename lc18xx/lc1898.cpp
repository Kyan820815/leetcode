//--- Q: 1898. Maximum Number of Removable Characters

//--- method 1: binary search
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> loc(s.size(), INT_MAX);
        for (int i = 0; i < removable.size(); ++i) {
            loc[removable[i]] = i;
        }
        auto canRemove = [&](int idx){
            int i = 0, j = 0;
            while (i < s.size() && j < p.size()) {
                while (i < s.size() && loc[i] <= idx) {
                    ++i;
                }
                if (i < s.size() && s[i++] == p[j]) {
                    ++j;
                }
            }
            return j == p.size();
        };
        int left = 0, right = removable.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (canRemove(mid)) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return canRemove(left) ? left+1 : left;
    }
};