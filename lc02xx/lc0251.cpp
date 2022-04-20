//--- Q: 0251. Flatten 2D Vector

//--- method 1: two pointers, reference, O(1) space
class Vector2D {
public:
    vector<vector<int>> &vec_;
    int i, j;
    Vector2D(vector<vector<int>>& vec): vec_(vec) {
        i = 0, j = 0;
        update();
    }
    
    int next() {
        int val = vec_[i][j++];
        update();
        return val;
    }
    
    bool hasNext() {
        return i != vec_.size();
    }
private:
    void update() {
        while (i < vec_.size() && j == vec_[i].size()) {
            j = 0, i += 1;
        }
    }
};

//--- method 2: two pointers, iterator, O(1) space
class Vector2D {
public:
    vector<vector<int>>::iterator cur, end;
    int j;
    Vector2D(vector<vector<int>>& vec) {
        cur = vec.begin(), end = vec.end();
        j = 0;
        update();
    }
    
    int next() {
        int val = (*cur)[j++];
        update();
        return val;
    }
    
    bool hasNext() {
        return cur != end;
    }
private:
    void update() {
        while (cur != end && j == (*cur).size()) {
            cur = std::next(cur);
            j = 0;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */