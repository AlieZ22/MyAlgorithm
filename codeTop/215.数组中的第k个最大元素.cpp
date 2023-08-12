#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 建立一个大根堆，做k-1次删除之后，堆顶元素就是答案
*/
class Solution_hot215 {
public:
    void adjustHeap(vector<int>& nums, int i, int heapSize){
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if(l < heapSize && nums[l] > nums[largest]){
            largest = l;
        }
        if(r < heapSize && nums[r] > nums[largest]){
            largest = r;
        }
        if(largest != i){
            swap(nums[i], nums[largest]);
            adjustHeap(nums, largest, heapSize);
        }
    }
    void buildMaxHeap(vector<int>& nums, int heapSize){
        // 每个非叶节点的根节点依此调整
        for (int i = heapSize / 2; i >= 0; --i){
            adjustHeap(nums, i, heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // 删除过程，每次删除堆顶，将最后一个元素移到堆顶，然后调整堆结构
        int n = nums.size();
        buildMaxHeap(nums, n);
        for(int i=1; i<k; ++i){
            swap(nums[0], nums[nums.size()-i]);        // 注意这里要为nums.size()
            --n;
            adjustHeap(nums, 0, n);
        }
        return nums[0];
    }
};