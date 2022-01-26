//--- Q: 1103. Distribute Candies to People

//--- method 1: linear aggredation, O(sqrt(n))
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int num = 1, idx = 0;
        while (candies-num >= 0) {
            res[idx] += num;
            candies -= num;
            num++;
            if (++idx == num_people) {
                idx = 0;
            }
        }
        res[idx] += candies;
        return res;
    }
};