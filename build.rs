fn main() {
    cxx_build::bridge("src/main.rs")
        .file("src/llvm-cxx.cc")
        .include("/usr/include/llvm-14/")
        .include("/usr/include/llvm-c-14/")
        .warnings(false)
        // .object("/usr/lib/llvm-14/lib/libLLVM-14.so")
        .compile("llvm-cxx");

    println!("cargo:libdir={}", "/usr/lib/llvm-14/lib/");
    println!("cargo:rustc-link-lib=LLVM-14");
}
