#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
* @method: 双指针，头尾相向，每次swap
* @evaluation: O(n)
*/

class Solution344 {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};