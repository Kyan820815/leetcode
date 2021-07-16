//--- Q: 0339. Nested List Weight Sum

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

//--- method 1: iteartion
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int level = 1, val = 0;
        for (;nestedList.size();) {
            vector<NestedInteger> tmp;
            for (auto &element: nestedList) {
                if (element.isInteger()) {
                    val += element.getInteger() * level;
                } else {
                    auto list = element.getList();
                    tmp.insert(tmp.end(), list.begin(), list.end());
                }
            }
            nestedList = tmp;
            ++level;
        }
        return val;
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList, int level=0) {
        int val = 0;
        ++level;
        for (auto &element: nestedList) {
            if (element.isInteger()) {
                val += element.getInteger() * level;
            } else {
                auto next_list = element.getList();
                val += depthSum(next_list, level);
            }
        }
        return val;
    }
};