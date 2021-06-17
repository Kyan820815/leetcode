//--- Q: 1628. Design an Expression Tree With Evaluate Function

//--- method 1: ood
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
    
protected:
    // define your fields here
};

class NumNode: public Node {
public:
    NumNode(int num): _val(num) {}
    int evaluate() const {
        return _val;
    }
private:
    int const _val;
};

class OpNode: public Node {
public:
    OpNode (Node *left, Node *right): _left(left), _right(right) {}
    ~OpNode () {
        delete _left;
        delete _right;
    }
protected:
    Node *const _left;
    Node *const _right;
};

class AddNode: public OpNode {
public:
    AddNode(Node *left, Node *right): OpNode(left, right) {}
    int evaluate() const {
        return _left->evaluate() + _right->evaluate();
    }
};

class SubtractNode: public OpNode {
public:
    SubtractNode(Node *left, Node *right): OpNode(left, right) {}
    int evaluate() const {
        return _left->evaluate() - _right->evaluate();
    }
};

class MultiplyNode: public OpNode {
public:
    MultiplyNode(Node *left, Node *right): OpNode(left, right) {}
    int evaluate() const {
        return _left->evaluate() * _right->evaluate();
    }
};

class DivideNode: public OpNode {
public:
    DivideNode(Node *left, Node *right): OpNode(left, right) {}
    int evaluate() const {
        return _left->evaluate() / _right->evaluate();
    }
};



/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node *> sk;
        for (auto &str: postfix) {
            if (set.find(str) != set.end()) {
                auto right = sk.back();
                sk.pop_back();
                auto left = sk.back();
                sk.pop_back();
                sk.push_back(createNode(str, left, right));
            } else {
                sk.push_back(new NumNode(stoi(str)));
            }
        }
        return sk[0];
    }
private:
    unordered_set<string> set = {"+", "-", "*", "/"};
    Node *createNode(string &op, Node *left, Node *right) {
        switch (op[0]) {
            case '+':
                return new AddNode(left, right);
                break;
            case '-':
                return new SubtractNode(left, right);
                break;
            case '*':
                return new MultiplyNode(left, right);
                break;
            case '/':
                return new DivideNode(left, right);
                break;
            default:
                return NULL;
        }
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */