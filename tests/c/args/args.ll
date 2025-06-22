; ModuleID = '.\args.c'
source_filename = ".\\args.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.43.34809"

$"??_C@_0P@FKKJLIOJ@SecretPassword?$AA@" = comdat any

@"??_C@_0P@FKKJLIOJ@SecretPassword?$AA@" = linkonce_odr dso_local unnamed_addr constant [15 x i8] c"SecretPassword\00", comdat, align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @IRSENTRY_MOCK_NOPARAMS() #0 {
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca [64 x i8], align 16
  store i32 5, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  store i32 %0, ptr %5, align 4
  %7 = load ptr, ptr %4, align 8
  %8 = getelementptr inbounds ptr, ptr %7, i64 1
  %9 = load ptr, ptr %8, align 8
  %10 = call i32 @strcmp(ptr noundef %9, ptr noundef @"??_C@_0P@FKKJLIOJ@SecretPassword?$AA@") #2
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %13

12:                                               ; preds = %2
  call void @IRSENTRY_MOCK_NOPARAMS()
  br label %13

13:                                               ; preds = %12, %2
  ret i32 0
}

; Function Attrs: nounwind
declare dso_local i32 @strcmp(ptr noundef, ptr noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"clang version 20.1.0"}
