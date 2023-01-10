#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* @method: 滑动窗口，窗口内只能有两种水果（用哈希表记录每种的数目），取只含2种水果的最长连续子数组
* @evaluation: O(n), unordered_map erase复杂度为O(1)
*/

class Solution904 {
public:
    const int BASKET_NUM = 2;

    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> umap;
        int maxLen = 0;
        int start=0, end=0;
        for(; end < fruits.size(); ++end){
            ++umap[fruits[end]];
            while(umap.size() > BASKET_NUM){
                if(--umap[fruits[start]] == 0)
                    umap.erase(fruits[start]);
                ++start;
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};


int main()
{
    Solution904 s;
    vector<int> v{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << s.totalFruit(v) << endl;
    return 0;
}