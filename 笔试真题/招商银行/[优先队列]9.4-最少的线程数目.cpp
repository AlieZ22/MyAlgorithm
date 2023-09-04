/*
题干：
有n个计划任务，任务规定了开始时间和结束时间，每个任务需要一个线程来执行，
计划任务执行完成后会释放线程。
Q：线程池最少需要创建多少线程才能完成所有任务的执行？
*/

// 开始的思路是相交区间数+1，但仔细想了会觉得不对，任务执行完成后会释放线程

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task{
    int start, end;
};

struct Compare{
    bool operator()(const Task& a, const Task& b){
        return a.end > b.end;
    }
};

int minThreadPool(vector<Task>& tasks){
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
        return a.start < b.start;
    });
    priority_queue<Task, vector<Task>, Compare> q;
    
    int threadCnt = 0;
    for(const auto& task: tasks){
        while(!q.empty() && q.top().end <= task.start){
            q.pop();
        }
        q.push(task);
        threadCnt = max(threadCnt, static_cast<int>(q.size()));
    }
    return threadCnt;
}

int main(){
    /*
    2
    1 3
    2 4
    --> 2
    */
    int n;
    cout<<"请输入任务数：";
    cin>>n;
    vector<Task> tasks(n);
    cout<<"请输入任务的开始时间和结束时间："<<endl;
    for(int i=0; i<n; ++i){
        cin>> tasks[i].start >> tasks[i].end;
    }
    int ans = minThreadPool(tasks);
    cout<<"至少需要 "<<ans<<" 个线程。"<<endl;
    return 0;
}