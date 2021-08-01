//--- Q: 0594. Longest Harmonious Subsequence

//--- method 1: map
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (auto &num: nums) {
            ++map[num];
        }
        for (auto &num: nums) {
            if (map.find(num-1) != map.end()) {
                res = max(res, map[num]+map[num-1]);
            }
        }
        return res;
    }
};

//--- method 2: sort and cnt
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = -1000000002, lcnt = 0, cnt = 1, res = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i-1]) {
                if (nums[i-1]-last == 1) {
                    res = max(res, cnt+lcnt);
                }
                lcnt = cnt;
                last = nums[i-1];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return res;
    }
};

//--- method 3: queue
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        queue<int> que;
        que.push(0);
        for (int i = 1; i < nums.size(); ++i) {
            while (que.size() && nums[i]-nums[que.front()] > 1) {
                que.pop();
            }
            if (que.size() && nums[i]-nums[que.front()] == 1) {
                res = max(res, i-que.front()+1);
            }
            if (nums[i] > nums[i-1]) {
                que.push(i);
            }
        }
        return res;
    }
};

//--- method 4: sort and find interval
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, lstart = 0, nstart = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i]-nums[lstart] > 1) {
                lstart = nstart;
            }
            if (nums[i]-nums[lstart] == 1) {
                res = max(res, i-lstart+1);
            }
            if (nums[i] > nums[i-1]) {
                nstart = i;
            }
        }
        return res;
    }
};


