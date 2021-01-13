//--- Q: 1485. Clone Binary Tree With Random Pointer

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

//--- method 1: O(1) space
class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        makeCopy(root);
        makeRondom(root);
        return breakNode(root);
    }
    void makeCopy(Node *node) {
        if (!node) {
            return;
        }
        NodeCopy *copy = new NodeCopy(node->val);
        copy->left = node->left;
        copy->right = node->right;
        node->left = copy;
        node->right = NULL;
        makeCopy(copy->left);
        makeCopy(copy->right);
    }
    void makeRondom(Node *node) {
        if (!node) {
            return;
        }
        if (node->random) {
            node->left->random = node->random->left;
        }
        makeRandom(node->left->left);
        makeRandom(node->left->right);
    }
    NodeCopy *breakNode(Node *node) {
        if (!node) {
            return NULL;
        }
        NodeCopy *copy = node->left;
        root->left = copy->left;
        root->right = copy->right;
        copy->left = breakNode(root->left);
        copy->right = breakNode(root->right);
        return copy;
    }
};

//--- method 2: O(n) space
class Solution {
public:
    unordered_map<Node *, NodeCopy *> map;
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy *copy = preorder(root);
        return copy;
    }
    NodeCopy *preorder(Node *root) {
        if (!root) {
            return NULL;
        }
        if (map.find(root) != map.end()) {
            return map[root];
        }
        NodeCopy *copy = new NodeCopy(root->val);
        map[root] = copy;
        copy->left = preorder(root->left);
        copy->right = preorder(root->right);
        copy->random = preorder(root->random);
        return copy;
    }
};