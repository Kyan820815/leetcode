//--- Q: 1195. Fizz Buzz Multithreaded

//--- method 1: unique lock
class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
        idx = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (idx <= n) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this]() {
                return idx % 3 == 0 && idx % 5 != 0 || idx > n;
            });
            if (idx > n) {
                break;
            }
            printFizz();
            idx++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (idx <= n) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this]() {
                return idx % 3 != 0 && idx % 5 == 0 || idx > n;
            });
            if (idx > n) {
                break;
            }
            printBuzz();
            idx++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (idx <= n) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this]() {
                return idx % 3 == 0 && idx % 5 == 0 || idx > n;
            });
            if (idx > n) {
                break;
            }
            printFizzBuzz();
            idx++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (idx <= n) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this]() {
                return idx % 3 != 0 && idx % 5 != 0 || idx > n;
            });
            if (idx > n) {
                break;
            }
            printNumber(idx);
            idx++;
            cv.notify_all();
        }
    }
    
    condition_variable cv;
    int idx;
    mutex mtx;
};