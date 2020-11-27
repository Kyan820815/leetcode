//--- Q: 060. Permutation Sequence

//--- method 1: O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> perm(n,1);
        vector<int> nums(n,1);
        string res;
        int cnt = n-1;

        for (int i = 1; i < n; ++i)
        {
        	perm[i] = perm[i-1]*i; 
        	nums[i] = i+1;
        }
        --k;
        while (nums.size())
        {
        	int q = k/perm[cnt];
        	k = k % perm[cnt];
        	--cnt;
        	res.push_back(nums[q]+'0');
        	nums.erase(nums.begin()+q);
        }
        return res;
    }
};