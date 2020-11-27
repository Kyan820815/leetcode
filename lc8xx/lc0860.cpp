//--- Q: 860. Lemonade Change

//--- method 1: one pass count # of 5 and 10
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0, m10 = 0;
        for (int i = 0; i < bills.size(); ++i)
        {
        	if (bills[i] == 5)
        		++m5;
        	else if (bills[i] == 10)
        	{
        		if (m5 > 0)
        			--m5;
        		else return false;
        		++m10;
        	}
        	else
        	{
        		if (m5 > 0 && m10 > 0)
        		{
        			--m5;
        			--m10;
        		}
        		else if (m5 > 2)
        			m5 -= 3;
        		else
        			return false;
        	}
        }
        return true;
    }
};