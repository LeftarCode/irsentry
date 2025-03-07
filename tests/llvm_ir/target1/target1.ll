
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@global_var = global i32 0, align 4

define i1 @atomicCompareAndSwap(i32 %expected, i32 %newValue) {
entry:
    %result = cmpxchg weak i32* @global_var, i32 %expected, i32 %newValue monotonic monotonic
    %success = extractvalue { i32, i1 } %result, 1
    ret i1 %success
}
