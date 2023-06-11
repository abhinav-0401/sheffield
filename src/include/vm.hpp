#pragma once

#include "chunk.hpp"

namespace sheffield {

enum InterpretResult {
    okay = 0,
    compile_err,
    runtime_err,
};

class VM {
  public:
    Chunk* chunk;
    
    VM();
    InterpretResult interpret();
};

} // namespace sheffield
