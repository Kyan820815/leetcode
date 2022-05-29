//--- Q: 1792. Maximum Average Pass Ratio

//--- method 1: total profit
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto addProfit = [](const array<int,2> &cl) {
            return (double)(cl[0]+1)/(cl[1]+1)-(double)cl[0]/cl[1];
        };
        auto comp = [&addProfit](const array<int,2> &cla, const array<int,2> &clb) {
            return addProfit(cla) < addProfit(clb);
        };
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(comp)> que(comp);
        for (auto &cl: classes) {
            que.push({cl[0],cl[1]});
        }
        while (extraStudents--) {
            auto now = que.top();
            que.pop();
            if (now[0] == now[1]) {
                break;
            }
            que.push({now[0]+1,now[1]+1});
        }
        double res = 0;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            res += (double)now[0]/now[1];
        }
        return res/classes.size();
    }
};

//--- method 2: additional profit
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [](double pass, double total) {
            return (pass+1)/(total+1)-pass/total;
        };
        auto comp = [](const pair<double,array<int,2>> &a, const pair<double,array<int,2>> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<double,array<int,2>>, vector<pair<double,array<int,2>>>, decltype(comp)> que(comp);
        double res = 0;
        for (auto &cl: classes) {
            res += (double)cl[0]/cl[1];
            que.push({profit(cl[0],cl[1]), {cl[0],cl[1]}});
        }
        while (extraStudents--) {
            auto [pft, cl] = que.top();
            que.pop();
            res += pft;
            que.push({profit(cl[0]+1,cl[1]+1), {cl[0]+1,cl[1]+1}});
        }
        return res/classes.size();
    }
};