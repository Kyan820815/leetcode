//--- Q: 1985. Find the Kth Largest Integer in the Array

//--- method 1: built in sort function
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), [](string &a, string &b) {
            return a.size() > b.size() || a.size() == b.size() && a > b;
        });
        return nums[k-1];
    }
};

//--- method 2: map lamda function
class Solution {
public:
    using mymap = map<string, int, function<bool(const string&, const string&)>>;
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string &a, const string &b) {
            return a.size() > b.size() || a.size() == b.size() && a > b;
        };
        mymap map(comp);
        for (auto &str: nums) {
            ++map[str];
        }
        int cnt = 0;
        for (auto &node: map) {
            cnt += node.second;
            if (cnt >= k) {
                return node.first;
            }
        }
        return "";
    }
};