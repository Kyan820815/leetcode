//--- Q: 1146. Snapshot Array

//--- method 1: save change to index in map
class SnapshotArray {
public:
    SnapshotArray(int length) {
        cnt = 0;        
        for (int i = 0; i < length; ++i) {
            record[i][cnt] = 0;
        }
    }
    
    void set(int index, int val) {
        record[index][cnt] = val;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto now = record[index].upper_bound(snap_id);
        --now;
        return now->second;
    }
    int cnt;
    unordered_map<int, map<int, int>> record;
};

//--- method 2: binary search
class SnapshotArray {
public:
    SnapshotArray(int length) {
        version = 0;
        for (int i = 0; i < length; ++i) {
            map[i].push_back({version,0});
        }
    }
    
    void set(int index, int val) {
        auto &vec = map[index];
        if (vec.back().first == version) {
            vec.back().second = val;
        } else {
            vec.push_back({version, val});
        }
    }
    
    int snap() {
        return version++;    
    }
    
    int get(int index, int snap_id) {
        auto &vec = map[index];
        int left = 0, right = vec.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (vec[mid].first < snap_id) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return vec[left].first > snap_id ? vec[left-1].second : vec[left].second;
    }
    int version;
    unordered_map<int, vector<pair<int,int>>> map;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */