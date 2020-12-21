//--- Q: 1472. Design Browser History

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//--- method 1: two stack
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.push_back(url);
        future.clear();
    }
    
    string back(int steps) {
        while (history.size() > 1 && steps) {
            --steps;
            future.push_back(history.back());
            history.pop_back();
        }
        return history.back();
    }
    
    string forward(int steps) {
        while (future.size() && steps) {
            --steps;
            history.push_back(future.back());
            future.pop_back();
        }
        return history.back();
    }
    vector<string> history, future;
};

//--- method 2: list
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        end = now = 0;
        arr.push_back(homepage);
    }
    
    void visit(string url) {
        if (++now < arr.size()) {
            arr[now] = url;
        } else {
            arr.push_back(url);
        }
        end = now;
    }
    
    string back(int steps) {
        now -= steps;
        if (now < 0) {
            now = 0;
        }
        return arr[now];
    }
    
    string forward(int steps) {
        now += steps;
        if (now > end) {
            now = end;
        }
        return arr[now];
    }
    vector<string> arr;
    int end, now;
};

//--- method 3: unordered_map. my version
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        end = now = 0;
        map[now] = homepage;
    }
    
    void visit(string url) {
        map[++now] = url;
        end = now;
    }
    
    string back(int steps) {
        now -= steps;
        if (now < 0) {
            now = 0;
        }
        return map[now];
    }
    
    string forward(int steps) {
        now += steps;
        if (now > end) {
            now = end;
        }
        return map[now];
    }
    unordered_map<int, string> map;
    int end, now;
};