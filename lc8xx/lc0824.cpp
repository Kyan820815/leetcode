//--- Q: 824. Goat Latin

//--- method 1: linear processing
class Solution {
public:
    string toGoatLatin(string S) {
        string last = "a", word, res = "";
        unordered_set<char> set({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        istringstream ss(S);
        while (ss >> word) {
            res += set.find(word[0]) != set.end() ? word : string() + word.substr(1) + word[0];
            res += "ma" + last + " ";
            last += 'a';
        }
        res.pop_back();
        return res;
    }
};