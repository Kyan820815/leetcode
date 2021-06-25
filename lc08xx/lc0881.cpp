//--- Q: 881. Boats to Save People

//--- method 1: two pointer
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(), people.rend());
        int left = 0, right = people.size()-1, res = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                --right;
            }
            ++left;
            ++res;
        }
        return res;
    }
};