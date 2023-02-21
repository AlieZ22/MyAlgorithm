#include <iostream>
using namespace std;

/*
* 单例模式：只能生成一个实例对象
*/

class Single{
public:
    static Single &getInstance();   // 获得单例实例对象
    void print();                   // 打印实例地址
private:
    // 禁止外部构造、析构、拷贝构造、赋值
    Single(){
        cout << "构造函数" << endl;
    }
    ~Single(){
        cout << "析构函数" << endl;
    }
    Single(const Single& single){}
    const Single &operator=(const Single &single){};
};

Single& Single::getInstance(){
    // 用静态局部变量实现单实例：生命周期（整个程序运行期间）+ c++11新特性（内部静态变量是线程安全的）
    static Single single;
    return single;
}

void Single::print(){
    cout << "实例内存地址为：" << this << endl;
}