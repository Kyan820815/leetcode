//--- Q: 287. Find the Duplicate Number

//--- method 1: slow & fast pointer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//--- method 2: binary search, time: nlogn, space: 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int mid, left = 1, right = nums.size()-1;

        while(left < right)
        {
            int count = 0;
            mid = (left+right)/2;
            for(int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] <= mid)
                    count++;
            }
            if (count > mid)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

//--- method 3: sort, time: nlogn but modify array, space: 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i+1])
            {
                dup = nums[i];
                break;
            }
        }
        return dup;

    }
};