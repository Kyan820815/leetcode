//--- Q: 2099. Find Subsequence of Length K With the Largest Sum

//--- method 1: quick select
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res, tmp = nums;
        nth_element(tmp.begin(), tmp.begin()+k-1, tmp.end(), [](const int &a, const int &b){
            return a > b;
        });
        int kth = tmp[k-1], kcnt = 0;
        for (int i = 0; i < k; ++i) {
            kcnt += tmp[i] == kth;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (k && (nums[i] > kth || nums[i] == kth && kcnt-- > 0)) {
                res.push_back(nums[i]);
                --k;
            }
        }
        return res;
    }
};

//--- method 2: priority queue
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res, idx;
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        auto comp = [&nums](const int &a, const int &b) {
            return nums[a] > nums[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que1(comp);
        priority_queue<int, vector<int>, greater<int>> que2;
        for (int i = 0; i < nums.size(); ++i) {
            que1.push(i);
            if (que1.size() > k) {
                que1.pop();
            }
        }
        while (que1.size()) {
            que2.push(que1.top());
            que1.pop();
        }
        while (que2.size()) {
            res.push_back(nums[que2.top()]);
            que2.pop();
        }
        return res;
    }
};

//--- method 3: map operation
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> map;
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
            if (i >= k) {
                if (!--map.begin()->second) {
                    map.erase(map.begin());
                }
            }
        }
        for (auto &num: nums) {
            if (map.find(num) != map.end()) {
                res.push_back(num);
                if (!--map[num]) {
                    map.erase(num);
                }
            }
        }
        return res;
    }
};