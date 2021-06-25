//--- Q: 077. Combinations

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out_vec;
        vector<int> out;
        dfs(n,k,1,out,out_vec);
        return out_vec;
    }
    void dfs(int n, int k, int start, vector<int> &out, vector<vector<int>> &out_vec)
    {
        if (k == 0)
        {
            out_vec.push_back(out);
            return;
        }
        if (k > n-start+1) return;
        for (int i = start; i <= n; ++i)
        {
            out.push_back(i);
            dfs(n, k-1, i+1 , out, out_vec);
            out.pop_back();
        }
    }
};

//--- method 2: dfs with dp model C(n, k) = C(n-1, k) + C(n-1, k-1)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out_vec;
        vector<int> out;
        dfs(n,k,1,out,out_vec);
        return out_vec;
    }
    void dfs(int n, int k, int start, vector<int> &out, vector<vector<int>> &out_vec)
    {
        if (k == 0)
        {
            out_vec.push_back(out);
            return;
        }
        if (n-start+1 < k) return;
        out.push_back(start);
        dfs(n,k-1,start+1,out,out_vec);
        out.pop_back();
        dfs(n,k,start+1,out,out_vec);
    }
};