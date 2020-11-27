//--- Q: 011. Container With Most Water

//--- always find max idx & keep it
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int h_val;
        int volume, max_volume=0;      

     	while(left < right)
     	{
     		h_val = (height[left] <= height[right]) ? height[left] : height[right];
     		volume = h_val*(right-left);
     		if (volume > max_volume)
     			max_volume = volume;

     		if (height[left] <= height[right])
     			left++;
     		else
     			right--;
     	}
     	return max_volume;
    }
};