; ModuleID = 'target2.c'
source_filename = "target2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @complicatedFunction(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store i32 %0, i32* %5, align 4
  store i32 %1, i32* %6, align 4
  store i32 %2, i32* %7, align 4
  %9 = load i32, i32* %5, align 4
  %10 = sdiv i32 %9, 10
  %11 = load i32, i32* %6, align 4
  %12 = sdiv i32 %11, 10
  %13 = add nsw i32 %10, %12
  %14 = load i32, i32* %7, align 4
  %15 = sdiv i32 %14, 10
  %16 = sub nsw i32 %13, %15
  store i32 %16, i32* %8, align 4
  %17 = load i32, i32* %5, align 4
  %18 = icmp sgt i32 %17, 100
  br i1 %18, label %19, label %33

19:                                               ; preds = %3
  %20 = load i32, i32* %6, align 4
  %21 = icmp slt i32 %20, 1000000
  br i1 %21, label %22, label %33

22:                                               ; preds = %19
  %23 = load i32, i32* %7, align 4
  %24 = srem i32 %23, 2
  %25 = icmp eq i32 %24, 0
  br i1 %25, label %26, label %29

26:                                               ; preds = %22
  %27 = load i32, i32* %8, align 4
  %28 = add nsw i32 %27, 1
  store i32 %28, i32* %8, align 4
  br label %32

29:                                               ; preds = %22
  %30 = load i32, i32* %8, align 4
  %31 = sub nsw i32 %30, 1
  store i32 %31, i32* %8, align 4
  br label %32

32:                                               ; preds = %29, %26
  br label %39

33:                                               ; preds = %19, %3
  %34 = load i32, i32* %5, align 4
  %35 = load i32, i32* %6, align 4
  %36 = sub nsw i32 %34, %35
  %37 = load i32, i32* %7, align 4
  %38 = add nsw i32 %36, %37
  store i32 %38, i32* %8, align 4
  br label %39

39:                                               ; preds = %33, %32
  %40 = load i32, i32* %8, align 4
  %41 = icmp sgt i32 %40, 1000
  br i1 %41, label %42, label %43

42:                                               ; preds = %39
  store i32 2, i32* %4, align 4
  br label %48

43:                                               ; preds = %39
  %44 = load i32, i32* %8, align 4
  %45 = icmp slt i32 %44, -1000
  br i1 %45, label %46, label %47

46:                                               ; preds = %43
  store i32 -2, i32* %4, align 4
  br label %48

47:                                               ; preds = %43
  store i32 0, i32* %4, align 4
  br label %48

