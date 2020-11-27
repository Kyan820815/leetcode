//--- Q: 599. Minimum Index Sum of Two Lists

//--- method 1: map operation
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;
        vector<string> res;
        int sum = INT_MAX;
        for (int i = 0; i < list1.size(); ++i)
        	map[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i)
        {
            if (!map.count(list2[i]))
                continue;
            if (sum > i + map[list2[i]])
            {
                sum = i + map[list2[i]];
                res.clear();
                res.push_back(list2[i]);
            }
            else if (sum == i + map[list2[i]])
                res.push_back(list2[i]);
        }
        return res;
    }
};