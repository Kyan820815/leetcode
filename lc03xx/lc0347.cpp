//--- Q: 0347. Top K Frequent Elements

//--- method 1: bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        vector<vector<int>> bucket(nums.size()+1);
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &num: map) {
            bucket[num.second].push_back(num.first);
        }
        for (int i = nums.size(); i > 0 && k; --i) {
            for (int j = 0; j < bucket[i].size() && k; ++j, --k)  {
                res.push_back(bucket[i][j]);
            }
        }
        return res;
    }
};

//--- method 2: min heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        auto comp = [&map](int &a, int &b) {
            return map[a] > map[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &num: map) {
            que.push(num.first);
            if (que.size() > k) {
                que.pop();
            }
        }
        while (que.size()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};