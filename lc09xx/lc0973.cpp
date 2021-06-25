//--- Q: 973. K Closest Points to Origin

//--- method 1: priority queue
class Solution {
public:
	static bool comp(pair<vector<int>,int> &a, pair<vector<int>,int> &b)
	{
		return a.second < b.second;
	}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<vector<int>,int>, vector<pair<vector<int>,int>>, decltype(&comp)> que(&comp);
        vector<vector<int>> res(K);

        for (int i = 0; i < points.size(); ++i)
        {
        	int x = points[i][0], y = points[i][1];
        	int dis = x*x+y*y;
        	if (que.size() < K)
        		que.push({points[i], dis});
        	else
        	{
        		if (dis < que.top().second)
        		{
        			que.pop();
        			que.push({points[i], dis});
        		}
        	}
        }
        for (int i = K-1; i >= 0; --i)
        {
        	res[i] = que.top().first;
        	que.pop();
        }
        return res;
    }
};

//--- method 2: quick select
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	int left = 0, right = points.size()-1;
    	while (true)
    	{
    		int mid = partition(points, left, right);
    		if (mid == K-1)
    			break;
    		else if (mid < K-1)
    			left = mid+1;
    		else
    			right = mid-1;
    	}
    	return vector<vector<int>>(points.begin(),points.begin()+K);
    }
    int random(int left, int right)
    {
    	return rand()%(right-left+1) + left;
    }
    int partition(vector<vector<int>>& points, int left, int right)
    {
    	int pivot = random(left, right);
    	int dis, mid = left-1;
    	swap(points[pivot], points[right]);
    	pivot = right;
    	dis = points[pivot][0]*points[pivot][0] + points[pivot][1]*points[pivot][1];
    	for (int i = left; i < right; ++i)
    	{
    		int now_dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
    		if (now_dis < dis)
    			swap(points[++mid], points[i]);
    	}
    	swap(points[++mid], points[pivot]);
    	return mid;
    }
};