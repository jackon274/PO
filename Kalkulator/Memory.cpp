#include "Memory.h"

Memory::Memory() {
    memory = 0;
}

void Memory::clearMemory() {
    memory = 0;
}

double Memory::readMemory() const{
    return memory;
}

