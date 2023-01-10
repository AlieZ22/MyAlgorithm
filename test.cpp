#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Rational{
public:
    Rational(int n=0, int d=1):numerator(n),denominator(d){}        // 刻意不加explicit，以允许隐式类型转换
    Rational(const Rational& rhs){
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
    }
    Rational& operator=(const Rational& rhs){
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
    }
    int getNumerator() const{
        return this->numerator;
    }
    int getDenominator() const{
        return this->denominator;
    }
    void trim(){      // 最简分数形式
        if(numerator%denominator == 0){
            numerator = numerator / denominator;
            denominator = 1;
        }
    }
private:
    int numerator;     // 分子
    int denominator;   // 分母
};

// non-member 函数进行运算，以支持int与rational的混合式运算
const Rational operator* (const Rational& lhs, const Rational& rhs){
    Rational res(lhs.getNumerator() * rhs.getNumerator(),
                    lhs.getDenominator() * rhs.getDenominator());
    res.trim();
    return res;
}


class Window{
public:
    Window(){}
    Window(int w, int h):width(w),height(h){}
    virtual ~Window(){}
    virtual void onResize(){
        width = 1;
        height = 1;
    }
    int getWidth() { return width; }
    int getHeight() { return height; }

private:
    int width;
    int height;
};

class SpecialWindow: public Window{
public:
    SpecialWindow(){}
    SpecialWindow(int w, int h, int sm):Window(w,h),specialMisc(sm){}
    virtual ~SpecialWindow(){}
    virtual void onResize(){
        static_cast<Window>(*this).onResize();   // 这样是错误的，不应该转型，这样会在转型副本上执行操作
        //Window::onResize();       // 正确的操作
        specialMisc = 1;
    }
    void print(string pre){
        cout << pre << endl;
        cout << "w: " << getWidth() << ", h: " << getHeight() << ", misc: " << specialMisc << endl;
    }
private:
    int specialMisc;
};

int main()
{
    // Rational类测试
    /*
    Rational oneHalf(1, 2);
    Rational result = 4 * oneHalf;
    cout << result.getNumerator() << "/" << result.getDenominator() << endl;
    */

    // Window类测试
    SpecialWindow sw(4, 6, 7);
    sw.print("origin:");
    sw.onResize();         // attention! 当要转型时，这是一个可能发生错误的警告
    sw.print("after onResize:");

    return 0;
}