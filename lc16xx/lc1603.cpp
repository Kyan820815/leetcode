//--- Q: 1603. Design Parking System

//--- method 1: thread safe
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        arr = {big, medium, small};
    }
    
    bool addCar(int carType) {
        auto &m = mtx[carType-1];
        unique_lock<mutex> ulock(m);
        return --arr[carType-1] >= 0;
    }
    vector<int> arr;
    array<mutex,3> mtx;
};


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */