//--- Q: 977. Squares of a Sorted Array

//--- method 1: double pointer 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int left = 0, right = A.size()-1;
        for (int i = A.size()-1; i >= 0; --i)
        {
        	if (abs(A[left]) > abs(A[right]))
        	{
        		res[i] = pow(A[left], 2);
        		++left;
        	}
        	else
        	{
        		res[i] = pow(A[right], 2);
        		--right;
        	}
        }
        return res;
    }
};

//--- method 2: stack operation 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        stack<int> sk;
        for (int i = 0; i < A.size(); ++i)
        {
        	while (sk.size() && sk.top() < pow(A[i],2))
        	{
        		res.push_back(sk.top());
        		sk.pop();
        	}
        	sk.push(pow(A[i], 2));
        }
        while (sk.size())
        {
        	res.push_back(sk.top());
        	sk.pop();
        }
        return res;
    }
};