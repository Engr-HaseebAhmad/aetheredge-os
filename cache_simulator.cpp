#include <iostream>
#include <algorithm>
#include "cache_simulator.hpp"

// Sets up the cache size and fills it with empty values (-1 means empty)
CacheSimulator::CacheSimulator(int size) {
    cacheSize = size;
    cacheBlocks.resize(cacheSize, -1); 
}

// Simulates CPU reading a memory address
void CacheSimulator::accessAddress(int address) {
    std::cout << "[CPU Request] Accessing Address: " << address << " -> ";

    // Check if the address is already present in our cache table
    auto it = std::find(cacheBlocks.begin(), cacheBlocks.end(), address);

    if (it != cacheBlocks.end()) {
        // Data found! This is a Cache Hit (Fast execution)
        std::cout << "CACHE HIT! (Data loaded instantly from table)" << std::endl;
    } else {
        // Data not found! This is a Cache Miss (Slow execution)
        std::cout << "CACHE MISS! (Going to library/RAM to fetch data)" << std::endl;

        // Bring the new data into the cache (Simulating Least Recently Used replacement)
        cacheBlocks.erase(cacheBlocks.begin()); // Remove the oldest data from the table
        cacheBlocks.push_back(address);        // Add the new data to the table
    }
}
