//--- Q: 207. Course Schedule

//--- method 1: dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> connect;
		vector<int> path(numCourses, 0);
		bool find = true;
        connect.resize(numCourses);
		for (int i = 0; i < prerequisites.size(); ++i)
			connect[prerequisites[i][0]].push_back(prerequisites[i][1]);
    	for (int i = 0; i < numCourses; ++i)
    	{
            if (path[i] == 0)
    		  dfs(path, connect, find, i);
    		if (!find) break;
    	}
    	return find;
    }
    void dfs(vector<int> &path, vector<vector<int>> &connect, bool &find, int now)
    {
    	path[now] = 1;
    	for (int i = 0; i < connect[now].size(); ++i)
    	{
			if (path[connect[now][i]] == 1)
    		{
    			find = false;
    			return;
    		}
    		else if (path[connect[now][i]] == 2)
    			continue;
    		else
				dfs(path, connect, find, connect[now][i]);
    	}
    	path[now] = 2;
    }
};

//--- method 2: bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> connect;
        vector<int> in_degree(numCourses, 0);
        bool find = true;

        connect.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            connect[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in_degree[prerequisites[i][1]]++;
        }
        return  bfs(in_degree, connect, numCourses);;
    }
    bool bfs(vector<int> &in_degree, vector<vector<int>> &connect, int numCourses)
    {
        int top;
        queue<int> que; 
        for (int i = 0; i < numCourses; ++i)
        {
            if (in_degree[i] == 0)
                que.push(i);
        }
        int count = que.size();
        while(!que.empty())
        {
            top = que.front();
            for (int i = 0; i < connect[top].size(); ++i)
            {
                in_degree[connect[top][i]]--;
                if (in_degree[connect[top][i]] == 0)
                {
                    que.push(connect[top][i]);
                    count++;
                }
            }
            que.pop();
        }
        return (count != numCourses) ? false : true;
    }
};