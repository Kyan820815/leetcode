//--- Q: 0480. Sliding Window Median

//--- method 1: multiset
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> set(nums.begin(), nums.begin()+k);
        multiset<int>::iterator median = next(set.begin(), k/2);
        for (int i = k; i <= nums.size(); ++i) {
            if (k&1) {
                res.push_back(*median);
            } else {
                res.push_back(((double)*median+*prev(median))/2);
            }
            if (i == nums.size()) {
                break;
            }
            set.insert(nums[i]);
            if (nums[i] < *median) {
                median = prev(median);
            }
            if (nums[i-k] <= *median) {
                median = next(median);
            }
            set.erase(set.lower_bound(nums[i-k]));
        }
        return res;
    }
};

//--- method 2: two set
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        auto comp_left = [&nums](int a, int b) {
            return nums[a] > nums[b] || nums[a] == nums[b] && a > b;
        };
        auto comp_right = [&nums](int a, int b) {
            return nums[a] < nums[b] || nums[a] == nums[b] && a > b;
        };
        set<int, decltype(comp_left)> left(comp_left);
        set<int, decltype(comp_right)> right(comp_right);
        auto balance = [&left, &right, &nums]() {
            while (left.size() >= right.size()) {
                right.insert(*left.begin());
                left.erase(left.begin());
            }
            if (right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };
        auto median = [&left, &right, &nums]() {
            return left.size() > right.size() ? nums[*left.begin()] : ((double)nums[*left.begin()]+nums[*right.begin()])/2;
        };
        for (int i = 0; i < k; ++i) {
            left.insert(i);
        }
        balance();
        res.push_back(median());
        for (int i = k; i < nums.size(); ++i) {
            left.insert(i);
            if (left.find(i-k) != left.end()) {
                left.erase(i-k);
            } else {
                right.erase(i-k);
            }
            balance();
            res.push_back(median());
        }
        return res;
    }
};

