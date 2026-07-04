#include <iostream>
#include "rtos_scheduler.hpp"

// Simulates reading high-frequency navigation sensor streams
void TaskScheduler::runNavigationTask() {
    std::cout << "[TASK] Running Navigation Task: Reading multi-axis sensor array data..." << std::endl;
}

// Simulates checking system safety parameters
void TaskScheduler::runDiagnosticTask() {
    std::cout << "[SYSTEM] Running Diagnostic Task: Checking memory pool and battery status..." << std::endl;
}

// Controls the time-sliced execution of both tasks
void TaskScheduler::startLoop(int totalCycles) {
    std::cout << "--- Starting Real-Time Task Scheduler Loop ---" << std::endl;

    for (int cycle = 1; cycle <= totalCycles; cycle++) {
        std::cout << "\n--- System Execution Cycle: " << cycle << " ---" << std::endl;

        // Navigation task runs on every single cycle (High priority)
        runNavigationTask();

        // Diagnostic task runs only once every 3 cycles (Low priority)
        if (cycle % 3 == 0) {
            runDiagnosticTask();
        }
    }
    
    std::cout << "\n--- Task Scheduler Loop Finished Safely ---" << std::endl;
}
