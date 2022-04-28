//--- Q: 1694. Reformat Phone Number

//--- method 1: naive processing
class Solution {
public:
    string reformatNumber(string number) {
        string str = "";
        for (auto &ch: number) {
            if (isdigit(ch)) {
                str += ch;
            }
        }
        int i, n = str.size();
        string res = "";
        for (i = 0; i < n-4; i+=3) {
            res += str.substr(i, 3);
            res += '-';
        }
        if (n-i == 4) {
            res += str.substr(i, 2);
            res += '-';
            res += str.substr(i+2, 2);
        } else {
            res += str.substr(i, n-i);
        }
        return res;
    }
};

//--- method 2: recursion
class Solution {
public:
    string reformatNumber(string number) {
        function<string(string)> format = [&](string n) {
            if (n.size() >= 4) {
                int take = n.size() > 4 ? 3 : 2;
                return n.substr(0, take) + "-" + format(n.substr(take));
            }
            return n;
        };
        auto it = copy_if(number.begin(), number.end(), number.begin(), [](const char &a) {
            return isdigit(a);
        });
        return format(string(number.begin(), it));
    }
};