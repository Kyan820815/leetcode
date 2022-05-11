//--- Q: 1701. Average Waiting Time

//--- method 1: interval
class Solution {
public:
    using ll = long long;
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res;
        ll finisht = 0, waitingt = 0;
        for (auto &customer: customers) {
            if (customer[0] < finisht) {
                waitingt += customer[1] + finisht - customer[0];
                finisht += customer[1];
            } else {
                waitingt += customer[1];
                finisht = customer[0]+customer[1];
            }
        }
        return (double)waitingt/customers.size();
    }
};