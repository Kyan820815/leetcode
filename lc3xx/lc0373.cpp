//--- Q: 373. Find K Pairs with Smallest Sums

//--- method 1: prioirty queue, min heap
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.size() == 0 || nums2.size() == 0)
            return res;
        auto comp = [&nums1, &nums2](vector<int> &a, vector<int> &b)
        {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        que.push({0, 0});
        while (k > 0 && que.size() > 0)
        {
            vector<int> now = que.top();
            que.pop();
            res.push_back({nums1[now[0]], nums2[now[1]]});
            --k;
            if (now[0]+1 < nums1.size())
                que.push({now[0]+1, now[1]});
            if (now[0] == 0 && now[1]+1 < nums2.size())
                que.push({now[0], now[1]+1});
        }
        return res;
    }
};

//--- method 2: prioirty queue, max heap
class Solution {
public:
	static bool comp(vector<int> &a, vector<int>&b)
	{
		return a[0]+a[1] < b[0]+b[1];
	}
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> que(&comp);
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); ++i)
        {
        	for (int j = 0; j < nums2.size(); ++j)
        	{
        		if (que.size() < k)
        			que.push({nums1[i], nums2[j]});
        		else
        		{
        			int sum = nums1[i] + nums2[j];
        			if (sum <= que.top()[0]+que.top()[1])
        			{
        				que.pop();
        				que.push({nums1[i], nums2[j]});
        			}
        		}
        	}
        }
        while (que.size() > 0)
        {
        	res.push_back(que.top());
        	que.pop();
        }
        return res;
    }
};