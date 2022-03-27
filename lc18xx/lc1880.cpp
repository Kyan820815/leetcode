//--- Q: 1880. Check if Word Equals Summation of Two Words

//--- method 1: naive count
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int s1 = 0, s2 = 0, t = 0;
        for (auto &ch: firstWord) {
            s1 = s1*10 + (ch-'a');
        }
        for (auto &ch: secondWord) {
            s2 = s2*10 + (ch-'a');
        }
        for (auto &ch: targetWord) {
            t = t*10 + (ch-'a');
        }
        return s1+s2 == t;
    }
};

//--- method 2: lambda func
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto func = [](string &s) {
            int sum = 0;
            for (auto &ch: s) {
                sum = (sum*10) + (ch-'a');
            }
            return sum;
        };
        return func(firstWord)+func(secondWord) == func(targetWord);
    }
};