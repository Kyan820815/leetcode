//--- Q: 247. Strobogrammatic Number II

//--- method 1: dfs with n from large to small
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> map({"11", "88", "00", "69", "96"}), res;
        string now(n, '0');
        dfs(0, n-1, now, res, map);
        return res;
    }
    void dfs(int i, int j, string &now, vector<string> &res, vector<string> &map) {
        if (i > j) {
            res.push_back(now);
        } else if (i < j) {
            for (int k = 0; k < 5; ++k) {
                if (k == 2 && !i)
                    continue;
                now[i] = map[k][0];
                now[j] = map[k][1];
                dfs(i+1, j-1, now, res, map);
                now[i] = now[j] = '0';
            }
        } else if (i == j) {
            for (int k = 0; k < 3; ++k) {
                if (k == 2 && !i && now.size() > 1)
                    continue;
                now[i] = map[k][0];
                dfs(i+1, j-1, now, res, map);
                now[i] = '0';
            }
        }
    }
};

//--- method 2: dfs with find n from small to large
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return dfs(0, n-1);
    }
    vector<string> dfs(int i, int j) {
        if (i > j)
            return {""};
        else if (i == j)
            return {"0", "1", "8"};
        
        vector<string> get = dfs(i+1, j-1), res;
        for (int k = 0; k < get.size(); ++k) {
            if (i)
                res.push_back("0" + get[k] + "0");
            res.push_back("1" + get[k] + "1");
            res.push_back("8" + get[k] + "8");
            res.push_back("6" + get[k] + "9");
            res.push_back("9" + get[k] + "6");
        }
        return res;
    }
};

//--- method 3: dfs with n from small to large
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> map({"11", "88", "00", "69", "96"});
        vector<string> res;
        dfs(n, "", res, map);
        dfs(n, "0", res, map);
        dfs(n, "1", res, map);
        dfs(n, "8", res, map);
        return res;
    }
   void dfs(int len, string now, vector<string> &res, vector<string> &map) {
        if (now.size() < len-1) {
            for (int k = 0; k < 5; ++k) {
                if (k == 2 && now.size()+2 >= len)
                    continue;
                dfs(len, map[k][0] + now + map[k][1], res, map);
            }
        } else if (now.size() == len) {
            res.push_back(now);
        }
    }
};

