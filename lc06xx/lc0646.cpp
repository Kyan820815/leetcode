//--- Q: 646. Maximum Length of Pair Chain

//--- method 1: O(nlogn) dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = 1;
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){
        	return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });

        int min = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i)
        {
        	if (pairs[i][0] > min)
        	{
        		len++;
        		min = pairs[i][1];
        	}
        	else if (pairs[i][1] < min)
        		min = pairs[i][1];
        }
        return len;
    }
};

//--- method 2: O(n^2) dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 1;
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int end = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > end) {
                ++res;
                end = pairs[i][1];
            }
        }
        return res;
    }
};