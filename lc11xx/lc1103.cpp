//--- Q: 1103. Distribute Candies to People

//--- method 1: linear aggredation, O(sqrt(n))
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int idx = 0, num = 1;
        while (candies-num >= 0) {
            candies -= num;
            res[idx++] += num++;
            if (idx == num_people) {
                idx = 0;
            }
        }
        res[idx] += candies;
        return res;
    }
};