#include <iostream>
#include "pool_allocator.hpp"
#include "rtos_scheduler.hpp"

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "        AETHEREDGE-OS INITIALIZATION MODULE       " << std::endl;
    std::cout << "==================================================" << std::endl;

    // 1. Initialize Memory Infrastructure
    // Creating a pool with 64 bytes per block and 5 total blocks
    PoolAllocator systemMemoryPool(64, 5);
    std::cout << "[OK] Static Block Memory Pool initialized safely." << std::endl;

    // 2. Initialize Real-Time Runtime Environment
    TaskScheduler osScheduler;
    std::cout << "[OK] Real-Time Task Scheduler initialized safely." << std::endl;

    // 3. Allocate memory buffer from our pool for safe telemetry tracking
    void* telemetryBuffer = systemMemoryPool.allocate();
    if (telemetryBuffer != nullptr) {
        std::cout << "[OK] Telemetry runtime buffer allocated from static pool." << std::endl;
    }

    // 4. Start the execution loop for 6 simulation cycles
    osScheduler.startLoop(6);

    // 5. Clean up and return memory to pool after execution completes
    systemMemoryPool.deallocate(telemetryBuffer);
    std::cout << "[OK] Telemetry runtime buffer returned to static pool." << std::endl;

    std::cout << "==================================================" << std::endl;
    std::cout << "       SYSTEM SHUTDOWN CLEANUP COMPLETED          " << std::endl;
    std::cout << "==================================================" << std::endl;

    return 0;
}
