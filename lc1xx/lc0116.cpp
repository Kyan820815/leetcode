//--- Q: 116. Populating Next Right Pointers in Each Node 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

//--- method 1: link left to right
class Solution {
public:
    Node* connect(Node* root) {
        Node *now = root;
        Node *head = NULL, *last = NULL;
        while (now)
        {
            if (!head)
                head = now->left;
            if (now->left) {
                now->left->next = now->right;
                if (last)
                    last->next = now->left;
                last = now->right;
            } else
                break;
            now = now->next;
            if (!now) {
                now = head;
                last = head = NULL;
            }
        }
        return root;
    }
};

//--- method 2: bfs
class Solution {
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
    void bfs(Node *root)
    {
        Node *head = NULL, *rear = NULL;
        Node *now = root;
        while (now)
        {
            if (!head)
                head = rear = now->left;
            else
            {
                rear->next = now->left;
                rear = rear->next;
            }
            if (!head)
                head = rear = now->right;
            else
            {
                rear->next = now->right;
                rear = rear->next;
            }

            now = now->next;
            if (!now)
            {
                now = head;
                head = rear = NULL;
            }
        }
    }
};

