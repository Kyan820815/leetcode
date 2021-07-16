//--- Q: 0341. Flatten Nested List Iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//--- method 1: stack recursion
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            sk.push_back(*it);
        }
    }
    
    int next() {
        auto val = sk.back();
        sk.pop_back();
        return val.getInteger();
    }
    
    bool hasNext() {
        while (sk.size() && !sk.back().isInteger()) {
            auto back = sk.back().getList();
            sk.pop_back();
            for (auto it = back.rbegin(); it != back.rend(); ++it) {
                sk.push_back(*it);
            }
        }
        return sk.size();
    }
    vector<NestedInteger> sk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */