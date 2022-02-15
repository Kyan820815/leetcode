//--- Q: 1826. Faulty Sensor

//--- method 1: two pointers
class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size(), i = 0;
        while (i < n && sensor1[i] == sensor2[i]) {
            ++i;
        }
        while (i < n-1 && sensor1[i] == sensor2[i+1] && sensor1[i+1] == sensor2[i]) {
            ++i;
        }
        
        return i >= n-1 ? -1 : (sensor1[i] == sensor2[i+1] ? 1 : 2);
    }
};