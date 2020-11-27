//--- Q: 277. Find the Celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

//--- method 1: O(n) two pass
class Solution {
public:
    int findCelebrity(int n) {
        int cel = 0, cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(cel, i)) {
                cel = i;
            }                
        }
        for (int i = 0; i < n; ++i) {
            if (i != cel && (!knows(i, cel) || knows(cel, i))) {
                return -1;
            }
        }
        return cel;
    }
};