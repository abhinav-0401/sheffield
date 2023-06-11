#include <iostream>
#include <cstdint>
#include <cstddef>
#include "include/chunk.hpp"

namespace sheffield {

Chunk::Chunk() {
    std::cout << "A chunk was constructed\n";
}

void Chunk::write(uint8_t bytecode) {
    this->instructions.push_back(bytecode);
}

uint8_t Chunk::add_constant(Value value) {
    this->constants.push_back(value);
    return static_cast<uint8_t>(this->constants.size() - 1);
}

} // namespace sheffield