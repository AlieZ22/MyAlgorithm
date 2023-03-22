#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t threads) : stop(false) {
        for (size_t i = 0; i < threads; ++i) {
            threads_.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->mutex_);
                        this->condition_.wait(lock, [this] {
                            return this->stop || !this->tasks_.empty();
                        });
                        if (this->stop && this->tasks_.empty())
                            return;
                        task = std::move(this->tasks_.front());
                        this->tasks_.pop();
                    }
                    task();
                }
            });
        }
    }

    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args) {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            tasks_.emplace(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        }
        condition_.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            stop = true;
        }
        condition_.notify_all();
        for (std::thread& thread : threads_)
            thread.join();
    }

private:
    std::vector<std::thread> threads_;
    std::queue<std::function<void()>> tasks_;
    std::mutex mutex_;
    std::condition_variable condition_;
    bool stop;
};

/*
在上述代码中，我们使用std::thread、std::mutex、std::condition_variable和std::queue等C++标准库的线程相关工具来实现线程池。
其中，ThreadPool类包括以下几个主要的成员函数：
 - 构造函数：创建线程池，初始化工作线程的数量和任务队列等属性。
 - enqueue函数：将任务添加到任务队列中，由工作线程来执行。
 - 析构函数：销毁线程池，等待所有工作线程结束。
在线程池的实现中，我们使用了生产者-消费者模型，将任务添加到任务队列中，由工作线程来处理任务。
同时，我们使用互斥锁和条件变量等工具来保证线程池的线程安全和高效率。

使用上述线程池的示例代码如下：
*/

#include <iostream>
#include <chrono>

void task(int num) {
    std::cout << "Task " << num << " is running" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Task " << num << " is done" << std::endl;
}

int main() {
    ThreadPool pool(4);
    for (int i = 0; i < 8; ++i)
        pool.enqueue(task, i);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}


/*
在上述代码中，我们创建了一个ThreadPool对象，并使用enqueue函数将8个任务添加到任务队列中。
每个任务运行1秒钟，最后等待10秒钟，以等待所有任务完成。
*/
