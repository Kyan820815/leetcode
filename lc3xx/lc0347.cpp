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

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector<vector<int>> cnt(nums.size()+1);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }
        for (auto &m: map) {
            cnt[m.second].push_back(m.first);
        }
        for (int i = cnt.size()-1; i >= 1 && k > 0; --i) {
            for (int j = 0; j < cnt[i].size() && k > 0; ++j) {
                res.push_back(cnt[i][j]);
                --k;
            }
        }
        return res;
    }
};