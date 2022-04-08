//--- Q: 1630. Arithmetic Subarrays

//--- method 1: sort
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        int n = l.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<int,int> map;
            int minv = INT_MAX, maxv = INT_MIN;
            vector<int> tmp(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(tmp.begin(), tmp.end());
            int diff = tmp[1]-tmp[0], find = 1;
            for (int i = 2; i < tmp.size(); ++i) {
                if (tmp[i]-tmp[i-1] != diff) {
                    find = 0;
                    break;
                }
            }
            res.push_back(find);
        }
        return res;
    }
};

//--- method 2: no sort
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        int n = l.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<int,int> map;
            int minv = INT_MAX, maxv = INT_MIN;
            for (int j = l[i]; j <= r[i]; ++j) {
                minv = min(minv, nums[j]);
                maxv = max(maxv, nums[j]);
                ++map[nums[j]];
            }
            int cnt = r[i]-l[i];
            if ((maxv-minv) % cnt != 0) {
                res.push_back(false);
                continue;
            }
            int diff = (maxv-minv)/cnt, cur = minv, valid = 1;
            --map[cur];
            for (int j = 0; j < cnt; ++j) {
                cur += diff;
                if (--map[cur] < 0) {
                    valid = 0;
                    break;
                }
            }
            res.push_back(valid);
        }
        return res;
    }
};