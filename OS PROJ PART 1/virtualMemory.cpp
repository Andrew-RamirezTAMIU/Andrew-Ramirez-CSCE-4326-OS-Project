#include "VirtualMemory.h"
#include <iostream>

using namespace std;

int translateAddress(int virtualAddress, const vector<PageTableEntry>& pageTable) {
    int virtualPage = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    if (virtualPage >= pageTable.size()) {
        cout << "Invalid virtual address.\n";
        return -1;
    }

    const PageTableEntry& entry = pageTable[virtualPage];
    if (!entry.valid) {
        cout << "Page fault! Page " << virtualPage << " not in memory.\n";
        return -1;
    }

    int physicalAddress = entry.frameNumber * PAGE_SIZE + offset;
    return physicalAddress;
}

int allocateFreeFrame(vector<bool>& frameTable) {
    for (int i = 0; i < frameTable.size(); i++) {
        if (!frameTable[i]) {
            frameTable[i] = true;
            return i;
        }
    }
    return -1; // No free frame 
}
