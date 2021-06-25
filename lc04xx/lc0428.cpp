//--- Q: 428. Serialize and Deserialize N-ary Tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//--- method 1: O(n) time
class Codec {
public:
    // Encodes a tree to a single string.
    void serialize(Node *root, ostringstream &ostr) {
        if (root) {
            ostr << " " + to_string(root->val);
            for (int i = 0; i < root->children.size(); ++i) {
                serialize(root->children[i], ostr);
            }
        }
        ostr << " #";
    }
    
    Node *deserialize(istringstream &istr) {
        string val;
        istr >> val;
        if (val == "#") {
            return NULL;
        }
        Node *root = new Node(stoi(val));
        Node *get;
        while ((get = deserialize(istr)) != NULL) {
            root->children.push_back(get);
        }
        return root;
    }
    
    string serialize(Node* root) {
        ostringstream ostr;
        serialize(root, ostr);
        return ostr.str();
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream istr(data);
        Node *root = deserialize(istr);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));