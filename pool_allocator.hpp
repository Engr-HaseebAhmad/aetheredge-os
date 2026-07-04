#ifndef POOL_ALLOCATOR_HPP
#define POOL_ALLOCATOR_HPP

#include <cstddef>

class PoolAllocator {
private:
    size_t blockSize;       // Har memory block ka size (e.g., 32 bytes)
    size_t totalBlocks;     // Total kitne blocks chahiye
    char* memoryPool;       // Poore reserved memory block ka pointer
    bool* blockStatus;      // Yeh track karne ke liye ke kaunsa block use ho rha hai aur kaunsa free

public:
    // Constructor: Jab allocator banega, to memory reserve karega
    PoolAllocator(size_t block_size, size_t total_blocks);

    // Allocate function: Yeh pool ke andar se free block ka rasta (pointer) dega
    void* allocate();

    // Deallocate function: Kaam khatam hone par block ko free karega
    void deallocate(void* ptr);

    // Destructor: Jab kaam khatam ho jaye to poori memory saaf kar dega
    ~PoolAllocator();
};

#endif // POOL_ALLOCATOR_HPP
