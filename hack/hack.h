#ifndef HACK_H_
#define HACK_H_

#include <iostream>

const char NOP_SYMB = 0x90;
const size_t PLACE_IN_FILE_TO_WRITE = 0x25D - 0x100; 
const size_t SYMBS_TO_WRITE_COUNT   = 15;

void Hack(const char* prog_name);

#endif // #define HACK_H_