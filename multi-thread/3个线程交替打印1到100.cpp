#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex data_mutex;
condition_variable data_var;
int flag=1;
int i=0;
#define MAXNUM 100

void printA(){
    while(i<MAXNUM){
        unique_lock<mutex> lck(data_mutex);
        data_var.wait(lck, []{return flag==1;});
        flag=2;
        if(i>=MAXNUM){
            data_var.notify_all();
            break;
        }
        i++;
        cout<<"threadA:"<<i<<endl;
        data_var.notify_all();
    }
    cout<<"finish A"<<endl;
}

void printB(){
    while(i<MAXNUM){
        unique_lock<mutex> lck(data_mutex);
        data_var.wait(lck, []{return flag==2;});
        flag=3;
        if(i>=MAXNUM){
            data_var.notify_all();
            break;
        }
        i++;
        cout<<"threadB:"<<i<<endl;
        data_var.notify_all();
    }
    cout<<"finish B"<<endl;
}

void printC(){
    while(i<MAXNUM){
        unique_lock<mutex> lck(data_mutex);
        data_var.wait(lck, []{return flag==3;});
        flag=1;
        if(i>=MAXNUM){
            data_var.notify_all();
            break;
        }
        i++;
        cout<<"threadC:"<<i<<endl;
        data_var.notify_all();
    }
    cout<<"finish C"<<endl;
}

int main(){
    thread tA(printA);
    thread tB(printB);
    thread tC(printC);
    tA.join();
    tB.join();
    tC.join();
    system("pause");
    return 0;
}