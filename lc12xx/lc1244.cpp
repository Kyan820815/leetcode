//--- Q: 1244. Design A Leaderboard

//--- method 1: map
class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        board.erase({people[playerId], playerId});
        people[playerId] += score;
        board.insert({people[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        for (auto i = board.rbegin(); i != board.rend() && K; ++i, --K) {
            sum += i->first;
        }
        return sum;
    }
    
    void reset(int playerId) {
        board.erase({people[playerId], playerId});
        people.erase(playerId);
    }
    set<pair<int, int>> board;
    unordered_map<int, int> people;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */