//--- Q: 0306. Additive Number

//--- method 1: string compare
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size()/2;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= len; ++j) {
                if (num[0] == '0' && i != 1 || num[i] == '0' && j != 1) {
                    continue;
                }
                if (dfs(0, num.substr(0,i), num.substr(i, j), num)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int idx, string num1, string num2, string num) {
        string next = add(num1, num2);
        if (next != num.substr(idx+num1.size()+num2.size(), next.size())) {
            return false;
        }
        if (idx+num1.size()+num2.size()+next.size() == num.size()) {
            return true;
        }
        return dfs(idx+num1.size(), num2, next, num);
    }
    string add(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res(max(n1,n2)+1, '0');
        int i = n1-1, j = n2-1, k = res.size()-1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += (num1[i--]-'0');
            }
            if (j >= 0) {
                carry += (num2[j--]-'0');
            }
            res[k--] = (carry%10)+'0';
            carry /= 10;
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};