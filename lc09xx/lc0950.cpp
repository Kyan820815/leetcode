//--- Q: 950. Reveal Cards In Increasing Order

//--- method 1: nlogn sort and deque simulation for reversed process
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> que{deck.back()};
        for (int i = n-2; i >= 0; --i) {
            que.push_front(que.back());
            que.pop_back();
            que.push_front(deck[i]);
        }
        return vector<int>(que.begin(), que.end());
    }
};