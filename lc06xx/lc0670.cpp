//--- Q: 0670. Maximum Swap

//--- method 1: find the last pair that num[i] < num[maxi]
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size(), maxi = n-1;
        pair<int,int> p = {n-1, n-1};
        for (int i = n-1; i >= 0; --i) {
            if (str[i] < str[maxi]) {
                p.first = i;
                p.second = maxi;                
            } else if (str[i] > str[maxi]) {
                maxi = i;
            }
        }
        swap(str[p.first], str[p.second]);
        return stoi(str);
    }
};