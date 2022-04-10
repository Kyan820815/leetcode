//--- Q: 0954. Array of Doubled Pairs

//--- method 1: sort unique value in arr
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> map;
        for (auto &num: arr) {
            ++map[num];
        }
        vector<int> keys;
        for (auto &node: map) {
            keys.push_back(node.first);
        }
        sort(keys.begin(), keys.end(), [](const int &a, const int &b){
            return abs(a) < abs(b);
        });
        for (auto &key: keys) {
            if (map[2*key] < map[key]) {
                return false;
            }
            map[2*key] -= map[key];
        }
        return true;
    }
};

//--- method 2: sort arr
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> map;
        for (auto &num: arr) {
            ++map[num];
        }
        sort(arr.begin(), arr.end());
        for (auto &num: arr) {
            if (!map[num]) {
                continue;
            }
            if (num < 0 && num%2 != 0) {
                return false;
            }
            int target = num < 0 ? num/2 : num*2;
            if (!map[target]) {
                return false;
            }
            --map[target];
            --map[num];
        }
        return true;
    }
};