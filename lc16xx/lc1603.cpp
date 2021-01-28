//--- Q: 1603. Design Parking System

//--- method 1: thread safe
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        num = {big, medium, small};
    }
    
    bool addCar(int carType) {
        {
            auto &mu = mtx[carType-1];
            unique_lock<mutex> ulock(mu);
            return --num[carType-1] >= 0;
        }
        return false;
    }
    array<mutex, 3> mtx;
    vector<int> num;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */