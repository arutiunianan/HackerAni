#include "hack.h"

void Hack(const char* prog_name)
{
    FILE* prog_file = fopen(prog_name, "r+");

    fseek(prog_file, PLACE_IN_FILE_TO_WRITE, SEEK_SET);

    for(size_t i = 0; i < SYMBS_TO_WRITE_COUNT; i++)
    {
        fputc(NOP_SYMB, prog_file);
    }
    fclose(prog_file);
}