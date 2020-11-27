//--- Q: 117. Populating Next Right Pointers in Each Node II

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

//--- method 1: elegant version
class Solution {
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
    void bfs(Node* root)
    {
    	Node *head, *rear, *now;
    	head = rear = NULL;
    	now = root;
    	while(now)
    	{
    		if (now->left)
    		{
    			if (!rear) head = rear = now->left;
    			else
    			{
	    			rear->next = now->left;
	    			rear = rear->next;
    			}
    		}
    		if (now->right)
    		{
    			if (!rear) head = rear = now->right;
    			else
    			{
	    			rear->next = now->right;
	    			rear = rear->next;
    			}
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

//--- method 2: counting parameter
class Solution {
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
    void bfs(Node* root)
    {
    	Node *head, *rear, *tail;
    	int q_size_prv = 1, q_size_now = 0;

    	head = rear = root;
    	while(head)
    	{
    		if (head->left)
    		{
    			rear->next = head->left;
    			rear = rear->next;
    			q_size_now++;
    		}
    		if (head->right)
    		{
    			rear->next = head->right;
    			rear = rear->next;
    			q_size_now++;
    		}
    		tail = head;
    		head = head->next;
    		if (--q_size_prv == 0)
    		{
    			tail->next = NULL;
    			q_size_prv = q_size_now;
    			q_size_now = 0;
    		}
    	}
    }
};

//--- method 3: STL queue version
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        bfs(root);
        return root;
    }
    void bfs(Node* root)
    {
    	queue<Node*> que;
    	Node* head;
    	int q_size = 1;
    	que.push(root);

    	while(!que.empty())
    	{
    		if (que.front()->left)
    		{
    			que.back()->next = que.front()->left;
    			que.push(que.front()->left);
    		}
    		if (que.front()->right)
    		{
    			que.back()->next = que.front()->right;
    			que.push(que.front()->right);
    		}
    		head = que.front();
    		que.pop();
    		if (--q_size == 0)
    		{
    			head->next = NULL;
    			q_size = que.size();
    		}
    	}
    }
};