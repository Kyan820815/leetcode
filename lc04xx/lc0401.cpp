//--- Q: 401. Binary Watch

//--- method 1: bit manipulation
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (count_bit(i) + count_bit(j) == num) {
                    res.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
                }
            }
        }
        return res;
    }
    int count_bit(int val) {
        int cnt = 0;
        while (val) {
            cnt += (val&1);
            val >>= 1;
        }
        return cnt;
    }
};

//--- method 2: recursion
class Solution {
public:
    vector<string> res;
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> arr = {8,4,2,1,32,16,8,4,2,1};
        dfs(0, arr, turnedOn, 0, 0);
        return res;
    }
    void dfs(int now, vector<int> &arr, int cnt, int h, int m) {
        if (h > 11 || m > 59) {
            return;
        }
        if (!cnt) {
            string hour = to_string(h), min = to_string(m);
            min = min.size() == 1 ? "0"+min : min;
            res.push_back(hour+":"+min);
            return;
        }
        for (int i = now; i < arr.size(); ++i) {
            if (i < 4) {
                dfs(i+1, arr, cnt-1, h+arr[i], m);
            } else {
                dfs(i+1, arr, cnt-1, h, m+arr[i]);
            }
        }
    }
};
