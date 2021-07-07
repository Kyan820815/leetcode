//--- Q: 0179. Largest Number

//--- method 1: built-in function
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto &num: nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return a+b > b+a; 
        });
        string res =  "";
        for (auto &str: arr) {
            res += str;
        }
        return res[0] == '0' ? "0" : res;
    }
};

//--- method 2: divide and conquer
class Solution {
public:
    vector<string> arr;
    string largestNumber(vector<int>& nums) {
        for (auto &num: nums) {
            arr.push_back(to_string(num));
        }
        divide(0, arr.size()-1);
        string res =  "";
        for (auto &str: arr) {
            res += str;
        }
        return res[0] == '0' ? "0" : res;
    }
    void divide(int start, int end) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid);
            divide(mid+1, end);
            conquer(start, mid, end);
        }
    }
    void conquer(int start, int mid, int end) {
        int i = start, j = mid+1;
        vector<string> cpy;
        while (i <= mid && j <= end) {
            if (arr[i]+arr[j] > arr[j]+arr[i]) {
                cpy.push_back(arr[i++]);
            } else {
                cpy.push_back(arr[j++]);
            }
        }
        while (i <= mid) {
            cpy.push_back(arr[i++]);
        }
        while (j <= end) {
            cpy.push_back(arr[j++]);
        }
        for (int i = start; i <= end; ++i) {
            arr[i] = cpy[i-start];
        }
    }
};