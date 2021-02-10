//--- Q: 1356. Sort Integers by The Number of 1 Bits

//--- method 1: count bits
class Solution {
public:
    int count(int a) {
        int cnt = 0;
        while (a) {
            a = a&(a-1);
            ++cnt;
            // cnt += a&1;
            // a >>= 1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int &a, int &b) {
            int vala = count(a), valb = count(b);
            return vala <  valb || vala == valb && a < b;
        });
        return arr;
    }
};