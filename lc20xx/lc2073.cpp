//--- Q: 2073. Time Needed to Buy Tickets

//--- method 1: one pass
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        for (int i = 0; i < tickets.size(); ++i) {
            int val = min(tickets[i], tickets[k]);
            if (i > k && val == tickets[k]) {
                --val;
            }
            res += val;
        }
        return res;
    }
};
