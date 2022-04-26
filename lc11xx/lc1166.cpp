//--- Q: 1166. Design File System

//--- method 1: trie tree
class TNode {
public:
    TNode(int val) {
        val_ = val;
    }
    unordered_map<string, TNode *> next;
    string name_;
    int val_;
};

class FileSystem {
public:
    TNode *root;
    FileSystem() {
        root = new TNode(0);
    }
    
    bool createPath(string path, int value) {
        if (path == "" || path == "/") {
            return false;
        }
        auto arr = pathArr(path);
        auto now = root;
        int n = arr.size();
        for (int i = 0; i < n-1; ++i) {
            if (now->next.find(arr[i]) == now->next.end()) {
                return false;
            }
            now = now->next[arr[i]];
        }
        if (now->next.find(arr.back()) != now->next.end()) {
            return false;
        } else {
            now->next[arr.back()] = new TNode(value);
        }
        return true;
    }
    
    int get(string path) {
        if (path == "" || path == "/") {
            return false;
        }
        auto arr = pathArr(path);
        auto now = root;
        for (auto &name: arr) {
            if (now->next.find(name) == now->next.end()) {
                return -1;
            }
            now = now->next[name];
        }
        return now->val_;
    }
    
    vector<string> pathArr(string &path) {
        vector<string> arr;
        string name = "";
        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (name.size()) {
                    arr.push_back(name);
                }
                name = "";
            } else {
                name += path[i];
            }
        }
        return arr;
    }
};

//--- method 2: map


/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

