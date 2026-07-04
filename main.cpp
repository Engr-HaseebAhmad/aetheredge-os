#include <iostream>
#include "pool_allocator.hpp"
#include "rtos_scheduler.hpp"
#include "cache_simulator.hpp"

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "        AETHEREDGE-OS INITIALIZATION MODULE       " << std::endl;
    std::cout << "==================================================" << std::endl;

    // 1. Initialize Memory Infrastructure
    PoolAllocator systemMemoryPool(64, 5);
    std::cout << "[OK] Static Block Memory Pool initialized safely." << std::endl;

    // 2. Initialize Real-Time Runtime Environment
    TaskScheduler osScheduler;
    std::cout << "[OK] Real-Time Task Scheduler initialized safely." << std::endl;

    // 3. Initialize Hardware Cache Simulator (Size = 3 blocks)
    CacheSimulator cpuCache(3);
    std::cout << "[OK] L1 Cache Simulator initialized safely." << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    // 4. Simulate CPU memory accesses to test Cache Hits and Misses
    std::cout << "--- Starting Hardware Cache Simulation Test ---" << std::endl;
    cpuCache.accessAddress(10); // Miss (Cache empty)
    cpuCache.accessAddress(20); // Miss (Cache empty)
    cpuCache.accessAddress(10); // Hit! (Address 10 is already in cache)
    cpuCache.accessAddress(30); // Miss
    cpuCache.accessAddress(20); // Hit! (Address 20 is already in cache)
    cpuCache.accessAddress(40); // Miss (Cache full, replaces oldest address)
    
    std::cout << "--------------------------------------------------" << std::endl;

    // 5. Run the RTOS Task Scheduler Loop
    osScheduler.startLoop(4);

    std::cout << "==================================================" << std::endl;
    std::cout << "       SYSTEM SHUTDOWN CLEANUP COMPLETED          " << std::endl;
    std::cout << "==================================================" << std::endl;

    return 0;
}
