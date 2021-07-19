//--- Q: 0364. Nested List Weight Sum II

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//--- method 1: top down add unweighted into weighted(res)
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int tsum = 0, csum = 0;
        for (; nestedList.size();) {
            vector<NestedInteger> next_list;
            for (auto &element: nestedList) {
                if (element.isInteger()) {
                    csum += element.getInteger();
                } else {
                    next_list.insert(next_list.end(), element.getList().begin(), element.getList().end());
                }
            }
            nestedList = next_list;
            tsum += csum;
        }
        return tsum;
    }
};