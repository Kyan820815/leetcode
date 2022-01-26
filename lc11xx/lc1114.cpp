//--- Q: 1114. Print in Order

class Foo {
public:
    Foo() {
        idx = 1;        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [this]() {
            return idx == 1;
        });
        ++idx;
        printFirst();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [this]() {
            return idx == 2;
        });
        ++idx;
        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [this]() {
            return idx == 3;
        });
        ++idx;
        printThird();
        cv.notify_all();
    }
    condition_variable cv;
    mutex mtx;
    int idx;
};