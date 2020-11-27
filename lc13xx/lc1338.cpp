//--- Q: 1338. Reduce Array Size to The Half

//--- method 1: bucket sort
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> cnt(100001, 0), nums(100001, 0);
        int res = 0, total = arr.size();
        for (int i = 0; i < arr.size(); ++i) {
            ++nums[arr[i]];
        }
        for (int i = 1; i <= 100000; ++i) {
            if (nums[i]) {
                ++cnt[nums[i]];
            }
        }
        for (int i = 10000; i >= 1 && total > arr.size()/2; --i) {
            if (cnt[i]) {
                for (int j = 0; j < cnt[i] && total > arr.size()/2; ++j) {
                    ++res;
                    total -= i;
                }
            }
        }
        return res;
    }
};

//--- method 2: priority queue
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> cnt(100001, 0), nums(100001, 0);
        priority_queue<int> que;
        int res = 0, total = arr.size();
        for (int i = 0; i < arr.size(); ++i) {
            ++nums[arr[i]];
        }
        for (int i = 1; i <= 100000; ++i) {
            if (nums[i]) {
                que.push(nums[i]);
            }
        }
        while (que.size() && total > arr.size()/2) {
            total -= que.top();
            que.pop();
            ++res;
        }
        return res;
    }
};