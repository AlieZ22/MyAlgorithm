#include<iostream>
#include<algorithm>
using namespace std;

class Rational{
public:
    Rational(int n=0, int d=1):numerator(n),denominator(d){}        // 刻意不加explicit，以允许隐式类型转换
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

int main()
{
    Rational oneHalf(1, 2);
    Rational result = 4 * oneHalf;
    cout << result.getNumerator() << "/" << result.getDenominator() << endl;
    return 0;
}