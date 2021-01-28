//--- Q: 1570. Dot Product of Two Sparse Vectors

//--- method 1: map operation
class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                map[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (auto &i: map) {
            if (vec.map.find(i.first) != vec.map.end()) {
                res += i.second*vec.map[i.first];
            }
        }
        return res;
    }
    unordered_map<int, int> map;
};

//--- method 2: two pointer
class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                map.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        int idx1 = 0, idx2 = 0;
        while (idx1 < map.size() && idx2 < vec.map.size()) {
            if (map[idx1].first == vec.map[idx2].first) {
                res += map[idx1].second * vec.map[idx2].second;
                ++idx1, ++idx2;
            } else if (map[idx1].first > vec.map[idx2].first) {
                ++idx2;
            } else {
                ++idx1;
            }
        }
        return res;
    }
    vector<pair<int, int>> map;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);