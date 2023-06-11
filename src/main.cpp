#include <iostream>
#include <cstdint>
#include <string>
#include "include/chunk.hpp"
#include "include/debug.hpp"

int main() {
    sheffield::Chunk newChunk;
    newChunk.write(sheffield::Opcode::ret_i);
    newChunk.write(sheffield::Opcode::ret_i);
    newChunk.write(sheffield::Opcode::const_i);
    uint8_t const_index = newChunk.add_constant(1.2);
    newChunk.write(const_index);
    sheffield::debug::disassemble_chunk(newChunk, "test chunk");
}