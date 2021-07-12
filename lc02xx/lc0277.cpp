//--- Q: 0277. Find the Celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

//--- method 1: O(n) two pass
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, res)) {
                res = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (!knows(i, res) || knows(res, i))) {
                return -1;
            }
        }
        return res;
    }
};