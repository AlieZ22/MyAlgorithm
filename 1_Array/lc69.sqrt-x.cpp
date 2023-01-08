#include<iostream>
using namespace std;

/*
* @method: 浮点数二分，直接循环100次，判断不取等，改变不移位
* @evaluation: O(log n)
*/

class Solution69 {
public:
    int mySqrt(int x) {
        double l=0, r=x;
        for(int i=0; i<100; i++)
        {
            double mid = (l+r)/2;         // 浮点数没有位移运算
            if(mid*mid > x) r=mid;
            else l=mid;
        }
        return int(l);
    }
};