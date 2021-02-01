//--- Q: 1195. Fizz Buzz Multithreaded

//--- method 1: unique lock
class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
        now = three = five = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this](){
                return three == 3 && five != 5 || now > n;
            });
            if (now > n) {
                break;
            }
            printFizz();
            three = 1, ++five, ++now;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this](){
                return three != 3 && five == 5 || now > n;
            });
            if (now > n) {
                break;
            }
            printBuzz();
            five = 1, ++three, ++now;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this](){
                return three == 3 && five == 5 || now > n;
            });
            if (now > n) {
                break;
            }
            printFizzBuzz();
            three = five = 1, ++now;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [this](){
                return three != 3 && five != 5 || now > n;
            });
            if (now > n) {
                break;
            }
            printNumber(now);
            ++three, ++five, ++now;
            cv.notify_all();
        }
    }
    int three, five, now;
    mutex mtx;
    condition_variable cv;
};