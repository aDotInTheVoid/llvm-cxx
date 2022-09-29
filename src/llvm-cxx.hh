#pragma once

#include <memory>

#include "llvm/ADT/APFloat.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"

#include "rust/cxx.h"

using llvm::LLVMContext;
using llvm::Module;
using std::unique_ptr;

class IRBuilder {
  public:
    llvm::IRBuilder<> builder_;
    IRBuilder(LLVMContext &C) : builder_(C) {}
};

unique_ptr<LLVMContext> new_context();
unique_ptr<IRBuilder> new_ir_builder(LLVMContext &context);
unique_ptr<Module> new_module(rust::Str name, LLVMContext &context);