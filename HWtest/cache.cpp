#include "cache.h"
#include <iostream>
#include <cmath>

using namespace std;

Cache::Cache(size_t numEntries, size_t associativity) : numEntries(numEntries), associativity(associativity) {
        numSets = numEntries / associativity;
        blockOffsetBits = log2(numSets);
        cacheLines.resize(numEntries);
    }

bool Cache::access(uint32_t address) {
    uint32_t index = (address >> blockOffsetBits) & (numSets - 1); // get the set index
    uint32_t tag = address >> (blockOffsetBits + (uint32_t)log2(numSets)); // get the tag

    // Check for a hit in the corresponding set
    for (int i = 0; i < associativity; i++) {
        int lineIndex = index * associativity + i;
        if (cacheLines[lineIndex].valid && cacheLines[lineIndex].tag == tag) {
            return true; // HIT
        }
    }
    
    // If it's a MISS, we would need to update the cache line here (not implemented)
    updateCacheLine(address); // Update the cache line on a miss using FIFO replacement policy

    return false; // MISS

}

void Cache::updateCacheLine(uint32_t address) {
    uint32_t index = (address >> blockOffsetBits) & (numSets - 1); // get the set index
    uint32_t tag = address >> (blockOffsetBits + (uint32_t)log2(numSets)); // get the tag

    // Find the first invalid line or use FIFO replacement policy to update the cache line
    for (int i = 0; i < associativity; i++) {
        int lineIndex = index * associativity + i;
        if (!cacheLines[lineIndex].valid) {
            cacheLines[lineIndex].valid = true;
            cacheLines[lineIndex].tag = tag;
            return;
        }
    }

    // If all lines are valid, we can implement FIFO replacement policy here (not implemented)
    // Implement FIFO replacement policy to update the cache line
    int lineIndex = index * associativity; // Start with the first line in the set
    cacheLines[lineIndex].valid = true;
    cacheLines[lineIndex].tag = tag;

    // Shift the lines in the set to implement FIFO
    for (int i = 1; i < associativity; i++) {
        int nextLineIndex = index * associativity + i;
        cacheLines[nextLineIndex - 1] = cacheLines[nextLineIndex];
    }

}

