//--- Q: 0428. Serialize and Deserialize N-ary Tree

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
    string serialize(Node* root) {
        if (!root) {
            return "#";
        }
        ostringstream ss;
        encode(root, ss);
        return ss.str();
    }
    
    void encode(Node *root, ostringstream &ss) {
        ss << to_string(root->val) + " ";
        for (auto &next: root->children) {
            encode(next, ss);
        }
        ss << "# ";
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream ss(data);
        return decode(ss);
    }
    
    Node *decode(istringstream &ss) {
        string str;
        ss >> str;
        if (str == "#") {
            return nullptr;
        }
        Node *now = new Node(stoi(str)), *next;
        while (next = decode(ss)) {
            now->children.push_back(next);
        }
        return now;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));