//--- Q: 986. Interval List Intersections

//--- method 1: O(m+n) merge 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	   	int a = 0, b = 0;
	   	int start, end;
	   	vector<vector<int>> res;
	   	while (a < A.size() && b < B.size())
	   	{
	   		if (A[a][1] < B[b][0])
	   			++a;
	   		else if (B[b][1] < A[a][0])
	   			++b;
	   		else
	   		{
	   			start = max(A[a][0], B[b][0]);
	   			if (A[a][1] < B[b][1])
	   			{
	   				end = A[a][1];
	   				++a;
	   			}
   				else
   				{
   					end = B[b][1];
   					++b;
   				}
	   			res.push_back({start,end});
	   		}
	   	}
	   	return res;
    }
};
