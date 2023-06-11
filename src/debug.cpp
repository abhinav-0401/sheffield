#include <iostream>
#include <cstdint>
#include <cstddef>
#include <string>
#include "include/debug.hpp"
#include "include/chunk.hpp"

namespace sheffield {

namespace debug {

    size_t simple_instruction(const std::string& name, const Chunk& chunk, size_t offset) {
        std::cout << static_cast<uint16_t>(chunk.instructions[offset]) << " " << name << "\n";
        return ++offset;
    }

    size_t const_instruction(const Chunk& chunk, size_t offset) {
        std::cout << static_cast<uint16_t>(chunk.instructions[offset]) << " " << "CONST ";
        uint8_t const_index = chunk.instructions[offset + 1];
        std::cout << static_cast<uint16_t>(const_index) << " " << chunk.constants[const_index] << "\n";
        return offset + 2;
    }

    size_t disassemble_bytecode(const Chunk& chunk, size_t offset) {
        switch (chunk.instructions[offset]) {
            case Opcode::ret_i:
                return simple_instruction("RET", chunk, offset);
            case Opcode::const_i:
                return const_instruction(chunk, offset);
            default:
                std::cout << "unsupported!\n";
                return ++offset;
        }
    }

    void disassemble_chunk(const Chunk& chunk, const std::string& title) {
        std::cout << "---" << title  << "---\n";
        for (size_t offset = 0; offset < chunk.instructions.size();) {
            offset = disassemble_bytecode(chunk, offset);
        }
    }

} // namespace debug

} // namespace sheffield