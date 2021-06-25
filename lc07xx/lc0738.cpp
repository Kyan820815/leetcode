//--- Q: 738. Monotone Increasing Digits

//--- method 1: flush with 9 when previous index > now index
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int flush = num.size();
        for (int i = num.size()-2; i >= 0; --i) {
            if (num[i] > num[i+1]) {
                flush = i+1;
                --num[i];
            }
        }
        if (flush < num.size()) {
            for (int i = flush; i < num.size(); ++i) {
                num[i] = '9';
            }
        }
        return stoi(num);
    }
};