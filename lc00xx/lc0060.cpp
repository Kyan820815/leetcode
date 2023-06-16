//--- Q: 0060. Permutation Sequence
//--- last written: 2023/06/16

//--- method 1: O(n) find pattern
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> idx = {1}, block = {1};
        for (int i = 2; i <= n; ++i) {
            block.push_back(block.back()*idx.back());
            idx.push_back(i);
        }
        string res = "";
        --k;
        while (idx.size()) {
            auto pos = k/block.back();
            k %= block.back();
            block.pop_back();
            res += idx[pos]+'0';
            idx.erase(idx.begin()+pos);
        }
        return res;
    }
};