48:                                               ; preds = %47, %46, %42
  %49 = load i32, i32* %4, align 4
  ret i32 %49
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @checkLimits(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  %6 = load i32, i32* %4, align 4
  %7 = icmp slt i32 %6, 0
  br i1 %7, label %8, label %9

8:                                                ; preds = %2
  store i32 -1, i32* %3, align 4
  br label %23

9:                                                ; preds = %2
  %10 = load i32, i32* %5, align 4
  %11 = load i32, i32* %4, align 4
  %12 = icmp slt i32 %10, %11
  br i1 %12, label %13, label %14

13:                                               ; preds = %9
  store i32 -2, i32* %3, align 4
  br label %23

14:                                               ; preds = %9
  %15 = load i32, i32* %4, align 4
  %16 = load i32, i32* %5, align 4
  %17 = add nsw i32 %15, %16
  %18 = icmp sgt i32 %17, 300000000
  br i1 %18, label %19, label %20

19:                                               ; preds = %14
  store i32 99, i32* %3, align 4
  br label %23

20:                                               ; preds = %14
  br label %21

21:                                               ; preds = %20
  br label %22

22:                                               ; preds = %21
  store i32 1, i32* %3, align 4
  br label %23

23:                                               ; preds = %22, %19, %13, %8
  %24 = load i32, i32* %3, align 4
  ret i32 %24
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i64, align 8
  %8 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 1000000000, i32* %2, align 4
  store i32 2000000000, i32* %3, align 4
  store i32 314159265, i32* %4, align 4
  store i32 -1, i32* %5, align 4
  store i32 0, i32* %6, align 4
  %9 = load i32, i32* %2, align 4
  %10 = icmp sgt i32 %9, 0
  br i1 %10, label %11, label %57

11:                                               ; preds = %0
  %12 = load i32, i32* %3, align 4
  %13 = load i32, i32* %2, align 4
  %14 = icmp sgt i32 %12, %13
  br i1 %14, label %15, label %57

15:                                               ; preds = %11
  %16 = load i32, i32* %3, align 4
  %17 = load i32, i32* %2, align 4
  %18 = sub nsw i32 %16, %17
  %19 = icmp eq i32 %18, 1000000000
  br i1 %19, label %20, label %57

20:                                               ; preds = %15
  %21 = load i32, i32* %4, align 4
  %22 = srem i32 %21, 10
  %23 = icmp eq i32 %22, 5
  br i1 %23, label %24, label %57

24:                                               ; preds = %20
  %25 = load i32, i32* %5, align 4
  %26 = icmp slt i32 %25, 0
  br i1 %26, label %30, label %27

27:                                               ; preds = %24
  %28 = load i32, i32* %6, align 4
  %29 = icmp eq i32 %28, 0
  br i1 %29, label %30, label %57

30:                                               ; preds = %27, %24
  %31 = load i32, i32* %2, align 4
  %32 = load i32, i32* %3, align 4
  %33 = load i32, i32* %4, align 4
  %34 = call i32 @complicatedFunction(i32 noundef %31, i32 noundef %32, i32 noundef %33)
  %35 = icmp eq i32 %34, 2
  br i1 %35, label %36, label %57

36:                                               ; preds = %30
  %37 = load i32, i32* %2, align 4
  %38 = load i32, i32* %3, align 4
  %39 = call i32 @checkLimits(i32 noundef %37, i32 noundef %38)
  %40 = icmp eq i32 %39, 99
  br i1 %40, label %41, label %57

41:                                               ; preds = %36
  %42 = load i32, i32* %2, align 4
  %43 = sext i32 %42 to i64
  %44 = load i32, i32* %3, align 4
  %45 = sext i32 %44 to i64
  %46 = mul nsw i64 %43, %45
  store i64 %46, i64* %7, align 8
  %47 = load i64, i64* %7, align 8
  %48 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i64 0, i64 0), i64 noundef %47)
  %49 = load i64, i64* %7, align 8
  %50 = icmp slt i64 %49, 0
  br i1 %50, label %51, label %56

51:                                               ; preds = %41
  %52 = load i32, i32* %5, align 4
  %53 = load i32, i32* %6, align 4
  %54 = sub nsw i32 %52, %53
  %55 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %54)
  br label %56

56:                                               ; preds = %51, %41
  br label %84

57:                                               ; preds = %36, %30, %27, %20, %15, %11, %0
  %58 = load i32, i32* %2, align 4
  %59 = load i32, i32* %3, align 4
  %60 = add nsw i32 %58, %59
  %61 = load i32, i32* %4, align 4
  %62 = add nsw i32 %60, %61
  %63 = load i32, i32* %5, align 4
  %64 = add nsw i32 %62, %63
  %65 = load i32, i32* %6, align 4
  %66 = add nsw i32 %64, %65
  %67 = sdiv i32 %66, 2
  store i32 %67, i32* %8, align 4
  %68 = load i32, i32* %8, align 4
  %69 = icmp sgt i32 %68, 0
  br i1 %69, label %70, label %81

70:                                               ; preds = %57
  %71 = load i32, i32* %8, align 4
  %72 = srem i32 %71, 2
  %73 = icmp eq i32 %72, 0
  br i1 %73, label %74, label %77

74:                                               ; preds = %70
  %75 = load i32, i32* %8, align 4
  %76 = sub nsw i32 0, %75
  store i32 %76, i32* %8, align 4
  br label %80

77:                                               ; preds = %70
  %78 = load i32, i32* %8, align 4
  %79 = add nsw i32 %78, 5
  store i32 %79, i32* %8, align 4
  br label %80

80:                                               ; preds = %77, %74
  br label %81

81:                                               ; preds = %80, %57
  %82 = load i32, i32* %8, align 4
  %83 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %82)
  br label %84

84:                                               ; preds = %81, %56
  ret i32 0
}

declare i32 @printf(i8* noundef, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
