//--- Q: 412. Fizz Buzz

//--- method 1: without mod, use counter
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1, fizz = 1, buzz = 1; i <= n; ++i, ++fizz, ++buzz) {
            string str = "";
            if (fizz == 3) {
                str += "Fizz";
                fizz = 0;
            }
            if (buzz == 5) {
                str += "Buzz";
                buzz = 0;
            }
            if (!str.size()) {
                str += to_string(i);
            }
            res.push_back(str);
        }
        return res;
    }
};