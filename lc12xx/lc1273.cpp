//--- Q: 1273. Delete Tree Nodes

//--- method 1: one pass
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> res(nodes, 1);
        for (int i = nodes-1; i >= 1; --i) {
            value[parent[i]] += value[i];
            if (value[i]) {
                res[parent[i]] += res[i];
            }
        }
        return res[0];
    }
};

//--- method 2: postorder
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> tree(nodes);
        int desnode = 0;
        for (int i = 1; i < parent.size(); ++i) {
            tree[parent[i]].push_back(i);
        }
        postorder(0, value, tree, nodes, desnode);
        return nodes;
    }
    int postorder(int now, vector<int> &value, vector<vector<int>> &tree, int &nodes, int &desnode) {
        int sum = value[now];
        desnode = 1;
        for (int i = 0; i < tree[now].size(); ++i) {
            int tmp = 0;
            sum += postorder(tree[now][i], value, tree, nodes, tmp);
            desnode += tmp;
        }
        if (sum == 0) {
            nodes -= desnode;
            desnode = 0;
        }
        return sum;
    }
};