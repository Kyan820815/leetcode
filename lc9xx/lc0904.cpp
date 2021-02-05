//--- Q: 904. Fruit Into Baskets

//--- method 1: O(1) space, compare current element with last two distinct elements
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int idx = 0, cnt_b = 0, res = 0, n = tree.size(), a = -1, b = -1, cur = 0;
        while (idx < n) {
            if (tree[idx] == b) {
                ++cur, ++cnt_b;
            } else if (tree[idx] == a) {
                ++cur;
                a = b;
                b = tree[idx];
                cnt_b = 1;
            } else if (tree[idx] != a && tree[idx] != b) {
                cur = cnt_b + 1;
                a = b;
                b = tree[idx];
                cnt_b = 1;
            }
            ++idx;
            res = max(res, cur);
        }
        return res;
    }
};

//--- method 2: sliding window
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0, right = 0, res = 0, diff = 0, n = tree.size();
        vector<int> cnt(n, 0);
        while (right < n) {
            if (++cnt[tree[right]] == 1) {
                ++diff;
            }
            while (diff > 2) {
                if (!--cnt[tree[left++]]) {
                    --diff;
                }
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};