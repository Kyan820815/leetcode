//--- Q: 168. Excel Sheet Column Title

//--- method 1: string operation
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n)
        {
            n--;
        	res.push_back('A'+n%26);
        	n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};