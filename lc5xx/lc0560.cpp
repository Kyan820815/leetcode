//--- Q: 560. Subarray Sum Equals K

//--- method 1: dp with map, prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int sum = 0, res = 0;
    	unordered_map<int,int> dp;
    	dp[0] = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		res += dp[sum-k];
    		dp[sum]++;
    	}

    	return res;
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int sum = 0, res = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		if (tmp == k)
    			res++;
    		int tmp = sum;
    		for (int j = 0; j < i; ++j)
    		{
    			tmp -= nums[j];
    			if (tmp == k)
    				res++;
    		}
    	}
    	return res;
    }
};

//--- follow up
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        nums = {0, 5, -1, 1, 2, 1, 2, 4, 1, 2, 3, -3, 2, 0, 5};
        k = 5;
        nums = {0, 5, 0, 5};
        k = 5;
        unordered_map<int, int> map;
        int maxlen = 0, sum = 0, start;
        map[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (map.find(sum-k) != map.end()) {
                int len = i-map[sum-k];
                if (len > maxlen) {
                    maxlen = len;
                    start = map[sum-k]+1;
                }
            }
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }
        for (int i = start; i < start+maxlen; ++i) {
            cout << nums[i] << " ";
        }
        cout << "\n";
        return 0;
    }
};