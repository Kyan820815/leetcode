//--- Q: 1902. Depth of BST Given Insertion Order

//--- method 1: map
class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        map<int, int> map;
        int res = 0;
        for (int i = 0; i < order.size(); ++i) {
            auto next = map.upper_bound(order[i]);
            int lh = next != map.begin() ? prev(next)->second : 0;
            int rh = next->second;
            int ch = max(lh, rh)+1;
            map[order[i]] = ch;
            res = max(res, ch);
        }
        return res;
    }
};