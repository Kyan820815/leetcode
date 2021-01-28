//--- Q: 1518. Water Bottles

//--- method 1: log(n) time
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while (numBottles >= numExchange) {
            int drink = numBottles/numExchange;
            res += drink;
            numBottles = drink + numBottles%numExchange;
        }
        return res;
    }
};

//--- method 1: O(1) time
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};