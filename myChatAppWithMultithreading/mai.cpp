#include <iostream>
#include <thread>
#include <mutex>
#include "header.h"

std::mutex mtx; // Mutex for critical section

int executeWriter() {
    std::lock_guard<std::mutex> lock(mtx); // Ensures mutual exclusion

    return writer();
    
}

int executeReader() {
   
    std::lock_guard<std::mutex> lock(mtx);
    return reader();
}

int main() {
    std::thread t1(executeWriter);
    std::thread t2(executeReader);

    t1.join();
    t2.join();

    return 0;
}
