//--- 681. Next Closest Time

//--- method 1:
class Solution {
public:
    set<char> set;
    string nextClosestTime(string time) {
        char ori;
        set = {time[0], time[1], time[3], time[4]};
        string result = time;
        ori = result[4];
        result[4] = findnext(ori, '9');
        if (result[4] > ori) {
            return result;
        }
        ori = result[3];
        result[3] = findnext(ori, '5');
        if (result[3] > ori) {
            return result;
        }
        ori = result[1];
        result[1] = result[0] == '2' ? findnext(ori, '3') : findnext(ori, '9');
        if (result[1] > ori) {
            return result;
        }
        ori = result[0];
        result[0] = findnext(ori, '2');
        return result;
        
    }
    char findnext(char cur, char upper) {
        auto next = set.upper_bound(cur);
        return next != set.end() && *next <= upper ? *next : *set.begin();
    }
};