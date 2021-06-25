//--- Q: 797. All Paths From Source to Target

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    	vector<vector<int>> path;
    	vector<int> now_path;
    	dfs(graph, path, 0, now_path);
    	return path;
    }
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &path, int idx, vector<int> &now_path)
    {
    	now_path.push_back(idx);
    	if (graph[idx].size() == 0)
    	{
    		path.push_back(now_path);
    	}
    	for (int i = 0; i < graph[idx].size(); ++i)
    	{
    		dfs(graph, path, graph[idx][i], now_path);
    	}
    	now_path.pop_back();
    }
};