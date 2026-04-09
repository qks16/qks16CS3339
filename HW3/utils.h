#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cstdint>

//cache data structure
class Cache {
public:
    //constructor to initialize cache parameters and data structures
    Cache(size_t numEntries, size_t associativity);

    //function to access the cache with a given memory address and return whether it's a hit or miss
    bool access(uint32_t address);

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