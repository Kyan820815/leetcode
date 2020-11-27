//--- Q: 1427. Perform String Shifts

//--- method 1: string concatenation
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int diff = 0;
        for (int i = 0; i < shift.size(); ++i) {
            if (!shift[i][0]) {
                diff += shift[i][1];
            } else {
                diff -= shift[i][1];
            }
        }
        diff %= (int)s.size();
        if (diff > 0) {
            return s.substr(diff) + s.substr(0, diff) ;
        } else {
            return s.substr(s.size()+diff) + s.substr(0, s.size()+diff);
        }
    }
};