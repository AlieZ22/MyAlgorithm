#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex _mutex;
condition_variable cv;
int flag=1;
int i=0;
int n;

void printEven(){
    for(int i=2; i<=n; i+=2){
        unique_lock<mutex> lock(_mutex);
        cv.wait(lock, [&]{return flag==2;});
        cout<<i;
        flag = 1;
        cv.notify_one();
    }
}

void printOdd(){
    for(int i=1; i<=n; i+=2){
        unique_lock<mutex> lock(_mutex);
        cv.wait(lock, [&]{return flag==1;});
        cout<<i;
        flag = 2;
        cv.notify_one();
    }
}

int main(){
    scanf("%d", &n);
    thread tA(printOdd);
    thread tB(printEven);
    tA.join();
    tB.join();
    system("pause");
    return 0;
}