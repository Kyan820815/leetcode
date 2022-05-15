//--- Q: 0484. Find Permutation

//--- method 1: reverse
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size()+1);
        iota(res.begin(), res.end(), 1);
        for (int i = 0; i < s.size(); ++i) {
            int j = i, cnt = 0;
            while (j < s.size() && s[j] == 'D') {
                ++j, ++cnt;
            }
            reverse(res.begin()+i, res.begin()+i+cnt+1);
            i = j > i ? j-1 : i;
        }
        return res;
    }
};