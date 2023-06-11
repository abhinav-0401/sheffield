#pragma once

#include <iostream>
#include <cstddef>
#include "chunk.hpp"

namespace sheffield {

namespace debug {

    size_t disassemble_bytecode(const Chunk& chunk, size_t offset);
    void disassemble_chunk(const Chunk& chunk, const std::string& title);

} // namespace debug

} // namespace sheffield