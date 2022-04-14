//--- Q: 2103. Rings and Rods

//--- method 1:
class Solution {
public:
    int countPoints(string rings) {
        vector<int> arr(10, 0);
        int n = rings.size(), res = 0;
        for (int i = 0; i < n; i+=2) {
            int idx = rings[i+1]-'0';
            if (rings[i] == 'R') {
                arr[idx] |= 1;
            } else if (rings[i] == 'G') {
                arr[idx] |= 2;
            } else {
                arr[idx] |= 4;
            }
        }
        for (auto &i: arr) {
            res += i == 7;
        }
        return res;
    }
};