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
                res.push_back((double(*median) + *prev(median))/2);
            }
            if (i == nums.size()) {
                break;
            }
            set.insert(nums[i]);
            if (nums[i] < *median) {
                --median;
            }
            if (nums[i-k] <= *median) {
                ++median;
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
        auto left_cmp = [&nums](int i, int j) {
            return nums[i] > nums[j] || nums[i] == nums[j] && i > j;
        };
        auto right_cmp = [&nums](int i, int j) {
            return nums[i] < nums[j] || nums[i] == nums[j] && i < j;
        };
        set<int, decltype(left_cmp)> left(left_cmp);
        set<int, decltype(right_cmp)> right(right_cmp);        
        auto balance = [&left, &right, &nums]() {
            while (left.size() >= right.size()) {
                right.insert(*left.begin());
                left.erase(left.begin());
            }
            if (left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };
        vector<double> res;
        auto median = [&nums, &left, &right, k]() -> double {
            if (k&1) {
                return (double)nums[*left.begin()];
            } else {
                return ((double)nums[*left.begin()]+nums[*right.begin()])/2;
            }
        };
        for (int i = 0; i < k; ++i) {
            left.insert(i);
        }
        balance();
        res.push_back(median());
        for (int i = k; i < nums.size(); ++i) {
            if (left.find(i-k) != left.end()) {
                left.erase(i-k);
            } else {
                right.erase(i-k);
            }
            left.insert(i);
            balance();
            res.push_back(median());
        }
        return res;
    }
};