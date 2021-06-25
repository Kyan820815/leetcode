//--- Q: 310. Minimum Height Trees

//--- method 1: dfs recursion, my version
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	vector<vector<int>> graph;
    	vector<int> min_label;
    	vector<int> degree(n,0);
		queue<int> que;    	
    	int now_size = 0, q_size;

    	if (edges.size() == 0)
    		return vector<int>{0};
    	graph.resize(n);

    	for (int i = 0; i < edges.size(); ++i)
    	{
    		graph[edges[i][0]].push_back(edges[i][1]);
    		graph[edges[i][1]].push_back(edges[i][0]);
    		degree[edges[i][0]]++;
    		degree[edges[i][1]]++;
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		if (degree[i] == 1)
    			que.push(i);
    	}
    	q_size = que.size();
    	while(!que.empty())
    	{
    		int now = que.front();
    		que.pop();
			degree[now]--;
			q_size--;
			min_label.push_back(now);
    		for (int i = 0; i < graph[now].size(); ++i)
    		{
    			degree[graph[now][i]]--;
    			if (degree[graph[now][i]] == 1)
    			{
    				que.push(graph[now][i]);
    				now_size++;
    			}
    		}
    		if (q_size == 0)
    		{
    			q_size = now_size;
    			if (!que.empty())
    				min_label.clear();
    			now_size = 0;
    		}
    	}
    	return min_label;
    }
};

//--- method 2: clearn code
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	vector<vector<int>> graph;
    	vector<int> min_label;
    	vector<int> degree(n,0);
		queue<int> que;    	
    	int now_size = 0, q_size;

    	if (edges.size() == 0)
    		return vector<int>{0};
    	graph.resize(n);

    	for (int i = 0; i < edges.size(); ++i)
    	{
    		graph[edges[i][0]].push_back(edges[i][1]);
    		graph[edges[i][1]].push_back(edges[i][0]);
    		degree[edges[i][0]]++;
    		degree[edges[i][1]]++;
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		if (degree[i] == 1)
    			que.push(i);
    	}
    	while(n > 2)
    	{
    		int q_size = que.size();
    		n = n-q_size;	
			for (int i = 0; i < q_size; ++i)
			{
				int now = que.front();
				degree[now]--;
				que.pop();
	    		for (int j = 0; j < graph[now].size(); ++j)
	    		{
	    			degree[graph[now][j]]--;
	    			if (degree[graph[now][j]] == 1)
	    				que.push(graph[now][j]);
	    		}
			}
    	}
    	while(que.size() != 0)
    	{
    		min_label.push_back(que.front());
    		que.pop();
    	}
    	return min_label;
    }
};