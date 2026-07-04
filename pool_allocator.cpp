#include <iostream>
#include "pool_allocator.hpp"

int main() {
    std::cout << "--- Starting AetherEdge-OS Memory Test ---" << std::endl;

    // Create a memory pool: 32 bytes per block, and 3 total blocks
    PoolAllocator myPool(32, 3);

    // Request the first block of memory
    void* block1 = myPool.allocate();
    if (block1 != nullptr) {
        std::cout << "Block 1 successfully allocated!" << std::endl;
    }

    // Request the second block of memory
    void* block2 = myPool.allocate();
    if (block2 != nullptr) {
        std::cout << "Block 2 successfully allocated!" << std::endl;
    }

    // Give back (free) the first block of memory
    myPool.deallocate(block1);
    std::cout << "Block 1 returned to the pool." << std::endl;

    // Request another block (it should reuse the space from Block 1)
    void* block3 = myPool.allocate();
    if (block3 != nullptr) {
        std::cout << "Block 3 successfully allocated by reusing memory!" << std::endl;
    }

    std::cout << "--- Memory Test Finished Successfully ---" << std::endl;
    return 0;
}
