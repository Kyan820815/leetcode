#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int> &nums, int root, int length)
{
	int left_idx = root*2, right_idx = root*2+1;
	int largest_idx;
	if (left_idx <= length && nums[left_idx] > nums[root])
		largest_idx = left_idx;
	else largest_idx = root;

	if (right_idx <= length && nums[right_idx] > nums[largest_idx])
		largest_idx = right_idx;

	if (largest_idx != root) 				
	{
		swap(nums[largest_idx], nums[root]);
		max_heapify(nums, largest_idx, length);
	}
}

void buildMaxHeap(vector<int> &nums, int len)
{
	for (int i = len/2; i >= 1; --i)
		max_heapify(nums, i, len);
}

void heapsort(vector<int> &nums)
{
	int len = nums.size();
	nums.insert(nums.begin(), 0);

	buildMaxHeap(nums, len); //--- O(n)
	while(len > 0)
	{
		swap(nums[1], nums[len--]);
		max_heapify(nums, 1, len); 	
	}
	nums.erase(nums.begin());
}

int main(void)
{
	vector<int> nums = {9,8,7,6,5,4,3,2,1};
	heapsort(nums);

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << "\n";
	return 0;
}