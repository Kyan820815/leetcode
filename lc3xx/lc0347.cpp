//--- Q: 347. Top K Frequent Elements

//--- method 1: heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        auto comp = [&map](int a, int b)
        {
            return  map[a] > map[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        for (int i = 0; i < nums.size(); ++i)
            ++map[nums[i]];
        for (auto &m: map)
        {
            if (que.size() < k)
                que.push(m.first);
            else if (m.second > map[que.top()])
            {
                que.pop();
                que.push(m.first);
            }
        }
        while (que.size())
        {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appear;
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> ans;
        int cnt = 0;

        for (int i = 0; i < nums.size(); ++i)
            appear[nums[i]]++;

        for (auto &a: appear)
        {
            int times = a.second;
            int val = a.first;
            bucket[times].push_back(val);
        }

        for (int i = nums.size(); i >= 1; --i)
        {
            if (bucket[i].size() != 0)
            {
                for (int j = 0; j < bucket[i].size(); ++j)
                {
                    if (cnt++ < k)
                        ans.push_back(bucket[i][j]);
                    else
                        return ans;
                }
            }
        }
        return ans;
    }
};