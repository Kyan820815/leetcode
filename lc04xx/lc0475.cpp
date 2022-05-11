//--- Q: 0475. Heaters

//--- method 1: binary search
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (auto &house: houses) {
            auto pos = upper_bound(heaters.begin(), heaters.end(), house);
            int left = INT_MAX, right = INT_MAX;
            if (pos != heaters.end()) {
                right = *pos-house;
            }
            if (pos != heaters.begin()) {
                left = house-*prev(pos);
            }
            res = max(res, min(left, right));
        }
        return res;
    }
};