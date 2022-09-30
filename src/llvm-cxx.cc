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

unique_ptr<Value> new_float(double value, LLVMContext &context) {
    return std::make_unique<Value>(
        llvm::ConstantFP::get(context, llvm::APFloat(value)));
}

unique_ptr<Value> create_f_add(IRBuilder &builder, Value &lhs, Value &rhs) {
    return std::make_unique<Value>(
        builder.builder_.CreateFAdd(lhs.value_, rhs.value_));
}
unique_ptr<Value> create_f_sub(IRBuilder &builder, Value &lhs, Value &rhs) {
    return std::make_unique<Value>(
        builder.builder_.CreateFSub(lhs.value_, rhs.value_));
}