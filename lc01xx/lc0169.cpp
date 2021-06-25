//--- Q: 169. Majority Element

//--- method 1: maintain majority number, better
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int main, count = 0;

        for(int idx = 0; idx < nums.size(); ++idx)
        {
            if (count == 0)
            {
                main = nums[idx];
                count++;
            } 
            else
            {
                if(main != nums[idx])
                    count--;
                else
                    count++;
            }
        }
        return main;
    }
};

//--- method 2: merge sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> sort_nums;
        sort_nums.resize(nums.size());
        merge(nums, sort_nums, 0, nums.size()-1);

        return nums[nums.size()/2];
    }

    void merge(vector<int>& nums, vector<int>& sort_nums, int start, int end)
    {
        int mid;
        if (start < end)
        {
            mid = (start + end) / 2;
            merge(nums, sort_nums, start, mid);
            merge(nums, sort_nums, mid+1, end);
            sort(nums, sort_nums, start, mid, end);
        } 
    }
    void sort(vector<int>& nums, vector<int>& sort_nums, int start, int mid, int end)
    {
      int i = start, j = mid+1, idx = start;

      while(i <= mid && j <= end)
      {
          if (nums[i] <= nums[j])
              sort_nums[idx++] = nums[i++];
          else
              sort_nums[idx++] = nums[j++];
      }
      while(i <= mid)
          sort_nums[idx++] = nums[i++];
      while(j <= end)
          sort_nums[idx++] = nums[j++];
      for (idx = start; idx <= end; idx++)
          nums[idx] = sort_nums[idx];
    }
};


//--- method 3: map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> majMap;
        int maj;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!majMap.count(nums[i]))
                majMap[nums[i]] = 1;
            else
                majMap[nums[i]]++;
            if (majMap[nums[i]] > nums.size()/2)
            {
                maj = i;
                break;
            }
        }
        return nums[maj];
    }
};