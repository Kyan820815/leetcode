//--- Q: 1122. Relative Sort Array

//--- method 1: lambda sort function
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> idx;
        for (int i = 0; i < arr1.size(); ++i) {
            idx.push_back(i);
        }
        unordered_map<int,int> map;
        for (int i = 0; i < arr2.size(); ++i) {
            map[arr2[i]] = i;
        }
        sort(idx.begin(), idx.end(), [&arr1, &map](const int &a, const int &b) {
            if (map.find(arr1[a]) != map.end() && map.find(arr1[b]) != map.end()) {
                return map[arr1[a]] < map[arr1[b]];
            } else if (map.find(arr1[a]) != map.end()) {
                return true;
            } else if (map.find(arr1[b]) != map.end()) {
                return false;
            } else {
                return arr1[a] < arr1[b];
            }
        });
        vector<int> res;
        for (auto &i: idx) {
            res.push_back(arr1[i]);
        }
        return res;
    }
};

//--- method 2: counting sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res, cnt(1001, 0);
        for (auto &num: arr1) {
            ++cnt[num];
        }
        for (auto &num: arr2) {
            while (cnt[num]) {
                res.push_back(num);
                --cnt[num];
            }
        }
        for (int i = 1; i <= 1000; ++i) {
            while (cnt[i]) {
                res.push_back(i);
                --cnt[i];
            }
        }
        return res;
    }
};