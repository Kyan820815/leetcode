//--- Q: 0904. Fruit Into Baskets

//--- method 2: sliding window
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, n = fruits.size(), res = 0, types = 0;
        vector<int> tree(n, 0);
        while (right < n) {
            types += ++tree[fruits[right]] == 1;
            while (types > 2) {
                types -= !--tree[fruits[left++]];
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};

//--- method 1: O(1) space, compare current element with last two distinct elements
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), res = 0, cur = 0, cnta = 0, cntb = 0, a = -1, b = -1;
        for (int i = 0; i < n; ++i) {
            if (fruits[i] == b) {
                ++cur, ++cntb;
            } else if (fruits[i] == a) {
                ++cur;
                a = b, b = fruits[i];
                cnta = cntb, cntb = 1;
            } else {
                cur = cntb+1;
                a = b, b = fruits[i];
                cnta = cntb, cntb = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};