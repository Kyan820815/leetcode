//--- Q: 2037. Minimum Number of Moves to Seat Everyone

//--- method 1: sort
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = students.size(), res = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < n; ++i) {
            res += abs(students[i]-seats[i]);
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = students.size(), res = 0;
        vector<int> seatBucket(101, 0), studentBucket(101, 0);
        for (int i = 0; i < n; ++i) {
            ++seatBucket[seats[i]];
            ++studentBucket[students[i]];
        }
        int i = 1, j = 1;
        while (n) {
            while (!seatBucket[i]) {
                ++i;
            }
            while (!studentBucket[j]) {
                ++j;
            }
            res += abs(i-j);
            --seatBucket[i];
            --studentBucket[j];
            --n;
        }
        return res;
    }
};

