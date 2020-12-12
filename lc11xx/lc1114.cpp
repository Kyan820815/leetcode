//--- Q: 1114. Print in Order

//--- method 1: condition variable & unique lock
class Foo {
public:
    Foo() {
        now = 0;        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){
                return now == 0;
            });
            ++now;
            printFirst();
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){
                return now == 1;
            });
            ++now;
            printSecond();
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){
                return now == 2;
            });
            ++now;
            printThird();
        }
        cv.notify_all();
    }
    condition_variable cv;
    mutex mtx;
    int now;
};

