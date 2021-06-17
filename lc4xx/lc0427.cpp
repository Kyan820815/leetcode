//--- Q: 427. Construct Quad Tree

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
        return postorder(grid, grid.size(), 0, 0);
    }
    Node *postorder(vector<vector<int>> &grid, int len, int r, int c) {
        if (len == 1) {
            return new Node(grid[r][c], true);
        }
        Node *topLeft = postorder(grid, len/2, r, c);
        Node *topRight = postorder(grid, len/2, r, c+len/2);
        Node *bottomLeft = postorder(grid, len/2, r+len/2, c);
        Node *bottomRight = postorder(grid, len/2, r+len/2, c+len/2);
        Node *now = new Node();
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
            topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            now->val = topLeft->val;
            now->isLeaf = true;
        } else {
            now->val = 1;
            now->topLeft = topLeft;
            now->topRight = topRight;
            now->bottomLeft = bottomLeft;
            now->bottomRight = bottomRight;
        }
        return now;
    }
};