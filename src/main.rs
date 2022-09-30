#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("llvm-cxx/src/llvm-cxx.hh");

        type LLVMContext;
        type IRBuilder;
        type Module;
        type Value;

        fn new_context() -> UniquePtr<LLVMContext>;
        fn new_ir_builder(context: Pin<&mut LLVMContext>) -> UniquePtr<IRBuilder>;
        fn new_module(name: &str, context: Pin<&mut LLVMContext>) -> UniquePtr<Module>;
        fn new_float(value: f64, context: Pin<&mut LLVMContext>) -> UniquePtr<Value>;
        fn create_f_add(
            builder: Pin<&mut IRBuilder>,
            lhs: Pin<&mut Value>,
            rhs: Pin<&mut Value>,
        ) -> UniquePtr<Value>;
        fn create_f_sub(
            builder: Pin<&mut IRBuilder>,
            lhs: Pin<&mut Value>,
            rhs: Pin<&mut Value>,
        ) -> UniquePtr<Value>;
    }
}

fn main() {
    let mut cx = ffi::new_context();
    let mut irb = ffi::new_ir_builder(cx.pin_mut());
    let module = ffi::new_module("test", cx.pin_mut());

    let mut f0 = ffi::new_float(1.0, cx.pin_mut());
    let mut f1 = ffi::new_float(2.0, cx.pin_mut());
    let f3 = ffi::create_f_add(irb.pin_mut(), f0.pin_mut(), f1.pin_mut());
}
