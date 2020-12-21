//--- Q: 1650. Lowest Common Ancestor of a Binary Tree III

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

//--- method 1: O(1) space bottom up traverse
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *nodep = p, *nodeq = q;
        while (nodep != nodeq) {
            nodep = nodep->parent;
            nodeq = nodeq->parent;
            if (nodep == nodeq) {
                return nodep;
            }
            if (!nodep) {
                nodep = q;
            }
            if (!nodeq) {
                nodeq = p;
            }
        }
        return nodep;
    }
};