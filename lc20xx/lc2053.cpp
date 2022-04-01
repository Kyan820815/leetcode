//--- Q: 2053. Kth Distinct String in an Array

//--- method 1: map operation
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (auto &str: arr) {
            ++map[str];
        }
        for (auto &str: arr) {
            if (map[str] == 1) {
                if (!--k) {
                    return str;
                }
            }
        }
        return "";
    }
};