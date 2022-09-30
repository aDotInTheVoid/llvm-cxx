#include "llvm-cxx/src/llvm-cxx.hh"
#include "llvm-cxx/src/main.rs.h"

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

ValuePtr new_float(double value, LLVMContext &context) {
    Value *v = llvm::ConstantFP::get(context, llvm::APFloat(value));
    return ValuePtr{v};
}

ValuePtr create_f_add(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs) {
    Value *v = builder.builder_.CreateFAdd(lhs.value, rhs.value);
    return ValuePtr{v};
}

ValuePtr create_f_sub(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs) {
    Value *v = builder.builder_.CreateFSub(lhs.value, rhs.value);
    return ValuePtr{v};
}
ValuePtr create_f_div(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs) {
    Value *v = builder.builder_.CreateFDiv(lhs.value, rhs.value);
    return ValuePtr{v};
}
ValuePtr create_f_mul(IRBuilder &builder, ValuePtr lhs, ValuePtr rhs) {
    Value *v = builder.builder_.CreateFMul(lhs.value, rhs.value);
    return ValuePtr{v};
}
