//--- Q: 0038. Count and Say
//--- last written: 2023/07/02

//--- method 1: process last res
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i) {
            int cnt = 1;
            string tmp = "";
            for (int j = 1; j <= res.size(); ++j) {
                if (j == res.size() || res[j] != res[j-1]) {
                    tmp += to_string(cnt) + res[j-1];
                    cnt = 0;
                }
                ++cnt;
            }
            res = tmp;
        }
        return res;
    }
};
