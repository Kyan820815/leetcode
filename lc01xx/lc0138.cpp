//--- Q: 138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

//--- method 1: copy link, better
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *findNode, *cur;
        Node *root, *rear;

        if (head == NULL)
            return head;

        cur = head;

        while(cur != NULL)
        {
            findNode = (Node *)malloc(sizeof(Node));
            findNode->val = cur->val;
            findNode->next = cur->next;

            cur->next = findNode;

            cur = cur->next->next;
        }

        cur = head;
        root = rear = NULL;
        while(cur != NULL)
        {
            if(cur->random != NULL)
                findNode = cur->random->next;
            else
                findNode = NULL;

            cur->next->random = findNode;
            
            cur = cur->next->next;
        }

        cur = head;
        root = rear = cur->next;
        while(rear->next != NULL)
        {
            cur->next = cur->next->next;
            cur = cur->next;
            rear->next = rear->next->next;
            rear = rear->next;
        }
        cur->next = NULL;

        return root;
    }
};

//--- method 2: map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapNode;
        Node *findNode, *cur;
        Node *root, *rear;

        if (head == NULL)
            return head;

        cur = head;
        root = rear = NULL;

        while(cur != NULL)
        {
            findNode = (Node *)malloc(sizeof(Node));
            findNode->val = cur->val;
            findNode->next = NULL;

            if (root == NULL && rear == NULL)
                root = rear = findNode;
            else
            {
                rear->next = findNode;
                rear = rear->next;
            }

            mapNode.insert(pair<Node*,Node*>(cur,findNode));

            cur = cur->next;
        }

        cur = head;
        rear = root;
        while(cur != NULL)
        {
            if(cur->random != NULL)
                findNode = mapNode[cur->random];
            else
                findNode = NULL;

            rear->random = findNode;
            rear = rear->next;
            cur = cur->next;
        }

        return root;
    }
};