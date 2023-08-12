class ZeroEvenOdd {
private:
    int n;
    mutex _mutex;
    condition_variable cv;
    int flag = 0;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1; i<=n; ++i){
            unique_lock<mutex> lock(_mutex);
            cv.wait(lock, [&]{return flag==0;});
            printNumber(0);
            if(i%2==0){
                flag = 2;
            }else{
                flag = 1;
            }
            cv.notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2; i<=n; i+=2){
            unique_lock<mutex> lock(_mutex);
            cv.wait(lock, [&]{return flag==2;});
            printNumber(i);
            flag = 0;
            cv.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1; i<=n; i+=2){
            unique_lock<mutex> lock(_mutex);
            cv.wait(lock, [&]{return flag==1;});
            printNumber(i);
            flag = 0;
            cv.notify_one();
        }
    }
};