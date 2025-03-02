#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <stdexcept>

class ThreadPool {
private:
    // Worker threads
    std::vector<std::thread> workers;
    
    // Task queue
    std::queue<std::function<void()>> tasks;
    
    // Synchronization
    mutable std::mutex queueMutex;
    std::condition_variable condition;
    
    // Pool state
    bool stop;
    size_t activeThreads;
    
    // TODO: Add helper methods
    void workerFunction();
    
public:
    // TODO: Implement constructor
    explicit ThreadPool(size_t threads);
    
    // TODO: Delete copy operations
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    
    // TODO: Delete move operations
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;
    
    // TODO: Implement destructor
    ~ThreadPool();
    
    // Task submission
    template<class F>
    auto enqueue(F&& f) -> std::future<decltype(f())> {
        using return_type = decltype(f());
        
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::forward<F>(f)
        );
        
        std::future<return_type> res = task->get_future();
        
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            
            if (stop) {
                throw std::runtime_error("Cannot enqueue on stopped ThreadPool");
            }
            
            tasks.emplace([task](){ (*task)(); });
        }
        
        condition.notify_one();
        return res;
    }
    
    // TODO: Implement status methods
    size_t getActiveThreads() const;
    size_t getQueuedTasks() const;
    
    // TODO: Implement pool control
    void waitAll();
    void pause();
    void resume();
    
    // Status check
    bool isStopped() const { return stop; }
};

#endif // THREAD_POOL_H
