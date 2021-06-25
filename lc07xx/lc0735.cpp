//--- Q: 735. Asteroid Collision

//--- method 1: stack iteration
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sk;
        for (auto &stone: asteroids) {
            int push = 1;
            if (stone < 0) {
                while (sk.size() && sk.back() > 0) {
                    if (sk.back() < abs(stone)) {
                        sk.pop_back();
                    } else if (sk.back() == abs(stone)) {
                        push = 0;
                        sk.pop_back();
                        break;
                    } else {
                        push = 0;
                        break;
                    }
                }
                if (push) {
                    sk.push_back(stone);
                }
            } else {
                sk.push_back(stone);
            }
        }
        return sk;
    }
};