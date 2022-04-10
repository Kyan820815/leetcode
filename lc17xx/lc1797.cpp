//--- Q: 1797. Design Authentication Manager

//--- method 1: map & set
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        live = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime+live;
        set.insert(map[tokenId]);
    }
    
    void renew(string tokenId, int currentTime) {
        if (map.find(tokenId) != map.end() && map[tokenId] > currentTime) {
            set.erase(map[tokenId]);
            map[tokenId] = currentTime+live;
            set.insert(map[tokenId]);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto pos = set.upper_bound(currentTime);
        set.erase(set.begin(), pos);
        return set.size();
    }
    unordered_map<string,int> map;
    set<int> set;
    int live;
};

//--- method 2: map

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */