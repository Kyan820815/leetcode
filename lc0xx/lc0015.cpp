//--- Q: 015. 3Sum

//--- method 1: build-in sort
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right, target;
        int n = nums.size();
        vector<vector<int>> out;
        if (n < 3) return out;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; ++i)
        {
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            if (nums[i] + nums[n-1] + nums[n-2] < 0) continue;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            target = -nums[i];
            left = i+1;
            right = n-1;
            while(left < right)
            {
                if (nums[left]+nums[right] == target)
                {
                    out.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if (nums[left]+nums[right] < target) left++;
                else if (nums[left]+nums[right] > target) right--;
            }
        }
        return out;
    }
};

//--- method 2: merge sort
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right, target;
        vector<vector<int>> out;
        divide(nums, 0, nums.size()-1);
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] > 0)
        		break;
        	if (i > 0 && nums[i] == nums[i-1])
        		continue;
        	target = -nums[i];
        	left = i+1;
        	right = nums.size()-1;
        	while(left < right)
        	{
        		if (nums[left]+nums[right] == target)
        		{
        			out.push_back({nums[i], nums[left], nums[right]});
        			left++, right--;
        			while(left < right && nums[left] == nums[left-1]) left++;
        			while(left < right && nums[right] == nums[right+1]) right--;
        		}
        		else if (nums[left]+nums[right] < target) left++;
        		else if (nums[left]+nums[right] > target) right--;
        	}
        }
        return out;
    }
    void divide(vector<int>& nums, int start, int end) {
    	int mid;
    	if (start < end)
    	{
    		mid = (start+end) / 2;
    		divide(nums, start, mid);
    		divide(nums, mid+1, end);
    		conquer(nums, start, mid, end);
    	}
    }
    void conquer(vector<int>& nums, int start, int mid, int end) {
    	int *copy, left = start, right = mid+1, idx = 0;
    	copy = (int *)malloc(sizeof(int)*(end-start+1));

    	while(left <= mid && right <= end)
   			copy[idx++] = (nums[left] < nums[right]) ? nums[left++] : nums[right++];
		while(left <= mid)   			
			copy[idx++] = nums[left++];
		while(right <= end)
			copy[idx++] = nums[right++];

		for(int i = 0; i < idx; ++i)
			nums[start+i] = copy[i];
    }
};

//--- method 3: no sort O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> dup;
        unordered_map<int, int> seen;
        set<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (dup.find(nums[i]) == dup.end()) {
                dup.insert(nums[i]);
                for (int j = i+1; j < n; ++j) {
                    int comp = -nums[i]-nums[j];
                    if (seen.find(comp) != seen.end() && seen[comp] == i) {
                        vector<int> arr = {nums[i], nums[j], comp};
                        sort(arr.begin(), arr.end());
                        res.insert(arr);
                    }
                    seen[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};