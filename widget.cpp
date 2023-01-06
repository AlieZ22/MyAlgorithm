#include<iostream>
#include<memory>
using namespace std;

class Widget{
public:
    Widget(){ cout << "Widget constructed by default." << endl; }
    Widget(int ix) : x(ix) { cout << "Widget constructed." << endl; }
    Widget(const Widget &rhs) { 
        x = rhs.x;
        cout << "Widget constructed by copying." << endl;
    }
    ~Widget(){
        cout << "Widget destructed." << endl;
    }
    int getX(){
        return this->x;
    }
private:
    int x;
};

void f1(){     // 手动资源管理
    Widget *pw = new Widget(7);
    cout << "pw.x = " << pw->getX() << endl;
    delete pw;
}

void f2(){    // auto_ptr自动资源管理
    auto_ptr<Widget> auto_pw(new Widget(77));
    cout << "pw.x = " << auto_pw->getX() << endl;
}


int main(){
    f2();
    return 0;
}