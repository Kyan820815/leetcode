//--- Q: 1805. Number of Different Integers in a String

//--- method 1: naive processing
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set;
        string num = "";
        int n = word.size();
        for (int i = 0; i <= n; ++i) {
            if (i == n || isalpha(word[i])) {
                if (i && isdigit(word[i-1])) {
                    int j;
                    for (j = 0; j < num.size(); ++j) {
                        if (num[j] != '0') {
                            set.insert(num.substr(j));
                            break;
                        }
                    }
                    if (j == num.size()) {
                        set.insert("0");
                    }
                    num = "";
                }
            } else {
                num += word[i];
            }
        }
        return set.size();
    }
};

//--- method 2: two pointers
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set = {""};
        for (int i = 0, j = 0; j <= word.size(); ++j) {
            if (j < word.size() && isdigit(word[j])) {
                i += i < j && word[i] == '0';
            } else {
                set.insert(word.substr(i, j-i));
                i = j+1;
            }
        }
        return set.size()-1;
    }
};