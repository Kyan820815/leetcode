//--- Q: 738. Monotone Increasing Digits

//--- method 1: flush with 9 when previous index > now index
class Solution {
public:
    int monotoneIncreasingDigits(int N, int sum = 0) {
        string res = to_string(N);
        int flow = res.size();
        for (int i = res.size()-1; i > 0; --i) {
            if (res[i-1] > res[i]) {
                --res[i-1];
                flow = i;
            }
        }
        for (int i = flow; i < res.size(); ++i) {
            res[i] = '9';
        }
        return stoi(res);
    }
};