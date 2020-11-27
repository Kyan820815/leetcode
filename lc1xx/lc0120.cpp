//--- Q: 120. Triangle

//--- O(1) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        triangle.push_back(vector<int>(n+1,0));
        for (int i = n-1; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};

//--- method 1-1: dp iteration, O(n) space, better, clean code
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> check(triangle.size()+1, 0);
        for (int i = triangle.size()-1; i >= 0; --i)
        	for(int j = 0; j <= i; ++j)
        		check[j] = min(check[j], check[j+1])+triangle[i][j];
        return check[0];
    }
};

//--- method 1-2: dp iteration, O(n) space, better
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> check;
        check = triangle[triangle.size()-1];
        for (int i = triangle.size()-1; i >= 1; --i)
        	for(int j = 0; j < i; ++j)
        		check[j] = min(check[j], check[j+1])+triangle[i-1][j];
        return check[0];
    }
};

//--- method 2: dp iteration, O(n^2) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> check;
        check.resize(triangle.size());
        check[triangle.size()-1] = triangle[triangle.size()-1];
        for (int i = triangle.size()-1; i >= 1; --i)
        {
        	check[i-1].resize(i);
        	for(int j = 0; j < check[i-1].size(); ++j)
        	{
        		check[i-1][j] = min(check[i][j], check[i][j+1])+triangle[i-1][j];
        	}
        }
        return check[0][0];
    }
};

//--- method 3: dfs, but will be TLE
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min_sum = INT_MAX;
        dfs(triangle, 0, min_sum, 0, 0);
        return min_sum;
    }
    void dfs(vector<vector<int>> &triangle, int sum, int &min_sum, int level, int idx)
    {
    	sum = sum + triangle[level][idx];
    	if (level == triangle.size()-1)
    	{
    		min_sum = min(min_sum, sum);
    		return;
    	}
    	dfs(triangle, sum, min_sum, level+1, idx);
    	dfs(triangle, sum, min_sum, level+1, idx+1);
    }
};