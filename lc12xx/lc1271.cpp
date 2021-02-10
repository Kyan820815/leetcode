//--- Q: 1271. Hexspeak

//--- method 1: turn string into long long int
class Solution {
public:
    string toHexspeak(string num) {
        unordered_map<int, char> map = {{0,'O'},{1,'I'},{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};
        long long int val = stoll(num);
        string res = "";
        while (val) {
            int rem = val%16;
            if (rem < 10 && rem > 1) {
                return "ERROR";
            }
            res = map[rem] + res;
            val /= 16;
        }
        return res;
    }
};