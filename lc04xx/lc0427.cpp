//--- Q: 0427. Construct Quad Tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

//--- method 1: postorder
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(0, 0, n/2, grid);
    }
    Node *dfs(int r, int c, int n, vector<vector<int>> &grid) {
        if (!n) {
            return new Node(grid[r][c], true);
        }
        auto tl = dfs(r, c, n/2, grid);
        auto tr = dfs(r, c+n, n/2, grid);
        auto bl = dfs(r+n, c, n/2, grid);
        auto br = dfs(r+n, c+n, n/2, grid);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && 
            tl->val == tr->val && tl->val == bl->val && tl->val == br->val) {
            return new Node(grid[r][c], true);
        } else {
            return new Node(grid[r][c], false, tl, tr, bl, br);
        }
    }
};