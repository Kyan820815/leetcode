//--- Q: 1447. Simplified Fractions

//--- method 1: impl gcd
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        auto gcd = [](int a, int b) {
            while (a && b) {
                a %= b;
                swap(a, b);
            }
            return a;
        };
        vector<string> res;
        for (int i = 1; i <= n-1; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (gcd(j,i) == 1) {
                    res.push_back(to_string(i)+"/"+to_string(j));
                }
            }
        }
        return res;
    }
};

//--- method 2: built-in gcd
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 1; i <= n-1; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (gcd(i,j) == 1) {
                    res.push_back(to_string(i)+"/"+to_string(j));
                }
            }
        }
        return res;
    }
};