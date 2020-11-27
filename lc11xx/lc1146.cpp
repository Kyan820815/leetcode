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

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */