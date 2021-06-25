//--- Q: 338. Counting Bits

//--- method 1: O(n) space
class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> res(num+1,0);
        for (int i = 1; i <= num; ++i)
        	res[i] = res[i>>1] + (i & 1);
        return res;
    }
};

//--- method 2:  O(32*n) space
class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> bit(32, 0);
    	vector<int> res(num+1,0);
        for (int i = 1; i <= num; ++i)
        {
        	int minus = 0;
        	for (int j = 0; j < 32; ++j)
        	{
        		if (bit[j] == 0)
        		{
        			bit[j] = 1;
        			break;
        		}
                bit[j] = 0;
        		++minus;
        	}
        	res[i] = res[i-1] - minus + 1;
        }
        return res;
    }
};