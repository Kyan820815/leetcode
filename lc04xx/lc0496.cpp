//--- Q: 496. Next Greater Element I

//--- method 1: stack iteration with map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1), sk;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); ++i)
            map[nums1[i]] = i;
        for (int i = 0; i < nums2.size(); ++i) {
            while (sk.size() && nums2[sk.back()] < nums2[i]) {
                if (map.find(nums2[sk.back()]) != map.end())
                    res[map[nums2[sk.back()]]] = nums2[i];
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return res;
    }
};

//--- method 2: find number in other array
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> res(nums1.size(), -1);
    	for (int i = 0; i < nums1.size(); ++i)
    	{
    		int j, k;
    		for (j = 0; j < nums2.size(); ++j)
    			if (nums2[j] == nums1[i]) break;
    		for (k = j+1; k < nums2.size(); ++k)
    			if (nums2[k] > nums2[j]) break;
            if (k < nums2.size())
    		    nums1[i] = nums2[k];
            else nums1[i] = -1;
    	}
    	return nums1;
    }
};