#include "ThreadPool_starter.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
using namespace std;

void testBasicFunctionality() {
    cout << "\n1. Testing Basic Functionality" << endl;
    cout << "===========================" << endl;
    
    ThreadPool pool(4);
    cout << "Thread pool created with 4 threads" << endl;
    
    // Simple task
    auto result = pool.enqueue([]() {
        this_thread::sleep_for(chrono::milliseconds(100));
        return 42;
    });
    
    cout << "Task result: " << result.get() << endl;
    cout << "Active threads: " << pool.getActiveThreads() << endl;
    cout << "Queued tasks: " << pool.getQueuedTasks() << endl;
}

void testMultipleTasks() {
    cout << "\n2. Testing Multiple Tasks" << endl;
    cout << "========================" << endl;
    
    ThreadPool pool(2);  // Deliberately use fewer threads than tasks
    vector<future<int>> results;
    
    // Enqueue multiple tasks
    for (int i = 0; i < 5; ++i) {
        results.emplace_back(pool.enqueue([i]() {
            cout << "Task " << i << " starting..." << endl;
            this_thread::sleep_for(chrono::milliseconds(100 * i));
            cout << "Task " << i << " completed" << endl;
            return i;
        }));
    }
    
    // Get results
    for (size_t i = 0; i < results.size(); ++i) {
        cout << "Result " << i << ": " << results[i].get() << endl;
    }
}

void testErrorHandling() {
    cout << "\n3. Testing Error Handling" << endl;
    cout << "========================" << endl;
    
    ThreadPool pool(1);
    
    // Task that throws an exception
    try {
        auto result = pool.enqueue([]() {
            throw runtime_error("Task error");
            return 0;
        });
        
        result.get();  // Should throw
        assert(false && "Should not reach here");
        
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    // Try to enqueue task after stopping pool
    try {
        pool.~ThreadPool();  // Force destruction
        
        auto result = pool.enqueue([]() { return 42; });
        assert(false && "Should not reach here");
        
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testPoolControl() {
    cout << "\n4. Testing Pool Control" << endl;
    cout << "======================" << endl;
    
    ThreadPool pool(2);
    
    // Start some long-running tasks
    vector<future<int>> results;
    for (int i = 0; i < 4; ++i) {
        results.emplace_back(pool.enqueue([i]() {
            this_thread::sleep_for(chrono::milliseconds(500));
            return i;
        }));
    }
    
    // Test pause/resume
    cout << "Pausing pool..." << endl;
    pool.pause();
    cout << "Pool paused. Active threads: " << pool.getActiveThreads() << endl;
    
    cout << "Resuming pool..." << endl;
    pool.resume();
    cout << "Pool resumed. Active threads: " << pool.getActiveThreads() << endl;
    
    // Wait for all tasks
    cout << "Waiting for all tasks..." << endl;
    pool.waitAll();
    cout << "All tasks completed" << endl;
}

void testStressTest() {
    cout << "\n5. Stress Testing" << endl;
    cout << "=================" << endl;
    
    ThreadPool pool(4);
    vector<future<int>> results;
    
    // Create random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> sleepDist(10, 100);
    
    // Enqueue many tasks with random sleep times
    const int numTasks = 20;
    for (int i = 0; i < numTasks; ++i) {
        results.emplace_back(pool.enqueue([i, &sleepDist, &gen]() {
            this_thread::sleep_for(chrono::milliseconds(sleepDist(gen)));
            return i;
        }));
    }
    
    // Monitor pool status
    for (int i = 0; i < 5; ++i) {
        cout << "Active threads: " << pool.getActiveThreads() 
             << ", Queued tasks: " << pool.getQueuedTasks() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
    // Get all results
    for (auto& result : results) {
        result.get();
    }
    
    cout << "Stress test completed" << endl;
}

int main() {
    cout << "Thread Pool Tests" << endl;
    cout << "=================" << endl;
    
    try {
        testBasicFunctionality();
        testMultipleTasks();
        testErrorHandling();
        testPoolControl();
        testStressTest();
        
        cout << "\nAll tests completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
