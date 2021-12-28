//--- Q: 0946. Validate Stack Sequences

//--- method 1: O(n) space
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int idx = -1, j = 0;
        for (int i = 0; i <= pushed.size(); ++i) {
            while (idx >= 0 && j < popped.size() && pushed[idx] == popped[j]) {
                --idx, ++j;
            }
            if (i == pushed.size()) {
                break;
            }
            swap(pushed[++idx], pushed[i]);
        }
        return idx == -1;
    }
};

//--- method 2: O(1) space two pointer
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int idx = -1, j = 0;
        for (int i = 0; i <= pushed.size(); ++i) {
            while (idx >= 0 && j < popped.size() && pushed[idx] == popped[j]) {
                --idx, ++j;
            }
            if (i == pushed.size()) {
                break;
            }
            swap(pushed[++idx], pushed[i]);
        }
        return idx == -1;
    }
};