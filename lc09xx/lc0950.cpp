//--- Q: 0950. Reveal Cards In Increasing Order

//--- method 1: nlogn sort and deque simulation for reversed process
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> que;
        for (int i = deck.size()-1; i >= 0; --i) {
            if (que.size()) {
                que.push_front(que.back());
                que.pop_back();
            }
            que.push_front(deck[i]);
        }
        return vector<int>(que.begin(), que.end());
    }
};