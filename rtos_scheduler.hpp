#ifndef RTOS_SCHEDULER_HPP
#define RTOS_SCHEDULER_HPP

class TaskScheduler {
public:
    // Function to simulate reading autonomous navigation sensor data
    void runNavigationTask();

    // Function to simulate background system health diagnostics
    void runDiagnosticTask();

    // The main execution loop that manages task intervals
    void startLoop(int totalCycles);
};

#endif // RTOS_SCHEDULER_HPP
