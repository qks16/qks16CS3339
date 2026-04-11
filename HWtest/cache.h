#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include <cstdint>
#include <cstddef>

//cache data structure
class Cache {
public:
    //constructor to initialize cache parameters and data structures
    Cache(size_t numEntries, size_t associativity) : numEntries(numEntries), associativity(associativity) {
        numSets = numEntries / associativity;
        blockOffsetBits = log2(numSets);
        cacheLines.resize(numEntries);
    }

    //function to access the cache with a given memory address and return whether it's a hit or miss
    bool access(uint32_t address);

    //function to update the cache line on a miss using FIFO replacement policy
    void updateCacheLine(uint32_t address);


private:
    struct CacheLine {
        bool valid = false;
        uint32_t tag = 0;
    };
    size_t numEntries;
    size_t numSets;
    size_t blockOffsetBits;
    size_t associativity;
    std::vector<CacheLine> cacheLines;
    
};

#endif