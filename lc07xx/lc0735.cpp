//--- Q: 0735. Asteroid Collision

//--- method 1: stack iteration
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sk;
        for (auto &stone: asteroids) {
            if (stone < 0) {
                while (sk.size() && sk.back() > 0 && sk.back() < abs(stone)) {
                    sk.pop_back();
                }
                if (!sk.size() || sk.back() < 0) {
                    sk.push_back(stone);
                } else if (sk.size() && sk.back() == abs(stone)) {
                    sk.pop_back();
                }
            } else {
                sk.push_back(stone);
            }
        }
        return sk;
    }
};