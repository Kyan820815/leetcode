//--- Q: 0067. Add Binary
//--- last written: 2023/04/04

//--- method 1: bit by bit add
class Solution {
public:
    string addBinary(string a, string b) {
        int asz = a.size(), bsz = b.size(), i = asz-1, j = bsz-1, carry = 0, k;
        string res(max(asz, bsz)+1, '0');
        k = res.size()-1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += a[i--]-'0';
            }
            if (j >= 0) {
                carry += b[j--]-'0';
            }
            res[k--] = (carry&1)+'0';
            carry >>= 1;
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};
