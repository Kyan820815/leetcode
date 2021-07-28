//--- Q: 0412. Fizz Buzz

//--- method 1: without mod, use counter
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        int three = 0, five = 0;
        for (int i = 0; i < n; ++i) {
            ++three, ++five;
            string str = "";
            if (three == 3) {
                str += "Fizz";
                three = 0;
            }
            if (five == 5) {
                str += "Buzz";
                five = 0;
            }
            if (!str.size()) {
                str += to_string(i+1);
            }
            res.push_back(str);
        }
        return res;
    }
};