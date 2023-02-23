#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 一遍遍历，每天记录当前最低点，每天计算获利
*/

class Solution_hot121 {
public:
    int maxProfit(vector<int>& prices) {
        int minValIndex = 0;
        int maxP = 0, currP =0;
        for(int i=0; i<prices.size(); ++i){
            currP = prices[i] - prices[minValIndex];
            maxP = currP > maxP? currP: maxP;
            minValIndex = prices[i] < prices[minValIndex]? i: minValIndex;
        }
        return maxP;
    }
};