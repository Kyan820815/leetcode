//--- Q: 1146. Snapshot Array

//--- method 1: binary search
class SnapshotArray {
public:
    int snap_version = 0;
    SnapshotArray(int length) {
        data.resize(length);
        for (int i = 0; i < length; ++i) {
            data[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        if (data[index].back().first == snap_version) {
            data[index].back().second = val;
        } else {
            data[index].push_back({snap_version, val});
        }
    }
    
    int snap() {
        return snap_version++;
    }
    
    int get(int index, int snap_id) {
        int left = 0, right = data[index].size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (data[index][mid].first < snap_id) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return data[index][left].first > snap_id ? data[index][left-1].second : data[index][left].second;
    }
    vector<vector<pair<int,int>>> data;
};

//--- method 2: save change to index in map
class SnapshotArray {
public:
    int snap_version = 0;
    SnapshotArray(int length) {
        data.resize(length);
        for (int i = 0; i < length; ++i) {
            data[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        data[index][snap_version] = val;
    }
    
    int snap() {
        return snap_version++;
    }
    
    int get(int index, int snap_id) {
        auto pos = data[index].upper_bound(snap_id);
        return prev(pos)->second;
    }
    vector<map<int, int>> data;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */