//--- Q: 919. Complete Binary Tree Inserter

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
        rt = root;
        que.push(rt);
        while (que.size()) {
            auto now = que.front();
            if (now->left && now->right) {
                que.pop();
                que.push(now->left);
                que.push(now->right);
            } else {
                break;
            }
        }
    }
    
    int insert(int v) {
        auto now = que.front();
        if (!que.front()->left) {
            now->left = new TreeNode(v);
        } else {
            now->right = new TreeNode(v);
            que.push(now->left);
            que.push(now->right);
            que.pop();
        }
        return now->val;
    }
    
    TreeNode* get_root() {
        return rt;
    }
    TreeNode *rt;
    queue<TreeNode *> que;
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