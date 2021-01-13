//--- Q: 1268. Search Suggestions System

//--- method 1: vector lower bound
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        int start = 0;
        string word = "";
        sort(products.begin(), products.end());
        for (int i = 0; i < searchWord.size(); ++i) {
            word += searchWord[i];
            vector<string> sugg;
            auto now = lower_bound(products.begin()+start, products.end(), word);
            start = now - products.begin();
            for (int j = start; j < products.size(); ++j) {
                if (sugg.size() < 3 && products[j].substr(0, word.size()) == word) {
                    sugg.push_back(products[j]);
                } else {
                    break;
                }
            }
            res.push_back(sugg);
        }
        return res;
    }
};

//--- method 2: set lower bound
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res_vec;
        set<string> ss(products.begin(), products.end());
        int last = 0;
        string now_str  = "";
        for (int i = 0; i < searchWord.size(); ++i) {
            vector<string> res;
            now_str += searchWord[i];
            for (auto i = ss.lower_bound(now_str); i != ss.end(); ++i) {
                if (res.size() < 3 && (*i).substr(0, now_str.size()) == now_str) {
                    res.push_back(*i);
                } else {
                    break;
                }
            }
            res_vec.push_back(res);
        }
        return res_vec;
    }
};

//--- method 3: search from last searching index
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string word = "";
        int start = 0;
        for (int i = 0; i < searchWord.size(); ++i) {
            vector<string> now;
            word += searchWord[i];
            for (int j = start; j < products.size(); ++j) {
                // if (products[j] >= word) {
                if (strcmp(products[j].c_str(), word.c_str()) >= 0) {
                    start = j;
                    break;
                }
            }
            for (int j = start; j < products.size(); ++j) {
                if (products[j].substr(0, i+1) == word && now.size() < 3)
                    now.push_back(products[j]);
                else
                    break;
            }
            res.push_back(now);
        }
        return res;
    }
};