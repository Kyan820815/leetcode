//--- Q: 1281. Subtract the Product and Sum of Digits of an Integer

//--- method 1:
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while (n) {
            int val = n%10;
            sum += val;
            product *= val;
            n /= 10;
        }
        return product - sum;
    }
};