#include "llvm-cxx/src/llvm-cxx.hh"

#include "llvm/ADT/StringRef.h"

unique_ptr<LLVMContext> new_context() {
    return std::make_unique<LLVMContext>();
}

unique_ptr<Module> new_module(rust::Str name, LLVMContext &context) {
    return std::make_unique<Module>(llvm::StringRef(name.data(), name.size()),
                                    context);
}

unique_ptr<IRBuilder> new_ir_builder(LLVMContext &context) {
    return std::make_unique<IRBuilder>(context);
}
