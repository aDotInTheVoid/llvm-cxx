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
using llvm::Value;
using std::unique_ptr;

struct ValuePtr;

class IRBuilder : public llvm::IRBuilder<> {
  public:
    IRBuilder(LLVMContext &context) : llvm::IRBuilder<>(context) {}
};

unique_ptr<LLVMContext> new_context();
unique_ptr<IRBuilder> new_ir_builder(LLVMContext &context);
unique_ptr<Module> new_module(rust::Str name, LLVMContext &context);
ValuePtr new_float(double value, LLVMContext &context);
ValuePtr create_f_add(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs);
ValuePtr create_f_sub(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs);
ValuePtr create_f_div(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs);
ValuePtr create_f_mul(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs);

// unique_ptr<Value> create_f_sub(IRBuilder &builder, Value &lhs, Value &rhs);
