//--- Q: 946. Validate Stack Sequences

//--- method 1: O(1) space two pointer
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int idx = -1, j = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            pushed[++idx] = pushed[i];
            while (idx >= 0 && pushed[idx] == popped[j]) {
                ++j, --idx;
            }
        }
        return j == popped.size();
    }
};

//--- method 2: O(n) space
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> sk;
        int i = 0, j = 0, n = pushed.size();
        while (i < n && j < n) {
            sk.push_back(pushed[i++]);
            while (sk.size() && popped[j] == sk.back()) {
                sk.pop_back();
                ++j;
            }
        }
        return j == n;
    }
};