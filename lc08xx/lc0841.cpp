//--- Q: 841. Keys and Rooms

//--- method 1: bfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), qsize = 1;
        vector<bool> exist(n, false);
        exist[0] = true;
        queue<int> que;
        que.push(0);
        while (que.size())
        {
        	for (int i = 0; i < qsize; ++i)
        	{
        		int now = que.front();
        		n--;
        		que.pop();
        		for (int j = 0; j < rooms[now].size(); ++j)
        		{
        			if (!exist[rooms[now][j]])
        			{
        				que.push(rooms[now][j]);
        				exist[rooms[now][j]] = true;
        			}
        		}
        	}
        	qsize = que.size();
        }
        return (n == 0) ? true : false;
    }
};

//--- method 2: dfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> exist(n, false);
        exist[0] = true;
        dfs(rooms, exist, n, 0);
        return (n == 0) ? true : false;
    }
    void dfs(vector<vector<int>> &rooms, vector<bool> &exist, int &n, int now)
    {
    	--n;
    	for (int i = 0; i < rooms[now].size(); ++i)
    	{
    		if (!exist[rooms[now][i]])
    		{
    			exist[rooms[now][i]] = true;
    			dfs(rooms, exist, n, rooms[now][i]);
    		}
    	}
    }
};