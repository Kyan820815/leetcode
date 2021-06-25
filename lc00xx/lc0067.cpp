//--- Q: 67. Add Binary

//--- method 1: bit by bit add
class Solution {
public:
    string addBinary(string a, string b) {
    	int aidx = a.size()-1, bidx = b.size()-1, carry = 0;
    	string res = "";
    	while (aidx >= 0 || bidx >= 0 || carry)
    	{

    		int sum = ((aidx >= 0) ? a[aidx--]-'0' : 0) + ((bidx >= 0) ? b[bidx--]-'0' : 0) + carry;
    		carry = sum/2;
    		sum = sum & 1;
    		res = to_string(sum) + res;
    	}
    	return res;
    }
};