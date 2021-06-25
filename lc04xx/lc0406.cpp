//--- Q: 406. Queue Reconstruction by Height

//--- method 1: build-in sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	vector<vector<int>> out;
    	sort(people.begin(),people.end(),comp);
		for (int i = 0; i < people.size(); ++i)
			out.insert(out.begin()+people[i][1], people[i]);			
		return out;    
    }
    static bool comp(vector<int> &a, vector<int> &b)
    {
    	if (a[0] == b[0]) return a[1] < b[1];
    	return a[0] > b[0];
    }
};

//--- method 2: merge sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	vector<vector<int>> out;
    	divide(people, 0, people.size()-1);
		for (int i = 0; i < people.size(); ++i)
			out.insert(out.begin()+people[i][1], people[i]);			
		return out;    
    }
    void divide(vector<vector<int>> &people, int start, int end)
    {
    	int mid;
    	if (start < end)
    	{
    		mid = (start+end) / 2;
    		divide(people, start, mid);
    		divide(people, mid+1, end);
    		conquer(people, start, mid, end);
    	}
    }
    void conquer(vector<vector<int>> &people, int start, int mid, int end)
    {
    	vector<vector<int>> copy;
    	int left = start, right = mid+1, idx = 0;
    	copy.resize(end-start+1);
    	while(left <= mid && right <= end)
    	{
    		if (people[left][0] > people[right][0])
    			copy[idx++] = people[left++];
    		else if (people[left][0] == people[right][0])
    			copy[idx++] = (people[left][1] <= people[right][1]) ? people[left++] : people[right++];
    		else if (people[left][0] < people[right][0])
    			copy[idx++] = people[right++];
    	}
    	while (left <= mid)
    		copy[idx++] = people[left++];
    	while (right <= end)
    		copy[idx++] = people[right++];
    	for (int i = 0; i < idx; ++i)
    		people[start+i] = copy[i];
    }
};