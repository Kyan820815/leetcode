//--- Q: 666. Path Sum IV

//--- method 1: array representation, 1 pass
class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> map(5, vector<int>(9, 0));
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int depth = nums[i]/100 - 1;
            int idx = nums[i] % 100 / 10 - 1; 
            int val = nums[i] % 10;
            map[depth][idx] = val;
            if (depth > 0) {
                int p_val = map[depth-1][idx/2];
                if (p_val > 0) {
                    res -= p_val;
                    map[depth-1][idx/2] = -p_val;
                }
                map[depth][idx] += abs(p_val);
            }
            res += map[depth][idx];
        }
        return res;
    }
};

//--- method 2: dfs recursion, 2 pass
class Solution {
public:
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> val_arr;
    int res = 0;
    int pathSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int depth = pow(2, nums[i]/100-1)-1;
            int idx = nums[i] % 100 / 10; 
            int val = nums[i] % 10;
            if (depth+idx != 0) {
                map[(depth+idx)/2].push_back(depth+idx);
            }
            val_arr[depth+idx] = val;
        }
        dfs(0, 0);
        return res;
    }
    void dfs(int now, int sum) {
        sum += val_arr[now];
        if (!map[now].size()) {
            res += sum;
        }
        for (int i = 0; i < map[now].size(); ++i) {
            dfs(map[now][i], sum);
        }
    }
};