//--- Q: 1600. Throne Inheritance

//--- method 1: dfs
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        start = kingName;        
    }
    
    void birth(string parentName, string childName) {
        order_map[parentName].push_back(childName);
    }
    
    void death(string name) {
        death_map.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(start, res);
        return res;
    }
    
    void dfs(string &now, vector<string> &res) {
        if (death_map.find(now) == death_map.end()) {
            res.push_back(now);
        }
        for (int i = 0; i < order_map[now].size(); ++i) {
            dfs(order_map[now][i], res);
        }
    }
    unordered_map<string, vector<string>> order_map;
    unordered_set<string> death_map;
    string start;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */