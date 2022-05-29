//--- Q: 1360. Number of Days Between Two Dates

//--- method 1: compute between two dates
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (date1 > date2) {
            swap(date1, date2);
        }
        auto arr1 = process(date1);
        auto arr2 = process(date2);
        int res = 0;
        auto isLeap = [](int y) {
            return y%4 == 0 && (y%100 != 0 || y%400 == 0);
        };
        function<int(int,int,int)> compute = [&months, &isLeap](int start, int end, int year) {
            int days = 0;
            for (int i = start; i <= end; ++i) {
                days += months[i-1];
            }
            days += start <= 2 && 2 <= end && isLeap(year);
            return days;
        };
		for (int i = arr1[0]+1; i < arr2[0]; ++i) {
            res += 365 + isLeap(i);
        }
        if (arr1[0] < arr2[0]) {
            res += compute(arr1[1],12,arr1[0]);
            res += compute(1,arr2[1]-1,arr2[0]);
        } else {
            res += compute(arr1[1],arr2[1]-1,arr2[0]);
        }
        return res+arr2[2]-arr1[2];
    }
    vector<int> process(string &date) {
        int pos1 = 0;
        int pos2 = date.find('-', pos1);
        int pos3 = date.find('-', pos2+1);
        return {stoi(date.substr(pos1, pos2-pos1)), 
                stoi(date.substr(pos2+1, pos3-pos2-1)),
                stoi(date.substr(pos3+1))};
    }
};

//--- method 2: dates diff from 1971
class Solution {
public:
    vector<int> months = {31,28,31,30,31,30,31,31,30,31,30,31};
    int daysBetweenDates(string date1, string date2) {
		return abs(daysFrom1971(date1)-daysFrom1971(date2));
    }
    int daysFrom1971(string &date) {
        auto isLeap = [](int y) {
            return y%4 == 0 && (y%100 != 0 || y%400 == 0);
        };
        int y = stoi(date.substr(0,4)), m = stoi(date.substr(5,2)), d = stoi(date.substr(8));
        int days = 0;
        for (int i = 1971; i < y; ++i) {
            days += 365 + isLeap(i);
        }
        return days + d + (m > 2 && isLeap(y)) + accumulate(months.begin(), months.begin()+m-1, 0);
    }
};

