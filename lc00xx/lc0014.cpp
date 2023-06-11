//--- Q: 0014. Longest Common Prefix
//--- last written: 2023/05/28

//--- method 1: vertical scanning, better
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

//--- method 2: horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            int cur_len = min(len, (int)strs[i].size());
            for (int j = 0; j < cur_len; ++j) {
                if (strs[0][j] != strs[i][j]) {
                    cur_len = j;
                    break;
                }
            }
            len = cur_len;
        }
        return strs[0].substr(0,len);
    }
};

//--- method 3: divide and conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return divide(0, strs.size()-1, strs);
    }
    string divide(int start, int end, vector<string>& strs) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, strs);
            auto right = divide(mid+1, end, strs);
            return conquer(left, right);
        }
        return strs[start];
    }
    string conquer(string &left, string &right) {
        int len = min(left.size(), right.size());
        for (int i = 0; i < len; ++i) {
            if (left[i] != right[i]) {
                return left.substr(0,i);
            }
        }
        return left.substr(0,len);
    }
};

//--- method 4: binary search
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;
        for (auto &str: strs) {
            len = min(len, (int)str.size());
        }
        int left = 0, right = len;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (isCommon(mid, strs)) {
                left =  mid+1;
            } else {
                right = mid;
            }
        }
        if (!left) {
            return "";
        }
        return isCommon(left, strs) ? strs[0].substr(0,left) : strs[0].substr(0,left-1);
    }
    bool isCommon(int len, vector<string> &strs) {
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
               if (strs[j][i] != strs[0][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
