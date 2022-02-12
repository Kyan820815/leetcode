//--- Q: 2160. Minimum Sum of Four Digit Number After Splitting Digits

//--- method 1: sort and greedy
class Solution {
public:
    int minimumSum(int num) {
        array<int,4> arr;
        for (int i = 3; i >= 0; --i) {
            arr[i] = num%10;
            num /= 10;
        }
        sort(arr.begin(), arr.end());
        return arr[0]*10+arr[2] + arr[1]*10+arr[3];
    }
};