//--- Q: 1523. Count Odd Numbers in an Interval Range

//--- method 1: check low and high are odd or not
class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low+1)/2 + (low & high & 1);
    }
};