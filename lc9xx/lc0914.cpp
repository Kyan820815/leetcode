//--- Q: 914. X of a Kind in a Deck of Cards

//--- method 1: find greatest divisor
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> cnt(10000, 0);
        int last = 0;
        for (int i = 0; i < deck.size(); ++i) {
            ++cnt[deck[i]];
        }
        for (int i = 0; i < 10000; ++i) {
            if (cnt[i]) {
                last = findmin(last, cnt[i]);
                if (last == 1) {
                    return false;
                }
            }
        }
        return true;
    }
    int findmin(int small, int big) {
        if (small > big) {
            swap(small, big);
        }
        while (big && small) {
            big %= small;
            swap(small, big);
        }
        return big;
    }
};