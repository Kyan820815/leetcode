//--- Q: 0748. Shortest Completing Word

//--- method 1: naive processing
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        for (auto &ch: licensePlate) {
            if (isalpha(ch)) {
                if (isupper(ch)) {
                    ch ^= 32;
                }
                ++cnt[ch-'a'];
            }
        }
        string res = "";
        for (auto &word: words) {
            vector<int> tmp = cnt;
            for (auto &ch: word) {
                if (tmp[ch-'a'] == 0) {
                    continue;
                }
                --tmp[ch-'a'];
            }
            int invalid = 0;
            for (auto &v: tmp) {
                if (v) {
                    invalid = 1;
                    break;
                }
            }
            if (!invalid && (!res.size() || res.size() > word.size())) {
                res = word;
            }
        }
        return res;
    }
};

//--- method 2: modulo
class Solution {
public:
    using ull = unsigned long long;
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        auto count = [&](string &word) {
            ull val = 1;
            for (auto &ch: word) {
                if (isalpha(ch)) {
                    if (isupper(ch)) {
                        ch ^= 32;
                    }
                    val = ((ull)val*primes[ch-'a']);
                }
            }
            return val;
        };
        ull base = count(licensePlate);
        string res = "";
        for (auto &word: words) {
            ull curVal = count(word);
            if (curVal % base == 0 && (!res.size() || res.size() > word.size())) {
                res = word;
            }
        }
        return res;
    }
};