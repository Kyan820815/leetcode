//--- Q: 605. Can Place Flowers

//--- method 1: greedy method
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (n && !flowerbed[i] && (!i || !flowerbed[i-1]) && (i == flowerbed.size()-1 || !flowerbed[i+1])) {
                flowerbed[i] = 1;
                --n;
            }
        }
        return !n;
    }
};