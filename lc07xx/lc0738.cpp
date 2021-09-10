//--- Q: 0738. Monotone Increasing Digits

//--- method 1: flush with 9 when previous index > now index
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int last = str.size();
        for (int i = str.size()-1; i > 0; --i) {
            if (str[i-1] > str[i]) {
                --str[i-1];
                last = i-1;
            }
        }
        for (int i = last+1; i < str.size(); ++i) {
            str[i] = '9';
        }
        return stoi(str);
    }
};