//--- Q: 1775. Equal Sum Arrays With Minimum Number of Operations

//--- method 1: greedy
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size()*6 < nums1.size() || nums1.size()*6 < nums2.size()) {
            return -1;
        }
        vector<int> cnt(7, 0);
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 > s2) {
            swap(nums1, nums2);
        }
        for (auto &num: nums1) {
            ++cnt[6-num];
        }
        for (auto &num: nums2) {
            ++cnt[num-1];
        }
        int diff = abs(s1-s2), res = 0;
        for (int i = 5; i >= 1 && diff > 0; --i)         {
            int take = min(diff/i + (diff % i != 0), cnt[i]);
            diff -= take*i;
            res += take;
        }
        return res;
    }
};

//--- method 2: two priority queue
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size()*6 < nums1.size() || nums1.size()*6 < nums2.size()) {
            return -1;
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 > s2) {
            swap(nums1, nums2);
        }
        priority_queue<int, vector<int>, greater<int>> que1(nums1.begin(), nums1.end());
        priority_queue<int> que2(nums2.begin(), nums2.end());
        int diff = abs(s1-s2), res = 0;
        while (diff > 0) {
            if (!que1.size() || que2.size() && 6-que1.top() < que2.top()-1) {
                diff -= (que2.top()-1);
                que2.pop();
            } else {
                diff -= (6-que1.top());
                que1.pop();
            }
            ++res;
        }
        return res;
    }
};
