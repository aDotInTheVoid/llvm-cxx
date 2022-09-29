#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("llvm-cxx/src/llvm-cxx.hh");

        type LLVMContext;
        type IRBuilder;
        type Module;

        fn new_context() -> UniquePtr<LLVMContext>;
        fn new_ir_builder(context: Pin<&mut LLVMContext>) -> UniquePtr<IRBuilder>;
        fn new_module(name: &str, context: Pin<&mut LLVMContext>) -> UniquePtr<Module>;
    }
}

fn main() {
    let mut cx = ffi::new_context();
    let irb = ffi::new_ir_builder(cx.pin_mut());
    let module = ffi::new_module("test", cx.pin_mut());
}
