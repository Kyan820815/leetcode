//--- Q: 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

//--- method 1: set, shrink
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int left = 0, right = 0, res = 0;
        while (right < nums.size()) {
            s.insert(nums[right++]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
            res = max(res, right-left);
        }
        return res;
    }
};

//--- method 2: set, not shrink
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int left = 0, right = 0;
        while (right < nums.size()) {
            s.insert(nums[right++]);
            if (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
        }
        return right-left;
    }
};

//--- method 3: deque, shrink
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int left = 0, right = 0, res = 0;
        while (right < nums.size()) {
            while (maxd.size() && nums[maxd.back()] < nums[right]) {
                maxd.pop_back();
            }
            while (mind.size() && nums[mind.back()] > nums[right]) {
                mind.pop_back();
            }
            maxd.push_back(right);
            mind.push_back(right);
            while (maxd.size() && mind.size() && nums[maxd.front()]-nums[mind.front()] > limit) {
                if (maxd.front() == left) {
                    maxd.pop_front();
                }
                if (mind.front() == left) {
                    mind.pop_front();
                }
                ++left;
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};


//--- method 4: deque, not shrink
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (maxd.size() && nums[maxd.back()] < nums[right]) {
                maxd.pop_back();
            }
            while (mind.size() && nums[mind.back()] > nums[right]) {
                mind.pop_back();
            }
            maxd.push_back(right);
            mind.push_back(right);
            if (nums[maxd.front()]-nums[mind.front()] > limit) {
                if (maxd.front() == left) {
                    maxd.pop_front();
                }
                if (mind.front() == left) {
                    mind.pop_front();
                }
                ++left;
            }
            ++right;
        }
        return right-left;
    }
};
