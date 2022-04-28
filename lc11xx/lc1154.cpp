//--- Q: 1154. Day of the Year

//--- method 1: leap year
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = (date[5]-'0')*10 + (date[6]-'0');
        int day = (date[8]-'0')*10 + (date[9]-'0');
        int isMore = year%4 == 0 && year%100 != 0 || year%400 == 0;
        for (int i = 1; i < month; ++i) {
            day += 30 + (i < 8 ? i&1 : !(i&1));
        }
        if (month > 2) {
            day -= isMore ? 1 : 2;
        }
        return day;
    }
};