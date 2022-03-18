//--- Q: 0365. Water and Jug Problem

//--- method 1: gcd
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity+jug2Capacity < targetCapacity) {
            return false;
        }
        return targetCapacity%gcd(jug1Capacity,jug2Capacity) == 0;
    }
};

//--- method 2: find pattern
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity+jug2Capacity == targetCapacity) {
            return true;
        } else if (jug1Capacity+jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity > jug2Capacity) {
            swap(jug1Capacity, jug2Capacity);
        }
        int res = 0;
        while (1) {
            if (res < jug1Capacity) {
                res += jug2Capacity;
            } else {
                res -= jug1Capacity;
            }
            if (res == targetCapacity) {
                return true;
            }
            if (!res) {
                return false;
            }
        }
    }
};