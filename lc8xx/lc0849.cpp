//--- Q: 849. Maximize Distance to Closest Person

//--- method 1: find the midpoint of seats, two times pass
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int maxv = INT_MIN;
    	vector<int> res;
        for (int i = 0; i < seats.size(); ++i)
        	if (seats[i]) res.push_back(i);
        for (int i = 1; i < res.size(); ++i)
        	maxv = max(maxv, (res[i]-res[i-1])/2);
        maxv = max(maxv, (int)seats.size()-1-res.back());
        maxv = max(maxv, res.front());
        return maxv;
    }
};

//--- method 2: similar to method 1, but one time pass
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int maxv = INT_MIN, last = -1;
        for (int i = 0; i < seats.size(); ++i)
        {
        	if (seats[i])
        	{
        		if (last == -1)
        			maxv = max(maxv, i);
        		else 
        			maxv = max(maxv, (i-last)/2);
            	last = i;
        	}
        }
        maxv = max(maxv, ((int)seats.size()-1-last));
        return maxv;
    }
};