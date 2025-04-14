#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H
#include <iostream>
#include <vector>
// 4KB pages
// 64KB virtual memory
// 0.5 mb physical memory
const int PAGE_SIZE = 4096;             
const int VIRTUAL_MEM_SIZE = 65536;        
const int PHYSICAL_MEM_SIZE = 512000;       
const int VIRTUAL_PAGES = VIRTUAL_MEM_SIZE / PAGE_SIZE;
const int PHYSICAL_FRAMES = PHYSICAL_MEM_SIZE / PAGE_SIZE;

using namespace std;

struct PageTableEntry {
    bool valid;
    bool dirty;
    int frameNumber;
};

// Core 
int translateAddress(int virtualAddress, const vector<PageTableEntry>& pageTable);
int allocateFreeFrame(vector<bool>& frameTable);

#endif
