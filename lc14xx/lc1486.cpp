//--- Q: 1486. 

//--- method 1: find pattern
class Solution {
public:
    int xorOperation(int n, int start) {
        int last = start+(n-1)*2, res;
        if (n%4 == 1) {
            if (start % 4 == 0 || start % 4 == 1) {
                res = last;    
            } else {
                res = start;
            }
        } else if (n%4 == 2) {
            if (start % 4 == 0 || start % 4 == 1) {
                res = 2;    
            } else {
                res = last^start;
            }
            
        } else if (n%4 == 3) {
            if (start % 4 == 0 || start % 4 == 1) {
                res = last^2;    
            } else {
                res = start^2;
            }
        } else {
            if (start % 4 == 0 || start % 4 == 1) {
                res = 0;    
            } else {
                res = last^start^2;
            }
        }
        return res;
    }
};