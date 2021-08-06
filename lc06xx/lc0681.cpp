//--- 0681. Next Closest Time

//--- method 1: set finding upper bound
class Solution {
public:
    string nextClosestTime(string time) {
        set<char> set = {time[0], time[1], time[3], time[4]};
        char now;
        string res = time;
        
        now = time[4];
        res[4] = findnext(now, '9', set);
        if (res[4] > now) {
            return res;
        }
        
        now = time[3];
        res[3] = findnext(now, '5', set);
        if (res[3] > now) {
            return res;
        }
        
        now = time[1];
        char boundary = time[0] <= '1' ? '9' : '3';
        res[1] = findnext(now, boundary, set);
        if (res[1] > now) {
            return res;
        }
        
        now = time[0];
        res[0] = findnext(now, '2', set);
        return res;
    }
    char findnext(char now, char boundary, set<char> &set) {
        auto next = set.upper_bound(now);
        return next == set.end() || *next > boundary ? *set.begin() : *next;
    }
};

