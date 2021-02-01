//--- Q: 1700. Number of Students Unable to Eat Lunch

//--- method 1: two pointer
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), left = 0, right = 0, cnt = n, times = 0;
        while (right < n) {
            if (students[left] == sandwiches[right]) {
                --cnt;
                times = 0;
                students[left] = -1;
                ++right;
            } else if (students[left] >= 0) {
                ++times;
            }
            if (times == cnt) {
                break;
            }
            left = (left+1) % n;
        }
        return cnt;
    }
};

//--- method 1: two pass, bucket sort
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), k = 0;
        vector<int> cnt(2, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[students[i]];
        }
        for (k = 0; k < n; ++k) {
            if (--cnt[sandwiches[k]] < 0) {
                break;
            }
        }
        return n-k;
    }
};