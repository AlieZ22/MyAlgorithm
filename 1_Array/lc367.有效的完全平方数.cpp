#include<iostream>
using namespace std;

/*
* @method: 先求个平方根，然后判断平方根是不是整数即可
* @evaluation: O(log n)
*/

class Solution367 {
public:
    double sqrtFunc(int num){
        double l = 0, r = num;
        double mid;
        for(int i=0; i<100; i++){
            mid = (l+r)/2;
            if(mid * mid > num) r=mid;
            else l=mid;
        }
        return l;
    }
    bool isPerfectSquare(int num) {
        double sqrtN = sqrtFunc(num);
        return sqrtN==int(sqrtN)? true: false;
    }
};