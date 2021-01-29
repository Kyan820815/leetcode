//--- Q: 1732. Find the Highest Altitude

//--- method 1: linear find
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, res = 0;
        for (int i = 0; i < gain.size(); ++i) {
            sum += gain[i];
            res = max(res, sum);
        }
        return res;
    }
};