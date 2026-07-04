#ifndef CACHE_SIMULATOR_HPP
#define CACHE_SIMULATOR_HPP

#include <vector>

class CacheSimulator {
private:
    int cacheSize;                 // Total capacity of our cache table
    std::vector<int> cacheBlocks;  // The actual storage slots inside the cache

public:
    // Constructor to set up the cache size
    CacheSimulator(int size);

    // Function to simulate CPU requesting a specific memory address
    void accessAddress(int address);
};

#endif // CACHE_SIMULATOR_HPP
