#include "ThreadPool_starter.h"
#include <iostream>

// TODO: Implement worker thread function
// This is the main loop for each worker thread
void ThreadPool::workerFunction() {
    // Continuously process tasks until stopped
    // Lock queue mutex
    // Wait for tasks or stop signal
    // Get task from queue if available
    // Execute task
    // Update active thread count
}

// TODO: Implement constructor
// Initialize thread pool with specified number of threads
ThreadPool::ThreadPool(size_t threads) : stop(false), activeThreads(0) {
    // Validate thread count
    // Initialize worker threads
    // Store threads in vector
    // Handle thread creation failures
}

// TODO: Implement destructor
// Ensure proper cleanup of thread pool
ThreadPool::~ThreadPool() {
    // Signal all threads to stop
    // Wake up all threads
    // Join all threads
    // Clean up resources
}

// TODO: Implement status methods
size_t ThreadPool::getActiveThreads() const {
    // Return number of currently active threads
    // Remember to protect shared data access
    return 0;  // Replace with your implementation
}

size_t ThreadPool::getQueuedTasks() const {
    // Return number of tasks in queue
    // Remember to protect shared data access
    return 0;  // Replace with your implementation
}

// TODO: Implement pool control methods
void ThreadPool::waitAll() {
    // Wait for all tasks to complete
    // Don't accept new tasks while waiting
    // Handle thread synchronization
}

void ThreadPool::pause() {
    // Temporarily stop processing new tasks
    // Allow current tasks to complete
    // Handle thread synchronization
}

void ThreadPool::resume() {
    // Resume processing tasks
    // Wake up worker threads
    // Handle thread synchronization
}

/* Example usage:

int main() {
    try {
        // Create thread pool with 4 threads
        ThreadPool pool(4);
        
        // Create some test tasks
        std::vector<std::future<int>> results;
        
        // Enqueue several tasks
        for (int i = 0; i < 8; ++i) {
            results.emplace_back(
                pool.enqueue([i] {
                    std::cout << "Task " << i << " running in thread " 
                             << std::this_thread::get_id() << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    return i * i;
                })
            );
        }
        
        // Get all results
        for (auto& result : results) {
            std::cout << "Task result: " << result.get() << std::endl;
        }
        
        // Test pool control
        pool.pause();
        std::cout << "Pool paused" << std::endl;
        
        pool.resume();
        std::cout << "Pool resumed" << std::endl;
        
        pool.waitAll();
        std::cout << "All tasks completed" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

*/
