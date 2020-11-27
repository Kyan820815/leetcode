//--- Q: 1299. Replace Elements with Greatest Element on Right Side

//--- method 1: backfoward, better
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxv = -1;
        for (int i = arr.size()-1; i >= 0; --i) {
            int tmp = maxv;
            maxv = max(maxv, arr[i]);
            arr[i] = tmp;
        }
        return arr;
    }
};

//--- method 2: backfoward
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> sk = {(int)arr.size()-1};
        for (int i = arr.size()-2; i >= 0; --i) {
            if (arr[sk.back()] < arr[i]) {
                sk.push_back(i);
            }
        }
        for (int i = 0; i < arr.size() && sk.size();) {
            if (i < sk.back()) {
                arr[i++] = arr[sk.back()];
            } else {
                sk.pop_back();
            }
        }
        arr.back() = -1;
        return arr;
    }
};