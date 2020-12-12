//--- Q: 1507. Reformat Date

//--- method 1: string operation
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> month;
        month["Jan"] = "01";
        month["Feb"] = "02";
        month["Mar"] = "03";
        month["Apr"] = "04";
        month["May"] = "05";
        month["Jun"] = "06";
        month["Jul"] = "07";
        month["Aug"] = "08";
        month["Sep"] = "09";
        month["Oct"] = "10";
        month["Nov"] = "11";
        month["Dec"] = "12";
        if (date.size() == 13) {
            return date.substr(9) + "-" + month[date.substr(5,3)] + "-" + date.substr(0, 2);
        } else {
            return date.substr(8) + "-" + month[date.substr(4,3)] + "-" + "0" + date.substr(0, 1);
        }
    }
};