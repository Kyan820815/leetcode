//--- Q: 0919. Complete Binary Tree Inserter

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//--- method 1: bfs
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        que.push(root);
        while (que.size()) {
            auto now = que.front();
            if (now->left) {
                que.push(now->left);
            }
            if (now->right) {
                que.push(now->right);
                que.pop();
            } else {
                break;
            }
        }
    }
    
    int insert(int val) {
        auto node = new TreeNode(val);
        auto now = que.front();
        if (!now->left) {
            now->left = node;
        } else {
            now->right = node;
            que.pop();
        }
        que.push(node);
        return now->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
    queue<TreeNode *> que;
    TreeNode *_root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

//--- method 2: index operation
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        r = root;
        que.push_back(NULL);
        que.push_back(root);
        for (int i = 1; i < que.size(); ++i)
        {
        	if (que[i]->left)
        		que.push_back(que[i]->left);
        	else break;
        	if (que[i]->right)
        		que.push_back(que[i]->right);
        	else break;
        }
    }
    
    int insert(int v) {
        TreeNode *node = new TreeNode(v);

        int parent = que.size()/2;

        if ((que.size()-1) % 2 == 1)
        	que[parent]->left = node;
        else
        	que[parent]->right = node;
        que.push_back(node);
        return que[parent]->val;
    }
    
    TreeNode* get_root() {
        return r;
    }
private:
	vector<TreeNode *> que;
	TreeNode *r;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */