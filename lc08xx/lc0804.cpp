//--- Q: 0804. Unique Morse Code Words

//--- method 1: count unique
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        array<string, 26> encode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> set;
        for (auto &word: words) {
            string code = "";
            for (auto &ch: word) {
                code += encode[ch-'a'];
            }
            if (set.find(code) == set.end()) {
                set.insert(code);
            }
        }
        return set.size();
    }
};