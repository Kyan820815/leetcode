//--- Q: 1184. Distance Between Bus Stops

//--- method 1: split two two array
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int left = 0, right = 0;
        if (start > destination) {
            swap(start, destination);
        }
        for (int i = 0; i < distance.size(); ++i) {
            if (i >= start && i < destination) {
                left += distance[i];
            } else {
                right += distance[i];
            }
        }
        return min(left, right);
    }
};