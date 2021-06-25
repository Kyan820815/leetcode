//--- Q: 896. Monotonic Array

//--- method 1: count times of up and down
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i)
        {
        	if (A[i] > A[i-1])
        		++up;
        	else if ( A[i] < A[i-1])
        		++down;
            if (up > 0 && down > 0) return false;
        }
        return true;
    }
};

//--- method 2: count bool of up and down
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
    	bool up = true, down = true;
        for (int i = 1; i < A.size(); ++i)
        {
        	up &= (A[i] >= A[i-1]); 
        	down &= (A[i] <= A[i-1]); 
            if (!up && !down) return false;
        }
        return true;
    }
};