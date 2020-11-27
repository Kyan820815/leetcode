//--- Q: 547. Friend Circles

//--- method 1: dfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
    	int res = 0, n = M.size();
    	vector<int> visit(n,0);
        for (int i = 0; i < n; ++i)
        {
    		if (!visit[i])
    		{
    			dfs(M, i, n, visit);
    			++res;
    		}
        }
        return res;
    }
    void dfs(vector<vector<int>> &M, int i, int n, vector<int> &visit)
    {
    	visit[i] = 1;
    	for (int k = 0; k < n; ++k)
    	{
    		if (M[i][k] && !visit[k])
    		{
    			dfs(M, k, n, visit);
    		}
    	}
    }
};

//--- method 2: bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
    	int res = 0, n = M.size();
    	vector<int> visit(n,0);
        for (int i = 0; i < n; ++i)
        {
    		if (!visit[i])
    		{
    			bfs(M, i, n, visit);
    			++res;
    		}
        }
        return res;
    }
    void bfs(vector<vector<int>> &M, int i, int n, vector<int> &visit)
    {
    	queue<int> que;
    	que.push(i);
    	visit[i] = 1;
    	while (que.size())
    	{
    		int now = que.front();
    		que.pop();
    		for (int j = 0; j < n; ++j)
    		{
    			if (!visit[j] && M[now][j])
    			{
    				visit[j] = 1;
    				que.push(j);
    			}
    		}
    	}
    }
};