//--- Q: 1491. Average Salary Excluding the Minimum and Maximum Salary

//--- method 1: linear processing
class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), minv = 1000000, maxv = 1000, sum = 0;
        for (auto &money: salary) {
            minv = min(minv, money);
            maxv = max(maxv, money);
            sum += money;
        }
        return (double)(sum-minv-maxv)/(n-2);
    }
};