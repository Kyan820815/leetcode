//--- Q: 341. Flatten Nested List Iterator

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

//--- method 1: dfs recursion
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
    	dfs(nestedList, res);
    	nIdx = 0;
    }

    int next() {
    	return res[nIdx++];
    }
    bool hasNext() {
    	return (nIdx < res.size()) ? true : false;
    }
	void dfs(vector<NestedInteger> &nestedList, vector<int> &res)
	{
		for (int i = 0; i < nestedList.size(); ++i)
		{
			if (nestedList[i].isInteger())
				res.push_back(nestedList[i].getInteger());
			else
				dfs(nestedList[i].getList(), res);
		}
	}
 private:
 	vector<int> res;
 	int nIdx;
};

//--- method 2: stack recursion
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >= 0; --i)
            sk.push(nestedList[i]);
    }

    int next() {
        return val;
    }

    bool hasNext() {
        if (sk.size())
        {
            while (sk.size() && !sk.top().isInteger())
            {
                vector<NestedInteger> tmp = sk.top().getList();
                sk.pop();
                for (int i = tmp.size()-1; i >= 0; --i)
                    sk.push(tmp[i]);
            }
            if (!sk.size()) return false;
            val = sk.top().getInteger();
            sk.pop();
            return true;
        }
        else return false;
    }
private:
    stack<NestedInteger> sk;
    int val;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */