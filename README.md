# AetherEdge-OS

This is a high-performance, real-time embedded framework written in modern C++.

## What I built so far:
1. **Custom Memory Pool Allocator**: A fast memory manager that prevents system crashes by recycling fixed-size memory blocks without using slow dynamic allocations.
2. **Real-Time Task Scheduler**: A deterministic scheduling system that runs high-priority navigation tasks every cycle and low-priority diagnostic tasks every third cycle.

## Files in this repository:
* `pool_allocator.hpp` & `.cpp`: The architecture and logic of the memory manager.
* `rtos_scheduler.hpp` & `.cpp`: The structure and execution loop of the real-time scheduler.
* `main.cpp`: The test file to run the entire system.
