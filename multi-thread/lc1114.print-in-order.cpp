#include <iostream>
#include <semaphore.h>
using namespace std;

void printFirst(){
    cout << "First" << endl;
}
void printSecond(){
    cout << "Second" << endl;
}
void printThird(){
    cout << "Third" << endl;
}

// 多线程并发访问一个Foo实例
/*
#include <semaphore.h>
sem_init; sem_post; sem_wait;
*/
class Foo{
private:
    sem_t firstJobDone;
    sem_t secondJobDone;
public:
    Foo(){
        // sem_init: 信号量初始化; args: 信号量地址，是否进程间共享，信号量初始值
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }
    void first(){
        printFirst();
        sem_post(&firstJobDone);
    }
    void second(){
        sem_wait(&firstJobDone);
        printSecond();
        sem_post(&secondJobDone);
    }
    void third(){
        sem_wait(&secondJobDone);
        printThird();
    }

};