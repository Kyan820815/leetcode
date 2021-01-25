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
    vector<int> h, m;
    vector<string> readBinaryWatch(int num) {
        h = {1,2,4,8}, m = {1,2,4,8,16,32};
        dfs(0, num, 0, 0);
        return res;
    }
    void dfs(int idx, int num, int hour, int min) {
        if (hour >= 12 || min >= 60) {
            return;
        }
        if (!num) {
            string hour_str = to_string(hour), min_str = to_string(min);
            string time = hour_str + ":" + (min_str.size() == 1 ? "0"+min_str : min_str);
            res.push_back(time);
            return;
        }
        for (int i = idx; i < h.size()+m.size(); ++i) {
            if (i < h.size()) {
                dfs(i+1, num-1, hour+h[i], min);
            } else {
                dfs(i+1, num-1, hour, min+m[i-h.size()]);
                
            }
        }
    }
};
