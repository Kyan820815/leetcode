//--- Q: 539. Minimum Time Difference

//--- method 1: O(nlogn)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    	vector<int> times;
    	int diff, min_diff = INT_MAX;
    	for (int i = 0; i < timePoints.size(); ++i)
    	{
    		int hours = (timePoints[i][0]-'0')*10 + timePoints[i][1]-'0';
    		int mins = (timePoints[i][3]-'0')*10 + timePoints[i][4]-'0';
    		times.push_back(hours*60+mins);
    	}
    	sort(times.begin(), times.end());
    	for (int i = 0; i < times.size()-1; ++i)
    	{
    		diff = times[i+1] - times[i];
    		if (diff < min_diff)
    			min_diff = diff;
    	}
    	return min_diff < times[0]+1440 - times.back() ? min_diff : times[0]+1440 - times.back();
    }
};

//--- method 2: O(n) 
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int first = INT_MAX, back = INT_MIN, min_diff = INT_MAX;
        int pre = -1;
        vector<int> times(1440, 0);
        for (int i = 0; i < timePoints.size(); ++i)
        {
        	int hours = (timePoints[i][0]-'0')*10 + timePoints[i][1]-'0';
        	int mins = (timePoints[i][3]-'0')*10 + timePoints[i][4]-'0';
        	times[hours*60+mins]++;
        	if (times[hours*60+mins] > 1)
        		return 0;
        }
        for (int i = 0; i < 1440; ++i)
        {
        	if (!times[i]) continue;
        	
        	if (first > i)
        		first = i;
        	if (back < i)
        		back = i;
			if (pre == -1)
        	{
        		pre = i;
        		continue;
        	}
        	if (i-pre < min_diff)
				min_diff = i-pre;        	
        	pre = i;
        }
        return min_diff < first+1440-back ? min_diff : first+1440-back;
    }
};