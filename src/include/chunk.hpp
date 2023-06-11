#pragma once

#include <vector>
#include <cstdint>
#include "value.hpp"

namespace sheffield {

enum Opcode: uint8_t {
    const_i = 0,
    ret_i,
};

class Chunk {
public:
    std::vector<uint8_t> instructions;
    std::vector<Value> constants;

    Chunk();
    void write(uint8_t byte);
    uint8_t add_constant(Value value);
};

} // namespace sheffield 