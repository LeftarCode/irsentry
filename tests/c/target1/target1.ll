; ModuleID = 'target1.c'
source_filename = "target1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.A = type { i32, i32, i8*, float, double }

@.str = private unnamed_addr constant [28 x i8] c"Dangerous function called!\0A\00", align 1
@.str.1 = private unnamed_addr constant [13 x i8] c"(x | y) != 0\00", align 1
@.str.2 = private unnamed_addr constant [10 x i8] c"target1.c\00", align 1
@__PRETTY_FUNCTION__.testBitwiseOperations = private unnamed_addr constant [51 x i8] c"int testBitwiseOperations(int, int, float, double)\00", align 1
@.str.3 = private unnamed_addr constant [13 x i8] c"Result = %d\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @dangerousFunction() #0 {
  %1 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([28 x i8], [28 x i8]* @.str, i64 0, i64 0))
  ret void
}

declare i32 @printf(i8* noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @testBitwiseOperations(i32 noundef %0, i32 noundef %1, float noundef %2, double noundef %3) #0 {
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca float, align 4
  %8 = alloca double, align 8
  store i32 %0, i32* %5, align 4
  store i32 %1, i32* %6, align 4
  store float %2, float* %7, align 4
  store double %3, double* %8, align 8
  %9 = load i32, i32* %5, align 4
  %10 = and i32 %9, 31
  %11 = icmp eq i32 %10, 31
  br i1 %11, label %12, label %18

12:                                               ; preds = %4
  %13 = load i32, i32* %6, align 4
  %14 = ashr i32 %13, 4
  %15 = and i32 %14, 1
  %16 = icmp eq i32 %15, 1
  br i1 %16, label %17, label %18

17:                                               ; preds = %12
  call void @dangerousFunction()
  br label %26

18:                                               ; preds = %12, %4
  %19 = load i32, i32* %5, align 4
  %20 = load i32, i32* %6, align 4
  %21 = or i32 %19, %20
  %22 = icmp ne i32 %21, 0
  br i1 %22, label %23, label %24

23:                                               ; preds = %18
  br label %25

24:                                               ; preds = %18
  call void @__assert_fail(i8* noundef getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i64 0, i64 0), i8* noundef getelementptr inbounds ([10 x i8], [10 x i8]* @.str.2, i64 0, i64 0), i32 noundef 17, i8* noundef getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.testBitwiseOperations, i64 0, i64 0)) #3
  unreachable

25:                                               ; preds = %23
  br label %26

26:                                               ; preds = %25, %17
  %27 = load i32, i32* %5, align 4
  %28 = load i32, i32* %6, align 4
  %29 = xor i32 %27, %28
  ret i32 %29
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8* noundef, i8* noundef, i32 noundef, i8* noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca %struct.A, align 8
  %3 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %4 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 0
  store i32 31, i32* %4, align 8
  %5 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 1
  store i32 16, i32* %5, align 4
  %6 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 0
  %7 = load i32, i32* %6, align 8
  %8 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 1
  %9 = load i32, i32* %8, align 4
  %10 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 3
  %11 = load float, float* %10, align 8
  %12 = getelementptr inbounds %struct.A, %struct.A* %2, i32 0, i32 4
  %13 = load double, double* %12, align 8
  %14 = call i32 @testBitwiseOperations(i32 noundef %7, i32 noundef %9, float noundef %11, double noundef %13)
  store i32 %14, i32* %3, align 4
  %15 = load i32, i32* %3, align 4
  %16 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([13 x i8], [13 x i8]* @.str.3, i64 0, i64 0), i32 noundef %15)
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { noreturn nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noreturn nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
