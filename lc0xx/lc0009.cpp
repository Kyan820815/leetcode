//--- Q: 009. Palindrome Number

//--- method 1: turn to string then compare
class Solution {
public:
    bool isPalindrome(int x) {
    	string x_str;

        if (x < 0)
        	return false;
        x_str = to_string(x);
        if (x_str.size() == 1)
        	return true;

        for (int i = 0; i < x_str.size()/2; ++i)
        {
        	if (x_str[i] != x_str[x_str.size()-1-i])
        		return false;
        }
        return true;
    }
};

//--- method 2: number operation
class Solution {
public:
    bool isPalindrome(int x) {
        long left = 1, right = 10;
        if (x < 0) return false;
        while (x/left)
            left *= 10;
        while (left > right)
        {
            if ((x%left)/(left/10) != (x%right)/(right/10))
                return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
};