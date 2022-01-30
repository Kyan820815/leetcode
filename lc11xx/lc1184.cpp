//--- Q: 1184. Distance Between Bus Stops

//--- method 1: split two two array
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = 0, partial = 0;
        if (start > destination) {
            swap(start, destination);
        }
        for (int i = 0; i < distance.size(); ++i) {
            if (i >= start && i < destination) {
                partial += distance[i];
            }
            total += distance[i];
        }
        return min(partial, total-partial);
    }
};