//--- Q: 2177. Find Three Consecutive Integers That Sum to a Given Number

//--- method 1: divisible by 3
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num%3 != 0) {
            return {};
        }
        long long x = num/3;
        return vector<long long>{x-1, x, x+1};
    }
};