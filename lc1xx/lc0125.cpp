//--- Q: 125. Valid Palindrome

//--- method 1: 
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left <= right)
        {
        	while (left < s.size() && (s[left]-'a' < 0 || s[left]-'a' > 25) && (s[left]-'A' < 0 || s[left]-'A' > 25)
        		&& (s[left]-'0' < 0 || s[left]-'0' > 9))
        		++left;
        	while (right >= 0 && (s[right]-'a' < 0 || s[right]-'a' > 25) && (s[right]-'A' < 0 || s[right]-'A' > 25)
        		&& (s[right]-'0' < 0 || s[right]-'0' > 9))
        		--right;
        	if (left > right) return true;
            if (s[left] >= 'a' && s[left] <= 'z')
                s[left] += 'A'-'a';
            if (s[right] >= 'a' && s[right] <= 'z')
                s[right] += 'A'-'a';
            if (s[left] - s[right] != 0) return false;
            left++;
            right--;
        }
        return true;
    }
};