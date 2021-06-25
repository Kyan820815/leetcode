//--- Q: 331. Verify Preorder Serialization of a Binary Tree

//--- method 1: find boundary condition '#'
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int idx = 0, null_cnt = 1;
        for (int i = 0; i < preorder.size(); ++i)
            if (preorder[i] == ',')
                preorder[i] = ' ';
        istringstream istr(preorder);
        string str;
        while (istr >> str)
        {
            if (str == "#")
                --null_cnt;
            else
            {
                if (null_cnt == 0) return false;
                else null_cnt++;
            }
        }
        return !null_cnt;
    }
};

//--- method 2: one pass
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int cnt = 1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] == ',') {
                continue;
            } else if (preorder[i] != '#') {
                if (!cnt) {
                    return false;
                }
                while (i < preorder.size() && preorder[i] != ',') {
                    ++i;
                }
                ++cnt;
            } else {
                --cnt;
            }
        }
        return !cnt;
    }
};