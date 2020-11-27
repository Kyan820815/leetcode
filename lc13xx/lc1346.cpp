//--- Q: 1346. Check If N and Its Double Exist

//--- method 1: find pair
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for (int i = 0; i < arr.size(); ++i) {
            if (set.find(arr[i] * 2) != set.end() 
                || !(arr[i] & 1) && set.find(arr[i] / 2) != set.end()) {
                return true;
            }
            set.insert(arr[i]);
        }
        return false;
    }
};