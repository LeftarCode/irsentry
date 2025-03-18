; ModuleID = 'perf2.c'
source_filename = "perf2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ListNode = type { i32, %struct.ListNode* }
%struct.BSTNode = type { i32, %struct.BSTNode*, %struct.BSTNode* }
%struct.GraphEdge = type { i32, i32, %struct.GraphEdge* }
%struct.GraphAdjList = type { %struct.GraphEdge**, i32 }
%struct.GraphMatrix = type { i32**, i32 }
%struct.ThreadData = type { i32, i32*, i32, i64 }
%union.pthread_attr_t = type { i64, [48 x i8] }
%struct.Matrix = type { i32, i32, i32** }
%struct.Variant = type { i32, %union.VariantValue }
%union.VariantValue = type { double, [56 x i8] }

@.str = private unnamed_addr constant [8 x i8] c"Lista: \00", align 1
@.str.1 = private unnamed_addr constant [7 x i8] c"%d -> \00", align 1
@.str.2 = private unnamed_addr constant [6 x i8] c"NULL\0A\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.4 = private unnamed_addr constant [33 x i8] c"Total sum (multi-thread) = %lld\0A\00", align 1
@.str.5 = private unnamed_addr constant [25 x i8] c"Czynniki pierwsze %lld: \00", align 1
@.str.6 = private unnamed_addr constant [3 x i8] c"2 \00", align 1
@.str.7 = private unnamed_addr constant [6 x i8] c"%lld \00", align 1
@.str.8 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str.9 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@.str.10 = private unnamed_addr constant [63 x i8] c"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\00", align 1
@.str.11 = private unnamed_addr constant [17 x i8] c"Variant Int: %d\0A\00", align 1
@.str.12 = private unnamed_addr constant [20 x i8] c"Variant Double: %f\0A\00", align 1
@.str.13 = private unnamed_addr constant [20 x i8] c"Variant String: %s\0A\00", align 1
@.str.14 = private unnamed_addr constant [17 x i8] c"Unknown Variant\0A\00", align 1
@.str.15 = private unnamed_addr constant [15 x i8] c"BST in-order: \00", align 1
@.str.16 = private unnamed_addr constant [39 x i8] c"Wynik mno\BFenia macierzy: C[0][0] = %d\0A\00", align 1
@.str.17 = private unnamed_addr constant [27 x i8] c"Nie mo\BFna pomno\BFy\E6 A i B.\0A\00", align 1
@.str.18 = private unnamed_addr constant [22 x i8] c"fibonacci(%d) = %lld\0A\00", align 1
@.str.19 = private unnamed_addr constant [22 x i8] c"factorial(%d) = %lld\0A\00", align 1
@.str.20 = private unnamed_addr constant [28 x i8] c"Czy %lld jest pierwsza? %s\0A\00", align 1
@.str.21 = private unnamed_addr constant [4 x i8] c"TAK\00", align 1
@.str.22 = private unnamed_addr constant [4 x i8] c"NIE\00", align 1
@.str.23 = private unnamed_addr constant [24 x i8] c"Losowy ci\B9g znak\F3w: %s\0A\00", align 1
@.str.24 = private unnamed_addr constant [12 x i8] c"Hello World\00", align 1
@.str.25 = private unnamed_addr constant [18 x i8] c"Koniec programu.\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local %struct.ListNode* @listCreateNode(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca %struct.ListNode*, align 8
  store i32 %0, i32* %2, align 4
  %4 = call noalias i8* @malloc(i64 noundef 16) #6
  %5 = bitcast i8* %4 to %struct.ListNode*
  store %struct.ListNode* %5, %struct.ListNode** %3, align 8
  %6 = load i32, i32* %2, align 4
  %7 = load %struct.ListNode*, %struct.ListNode** %3, align 8
  %8 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %7, i32 0, i32 0
  store i32 %6, i32* %8, align 8
  %9 = load %struct.ListNode*, %struct.ListNode** %3, align 8
  %10 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %9, i32 0, i32 1
  store %struct.ListNode* null, %struct.ListNode** %10, align 8
  %11 = load %struct.ListNode*, %struct.ListNode** %3, align 8
  ret %struct.ListNode* %11
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @listInsertFront(%struct.ListNode** noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.ListNode**, align 8
  %4 = alloca i32, align 4
  %5 = alloca %struct.ListNode*, align 8
  store %struct.ListNode** %0, %struct.ListNode*** %3, align 8
  store i32 %1, i32* %4, align 4
  %6 = load i32, i32* %4, align 4
  %7 = call %struct.ListNode* @listCreateNode(i32 noundef %6)
  store %struct.ListNode* %7, %struct.ListNode** %5, align 8
  %8 = load %struct.ListNode**, %struct.ListNode*** %3, align 8
  %9 = load %struct.ListNode*, %struct.ListNode** %8, align 8
  %10 = load %struct.ListNode*, %struct.ListNode** %5, align 8
  %11 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %10, i32 0, i32 1
  store %struct.ListNode* %9, %struct.ListNode** %11, align 8
  %12 = load %struct.ListNode*, %struct.ListNode** %5, align 8
  %13 = load %struct.ListNode**, %struct.ListNode*** %3, align 8
  store %struct.ListNode* %12, %struct.ListNode** %13, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @listPrint(%struct.ListNode* noundef %0) #0 {
  %2 = alloca %struct.ListNode*, align 8
  store %struct.ListNode* %0, %struct.ListNode** %2, align 8
  %3 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([8 x i8], [8 x i8]* @.str, i64 0, i64 0))
  br label %4

4:                                                ; preds = %7, %1
  %5 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  %6 = icmp ne %struct.ListNode* %5, null
  br i1 %6, label %7, label %15

7:                                                ; preds = %4
  %8 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  %9 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %8, i32 0, i32 0
  %10 = load i32, i32* %9, align 8
  %11 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str.1, i64 0, i64 0), i32 noundef %10)
  %12 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  %13 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %12, i32 0, i32 1
  %14 = load %struct.ListNode*, %struct.ListNode** %13, align 8
  store %struct.ListNode* %14, %struct.ListNode** %2, align 8
  br label %4, !llvm.loop !6

15:                                               ; preds = %4
  %16 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i64 0, i64 0))
  ret void
}

declare i32 @printf(i8* noundef, ...) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @listFree(%struct.ListNode* noundef %0) #0 {
  %2 = alloca %struct.ListNode*, align 8
  %3 = alloca %struct.ListNode*, align 8
  store %struct.ListNode* %0, %struct.ListNode** %2, align 8
  br label %4

4:                                                ; preds = %7, %1
  %5 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  %6 = icmp ne %struct.ListNode* %5, null
  br i1 %6, label %7, label %14

7:                                                ; preds = %4
  %8 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  store %struct.ListNode* %8, %struct.ListNode** %3, align 8
  %9 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  %10 = getelementptr inbounds %struct.ListNode, %struct.ListNode* %9, i32 0, i32 1
  %11 = load %struct.ListNode*, %struct.ListNode** %10, align 8
  store %struct.ListNode* %11, %struct.ListNode** %2, align 8
  %12 = load %struct.ListNode*, %struct.ListNode** %3, align 8
  %13 = bitcast %struct.ListNode* %12 to i8*
  call void @free(i8* noundef %13) #6
  br label %4, !llvm.loop !8

14:                                               ; preds = %4
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local %struct.BSTNode* @bstInsert(%struct.BSTNode* noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.BSTNode*, align 8
  %4 = alloca %struct.BSTNode*, align 8
  %5 = alloca i32, align 4
  %6 = alloca %struct.BSTNode*, align 8
  store %struct.BSTNode* %0, %struct.BSTNode** %4, align 8
  store i32 %1, i32* %5, align 4
  %7 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %8 = icmp eq %struct.BSTNode* %7, null
  br i1 %8, label %9, label %20

9:                                                ; preds = %2
  %10 = call noalias i8* @malloc(i64 noundef 24) #6
  %11 = bitcast i8* %10 to %struct.BSTNode*
  store %struct.BSTNode* %11, %struct.BSTNode** %6, align 8
  %12 = load i32, i32* %5, align 4
  %13 = load %struct.BSTNode*, %struct.BSTNode** %6, align 8
  %14 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %13, i32 0, i32 0
  store i32 %12, i32* %14, align 8
  %15 = load %struct.BSTNode*, %struct.BSTNode** %6, align 8
  %16 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %15, i32 0, i32 2
  store %struct.BSTNode* null, %struct.BSTNode** %16, align 8
  %17 = load %struct.BSTNode*, %struct.BSTNode** %6, align 8
  %18 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %17, i32 0, i32 1
  store %struct.BSTNode* null, %struct.BSTNode** %18, align 8
  %19 = load %struct.BSTNode*, %struct.BSTNode** %6, align 8
  store %struct.BSTNode* %19, %struct.BSTNode** %3, align 8
  br label %51

20:                                               ; preds = %2
  %21 = load i32, i32* %5, align 4
  %22 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %23 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %22, i32 0, i32 0
  %24 = load i32, i32* %23, align 8
  %25 = icmp slt i32 %21, %24
  br i1 %25, label %26, label %34

26:                                               ; preds = %20
  %27 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %28 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %27, i32 0, i32 1
  %29 = load %struct.BSTNode*, %struct.BSTNode** %28, align 8
  %30 = load i32, i32* %5, align 4
  %31 = call %struct.BSTNode* @bstInsert(%struct.BSTNode* noundef %29, i32 noundef %30)
  %32 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %33 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %32, i32 0, i32 1
  store %struct.BSTNode* %31, %struct.BSTNode** %33, align 8
  br label %49

34:                                               ; preds = %20
  %35 = load i32, i32* %5, align 4
  %36 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %37 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %36, i32 0, i32 0
  %38 = load i32, i32* %37, align 8
  %39 = icmp sgt i32 %35, %38
  br i1 %39, label %40, label %48

40:                                               ; preds = %34
  %41 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %42 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %41, i32 0, i32 2
  %43 = load %struct.BSTNode*, %struct.BSTNode** %42, align 8
  %44 = load i32, i32* %5, align 4
  %45 = call %struct.BSTNode* @bstInsert(%struct.BSTNode* noundef %43, i32 noundef %44)
  %46 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %47 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %46, i32 0, i32 2
  store %struct.BSTNode* %45, %struct.BSTNode** %47, align 8
  br label %48

48:                                               ; preds = %40, %34
  br label %49

49:                                               ; preds = %48, %26
  %50 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  store %struct.BSTNode* %50, %struct.BSTNode** %3, align 8
  br label %51

51:                                               ; preds = %49, %9
  %52 = load %struct.BSTNode*, %struct.BSTNode** %3, align 8
  ret %struct.BSTNode* %52
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @bstInOrder(%struct.BSTNode* noundef %0) #0 {
  %2 = alloca %struct.BSTNode*, align 8
  store %struct.BSTNode* %0, %struct.BSTNode** %2, align 8
  %3 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %4 = icmp ne %struct.BSTNode* %3, null
  br i1 %4, label %6, label %5

5:                                                ; preds = %1
  br label %17

6:                                                ; preds = %1
  %7 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %8 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %7, i32 0, i32 1
  %9 = load %struct.BSTNode*, %struct.BSTNode** %8, align 8
  call void @bstInOrder(%struct.BSTNode* noundef %9)
  %10 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %11 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %10, i32 0, i32 0
  %12 = load i32, i32* %11, align 8
  %13 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i64 0, i64 0), i32 noundef %12)
  %14 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %15 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %14, i32 0, i32 2
  %16 = load %struct.BSTNode*, %struct.BSTNode** %15, align 8
  call void @bstInOrder(%struct.BSTNode* noundef %16)
  br label %17

17:                                               ; preds = %6, %5
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @bstFree(%struct.BSTNode* noundef %0) #0 {
  %2 = alloca %struct.BSTNode*, align 8
  store %struct.BSTNode* %0, %struct.BSTNode** %2, align 8
  %3 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %4 = icmp ne %struct.BSTNode* %3, null
  br i1 %4, label %6, label %5

5:                                                ; preds = %1
  br label %15

6:                                                ; preds = %1
  %7 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %8 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %7, i32 0, i32 1
  %9 = load %struct.BSTNode*, %struct.BSTNode** %8, align 8
  call void @bstFree(%struct.BSTNode* noundef %9)
  %10 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %11 = getelementptr inbounds %struct.BSTNode, %struct.BSTNode* %10, i32 0, i32 2
  %12 = load %struct.BSTNode*, %struct.BSTNode** %11, align 8
  call void @bstFree(%struct.BSTNode* noundef %12)
  %13 = load %struct.BSTNode*, %struct.BSTNode** %2, align 8
  %14 = bitcast %struct.BSTNode* %13 to i8*
  call void @free(i8* noundef %14) #6
  br label %15

15:                                               ; preds = %6, %5
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @merge(i32* noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) #0 {
  %5 = alloca i32*, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32*, align 8
  %12 = alloca i32*, align 8
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  store i32* %0, i32** %5, align 8
  store i32 %1, i32* %6, align 4
  store i32 %2, i32* %7, align 4
  store i32 %3, i32* %8, align 4
  %18 = load i32, i32* %7, align 4
  %19 = load i32, i32* %6, align 4
  %20 = sub nsw i32 %18, %19
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %9, align 4
  %22 = load i32, i32* %8, align 4
  %23 = load i32, i32* %7, align 4
  %24 = sub nsw i32 %22, %23
  store i32 %24, i32* %10, align 4
  %25 = load i32, i32* %9, align 4
  %26 = sext i32 %25 to i64
  %27 = mul i64 4, %26
  %28 = call noalias i8* @malloc(i64 noundef %27) #6
  %29 = bitcast i8* %28 to i32*
  store i32* %29, i32** %11, align 8
  %30 = load i32, i32* %10, align 4
  %31 = sext i32 %30 to i64
  %32 = mul i64 4, %31
  %33 = call noalias i8* @malloc(i64 noundef %32) #6
  %34 = bitcast i8* %33 to i32*
  store i32* %34, i32** %12, align 8
  store i32 0, i32* %13, align 4
  br label %35

35:                                               ; preds = %51, %4
  %36 = load i32, i32* %13, align 4
  %37 = load i32, i32* %9, align 4
  %38 = icmp slt i32 %36, %37
  br i1 %38, label %39, label %54

39:                                               ; preds = %35
  %40 = load i32*, i32** %5, align 8
  %41 = load i32, i32* %6, align 4
  %42 = load i32, i32* %13, align 4
  %43 = add nsw i32 %41, %42
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds i32, i32* %40, i64 %44
  %46 = load i32, i32* %45, align 4
  %47 = load i32*, i32** %11, align 8
  %48 = load i32, i32* %13, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds i32, i32* %47, i64 %49
  store i32 %46, i32* %50, align 4
  br label %51

51:                                               ; preds = %39
  %52 = load i32, i32* %13, align 4
  %53 = add nsw i32 %52, 1
  store i32 %53, i32* %13, align 4
  br label %35, !llvm.loop !9

54:                                               ; preds = %35
  store i32 0, i32* %14, align 4
  br label %55

55:                                               ; preds = %72, %54
  %56 = load i32, i32* %14, align 4
  %57 = load i32, i32* %10, align 4
  %58 = icmp slt i32 %56, %57
  br i1 %58, label %59, label %75

59:                                               ; preds = %55
  %60 = load i32*, i32** %5, align 8
  %61 = load i32, i32* %7, align 4
  %62 = add nsw i32 %61, 1
  %63 = load i32, i32* %14, align 4
  %64 = add nsw i32 %62, %63
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds i32, i32* %60, i64 %65
  %67 = load i32, i32* %66, align 4
  %68 = load i32*, i32** %12, align 8
  %69 = load i32, i32* %14, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds i32, i32* %68, i64 %70
  store i32 %67, i32* %71, align 4
  br label %72

72:                                               ; preds = %59
  %73 = load i32, i32* %14, align 4
  %74 = add nsw i32 %73, 1
  store i32 %74, i32* %14, align 4
  br label %55, !llvm.loop !10

75:                                               ; preds = %55
  store i32 0, i32* %15, align 4
  store i32 0, i32* %16, align 4
  %76 = load i32, i32* %6, align 4
  store i32 %76, i32* %17, align 4
  br label %77

77:                                               ; preds = %123, %75
  %78 = load i32, i32* %15, align 4
  %79 = load i32, i32* %9, align 4
  %80 = icmp slt i32 %78, %79
  br i1 %80, label %81, label %85

81:                                               ; preds = %77
  %82 = load i32, i32* %16, align 4
  %83 = load i32, i32* %10, align 4
  %84 = icmp slt i32 %82, %83
  br label %85

85:                                               ; preds = %81, %77
  %86 = phi i1 [ false, %77 ], [ %84, %81 ]
  br i1 %86, label %87, label %124

87:                                               ; preds = %85
  %88 = load i32*, i32** %11, align 8
  %89 = load i32, i32* %15, align 4
  %90 = sext i32 %89 to i64
  %91 = getelementptr inbounds i32, i32* %88, i64 %90
  %92 = load i32, i32* %91, align 4
  %93 = load i32*, i32** %12, align 8
  %94 = load i32, i32* %16, align 4
  %95 = sext i32 %94 to i64
  %96 = getelementptr inbounds i32, i32* %93, i64 %95
  %97 = load i32, i32* %96, align 4
  %98 = icmp sle i32 %92, %97
  br i1 %98, label %99, label %111

99:                                               ; preds = %87
  %100 = load i32*, i32** %11, align 8
  %101 = load i32, i32* %15, align 4
  %102 = add nsw i32 %101, 1
  store i32 %102, i32* %15, align 4
  %103 = sext i32 %101 to i64
  %104 = getelementptr inbounds i32, i32* %100, i64 %103
  %105 = load i32, i32* %104, align 4
  %106 = load i32*, i32** %5, align 8
  %107 = load i32, i32* %17, align 4
  %108 = add nsw i32 %107, 1
  store i32 %108, i32* %17, align 4
  %109 = sext i32 %107 to i64
  %110 = getelementptr inbounds i32, i32* %106, i64 %109
  store i32 %105, i32* %110, align 4
  br label %123

111:                                              ; preds = %87
  %112 = load i32*, i32** %12, align 8
  %113 = load i32, i32* %16, align 4
  %114 = add nsw i32 %113, 1
  store i32 %114, i32* %16, align 4
  %115 = sext i32 %113 to i64
  %116 = getelementptr inbounds i32, i32* %112, i64 %115
  %117 = load i32, i32* %116, align 4
  %118 = load i32*, i32** %5, align 8
  %119 = load i32, i32* %17, align 4
  %120 = add nsw i32 %119, 1
  store i32 %120, i32* %17, align 4
  %121 = sext i32 %119 to i64
  %122 = getelementptr inbounds i32, i32* %118, i64 %121
  store i32 %117, i32* %122, align 4
  br label %123

123:                                              ; preds = %111, %99
  br label %77, !llvm.loop !11

124:                                              ; preds = %85
  br label %125

125:                                              ; preds = %129, %124
  %126 = load i32, i32* %15, align 4
  %127 = load i32, i32* %9, align 4
  %128 = icmp slt i32 %126, %127
  br i1 %128, label %129, label %141

129:                                              ; preds = %125
  %130 = load i32*, i32** %11, align 8
  %131 = load i32, i32* %15, align 4
  %132 = add nsw i32 %131, 1
  store i32 %132, i32* %15, align 4
  %133 = sext i32 %131 to i64
  %134 = getelementptr inbounds i32, i32* %130, i64 %133
  %135 = load i32, i32* %134, align 4
  %136 = load i32*, i32** %5, align 8
  %137 = load i32, i32* %17, align 4
  %138 = add nsw i32 %137, 1
  store i32 %138, i32* %17, align 4
  %139 = sext i32 %137 to i64
  %140 = getelementptr inbounds i32, i32* %136, i64 %139
  store i32 %135, i32* %140, align 4
  br label %125, !llvm.loop !12

141:                                              ; preds = %125
  br label %142

142:                                              ; preds = %146, %141
  %143 = load i32, i32* %16, align 4
  %144 = load i32, i32* %10, align 4
  %145 = icmp slt i32 %143, %144
  br i1 %145, label %146, label %158

146:                                              ; preds = %142
  %147 = load i32*, i32** %12, align 8
  %148 = load i32, i32* %16, align 4
  %149 = add nsw i32 %148, 1
  store i32 %149, i32* %16, align 4
  %150 = sext i32 %148 to i64
  %151 = getelementptr inbounds i32, i32* %147, i64 %150
  %152 = load i32, i32* %151, align 4
  %153 = load i32*, i32** %5, align 8
  %154 = load i32, i32* %17, align 4
  %155 = add nsw i32 %154, 1
  store i32 %155, i32* %17, align 4
  %156 = sext i32 %154 to i64
  %157 = getelementptr inbounds i32, i32* %153, i64 %156
  store i32 %152, i32* %157, align 4
  br label %142, !llvm.loop !13

158:                                              ; preds = %142
  %159 = load i32*, i32** %11, align 8
  %160 = bitcast i32* %159 to i8*
  call void @free(i8* noundef %160) #6
  %161 = load i32*, i32** %12, align 8
  %162 = bitcast i32* %161 to i8*
  call void @free(i8* noundef %162) #6
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @mergeSort(i32* noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %8 = load i32, i32* %5, align 4
  %9 = load i32, i32* %6, align 4
  %10 = icmp slt i32 %8, %9
  br i1 %10, label %11, label %27

11:                                               ; preds = %3
  %12 = load i32, i32* %5, align 4
  %13 = load i32, i32* %6, align 4
  %14 = add nsw i32 %12, %13
  %15 = sdiv i32 %14, 2
  store i32 %15, i32* %7, align 4
  %16 = load i32*, i32** %4, align 8
  %17 = load i32, i32* %5, align 4
  %18 = load i32, i32* %7, align 4
  call void @mergeSort(i32* noundef %16, i32 noundef %17, i32 noundef %18)
  %19 = load i32*, i32** %4, align 8
  %20 = load i32, i32* %7, align 4
  %21 = add nsw i32 %20, 1
  %22 = load i32, i32* %6, align 4
  call void @mergeSort(i32* noundef %19, i32 noundef %21, i32 noundef %22)
  %23 = load i32*, i32** %4, align 8
  %24 = load i32, i32* %5, align 4
  %25 = load i32, i32* %7, align 4
  %26 = load i32, i32* %6, align 4
  call void @merge(i32* noundef %23, i32 noundef %24, i32 noundef %25, i32 noundef %26)
  br label %27

27:                                               ; preds = %11, %3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @partitionQ(i32* noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %12 = load i32*, i32** %4, align 8
  %13 = load i32, i32* %6, align 4
  %14 = sext i32 %13 to i64
  %15 = getelementptr inbounds i32, i32* %12, i64 %14
  %16 = load i32, i32* %15, align 4
  store i32 %16, i32* %7, align 4
  %17 = load i32, i32* %5, align 4
  %18 = sub nsw i32 %17, 1
  store i32 %18, i32* %8, align 4
  %19 = load i32, i32* %5, align 4
  store i32 %19, i32* %9, align 4
  br label %20

20:                                               ; preds = %57, %3
  %21 = load i32, i32* %9, align 4
  %22 = load i32, i32* %6, align 4
  %23 = icmp slt i32 %21, %22
  br i1 %23, label %24, label %60

24:                                               ; preds = %20
  %25 = load i32*, i32** %4, align 8
  %26 = load i32, i32* %9, align 4
  %27 = sext i32 %26 to i64
  %28 = getelementptr inbounds i32, i32* %25, i64 %27
  %29 = load i32, i32* %28, align 4
  %30 = load i32, i32* %7, align 4
  %31 = icmp slt i32 %29, %30
  br i1 %31, label %32, label %56

32:                                               ; preds = %24
  %33 = load i32, i32* %8, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %8, align 4
  br label %35

35:                                               ; preds = %32
  %36 = load i32*, i32** %4, align 8
  %37 = load i32, i32* %8, align 4
  %38 = sext i32 %37 to i64
  %39 = getelementptr inbounds i32, i32* %36, i64 %38
  %40 = load i32, i32* %39, align 4
  store i32 %40, i32* %10, align 4
  %41 = load i32*, i32** %4, align 8
  %42 = load i32, i32* %9, align 4
  %43 = sext i32 %42 to i64
  %44 = getelementptr inbounds i32, i32* %41, i64 %43
  %45 = load i32, i32* %44, align 4
  %46 = load i32*, i32** %4, align 8
  %47 = load i32, i32* %8, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds i32, i32* %46, i64 %48
  store i32 %45, i32* %49, align 4
  %50 = load i32, i32* %10, align 4
  %51 = load i32*, i32** %4, align 8
  %52 = load i32, i32* %9, align 4
  %53 = sext i32 %52 to i64
  %54 = getelementptr inbounds i32, i32* %51, i64 %53
  store i32 %50, i32* %54, align 4
  br label %55

55:                                               ; preds = %35
  br label %56

56:                                               ; preds = %55, %24
  br label %57

57:                                               ; preds = %56
  %58 = load i32, i32* %9, align 4
  %59 = add nsw i32 %58, 1
  store i32 %59, i32* %9, align 4
  br label %20, !llvm.loop !14

60:                                               ; preds = %20
  br label %61

61:                                               ; preds = %60
  %62 = load i32*, i32** %4, align 8
  %63 = load i32, i32* %8, align 4
  %64 = add nsw i32 %63, 1
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds i32, i32* %62, i64 %65
  %67 = load i32, i32* %66, align 4
  store i32 %67, i32* %11, align 4
  %68 = load i32*, i32** %4, align 8
  %69 = load i32, i32* %6, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds i32, i32* %68, i64 %70
  %72 = load i32, i32* %71, align 4
  %73 = load i32*, i32** %4, align 8
  %74 = load i32, i32* %8, align 4
  %75 = add nsw i32 %74, 1
  %76 = sext i32 %75 to i64
  %77 = getelementptr inbounds i32, i32* %73, i64 %76
  store i32 %72, i32* %77, align 4
  %78 = load i32, i32* %11, align 4
  %79 = load i32*, i32** %4, align 8
  %80 = load i32, i32* %6, align 4
  %81 = sext i32 %80 to i64
  %82 = getelementptr inbounds i32, i32* %79, i64 %81
  store i32 %78, i32* %82, align 4
  br label %83

83:                                               ; preds = %61
  %84 = load i32, i32* %8, align 4
  %85 = add nsw i32 %84, 1
  ret i32 %85
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @quickSort(i32* noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %8 = load i32, i32* %5, align 4
  %9 = load i32, i32* %6, align 4
  %10 = icmp slt i32 %8, %9
  br i1 %10, label %11, label %24

11:                                               ; preds = %3
  %12 = load i32*, i32** %4, align 8
  %13 = load i32, i32* %5, align 4
  %14 = load i32, i32* %6, align 4
  %15 = call i32 @partitionQ(i32* noundef %12, i32 noundef %13, i32 noundef %14)
  store i32 %15, i32* %7, align 4
  %16 = load i32*, i32** %4, align 8
  %17 = load i32, i32* %5, align 4
  %18 = load i32, i32* %7, align 4
  %19 = sub nsw i32 %18, 1
  call void @quickSort(i32* noundef %16, i32 noundef %17, i32 noundef %19)
  %20 = load i32*, i32** %4, align 8
  %21 = load i32, i32* %7, align 4
  %22 = add nsw i32 %21, 1
  %23 = load i32, i32* %6, align 4
  call void @quickSort(i32* noundef %20, i32 noundef %22, i32 noundef %23)
  br label %24

24:                                               ; preds = %11, %3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @heapify(i32* noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %11 = load i32, i32* %6, align 4
  store i32 %11, i32* %7, align 4
  %12 = load i32, i32* %6, align 4
  %13 = mul nsw i32 2, %12
  %14 = add nsw i32 %13, 1
  store i32 %14, i32* %8, align 4
  %15 = load i32, i32* %6, align 4
  %16 = mul nsw i32 2, %15
  %17 = add nsw i32 %16, 2
  store i32 %17, i32* %9, align 4
  %18 = load i32, i32* %8, align 4
  %19 = load i32, i32* %5, align 4
  %20 = icmp slt i32 %18, %19
  br i1 %20, label %21, label %35

21:                                               ; preds = %3
  %22 = load i32*, i32** %4, align 8
  %23 = load i32, i32* %8, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds i32, i32* %22, i64 %24
  %26 = load i32, i32* %25, align 4
  %27 = load i32*, i32** %4, align 8
  %28 = load i32, i32* %7, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds i32, i32* %27, i64 %29
  %31 = load i32, i32* %30, align 4
  %32 = icmp sgt i32 %26, %31
  br i1 %32, label %33, label %35

33:                                               ; preds = %21
  %34 = load i32, i32* %8, align 4
  store i32 %34, i32* %7, align 4
  br label %35

35:                                               ; preds = %33, %21, %3
  %36 = load i32, i32* %9, align 4
  %37 = load i32, i32* %5, align 4
  %38 = icmp slt i32 %36, %37
  br i1 %38, label %39, label %53

39:                                               ; preds = %35
  %40 = load i32*, i32** %4, align 8
  %41 = load i32, i32* %9, align 4
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32, i32* %40, i64 %42
  %44 = load i32, i32* %43, align 4
  %45 = load i32*, i32** %4, align 8
  %46 = load i32, i32* %7, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds i32, i32* %45, i64 %47
  %49 = load i32, i32* %48, align 4
  %50 = icmp sgt i32 %44, %49
  br i1 %50, label %51, label %53

51:                                               ; preds = %39
  %52 = load i32, i32* %9, align 4
  store i32 %52, i32* %7, align 4
  br label %53

53:                                               ; preds = %51, %39, %35
  %54 = load i32, i32* %7, align 4
  %55 = load i32, i32* %6, align 4
  %56 = icmp ne i32 %54, %55
  br i1 %56, label %57, label %82

57:                                               ; preds = %53
  br label %58

58:                                               ; preds = %57
  %59 = load i32*, i32** %4, align 8
  %60 = load i32, i32* %6, align 4
  %61 = sext i32 %60 to i64
  %62 = getelementptr inbounds i32, i32* %59, i64 %61
  %63 = load i32, i32* %62, align 4
  store i32 %63, i32* %10, align 4
  %64 = load i32*, i32** %4, align 8
  %65 = load i32, i32* %7, align 4
  %66 = sext i32 %65 to i64
  %67 = getelementptr inbounds i32, i32* %64, i64 %66
  %68 = load i32, i32* %67, align 4
  %69 = load i32*, i32** %4, align 8
  %70 = load i32, i32* %6, align 4
  %71 = sext i32 %70 to i64
  %72 = getelementptr inbounds i32, i32* %69, i64 %71
  store i32 %68, i32* %72, align 4
  %73 = load i32, i32* %10, align 4
  %74 = load i32*, i32** %4, align 8
  %75 = load i32, i32* %7, align 4
  %76 = sext i32 %75 to i64
  %77 = getelementptr inbounds i32, i32* %74, i64 %76
  store i32 %73, i32* %77, align 4
  br label %78

78:                                               ; preds = %58
  %79 = load i32*, i32** %4, align 8
  %80 = load i32, i32* %5, align 4
  %81 = load i32, i32* %7, align 4
  call void @heapify(i32* noundef %79, i32 noundef %80, i32 noundef %81)
  br label %82

82:                                               ; preds = %78, %53
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @heapSort(i32* noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32* %0, i32** %3, align 8
  store i32 %1, i32* %4, align 4
  %8 = load i32, i32* %4, align 4
  %9 = sdiv i32 %8, 2
  %10 = sub nsw i32 %9, 1
  store i32 %10, i32* %5, align 4
  br label %11

11:                                               ; preds = %18, %2
  %12 = load i32, i32* %5, align 4
  %13 = icmp sge i32 %12, 0
  br i1 %13, label %14, label %21

14:                                               ; preds = %11
  %15 = load i32*, i32** %3, align 8
  %16 = load i32, i32* %4, align 4
  %17 = load i32, i32* %5, align 4
  call void @heapify(i32* noundef %15, i32 noundef %16, i32 noundef %17)
  br label %18

18:                                               ; preds = %14
  %19 = load i32, i32* %5, align 4
  %20 = add nsw i32 %19, -1
  store i32 %20, i32* %5, align 4
  br label %11, !llvm.loop !15

21:                                               ; preds = %11
  %22 = load i32, i32* %4, align 4
  %23 = sub nsw i32 %22, 1
  store i32 %23, i32* %6, align 4
  br label %24

24:                                               ; preds = %47, %21
  %25 = load i32, i32* %6, align 4
  %26 = icmp sgt i32 %25, 0
  br i1 %26, label %27, label %50

27:                                               ; preds = %24
  br label %28

28:                                               ; preds = %27
  %29 = load i32*, i32** %3, align 8
  %30 = getelementptr inbounds i32, i32* %29, i64 0
  %31 = load i32, i32* %30, align 4
  store i32 %31, i32* %7, align 4
  %32 = load i32*, i32** %3, align 8
  %33 = load i32, i32* %6, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds i32, i32* %32, i64 %34
  %36 = load i32, i32* %35, align 4
  %37 = load i32*, i32** %3, align 8
  %38 = getelementptr inbounds i32, i32* %37, i64 0
  store i32 %36, i32* %38, align 4
  %39 = load i32, i32* %7, align 4
  %40 = load i32*, i32** %3, align 8
  %41 = load i32, i32* %6, align 4
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32, i32* %40, i64 %42
  store i32 %39, i32* %43, align 4
  br label %44

44:                                               ; preds = %28
  %45 = load i32*, i32** %3, align 8
  %46 = load i32, i32* %6, align 4
  call void @heapify(i32* noundef %45, i32 noundef %46, i32 noundef 0)
  br label %47

47:                                               ; preds = %44
  %48 = load i32, i32* %6, align 4
  %49 = add nsw i32 %48, -1
  store i32 %49, i32* %6, align 4
  br label %24, !llvm.loop !16

50:                                               ; preds = %24
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local { %struct.GraphEdge**, i32 } @createGraphAdjList(i32 noundef %0) #0 {
  %2 = alloca %struct.GraphAdjList, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %5 = load i32, i32* %3, align 4
  %6 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %2, i32 0, i32 1
  store i32 %5, i32* %6, align 8
  %7 = load i32, i32* %3, align 4
  %8 = sext i32 %7 to i64
  %9 = mul i64 %8, 8
  %10 = call noalias i8* @malloc(i64 noundef %9) #6
  %11 = bitcast i8* %10 to %struct.GraphEdge**
  %12 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %2, i32 0, i32 0
  store %struct.GraphEdge** %11, %struct.GraphEdge*** %12, align 8
  store i32 0, i32* %4, align 4
  br label %13

13:                                               ; preds = %23, %1
  %14 = load i32, i32* %4, align 4
  %15 = load i32, i32* %3, align 4
  %16 = icmp slt i32 %14, %15
  br i1 %16, label %17, label %26

17:                                               ; preds = %13
  %18 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %2, i32 0, i32 0
  %19 = load %struct.GraphEdge**, %struct.GraphEdge*** %18, align 8
  %20 = load i32, i32* %4, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %19, i64 %21
  store %struct.GraphEdge* null, %struct.GraphEdge** %22, align 8
  br label %23

23:                                               ; preds = %17
  %24 = load i32, i32* %4, align 4
  %25 = add nsw i32 %24, 1
  store i32 %25, i32* %4, align 4
  br label %13, !llvm.loop !17

26:                                               ; preds = %13
  %27 = bitcast %struct.GraphAdjList* %2 to { %struct.GraphEdge**, i32 }*
  %28 = load { %struct.GraphEdge**, i32 }, { %struct.GraphEdge**, i32 }* %27, align 8
  ret { %struct.GraphEdge**, i32 } %28
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @addEdgeAdjList(%struct.GraphAdjList* noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) #0 {
  %5 = alloca %struct.GraphAdjList*, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca %struct.GraphEdge*, align 8
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %5, align 8
  store i32 %1, i32* %6, align 4
  store i32 %2, i32* %7, align 4
  store i32 %3, i32* %8, align 4
  %10 = load i32, i32* %6, align 4
  %11 = icmp slt i32 %10, 0
  br i1 %11, label %27, label %12

12:                                               ; preds = %4
  %13 = load i32, i32* %6, align 4
  %14 = load %struct.GraphAdjList*, %struct.GraphAdjList** %5, align 8
  %15 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %14, i32 0, i32 1
  %16 = load i32, i32* %15, align 8
  %17 = icmp sge i32 %13, %16
  br i1 %17, label %27, label %18

18:                                               ; preds = %12
  %19 = load i32, i32* %7, align 4
  %20 = icmp slt i32 %19, 0
  br i1 %20, label %27, label %21

21:                                               ; preds = %18
  %22 = load i32, i32* %7, align 4
  %23 = load %struct.GraphAdjList*, %struct.GraphAdjList** %5, align 8
  %24 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %23, i32 0, i32 1
  %25 = load i32, i32* %24, align 8
  %26 = icmp sge i32 %22, %25
  br i1 %26, label %27, label %28

27:                                               ; preds = %21, %18, %12, %4
  br label %53

28:                                               ; preds = %21
  %29 = call noalias i8* @malloc(i64 noundef 16) #6
  %30 = bitcast i8* %29 to %struct.GraphEdge*
  store %struct.GraphEdge* %30, %struct.GraphEdge** %9, align 8
  %31 = load i32, i32* %7, align 4
  %32 = load %struct.GraphEdge*, %struct.GraphEdge** %9, align 8
  %33 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %32, i32 0, i32 0
  store i32 %31, i32* %33, align 8
  %34 = load i32, i32* %8, align 4
  %35 = load %struct.GraphEdge*, %struct.GraphEdge** %9, align 8
  %36 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %35, i32 0, i32 1
  store i32 %34, i32* %36, align 4
  %37 = load %struct.GraphAdjList*, %struct.GraphAdjList** %5, align 8
  %38 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %37, i32 0, i32 0
  %39 = load %struct.GraphEdge**, %struct.GraphEdge*** %38, align 8
  %40 = load i32, i32* %6, align 4
  %41 = sext i32 %40 to i64
  %42 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %39, i64 %41
  %43 = load %struct.GraphEdge*, %struct.GraphEdge** %42, align 8
  %44 = load %struct.GraphEdge*, %struct.GraphEdge** %9, align 8
  %45 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %44, i32 0, i32 2
  store %struct.GraphEdge* %43, %struct.GraphEdge** %45, align 8
  %46 = load %struct.GraphEdge*, %struct.GraphEdge** %9, align 8
  %47 = load %struct.GraphAdjList*, %struct.GraphAdjList** %5, align 8
  %48 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %47, i32 0, i32 0
  %49 = load %struct.GraphEdge**, %struct.GraphEdge*** %48, align 8
  %50 = load i32, i32* %6, align 4
  %51 = sext i32 %50 to i64
  %52 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %49, i64 %51
  store %struct.GraphEdge* %46, %struct.GraphEdge** %52, align 8
  br label %53

53:                                               ; preds = %28, %27
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @freeGraphAdjList(%struct.GraphAdjList* noundef %0) #0 {
  %2 = alloca %struct.GraphAdjList*, align 8
  %3 = alloca i32, align 4
  %4 = alloca %struct.GraphEdge*, align 8
  %5 = alloca %struct.GraphEdge*, align 8
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %2, align 8
  store i32 0, i32* %3, align 4
  br label %6

6:                                                ; preds = %31, %1
  %7 = load i32, i32* %3, align 4
  %8 = load %struct.GraphAdjList*, %struct.GraphAdjList** %2, align 8
  %9 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %8, i32 0, i32 1
  %10 = load i32, i32* %9, align 8
  %11 = icmp slt i32 %7, %10
  br i1 %11, label %12, label %34

12:                                               ; preds = %6
  %13 = load %struct.GraphAdjList*, %struct.GraphAdjList** %2, align 8
  %14 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %13, i32 0, i32 0
  %15 = load %struct.GraphEdge**, %struct.GraphEdge*** %14, align 8
  %16 = load i32, i32* %3, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %15, i64 %17
  %19 = load %struct.GraphEdge*, %struct.GraphEdge** %18, align 8
  store %struct.GraphEdge* %19, %struct.GraphEdge** %4, align 8
  br label %20

20:                                               ; preds = %23, %12
  %21 = load %struct.GraphEdge*, %struct.GraphEdge** %4, align 8
  %22 = icmp ne %struct.GraphEdge* %21, null
  br i1 %22, label %23, label %30

23:                                               ; preds = %20
  %24 = load %struct.GraphEdge*, %struct.GraphEdge** %4, align 8
  store %struct.GraphEdge* %24, %struct.GraphEdge** %5, align 8
  %25 = load %struct.GraphEdge*, %struct.GraphEdge** %4, align 8
  %26 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %25, i32 0, i32 2
  %27 = load %struct.GraphEdge*, %struct.GraphEdge** %26, align 8
  store %struct.GraphEdge* %27, %struct.GraphEdge** %4, align 8
  %28 = load %struct.GraphEdge*, %struct.GraphEdge** %5, align 8
  %29 = bitcast %struct.GraphEdge* %28 to i8*
  call void @free(i8* noundef %29) #6
  br label %20, !llvm.loop !18

30:                                               ; preds = %20
  br label %31

31:                                               ; preds = %30
  %32 = load i32, i32* %3, align 4
  %33 = add nsw i32 %32, 1
  store i32 %33, i32* %3, align 4
  br label %6, !llvm.loop !19

34:                                               ; preds = %6
  %35 = load %struct.GraphAdjList*, %struct.GraphAdjList** %2, align 8
  %36 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %35, i32 0, i32 0
  %37 = load %struct.GraphEdge**, %struct.GraphEdge*** %36, align 8
  %38 = bitcast %struct.GraphEdge** %37 to i8*
  call void @free(i8* noundef %38) #6
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @bfsAdjList(%struct.GraphAdjList* noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.GraphAdjList*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32*, align 8
  %6 = alloca i32*, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca %struct.GraphEdge*, align 8
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %3, align 8
  store i32 %1, i32* %4, align 4
  %11 = load i32, i32* %4, align 4
  %12 = icmp slt i32 %11, 0
  br i1 %12, label %19, label %13

13:                                               ; preds = %2
  %14 = load i32, i32* %4, align 4
  %15 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %16 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %15, i32 0, i32 1
  %17 = load i32, i32* %16, align 8
  %18 = icmp sge i32 %14, %17
  br i1 %18, label %19, label %20

19:                                               ; preds = %13, %2
  br label %99

20:                                               ; preds = %13
  %21 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %22 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %21, i32 0, i32 1
  %23 = load i32, i32* %22, align 8
  %24 = sext i32 %23 to i64
  %25 = call noalias i8* @calloc(i64 noundef %24, i64 noundef 4) #6
  %26 = bitcast i8* %25 to i32*
  store i32* %26, i32** %5, align 8
  %27 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %28 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %27, i32 0, i32 1
  %29 = load i32, i32* %28, align 8
  %30 = sext i32 %29 to i64
  %31 = mul i64 4, %30
  %32 = call noalias i8* @malloc(i64 noundef %31) #6
  %33 = bitcast i8* %32 to i32*
  store i32* %33, i32** %6, align 8
  store i32 0, i32* %7, align 4
  store i32 0, i32* %8, align 4
  %34 = load i32*, i32** %5, align 8
  %35 = load i32, i32* %4, align 4
  %36 = sext i32 %35 to i64
  %37 = getelementptr inbounds i32, i32* %34, i64 %36
  store i32 1, i32* %37, align 4
  %38 = load i32, i32* %4, align 4
  %39 = load i32*, i32** %6, align 8
  %40 = load i32, i32* %8, align 4
  %41 = add nsw i32 %40, 1
  store i32 %41, i32* %8, align 4
  %42 = sext i32 %40 to i64
  %43 = getelementptr inbounds i32, i32* %39, i64 %42
  store i32 %38, i32* %43, align 4
  br label %44

44:                                               ; preds = %93, %20
  %45 = load i32, i32* %7, align 4
  %46 = load i32, i32* %8, align 4
  %47 = icmp slt i32 %45, %46
  br i1 %47, label %48, label %94

48:                                               ; preds = %44
  %49 = load i32*, i32** %6, align 8
  %50 = load i32, i32* %7, align 4
  %51 = add nsw i32 %50, 1
  store i32 %51, i32* %7, align 4
  %52 = sext i32 %50 to i64
  %53 = getelementptr inbounds i32, i32* %49, i64 %52
  %54 = load i32, i32* %53, align 4
  store i32 %54, i32* %9, align 4
  %55 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %56 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %55, i32 0, i32 0
  %57 = load %struct.GraphEdge**, %struct.GraphEdge*** %56, align 8
  %58 = load i32, i32* %9, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %57, i64 %59
  %61 = load %struct.GraphEdge*, %struct.GraphEdge** %60, align 8
  store %struct.GraphEdge* %61, %struct.GraphEdge** %10, align 8
  br label %62

62:                                               ; preds = %89, %48
  %63 = load %struct.GraphEdge*, %struct.GraphEdge** %10, align 8
  %64 = icmp ne %struct.GraphEdge* %63, null
  br i1 %64, label %65, label %93

65:                                               ; preds = %62
  %66 = load i32*, i32** %5, align 8
  %67 = load %struct.GraphEdge*, %struct.GraphEdge** %10, align 8
  %68 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %67, i32 0, i32 0
  %69 = load i32, i32* %68, align 8
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds i32, i32* %66, i64 %70
  %72 = load i32, i32* %71, align 4
  %73 = icmp ne i32 %72, 0
  br i1 %73, label %89, label %74

74:                                               ; preds = %65
  %75 = load i32*, i32** %5, align 8
  %76 = load %struct.GraphEdge*, %struct.GraphEdge** %10, align 8
  %77 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %76, i32 0, i32 0
  %78 = load i32, i32* %77, align 8
  %79 = sext i32 %78 to i64
  %80 = getelementptr inbounds i32, i32* %75, i64 %79
  store i32 1, i32* %80, align 4
  %81 = load %struct.GraphEdge*, %struct.GraphEdge** %10, align 8
  %82 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %81, i32 0, i32 0
  %83 = load i32, i32* %82, align 8
  %84 = load i32*, i32** %6, align 8
  %85 = load i32, i32* %8, align 4
  %86 = add nsw i32 %85, 1
  store i32 %86, i32* %8, align 4
  %87 = sext i32 %85 to i64
  %88 = getelementptr inbounds i32, i32* %84, i64 %87
  store i32 %83, i32* %88, align 4
  br label %89

89:                                               ; preds = %74, %65
  %90 = load %struct.GraphEdge*, %struct.GraphEdge** %10, align 8
  %91 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %90, i32 0, i32 2
  %92 = load %struct.GraphEdge*, %struct.GraphEdge** %91, align 8
  store %struct.GraphEdge* %92, %struct.GraphEdge** %10, align 8
  br label %62, !llvm.loop !20

93:                                               ; preds = %62
  br label %44, !llvm.loop !21

94:                                               ; preds = %44
  %95 = load i32*, i32** %5, align 8
  %96 = bitcast i32* %95 to i8*
  call void @free(i8* noundef %96) #6
  %97 = load i32*, i32** %6, align 8
  %98 = bitcast i32* %97 to i8*
  call void @free(i8* noundef %98) #6
  br label %99

99:                                               ; preds = %94, %19
  ret void
}

; Function Attrs: nounwind
declare noalias i8* @calloc(i64 noundef, i64 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @dfsVisit(%struct.GraphAdjList* noundef %0, i32 noundef %1, i32* noundef %2) #0 {
  %4 = alloca %struct.GraphAdjList*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32*, align 8
  %7 = alloca %struct.GraphEdge*, align 8
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32* %2, i32** %6, align 8
  %8 = load i32*, i32** %6, align 8
  %9 = load i32, i32* %5, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds i32, i32* %8, i64 %10
  store i32 1, i32* %11, align 4
  %12 = load %struct.GraphAdjList*, %struct.GraphAdjList** %4, align 8
  %13 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %12, i32 0, i32 0
  %14 = load %struct.GraphEdge**, %struct.GraphEdge*** %13, align 8
  %15 = load i32, i32* %5, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %14, i64 %16
  %18 = load %struct.GraphEdge*, %struct.GraphEdge** %17, align 8
  store %struct.GraphEdge* %18, %struct.GraphEdge** %7, align 8
  br label %19

19:                                               ; preds = %37, %3
  %20 = load %struct.GraphEdge*, %struct.GraphEdge** %7, align 8
  %21 = icmp ne %struct.GraphEdge* %20, null
  br i1 %21, label %22, label %41

22:                                               ; preds = %19
  %23 = load i32*, i32** %6, align 8
  %24 = load %struct.GraphEdge*, %struct.GraphEdge** %7, align 8
  %25 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %24, i32 0, i32 0
  %26 = load i32, i32* %25, align 8
  %27 = sext i32 %26 to i64
  %28 = getelementptr inbounds i32, i32* %23, i64 %27
  %29 = load i32, i32* %28, align 4
  %30 = icmp ne i32 %29, 0
  br i1 %30, label %37, label %31

31:                                               ; preds = %22
  %32 = load %struct.GraphAdjList*, %struct.GraphAdjList** %4, align 8
  %33 = load %struct.GraphEdge*, %struct.GraphEdge** %7, align 8
  %34 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %33, i32 0, i32 0
  %35 = load i32, i32* %34, align 8
  %36 = load i32*, i32** %6, align 8
  call void @dfsVisit(%struct.GraphAdjList* noundef %32, i32 noundef %35, i32* noundef %36)
  br label %37

37:                                               ; preds = %31, %22
  %38 = load %struct.GraphEdge*, %struct.GraphEdge** %7, align 8
  %39 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %38, i32 0, i32 2
  %40 = load %struct.GraphEdge*, %struct.GraphEdge** %39, align 8
  store %struct.GraphEdge* %40, %struct.GraphEdge** %7, align 8
  br label %19, !llvm.loop !22

41:                                               ; preds = %19
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @dfsAdjList(%struct.GraphAdjList* noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.GraphAdjList*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32*, align 8
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %3, align 8
  store i32 %1, i32* %4, align 4
  %6 = load i32, i32* %4, align 4
  %7 = icmp slt i32 %6, 0
  br i1 %7, label %14, label %8

8:                                                ; preds = %2
  %9 = load i32, i32* %4, align 4
  %10 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %11 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %10, i32 0, i32 1
  %12 = load i32, i32* %11, align 8
  %13 = icmp sge i32 %9, %12
  br i1 %13, label %14, label %15

14:                                               ; preds = %8, %2
  br label %27

15:                                               ; preds = %8
  %16 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %17 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %16, i32 0, i32 1
  %18 = load i32, i32* %17, align 8
  %19 = sext i32 %18 to i64
  %20 = call noalias i8* @calloc(i64 noundef %19, i64 noundef 4) #6
  %21 = bitcast i8* %20 to i32*
  store i32* %21, i32** %5, align 8
  %22 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %23 = load i32, i32* %4, align 4
  %24 = load i32*, i32** %5, align 8
  call void @dfsVisit(%struct.GraphAdjList* noundef %22, i32 noundef %23, i32* noundef %24)
  %25 = load i32*, i32** %5, align 8
  %26 = bitcast i32* %25 to i8*
  call void @free(i8* noundef %26) #6
  br label %27

27:                                               ; preds = %15, %14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @dijkstraAdjList(%struct.GraphAdjList* noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.GraphAdjList*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32*, align 8
  %7 = alloca i32*, align 8
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca %struct.GraphEdge*, align 8
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  store %struct.GraphAdjList* %0, %struct.GraphAdjList** %3, align 8
  store i32 %1, i32* %4, align 4
  %16 = load i32, i32* %4, align 4
  %17 = icmp slt i32 %16, 0
  br i1 %17, label %24, label %18

18:                                               ; preds = %2
  %19 = load i32, i32* %4, align 4
  %20 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %21 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %20, i32 0, i32 1
  %22 = load i32, i32* %21, align 8
  %23 = icmp sge i32 %19, %22
  br i1 %23, label %24, label %25

24:                                               ; preds = %18, %2
  br label %169

25:                                               ; preds = %18
  %26 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %27 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %26, i32 0, i32 1
  %28 = load i32, i32* %27, align 8
  store i32 %28, i32* %5, align 4
  %29 = load i32, i32* %5, align 4
  %30 = sext i32 %29 to i64
  %31 = mul i64 %30, 4
  %32 = call noalias i8* @malloc(i64 noundef %31) #6
  %33 = bitcast i8* %32 to i32*
  store i32* %33, i32** %6, align 8
  %34 = load i32, i32* %5, align 4
  %35 = sext i32 %34 to i64
  %36 = call noalias i8* @calloc(i64 noundef %35, i64 noundef 4) #6
  %37 = bitcast i8* %36 to i32*
  store i32* %37, i32** %7, align 8
  store i32 0, i32* %8, align 4
  br label %38

38:                                               ; preds = %47, %25
  %39 = load i32, i32* %8, align 4
  %40 = load i32, i32* %5, align 4
  %41 = icmp slt i32 %39, %40
  br i1 %41, label %42, label %50

42:                                               ; preds = %38
  %43 = load i32*, i32** %6, align 8
  %44 = load i32, i32* %8, align 4
  %45 = sext i32 %44 to i64
  %46 = getelementptr inbounds i32, i32* %43, i64 %45
  store i32 2147483647, i32* %46, align 4
  br label %47

47:                                               ; preds = %42
  %48 = load i32, i32* %8, align 4
  %49 = add nsw i32 %48, 1
  store i32 %49, i32* %8, align 4
  br label %38, !llvm.loop !23

50:                                               ; preds = %38
  %51 = load i32*, i32** %6, align 8
  %52 = load i32, i32* %4, align 4
  %53 = sext i32 %52 to i64
  %54 = getelementptr inbounds i32, i32* %51, i64 %53
  store i32 0, i32* %54, align 4
  store i32 0, i32* %9, align 4
  br label %55

55:                                               ; preds = %161, %50
  %56 = load i32, i32* %9, align 4
  %57 = load i32, i32* %5, align 4
  %58 = sub nsw i32 %57, 1
  %59 = icmp slt i32 %56, %58
  br i1 %59, label %60, label %164

60:                                               ; preds = %55
  store i32 2147483647, i32* %10, align 4
  store i32 -1, i32* %11, align 4
  store i32 0, i32* %12, align 4
  br label %61

61:                                               ; preds = %88, %60
  %62 = load i32, i32* %12, align 4
  %63 = load i32, i32* %5, align 4
  %64 = icmp slt i32 %62, %63
  br i1 %64, label %65, label %91

65:                                               ; preds = %61
  %66 = load i32*, i32** %7, align 8
  %67 = load i32, i32* %12, align 4
  %68 = sext i32 %67 to i64
  %69 = getelementptr inbounds i32, i32* %66, i64 %68
  %70 = load i32, i32* %69, align 4
  %71 = icmp ne i32 %70, 0
  br i1 %71, label %87, label %72

72:                                               ; preds = %65
  %73 = load i32*, i32** %6, align 8
  %74 = load i32, i32* %12, align 4
  %75 = sext i32 %74 to i64
  %76 = getelementptr inbounds i32, i32* %73, i64 %75
  %77 = load i32, i32* %76, align 4
  %78 = load i32, i32* %10, align 4
  %79 = icmp slt i32 %77, %78
  br i1 %79, label %80, label %87

80:                                               ; preds = %72
  %81 = load i32*, i32** %6, align 8
  %82 = load i32, i32* %12, align 4
  %83 = sext i32 %82 to i64
  %84 = getelementptr inbounds i32, i32* %81, i64 %83
  %85 = load i32, i32* %84, align 4
  store i32 %85, i32* %10, align 4
  %86 = load i32, i32* %12, align 4
  store i32 %86, i32* %11, align 4
  br label %87

87:                                               ; preds = %80, %72, %65
  br label %88

88:                                               ; preds = %87
  %89 = load i32, i32* %12, align 4
  %90 = add nsw i32 %89, 1
  store i32 %90, i32* %12, align 4
  br label %61, !llvm.loop !24

91:                                               ; preds = %61
  %92 = load i32, i32* %11, align 4
  %93 = icmp eq i32 %92, -1
  br i1 %93, label %94, label %95

94:                                               ; preds = %91
  br label %164

95:                                               ; preds = %91
  %96 = load i32*, i32** %7, align 8
  %97 = load i32, i32* %11, align 4
  %98 = sext i32 %97 to i64
  %99 = getelementptr inbounds i32, i32* %96, i64 %98
  store i32 1, i32* %99, align 4
  %100 = load %struct.GraphAdjList*, %struct.GraphAdjList** %3, align 8
  %101 = getelementptr inbounds %struct.GraphAdjList, %struct.GraphAdjList* %100, i32 0, i32 0
  %102 = load %struct.GraphEdge**, %struct.GraphEdge*** %101, align 8
  %103 = load i32, i32* %11, align 4
  %104 = sext i32 %103 to i64
  %105 = getelementptr inbounds %struct.GraphEdge*, %struct.GraphEdge** %102, i64 %104
  %106 = load %struct.GraphEdge*, %struct.GraphEdge** %105, align 8
  store %struct.GraphEdge* %106, %struct.GraphEdge** %13, align 8
  br label %107

107:                                              ; preds = %156, %95
  %108 = load %struct.GraphEdge*, %struct.GraphEdge** %13, align 8
  %109 = icmp ne %struct.GraphEdge* %108, null
  br i1 %109, label %110, label %160

110:                                              ; preds = %107
  %111 = load %struct.GraphEdge*, %struct.GraphEdge** %13, align 8
  %112 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %111, i32 0, i32 0
  %113 = load i32, i32* %112, align 8
  store i32 %113, i32* %14, align 4
  %114 = load %struct.GraphEdge*, %struct.GraphEdge** %13, align 8
  %115 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %114, i32 0, i32 1
  %116 = load i32, i32* %115, align 4
  store i32 %116, i32* %15, align 4
  %117 = load i32*, i32** %7, align 8
  %118 = load i32, i32* %14, align 4
  %119 = sext i32 %118 to i64
  %120 = getelementptr inbounds i32, i32* %117, i64 %119
  %121 = load i32, i32* %120, align 4
  %122 = icmp ne i32 %121, 0
  br i1 %122, label %156, label %123

123:                                              ; preds = %110
  %124 = load i32*, i32** %6, align 8
  %125 = load i32, i32* %11, align 4
  %126 = sext i32 %125 to i64
  %127 = getelementptr inbounds i32, i32* %124, i64 %126
  %128 = load i32, i32* %127, align 4
  %129 = icmp ne i32 %128, 2147483647
  br i1 %129, label %130, label %156

130:                                              ; preds = %123
  %131 = load i32*, i32** %6, align 8
  %132 = load i32, i32* %11, align 4
  %133 = sext i32 %132 to i64
  %134 = getelementptr inbounds i32, i32* %131, i64 %133
  %135 = load i32, i32* %134, align 4
  %136 = load i32, i32* %15, align 4
  %137 = add nsw i32 %135, %136
  %138 = load i32*, i32** %6, align 8
  %139 = load i32, i32* %14, align 4
  %140 = sext i32 %139 to i64
  %141 = getelementptr inbounds i32, i32* %138, i64 %140
  %142 = load i32, i32* %141, align 4
  %143 = icmp slt i32 %137, %142
  br i1 %143, label %144, label %156

144:                                              ; preds = %130
  %145 = load i32*, i32** %6, align 8
  %146 = load i32, i32* %11, align 4
  %147 = sext i32 %146 to i64
  %148 = getelementptr inbounds i32, i32* %145, i64 %147
  %149 = load i32, i32* %148, align 4
  %150 = load i32, i32* %15, align 4
  %151 = add nsw i32 %149, %150
  %152 = load i32*, i32** %6, align 8
  %153 = load i32, i32* %14, align 4
  %154 = sext i32 %153 to i64
  %155 = getelementptr inbounds i32, i32* %152, i64 %154
  store i32 %151, i32* %155, align 4
  br label %156

156:                                              ; preds = %144, %130, %123, %110
  %157 = load %struct.GraphEdge*, %struct.GraphEdge** %13, align 8
  %158 = getelementptr inbounds %struct.GraphEdge, %struct.GraphEdge* %157, i32 0, i32 2
  %159 = load %struct.GraphEdge*, %struct.GraphEdge** %158, align 8
  store %struct.GraphEdge* %159, %struct.GraphEdge** %13, align 8
  br label %107, !llvm.loop !25

160:                                              ; preds = %107
  br label %161

161:                                              ; preds = %160
  %162 = load i32, i32* %9, align 4
  %163 = add nsw i32 %162, 1
  store i32 %163, i32* %9, align 4
  br label %55, !llvm.loop !26

164:                                              ; preds = %94, %55
  %165 = load i32*, i32** %6, align 8
  %166 = bitcast i32* %165 to i8*
  call void @free(i8* noundef %166) #6
  %167 = load i32*, i32** %7, align 8
  %168 = bitcast i32* %167 to i8*
  call void @free(i8* noundef %168) #6
  br label %169

169:                                              ; preds = %164, %24
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local { i32**, i32 } @createGraphMatrix(i32 noundef %0) #0 {
  %2 = alloca %struct.GraphMatrix, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %6 = load i32, i32* %3, align 4
  %7 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %2, i32 0, i32 1
  store i32 %6, i32* %7, align 8
  %8 = load i32, i32* %3, align 4
  %9 = sext i32 %8 to i64
  %10 = mul i64 %9, 8
  %11 = call noalias i8* @malloc(i64 noundef %10) #6
  %12 = bitcast i8* %11 to i32**
  %13 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %2, i32 0, i32 0
  store i32** %12, i32*** %13, align 8
  store i32 0, i32* %4, align 4
  br label %14

14:                                               ; preds = %52, %1
  %15 = load i32, i32* %4, align 4
  %16 = load i32, i32* %3, align 4
  %17 = icmp slt i32 %15, %16
  br i1 %17, label %18, label %55

18:                                               ; preds = %14
  %19 = load i32, i32* %3, align 4
  %20 = sext i32 %19 to i64
  %21 = mul i64 %20, 4
  %22 = call noalias i8* @malloc(i64 noundef %21) #6
  %23 = bitcast i8* %22 to i32*
  %24 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %2, i32 0, i32 0
  %25 = load i32**, i32*** %24, align 8
  %26 = load i32, i32* %4, align 4
  %27 = sext i32 %26 to i64
  %28 = getelementptr inbounds i32*, i32** %25, i64 %27
  store i32* %23, i32** %28, align 8
  store i32 0, i32* %5, align 4
  br label %29

29:                                               ; preds = %48, %18
  %30 = load i32, i32* %5, align 4
  %31 = load i32, i32* %3, align 4
  %32 = icmp slt i32 %30, %31
  br i1 %32, label %33, label %51

33:                                               ; preds = %29
  %34 = load i32, i32* %4, align 4
  %35 = load i32, i32* %5, align 4
  %36 = icmp eq i32 %34, %35
  %37 = zext i1 %36 to i64
  %38 = select i1 %36, i32 0, i32 1073741823
  %39 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %2, i32 0, i32 0
  %40 = load i32**, i32*** %39, align 8
  %41 = load i32, i32* %4, align 4
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32*, i32** %40, i64 %42
  %44 = load i32*, i32** %43, align 8
  %45 = load i32, i32* %5, align 4
  %46 = sext i32 %45 to i64
  %47 = getelementptr inbounds i32, i32* %44, i64 %46
  store i32 %38, i32* %47, align 4
  br label %48

48:                                               ; preds = %33
  %49 = load i32, i32* %5, align 4
  %50 = add nsw i32 %49, 1
  store i32 %50, i32* %5, align 4
  br label %29, !llvm.loop !27

51:                                               ; preds = %29
  br label %52

52:                                               ; preds = %51
  %53 = load i32, i32* %4, align 4
  %54 = add nsw i32 %53, 1
  store i32 %54, i32* %4, align 4
  br label %14, !llvm.loop !28

55:                                               ; preds = %14
  %56 = bitcast %struct.GraphMatrix* %2 to { i32**, i32 }*
  %57 = load { i32**, i32 }, { i32**, i32 }* %56, align 8
  ret { i32**, i32 } %57
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @freeGraphMatrix(%struct.GraphMatrix* noundef %0) #0 {
  %2 = alloca %struct.GraphMatrix*, align 8
  %3 = alloca i32, align 4
  store %struct.GraphMatrix* %0, %struct.GraphMatrix** %2, align 8
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %19, %1
  %5 = load i32, i32* %3, align 4
  %6 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %7 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %6, i32 0, i32 1
  %8 = load i32, i32* %7, align 8
  %9 = icmp slt i32 %5, %8
  br i1 %9, label %10, label %22

10:                                               ; preds = %4
  %11 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %12 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %11, i32 0, i32 0
  %13 = load i32**, i32*** %12, align 8
  %14 = load i32, i32* %3, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32*, i32** %13, i64 %15
  %17 = load i32*, i32** %16, align 8
  %18 = bitcast i32* %17 to i8*
  call void @free(i8* noundef %18) #6
  br label %19

19:                                               ; preds = %10
  %20 = load i32, i32* %3, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %3, align 4
  br label %4, !llvm.loop !29

22:                                               ; preds = %4
  %23 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %24 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %23, i32 0, i32 0
  %25 = load i32**, i32*** %24, align 8
  %26 = bitcast i32** %25 to i8*
  call void @free(i8* noundef %26) #6
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @floydWarshall(%struct.GraphMatrix* noundef %0) #0 {
  %2 = alloca %struct.GraphMatrix*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store %struct.GraphMatrix* %0, %struct.GraphMatrix** %2, align 8
  %7 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %8 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %7, i32 0, i32 1
  %9 = load i32, i32* %8, align 8
  store i32 %9, i32* %3, align 4
  store i32 0, i32* %4, align 4
  br label %10

10:                                               ; preds = %103, %1
  %11 = load i32, i32* %4, align 4
  %12 = load i32, i32* %3, align 4
  %13 = icmp slt i32 %11, %12
  br i1 %13, label %14, label %106

14:                                               ; preds = %10
  store i32 0, i32* %5, align 4
  br label %15

15:                                               ; preds = %99, %14
  %16 = load i32, i32* %5, align 4
  %17 = load i32, i32* %3, align 4
  %18 = icmp slt i32 %16, %17
  br i1 %18, label %19, label %102

19:                                               ; preds = %15
  store i32 0, i32* %6, align 4
  br label %20

20:                                               ; preds = %95, %19
  %21 = load i32, i32* %6, align 4
  %22 = load i32, i32* %3, align 4
  %23 = icmp slt i32 %21, %22
  br i1 %23, label %24, label %98

24:                                               ; preds = %20
  %25 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %26 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %25, i32 0, i32 0
  %27 = load i32**, i32*** %26, align 8
  %28 = load i32, i32* %5, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds i32*, i32** %27, i64 %29
  %31 = load i32*, i32** %30, align 8
  %32 = load i32, i32* %4, align 4
  %33 = sext i32 %32 to i64
  %34 = getelementptr inbounds i32, i32* %31, i64 %33
  %35 = load i32, i32* %34, align 4
  %36 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %37 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %36, i32 0, i32 0
  %38 = load i32**, i32*** %37, align 8
  %39 = load i32, i32* %4, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds i32*, i32** %38, i64 %40
  %42 = load i32*, i32** %41, align 8
  %43 = load i32, i32* %6, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds i32, i32* %42, i64 %44
  %46 = load i32, i32* %45, align 4
  %47 = add nsw i32 %35, %46
  %48 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %49 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %48, i32 0, i32 0
  %50 = load i32**, i32*** %49, align 8
  %51 = load i32, i32* %5, align 4
  %52 = sext i32 %51 to i64
  %53 = getelementptr inbounds i32*, i32** %50, i64 %52
  %54 = load i32*, i32** %53, align 8
  %55 = load i32, i32* %6, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds i32, i32* %54, i64 %56
  %58 = load i32, i32* %57, align 4
  %59 = icmp slt i32 %47, %58
  br i1 %59, label %60, label %94

60:                                               ; preds = %24
  %61 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %62 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %61, i32 0, i32 0
  %63 = load i32**, i32*** %62, align 8
  %64 = load i32, i32* %5, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds i32*, i32** %63, i64 %65
  %67 = load i32*, i32** %66, align 8
  %68 = load i32, i32* %4, align 4
  %69 = sext i32 %68 to i64
  %70 = getelementptr inbounds i32, i32* %67, i64 %69
  %71 = load i32, i32* %70, align 4
  %72 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %73 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %72, i32 0, i32 0
  %74 = load i32**, i32*** %73, align 8
  %75 = load i32, i32* %4, align 4
  %76 = sext i32 %75 to i64
  %77 = getelementptr inbounds i32*, i32** %74, i64 %76
  %78 = load i32*, i32** %77, align 8
  %79 = load i32, i32* %6, align 4
  %80 = sext i32 %79 to i64
  %81 = getelementptr inbounds i32, i32* %78, i64 %80
  %82 = load i32, i32* %81, align 4
  %83 = add nsw i32 %71, %82
  %84 = load %struct.GraphMatrix*, %struct.GraphMatrix** %2, align 8
  %85 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %84, i32 0, i32 0
  %86 = load i32**, i32*** %85, align 8
  %87 = load i32, i32* %5, align 4
  %88 = sext i32 %87 to i64
  %89 = getelementptr inbounds i32*, i32** %86, i64 %88
  %90 = load i32*, i32** %89, align 8
  %91 = load i32, i32* %6, align 4
  %92 = sext i32 %91 to i64
  %93 = getelementptr inbounds i32, i32* %90, i64 %92
  store i32 %83, i32* %93, align 4
  br label %94

94:                                               ; preds = %60, %24
  br label %95

95:                                               ; preds = %94
  %96 = load i32, i32* %6, align 4
  %97 = add nsw i32 %96, 1
  store i32 %97, i32* %6, align 4
  br label %20, !llvm.loop !30

98:                                               ; preds = %20
  br label %99

99:                                               ; preds = %98
  %100 = load i32, i32* %5, align 4
  %101 = add nsw i32 %100, 1
  store i32 %101, i32* %5, align 4
  br label %15, !llvm.loop !31

102:                                              ; preds = %15
  br label %103

103:                                              ; preds = %102
  %104 = load i32, i32* %4, align 4
  %105 = add nsw i32 %104, 1
  store i32 %105, i32* %4, align 4
  br label %10, !llvm.loop !32

106:                                              ; preds = %10
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @threadFunctionSum(i8* noundef %0) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.ThreadData*, align 8
  %4 = alloca i64, align 8
  %5 = alloca i32, align 4
  store i8* %0, i8** %2, align 8
  %6 = load i8*, i8** %2, align 8
  %7 = bitcast i8* %6 to %struct.ThreadData*
  store %struct.ThreadData* %7, %struct.ThreadData** %3, align 8
  store i64 0, i64* %4, align 8
  store i32 0, i32* %5, align 4
  br label %8

8:                                                ; preds = %25, %1
  %9 = load i32, i32* %5, align 4
  %10 = load %struct.ThreadData*, %struct.ThreadData** %3, align 8
  %11 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %10, i32 0, i32 2
  %12 = load i32, i32* %11, align 8
  %13 = icmp slt i32 %9, %12
  br i1 %13, label %14, label %28

14:                                               ; preds = %8
  %15 = load %struct.ThreadData*, %struct.ThreadData** %3, align 8
  %16 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %15, i32 0, i32 1
  %17 = load i32*, i32** %16, align 8
  %18 = load i32, i32* %5, align 4
  %19 = sext i32 %18 to i64
  %20 = getelementptr inbounds i32, i32* %17, i64 %19
  %21 = load i32, i32* %20, align 4
  %22 = sext i32 %21 to i64
  %23 = load i64, i64* %4, align 8
  %24 = add nsw i64 %23, %22
  store i64 %24, i64* %4, align 8
  br label %25

25:                                               ; preds = %14
  %26 = load i32, i32* %5, align 4
  %27 = add nsw i32 %26, 1
  store i32 %27, i32* %5, align 4
  br label %8, !llvm.loop !33

28:                                               ; preds = %8
  %29 = load i64, i64* %4, align 8
  %30 = load %struct.ThreadData*, %struct.ThreadData** %3, align 8
  %31 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %30, i32 0, i32 3
  store i64 %29, i64* %31, align 8
  call void @pthread_exit(i8* noundef null) #7
  unreachable
}

; Function Attrs: noreturn
declare void @pthread_exit(i8* noundef) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @threadedArraySum(i32* noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i8*, align 8
  %8 = alloca i64, align 8
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i64, align 8
  %13 = alloca i32, align 4
  store i32* %0, i32** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  %14 = load i32, i32* %6, align 4
  %15 = zext i32 %14 to i64
  %16 = call i8* @llvm.stacksave()
  store i8* %16, i8** %7, align 8
  %17 = alloca i64, i64 %15, align 16
  store i64 %15, i64* %8, align 8
  %18 = load i32, i32* %6, align 4
  %19 = zext i32 %18 to i64
  %20 = alloca %struct.ThreadData, i64 %19, align 16
  store i64 %19, i64* %9, align 8
  %21 = load i32, i32* %5, align 4
  %22 = load i32, i32* %6, align 4
  %23 = sdiv i32 %21, %22
  store i32 %23, i32* %10, align 4
  store i32 0, i32* %11, align 4
  br label %24

24:                                               ; preds = %74, %3
  %25 = load i32, i32* %11, align 4
  %26 = load i32, i32* %6, align 4
  %27 = icmp slt i32 %25, %26
  br i1 %27, label %28, label %77

28:                                               ; preds = %24
  %29 = load i32, i32* %11, align 4
  %30 = load i32, i32* %11, align 4
  %31 = sext i32 %30 to i64
  %32 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %31
  %33 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %32, i32 0, i32 0
  store i32 %29, i32* %33, align 16
  %34 = load i32*, i32** %4, align 8
  %35 = load i32, i32* %11, align 4
  %36 = load i32, i32* %10, align 4
  %37 = mul nsw i32 %35, %36
  %38 = sext i32 %37 to i64
  %39 = getelementptr inbounds i32, i32* %34, i64 %38
  %40 = load i32, i32* %11, align 4
  %41 = sext i32 %40 to i64
  %42 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %41
  %43 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %42, i32 0, i32 1
  store i32* %39, i32** %43, align 8
  %44 = load i32, i32* %11, align 4
  %45 = load i32, i32* %6, align 4
  %46 = sub nsw i32 %45, 1
  %47 = icmp eq i32 %44, %46
  br i1 %47, label %48, label %54

48:                                               ; preds = %28
  %49 = load i32, i32* %5, align 4
  %50 = load i32, i32* %11, align 4
  %51 = load i32, i32* %10, align 4
  %52 = mul nsw i32 %50, %51
  %53 = sub nsw i32 %49, %52
  br label %56

54:                                               ; preds = %28
  %55 = load i32, i32* %10, align 4
  br label %56

56:                                               ; preds = %54, %48
  %57 = phi i32 [ %53, %48 ], [ %55, %54 ]
  %58 = load i32, i32* %11, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %59
  %61 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %60, i32 0, i32 2
  store i32 %57, i32* %61, align 16
  %62 = load i32, i32* %11, align 4
  %63 = sext i32 %62 to i64
  %64 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %63
  %65 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %64, i32 0, i32 3
  store i64 0, i64* %65, align 8
  %66 = load i32, i32* %11, align 4
  %67 = sext i32 %66 to i64
  %68 = getelementptr inbounds i64, i64* %17, i64 %67
  %69 = load i32, i32* %11, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %70
  %72 = bitcast %struct.ThreadData* %71 to i8*
  %73 = call i32 @pthread_create(i64* noundef %68, %union.pthread_attr_t* noundef null, i8* (i8*)* noundef @threadFunctionSum, i8* noundef %72) #6
  br label %74

74:                                               ; preds = %56
  %75 = load i32, i32* %11, align 4
  %76 = add nsw i32 %75, 1
  store i32 %76, i32* %11, align 4
  br label %24, !llvm.loop !34

77:                                               ; preds = %24
  store i64 0, i64* %12, align 8
  store i32 0, i32* %13, align 4
  br label %78

78:                                               ; preds = %95, %77
  %79 = load i32, i32* %13, align 4
  %80 = load i32, i32* %6, align 4
  %81 = icmp slt i32 %79, %80
  br i1 %81, label %82, label %98

82:                                               ; preds = %78
  %83 = load i32, i32* %13, align 4
  %84 = sext i32 %83 to i64
  %85 = getelementptr inbounds i64, i64* %17, i64 %84
  %86 = load i64, i64* %85, align 8
  %87 = call i32 @pthread_join(i64 noundef %86, i8** noundef null)
  %88 = load i32, i32* %13, align 4
  %89 = sext i32 %88 to i64
  %90 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %20, i64 %89
  %91 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %90, i32 0, i32 3
  %92 = load i64, i64* %91, align 8
  %93 = load i64, i64* %12, align 8
  %94 = add nsw i64 %93, %92
  store i64 %94, i64* %12, align 8
  br label %95

95:                                               ; preds = %82
  %96 = load i32, i32* %13, align 4
  %97 = add nsw i32 %96, 1
  store i32 %97, i32* %13, align 4
  br label %78, !llvm.loop !35

98:                                               ; preds = %78
  %99 = load i64, i64* %12, align 8
  %100 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([33 x i8], [33 x i8]* @.str.4, i64 0, i64 0), i64 noundef %99)
  %101 = load i8*, i8** %7, align 8
  call void @llvm.stackrestore(i8* %101)
  ret void
}

; Function Attrs: nofree nosync nounwind willreturn
declare i8* @llvm.stacksave() #4

; Function Attrs: nounwind
declare i32 @pthread_create(i64* noundef, %union.pthread_attr_t* noundef, i8* (i8*)* noundef, i8* noundef) #1

declare i32 @pthread_join(i64 noundef, i8** noundef) #2

; Function Attrs: nofree nosync nounwind willreturn
declare void @llvm.stackrestore(i8*) #4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local { i64, i32** } @createRandomMatrix(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.Matrix, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  %8 = load i32, i32* %4, align 4
  %9 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  store i32 %8, i32* %9, align 8
  %10 = load i32, i32* %5, align 4
  %11 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  store i32 %10, i32* %11, align 4
  %12 = load i32, i32* %4, align 4
  %13 = sext i32 %12 to i64
  %14 = mul i64 %13, 8
  %15 = call noalias i8* @malloc(i64 noundef %14) #6
  %16 = bitcast i8* %15 to i32**
  %17 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  store i32** %16, i32*** %17, align 8
  store i32 0, i32* %6, align 4
  br label %18

18:                                               ; preds = %53, %2
  %19 = load i32, i32* %6, align 4
  %20 = load i32, i32* %4, align 4
  %21 = icmp slt i32 %19, %20
  br i1 %21, label %22, label %56

22:                                               ; preds = %18
  %23 = load i32, i32* %5, align 4
  %24 = sext i32 %23 to i64
  %25 = mul i64 %24, 4
  %26 = call noalias i8* @malloc(i64 noundef %25) #6
  %27 = bitcast i8* %26 to i32*
  %28 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  %29 = load i32**, i32*** %28, align 8
  %30 = load i32, i32* %6, align 4
  %31 = sext i32 %30 to i64
  %32 = getelementptr inbounds i32*, i32** %29, i64 %31
  store i32* %27, i32** %32, align 8
  store i32 0, i32* %7, align 4
  br label %33

33:                                               ; preds = %49, %22
  %34 = load i32, i32* %7, align 4
  %35 = load i32, i32* %5, align 4
  %36 = icmp slt i32 %34, %35
  br i1 %36, label %37, label %52

37:                                               ; preds = %33
  %38 = call i32 @rand() #6
  %39 = srem i32 %38, 10
  %40 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  %41 = load i32**, i32*** %40, align 8
  %42 = load i32, i32* %6, align 4
  %43 = sext i32 %42 to i64
  %44 = getelementptr inbounds i32*, i32** %41, i64 %43
  %45 = load i32*, i32** %44, align 8
  %46 = load i32, i32* %7, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds i32, i32* %45, i64 %47
  store i32 %39, i32* %48, align 4
  br label %49

49:                                               ; preds = %37
  %50 = load i32, i32* %7, align 4
  %51 = add nsw i32 %50, 1
  store i32 %51, i32* %7, align 4
  br label %33, !llvm.loop !36

52:                                               ; preds = %33
  br label %53

53:                                               ; preds = %52
  %54 = load i32, i32* %6, align 4
  %55 = add nsw i32 %54, 1
  store i32 %55, i32* %6, align 4
  br label %18, !llvm.loop !37

56:                                               ; preds = %18
  %57 = bitcast %struct.Matrix* %3 to { i64, i32** }*
  %58 = load { i64, i32** }, { i64, i32** }* %57, align 8
  ret { i64, i32** } %58
}

; Function Attrs: nounwind
declare i32 @rand() #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local { i64, i32** } @multiplyMatrices(%struct.Matrix* noundef %0, %struct.Matrix* noundef %1) #0 {
  %3 = alloca %struct.Matrix, align 8
  %4 = alloca %struct.Matrix*, align 8
  %5 = alloca %struct.Matrix*, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  store %struct.Matrix* %0, %struct.Matrix** %4, align 8
  store %struct.Matrix* %1, %struct.Matrix** %5, align 8
  %11 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %12 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %11, i32 0, i32 1
  %13 = load i32, i32* %12, align 4
  %14 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %15 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %14, i32 0, i32 0
  %16 = load i32, i32* %15, align 8
  %17 = icmp ne i32 %13, %16
  br i1 %17, label %18, label %22

18:                                               ; preds = %2
  %19 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  store i32 0, i32* %19, align 8
  %20 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  store i32 0, i32* %20, align 4
  %21 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  store i32** null, i32*** %21, align 8
  br label %130

22:                                               ; preds = %2
  %23 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %24 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %23, i32 0, i32 0
  %25 = load i32, i32* %24, align 8
  %26 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  store i32 %25, i32* %26, align 8
  %27 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %28 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %27, i32 0, i32 1
  %29 = load i32, i32* %28, align 4
  %30 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  store i32 %29, i32* %30, align 4
  %31 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  %32 = load i32, i32* %31, align 8
  %33 = sext i32 %32 to i64
  %34 = mul i64 %33, 8
  %35 = call noalias i8* @malloc(i64 noundef %34) #6
  %36 = bitcast i8* %35 to i32**
  %37 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  store i32** %36, i32*** %37, align 8
  store i32 0, i32* %6, align 4
  br label %38

38:                                               ; preds = %55, %22
  %39 = load i32, i32* %6, align 4
  %40 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  %41 = load i32, i32* %40, align 8
  %42 = icmp slt i32 %39, %41
  br i1 %42, label %43, label %58

43:                                               ; preds = %38
  %44 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  %45 = load i32, i32* %44, align 4
  %46 = sext i32 %45 to i64
  %47 = mul i64 %46, 4
  %48 = call noalias i8* @malloc(i64 noundef %47) #6
  %49 = bitcast i8* %48 to i32*
  %50 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  %51 = load i32**, i32*** %50, align 8
  %52 = load i32, i32* %6, align 4
  %53 = sext i32 %52 to i64
  %54 = getelementptr inbounds i32*, i32** %51, i64 %53
  store i32* %49, i32** %54, align 8
  br label %55

55:                                               ; preds = %43
  %56 = load i32, i32* %6, align 4
  %57 = add nsw i32 %56, 1
  store i32 %57, i32* %6, align 4
  br label %38, !llvm.loop !38

58:                                               ; preds = %38
  store i32 0, i32* %7, align 4
  br label %59

59:                                               ; preds = %126, %58
  %60 = load i32, i32* %7, align 4
  %61 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %62 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %61, i32 0, i32 0
  %63 = load i32, i32* %62, align 8
  %64 = icmp slt i32 %60, %63
  br i1 %64, label %65, label %129

65:                                               ; preds = %59
  store i32 0, i32* %8, align 4
  br label %66

66:                                               ; preds = %122, %65
  %67 = load i32, i32* %8, align 4
  %68 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %69 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %68, i32 0, i32 1
  %70 = load i32, i32* %69, align 4
  %71 = icmp slt i32 %67, %70
  br i1 %71, label %72, label %125

72:                                               ; preds = %66
  store i64 0, i64* %9, align 8
  store i32 0, i32* %10, align 4
  br label %73

73:                                               ; preds = %107, %72
  %74 = load i32, i32* %10, align 4
  %75 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %76 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %75, i32 0, i32 1
  %77 = load i32, i32* %76, align 4
  %78 = icmp slt i32 %74, %77
  br i1 %78, label %79, label %110

79:                                               ; preds = %73
  %80 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %81 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %80, i32 0, i32 2
  %82 = load i32**, i32*** %81, align 8
  %83 = load i32, i32* %7, align 4
  %84 = sext i32 %83 to i64
  %85 = getelementptr inbounds i32*, i32** %82, i64 %84
  %86 = load i32*, i32** %85, align 8
  %87 = load i32, i32* %10, align 4
  %88 = sext i32 %87 to i64
  %89 = getelementptr inbounds i32, i32* %86, i64 %88
  %90 = load i32, i32* %89, align 4
  %91 = sext i32 %90 to i64
  %92 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %93 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %92, i32 0, i32 2
  %94 = load i32**, i32*** %93, align 8
  %95 = load i32, i32* %10, align 4
  %96 = sext i32 %95 to i64
  %97 = getelementptr inbounds i32*, i32** %94, i64 %96
  %98 = load i32*, i32** %97, align 8
  %99 = load i32, i32* %8, align 4
  %100 = sext i32 %99 to i64
  %101 = getelementptr inbounds i32, i32* %98, i64 %100
  %102 = load i32, i32* %101, align 4
  %103 = sext i32 %102 to i64
  %104 = mul nsw i64 %91, %103
  %105 = load i64, i64* %9, align 8
  %106 = add nsw i64 %105, %104
  store i64 %106, i64* %9, align 8
  br label %107

107:                                              ; preds = %79
  %108 = load i32, i32* %10, align 4
  %109 = add nsw i32 %108, 1
  store i32 %109, i32* %10, align 4
  br label %73, !llvm.loop !39

110:                                              ; preds = %73
  %111 = load i64, i64* %9, align 8
  %112 = trunc i64 %111 to i32
  %113 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  %114 = load i32**, i32*** %113, align 8
  %115 = load i32, i32* %7, align 4
  %116 = sext i32 %115 to i64
  %117 = getelementptr inbounds i32*, i32** %114, i64 %116
  %118 = load i32*, i32** %117, align 8
  %119 = load i32, i32* %8, align 4
  %120 = sext i32 %119 to i64
  %121 = getelementptr inbounds i32, i32* %118, i64 %120
  store i32 %112, i32* %121, align 4
  br label %122

122:                                              ; preds = %110
  %123 = load i32, i32* %8, align 4
  %124 = add nsw i32 %123, 1
  store i32 %124, i32* %8, align 4
  br label %66, !llvm.loop !40

125:                                              ; preds = %66
  br label %126

126:                                              ; preds = %125
  %127 = load i32, i32* %7, align 4
  %128 = add nsw i32 %127, 1
  store i32 %128, i32* %7, align 4
  br label %59, !llvm.loop !41

129:                                              ; preds = %59
  br label %130

130:                                              ; preds = %129, %18
  %131 = bitcast %struct.Matrix* %3 to { i64, i32** }*
  %132 = load { i64, i32** }, { i64, i32** }* %131, align 8
  ret { i64, i32** } %132
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @freeMatrix(%struct.Matrix* noundef %0) #0 {
  %2 = alloca %struct.Matrix*, align 8
  %3 = alloca i32, align 4
  store %struct.Matrix* %0, %struct.Matrix** %2, align 8
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %19, %1
  %5 = load i32, i32* %3, align 4
  %6 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %7 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %6, i32 0, i32 0
  %8 = load i32, i32* %7, align 8
  %9 = icmp slt i32 %5, %8
  br i1 %9, label %10, label %22

10:                                               ; preds = %4
  %11 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %12 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %11, i32 0, i32 2
  %13 = load i32**, i32*** %12, align 8
  %14 = load i32, i32* %3, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32*, i32** %13, i64 %15
  %17 = load i32*, i32** %16, align 8
  %18 = bitcast i32* %17 to i8*
  call void @free(i8* noundef %18) #6
  br label %19

19:                                               ; preds = %10
  %20 = load i32, i32* %3, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %3, align 4
  br label %4, !llvm.loop !42

22:                                               ; preds = %4
  %23 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %24 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %23, i32 0, i32 2
  %25 = load i32**, i32*** %24, align 8
  %26 = bitcast i32** %25 to i8*
  call void @free(i8* noundef %26) #6
  %27 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %28 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %27, i32 0, i32 2
  store i32** null, i32*** %28, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @factorial(i32 noundef %0) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = icmp slt i32 %4, 2
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  store i64 1, i64* %2, align 8
  br label %14

7:                                                ; preds = %1
  %8 = load i32, i32* %3, align 4
  %9 = sext i32 %8 to i64
  %10 = load i32, i32* %3, align 4
  %11 = sub nsw i32 %10, 1
  %12 = call i64 @factorial(i32 noundef %11)
  %13 = mul nsw i64 %9, %12
  store i64 %13, i64* %2, align 8
  br label %14

14:                                               ; preds = %7, %6
  %15 = load i64, i64* %2, align 8
  ret i64 %15
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @fibonacci(i32 noundef %0) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = icmp slt i32 %4, 2
  br i1 %5, label %6, label %9

6:                                                ; preds = %1
  %7 = load i32, i32* %3, align 4
  %8 = sext i32 %7 to i64
  store i64 %8, i64* %2, align 8
  br label %17

9:                                                ; preds = %1
  %10 = load i32, i32* %3, align 4
  %11 = sub nsw i32 %10, 1
  %12 = call i64 @fibonacci(i32 noundef %11)
  %13 = load i32, i32* %3, align 4
  %14 = sub nsw i32 %13, 2
  %15 = call i64 @fibonacci(i32 noundef %14)
  %16 = add nsw i64 %12, %15
  store i64 %16, i64* %2, align 8
  br label %17

17:                                               ; preds = %9, %6
  %18 = load i64, i64* %2, align 8
  ret i64 %18
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @isPrime(i64 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i64, align 8
  %4 = alloca i64, align 8
  store i64 %0, i64* %3, align 8
  %5 = load i64, i64* %3, align 8
  %6 = icmp sle i64 %5, 1
  br i1 %6, label %7, label %8

7:                                                ; preds = %1
  store i32 0, i32* %2, align 4
  br label %45

8:                                                ; preds = %1
  %9 = load i64, i64* %3, align 8
  %10 = icmp sle i64 %9, 3
  br i1 %10, label %11, label %12

11:                                               ; preds = %8
  store i32 1, i32* %2, align 4
  br label %45

12:                                               ; preds = %8
  %13 = load i64, i64* %3, align 8
  %14 = srem i64 %13, 2
  %15 = icmp eq i64 %14, 0
  br i1 %15, label %20, label %16

16:                                               ; preds = %12
  %17 = load i64, i64* %3, align 8
  %18 = srem i64 %17, 3
  %19 = icmp eq i64 %18, 0
  br i1 %19, label %20, label %21

20:                                               ; preds = %16, %12
  store i32 0, i32* %2, align 4
  br label %45

21:                                               ; preds = %16
  store i64 5, i64* %4, align 8
  br label %22

22:                                               ; preds = %41, %21
  %23 = load i64, i64* %4, align 8
  %24 = load i64, i64* %4, align 8
  %25 = mul nsw i64 %23, %24
  %26 = load i64, i64* %3, align 8
  %27 = icmp sle i64 %25, %26
  br i1 %27, label %28, label %44

28:                                               ; preds = %22
  %29 = load i64, i64* %3, align 8
  %30 = load i64, i64* %4, align 8
  %31 = srem i64 %29, %30
  %32 = icmp eq i64 %31, 0
  br i1 %32, label %39, label %33

33:                                               ; preds = %28
  %34 = load i64, i64* %3, align 8
  %35 = load i64, i64* %4, align 8
  %36 = add nsw i64 %35, 2
  %37 = srem i64 %34, %36
  %38 = icmp eq i64 %37, 0
  br i1 %38, label %39, label %40

39:                                               ; preds = %33, %28
  store i32 0, i32* %2, align 4
  br label %45

40:                                               ; preds = %33
  br label %41

41:                                               ; preds = %40
  %42 = load i64, i64* %4, align 8
  %43 = add nsw i64 %42, 6
  store i64 %43, i64* %4, align 8
  br label %22, !llvm.loop !43

44:                                               ; preds = %22
  store i32 1, i32* %2, align 4
  br label %45

45:                                               ; preds = %44, %39, %20, %11, %7
  %46 = load i32, i32* %2, align 4
  ret i32 %46
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @primeFactorization(i64 noundef %0) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  store i64 %0, i64* %2, align 8
  %4 = load i64, i64* %2, align 8
  %5 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([25 x i8], [25 x i8]* @.str.5, i64 0, i64 0), i64 noundef %4)
  br label %6

6:                                                ; preds = %10, %1
  %7 = load i64, i64* %2, align 8
  %8 = srem i64 %7, 2
  %9 = icmp eq i64 %8, 0
  br i1 %9, label %10, label %14

10:                                               ; preds = %6
  %11 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str.6, i64 0, i64 0))
  %12 = load i64, i64* %2, align 8
  %13 = sdiv i64 %12, 2
  store i64 %13, i64* %2, align 8
  br label %6, !llvm.loop !44

14:                                               ; preds = %6
  store i64 3, i64* %3, align 8
  br label %15

15:                                               ; preds = %34, %14
  %16 = load i64, i64* %3, align 8
  %17 = load i64, i64* %3, align 8
  %18 = mul nsw i64 %16, %17
  %19 = load i64, i64* %2, align 8
  %20 = icmp sle i64 %18, %19
  br i1 %20, label %21, label %37

21:                                               ; preds = %15
  br label %22

22:                                               ; preds = %27, %21
  %23 = load i64, i64* %2, align 8
  %24 = load i64, i64* %3, align 8
  %25 = srem i64 %23, %24
  %26 = icmp eq i64 %25, 0
  br i1 %26, label %27, label %33

27:                                               ; preds = %22
  %28 = load i64, i64* %3, align 8
  %29 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str.7, i64 0, i64 0), i64 noundef %28)
  %30 = load i64, i64* %3, align 8
  %31 = load i64, i64* %2, align 8
  %32 = sdiv i64 %31, %30
  store i64 %32, i64* %2, align 8
  br label %22, !llvm.loop !45

33:                                               ; preds = %22
  br label %34

34:                                               ; preds = %33
  %35 = load i64, i64* %3, align 8
  %36 = add nsw i64 %35, 2
  store i64 %36, i64* %3, align 8
  br label %15, !llvm.loop !46

37:                                               ; preds = %15
  %38 = load i64, i64* %2, align 8
  %39 = icmp sgt i64 %38, 2
  br i1 %39, label %40, label %43

40:                                               ; preds = %37
  %41 = load i64, i64* %2, align 8
  %42 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.8, i64 0, i64 0), i64 noundef %41)
  br label %43

43:                                               ; preds = %40, %37
  %44 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i64 0, i64 0))
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @randomStringManipulation(i8* noundef %0, i64 noundef %1) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i64, align 8
  %5 = alloca i8*, align 8
  %6 = alloca i64, align 8
  store i8* %0, i8** %3, align 8
  store i64 %1, i64* %4, align 8
  store i8* getelementptr inbounds ([63 x i8], [63 x i8]* @.str.10, i64 0, i64 0), i8** %5, align 8
  store i64 0, i64* %6, align 8
  br label %7

7:                                                ; preds = %24, %2
  %8 = load i64, i64* %6, align 8
  %9 = load i64, i64* %4, align 8
  %10 = sub i64 %9, 1
  %11 = icmp ult i64 %8, %10
  br i1 %11, label %12, label %27

12:                                               ; preds = %7
  %13 = load i8*, i8** %5, align 8
  %14 = call i32 @rand() #6
  %15 = sext i32 %14 to i64
  %16 = load i8*, i8** %5, align 8
  %17 = call i64 @strlen(i8* noundef %16) #8
  %18 = urem i64 %15, %17
  %19 = getelementptr inbounds i8, i8* %13, i64 %18
  %20 = load i8, i8* %19, align 1
  %21 = load i8*, i8** %3, align 8
  %22 = load i64, i64* %6, align 8
  %23 = getelementptr inbounds i8, i8* %21, i64 %22
  store i8 %20, i8* %23, align 1
  br label %24

24:                                               ; preds = %12
  %25 = load i64, i64* %6, align 8
  %26 = add i64 %25, 1
  store i64 %26, i64* %6, align 8
  br label %7, !llvm.loop !47

27:                                               ; preds = %7
  %28 = load i8*, i8** %3, align 8
  %29 = load i64, i64* %4, align 8
  %30 = sub i64 %29, 1
  %31 = getelementptr inbounds i8, i8* %28, i64 %30
  store i8 0, i8* %31, align 1
  ret void
}

; Function Attrs: nounwind readonly willreturn
declare i64 @strlen(i8* noundef) #5

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @createVariantInt(%struct.Variant* noalias sret(%struct.Variant) align 8 %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  store i32 %1, i32* %3, align 4
  %4 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 0
  store i32 0, i32* %4, align 8
  %5 = load i32, i32* %3, align 4
  %6 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 1
  %7 = bitcast %union.VariantValue* %6 to i32*
  store i32 %5, i32* %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @createVariantDouble(%struct.Variant* noalias sret(%struct.Variant) align 8 %0, double noundef %1) #0 {
  %3 = alloca double, align 8
  store double %1, double* %3, align 8
  %4 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 0
  store i32 1, i32* %4, align 8
  %5 = load double, double* %3, align 8
  %6 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 1
  %7 = bitcast %union.VariantValue* %6 to double*
  store double %5, double* %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @createVariantString(%struct.Variant* noalias sret(%struct.Variant) align 8 %0, i8* noundef %1) #0 {
  %3 = alloca i8*, align 8
  store i8* %1, i8** %3, align 8
  %4 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 0
  store i32 2, i32* %4, align 8
  %5 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 1
  %6 = bitcast %union.VariantValue* %5 to [64 x i8]*
  %7 = getelementptr inbounds [64 x i8], [64 x i8]* %6, i64 0, i64 0
  %8 = load i8*, i8** %3, align 8
  %9 = call i8* @strncpy(i8* noundef %7, i8* noundef %8, i64 noundef 63) #6
  %10 = getelementptr inbounds %struct.Variant, %struct.Variant* %0, i32 0, i32 1
  %11 = bitcast %union.VariantValue* %10 to [64 x i8]*
  %12 = getelementptr inbounds [64 x i8], [64 x i8]* %11, i64 0, i64 63
  store i8 0, i8* %12, align 1
  ret void
}

; Function Attrs: nounwind
declare i8* @strncpy(i8* noundef, i8* noundef, i64 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @printVariant(%struct.Variant* noundef %0) #0 {
  %2 = alloca %struct.Variant*, align 8
  store %struct.Variant* %0, %struct.Variant** %2, align 8
  %3 = load %struct.Variant*, %struct.Variant** %2, align 8
  %4 = getelementptr inbounds %struct.Variant, %struct.Variant* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 8
  switch i32 %5, label %24 [
    i32 0, label %6
    i32 1, label %12
    i32 2, label %18
  ]

6:                                                ; preds = %1
  %7 = load %struct.Variant*, %struct.Variant** %2, align 8
  %8 = getelementptr inbounds %struct.Variant, %struct.Variant* %7, i32 0, i32 1
  %9 = bitcast %union.VariantValue* %8 to i32*
  %10 = load i32, i32* %9, align 8
  %11 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([17 x i8], [17 x i8]* @.str.11, i64 0, i64 0), i32 noundef %10)
  br label %26

12:                                               ; preds = %1
  %13 = load %struct.Variant*, %struct.Variant** %2, align 8
  %14 = getelementptr inbounds %struct.Variant, %struct.Variant* %13, i32 0, i32 1
  %15 = bitcast %union.VariantValue* %14 to double*
  %16 = load double, double* %15, align 8
  %17 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([20 x i8], [20 x i8]* @.str.12, i64 0, i64 0), double noundef %16)
  br label %26

18:                                               ; preds = %1
  %19 = load %struct.Variant*, %struct.Variant** %2, align 8
  %20 = getelementptr inbounds %struct.Variant, %struct.Variant* %19, i32 0, i32 1
  %21 = bitcast %union.VariantValue* %20 to [64 x i8]*
  %22 = getelementptr inbounds [64 x i8], [64 x i8]* %21, i64 0, i64 0
  %23 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([20 x i8], [20 x i8]* @.str.13, i64 0, i64 0), i8* noundef %22)
  br label %26

24:                                               ; preds = %1
  %25 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([17 x i8], [17 x i8]* @.str.14, i64 0, i64 0))
  br label %26

26:                                               ; preds = %24, %18, %12, %6
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca %struct.ListNode*, align 8
  %3 = alloca i32, align 4
  %4 = alloca %struct.BSTNode*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32*, align 8
  %8 = alloca i32*, align 8
  %9 = alloca i32*, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca %struct.GraphAdjList, align 8
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca %struct.GraphMatrix, align 8
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32*, align 8
  %23 = alloca i32, align 4
  %24 = alloca %struct.Matrix, align 8
  %25 = alloca %struct.Matrix, align 8
  %26 = alloca %struct.Matrix, align 8
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i64, align 8
  %30 = alloca [32 x i8], align 16
  %31 = alloca %struct.Variant, align 8
  %32 = alloca %struct.Variant, align 8
  %33 = alloca %struct.Variant, align 8
  store i32 0, i32* %1, align 4
  %34 = call i64 @time(i64* noundef null) #6
  %35 = trunc i64 %34 to i32
  call void @srand(i32 noundef %35) #6
  store %struct.ListNode* null, %struct.ListNode** %2, align 8
  store i32 0, i32* %3, align 4
  br label %36

36:                                               ; preds = %42, %0
  %37 = load i32, i32* %3, align 4
  %38 = icmp slt i32 %37, 10
  br i1 %38, label %39, label %45

39:                                               ; preds = %36
  %40 = call i32 @rand() #6
  %41 = srem i32 %40, 100
  call void @listInsertFront(%struct.ListNode** noundef %2, i32 noundef %41)
  br label %42

42:                                               ; preds = %39
  %43 = load i32, i32* %3, align 4
  %44 = add nsw i32 %43, 1
  store i32 %44, i32* %3, align 4
  br label %36, !llvm.loop !48

45:                                               ; preds = %36
  %46 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  call void @listPrint(%struct.ListNode* noundef %46)
  %47 = load %struct.ListNode*, %struct.ListNode** %2, align 8
  call void @listFree(%struct.ListNode* noundef %47)
  store %struct.BSTNode* null, %struct.BSTNode** %4, align 8
  store i32 0, i32* %5, align 4
  br label %48

48:                                               ; preds = %56, %45
  %49 = load i32, i32* %5, align 4
  %50 = icmp slt i32 %49, 10
  br i1 %50, label %51, label %59

51:                                               ; preds = %48
  %52 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  %53 = call i32 @rand() #6
  %54 = srem i32 %53, 200
  %55 = call %struct.BSTNode* @bstInsert(%struct.BSTNode* noundef %52, i32 noundef %54)
  store %struct.BSTNode* %55, %struct.BSTNode** %4, align 8
  br label %56

56:                                               ; preds = %51
  %57 = load i32, i32* %5, align 4
  %58 = add nsw i32 %57, 1
  store i32 %58, i32* %5, align 4
  br label %48, !llvm.loop !49

59:                                               ; preds = %48
  %60 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([15 x i8], [15 x i8]* @.str.15, i64 0, i64 0))
  %61 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  call void @bstInOrder(%struct.BSTNode* noundef %61)
  %62 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i64 0, i64 0))
  %63 = load %struct.BSTNode*, %struct.BSTNode** %4, align 8
  call void @bstFree(%struct.BSTNode* noundef %63)
  store i32 15, i32* %6, align 4
  %64 = load i32, i32* %6, align 4
  %65 = sext i32 %64 to i64
  %66 = mul i64 4, %65
  %67 = call noalias i8* @malloc(i64 noundef %66) #6
  %68 = bitcast i8* %67 to i32*
  store i32* %68, i32** %7, align 8
  %69 = load i32, i32* %6, align 4
  %70 = sext i32 %69 to i64
  %71 = mul i64 4, %70
  %72 = call noalias i8* @malloc(i64 noundef %71) #6
  %73 = bitcast i8* %72 to i32*
  store i32* %73, i32** %8, align 8
  %74 = load i32, i32* %6, align 4
  %75 = sext i32 %74 to i64
  %76 = mul i64 4, %75
  %77 = call noalias i8* @malloc(i64 noundef %76) #6
  %78 = bitcast i8* %77 to i32*
  store i32* %78, i32** %9, align 8
  store i32 0, i32* %10, align 4
  br label %79

79:                                               ; preds = %101, %59
  %80 = load i32, i32* %10, align 4
  %81 = load i32, i32* %6, align 4
  %82 = icmp slt i32 %80, %81
  br i1 %82, label %83, label %104

83:                                               ; preds = %79
  %84 = call i32 @rand() #6
  %85 = srem i32 %84, 300
  store i32 %85, i32* %11, align 4
  %86 = load i32, i32* %11, align 4
  %87 = load i32*, i32** %7, align 8
  %88 = load i32, i32* %10, align 4
  %89 = sext i32 %88 to i64
  %90 = getelementptr inbounds i32, i32* %87, i64 %89
  store i32 %86, i32* %90, align 4
  %91 = load i32, i32* %11, align 4
  %92 = load i32*, i32** %8, align 8
  %93 = load i32, i32* %10, align 4
  %94 = sext i32 %93 to i64
  %95 = getelementptr inbounds i32, i32* %92, i64 %94
  store i32 %91, i32* %95, align 4
  %96 = load i32, i32* %11, align 4
  %97 = load i32*, i32** %9, align 8
  %98 = load i32, i32* %10, align 4
  %99 = sext i32 %98 to i64
  %100 = getelementptr inbounds i32, i32* %97, i64 %99
  store i32 %96, i32* %100, align 4
  br label %101

101:                                              ; preds = %83
  %102 = load i32, i32* %10, align 4
  %103 = add nsw i32 %102, 1
  store i32 %103, i32* %10, align 4
  br label %79, !llvm.loop !50

104:                                              ; preds = %79
  %105 = load i32*, i32** %7, align 8
  %106 = load i32, i32* %6, align 4
  %107 = sub nsw i32 %106, 1
  call void @mergeSort(i32* noundef %105, i32 noundef 0, i32 noundef %107)
  %108 = load i32*, i32** %8, align 8
  %109 = load i32, i32* %6, align 4
  %110 = sub nsw i32 %109, 1
  call void @quickSort(i32* noundef %108, i32 noundef 0, i32 noundef %110)
  %111 = load i32*, i32** %9, align 8
  %112 = load i32, i32* %6, align 4
  call void @heapSort(i32* noundef %111, i32 noundef %112)
  %113 = load i32*, i32** %7, align 8
  %114 = bitcast i32* %113 to i8*
  call void @free(i8* noundef %114) #6
  %115 = load i32*, i32** %8, align 8
  %116 = bitcast i32* %115 to i8*
  call void @free(i8* noundef %116) #6
  %117 = load i32*, i32** %9, align 8
  %118 = bitcast i32* %117 to i8*
  call void @free(i8* noundef %118) #6
  %119 = call { %struct.GraphEdge**, i32 } @createGraphAdjList(i32 noundef 10)
  %120 = bitcast %struct.GraphAdjList* %12 to { %struct.GraphEdge**, i32 }*
  %121 = getelementptr inbounds { %struct.GraphEdge**, i32 }, { %struct.GraphEdge**, i32 }* %120, i32 0, i32 0
  %122 = extractvalue { %struct.GraphEdge**, i32 } %119, 0
  store %struct.GraphEdge** %122, %struct.GraphEdge*** %121, align 8
  %123 = getelementptr inbounds { %struct.GraphEdge**, i32 }, { %struct.GraphEdge**, i32 }* %120, i32 0, i32 1
  %124 = extractvalue { %struct.GraphEdge**, i32 } %119, 1
  store i32 %124, i32* %123, align 8
  store i32 0, i32* %13, align 4
  br label %125

125:                                              ; preds = %138, %104
  %126 = load i32, i32* %13, align 4
  %127 = icmp slt i32 %126, 20
  br i1 %127, label %128, label %141

128:                                              ; preds = %125
  %129 = call i32 @rand() #6
  %130 = srem i32 %129, 10
  store i32 %130, i32* %14, align 4
  %131 = call i32 @rand() #6
  %132 = srem i32 %131, 10
  store i32 %132, i32* %15, align 4
  %133 = call i32 @rand() #6
  %134 = srem i32 %133, 50
  store i32 %134, i32* %16, align 4
  %135 = load i32, i32* %14, align 4
  %136 = load i32, i32* %15, align 4
  %137 = load i32, i32* %16, align 4
  call void @addEdgeAdjList(%struct.GraphAdjList* noundef %12, i32 noundef %135, i32 noundef %136, i32 noundef %137)
  br label %138

138:                                              ; preds = %128
  %139 = load i32, i32* %13, align 4
  %140 = add nsw i32 %139, 1
  store i32 %140, i32* %13, align 4
  br label %125, !llvm.loop !51

141:                                              ; preds = %125
  call void @bfsAdjList(%struct.GraphAdjList* noundef %12, i32 noundef 0)
  call void @dfsAdjList(%struct.GraphAdjList* noundef %12, i32 noundef 0)
  call void @dijkstraAdjList(%struct.GraphAdjList* noundef %12, i32 noundef 0)
  call void @freeGraphAdjList(%struct.GraphAdjList* noundef %12)
  %142 = call { i32**, i32 } @createGraphMatrix(i32 noundef 6)
  %143 = bitcast %struct.GraphMatrix* %17 to { i32**, i32 }*
  %144 = getelementptr inbounds { i32**, i32 }, { i32**, i32 }* %143, i32 0, i32 0
  %145 = extractvalue { i32**, i32 } %142, 0
  store i32** %145, i32*** %144, align 8
  %146 = getelementptr inbounds { i32**, i32 }, { i32**, i32 }* %143, i32 0, i32 1
  %147 = extractvalue { i32**, i32 } %142, 1
  store i32 %147, i32* %146, align 8
  store i32 0, i32* %18, align 4
  br label %148

148:                                              ; preds = %184, %141
  %149 = load i32, i32* %18, align 4
  %150 = icmp slt i32 %149, 6
  br i1 %150, label %151, label %187

151:                                              ; preds = %148
  %152 = load i32, i32* %18, align 4
  %153 = add nsw i32 %152, 1
  store i32 %153, i32* %19, align 4
  br label %154

154:                                              ; preds = %180, %151
  %155 = load i32, i32* %19, align 4
  %156 = icmp slt i32 %155, 6
  br i1 %156, label %157, label %183

157:                                              ; preds = %154
  %158 = call i32 @rand() #6
  %159 = srem i32 %158, 100
  store i32 %159, i32* %20, align 4
  %160 = load i32, i32* %20, align 4
  %161 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %17, i32 0, i32 0
  %162 = load i32**, i32*** %161, align 8
  %163 = load i32, i32* %18, align 4
  %164 = sext i32 %163 to i64
  %165 = getelementptr inbounds i32*, i32** %162, i64 %164
  %166 = load i32*, i32** %165, align 8
  %167 = load i32, i32* %19, align 4
  %168 = sext i32 %167 to i64
  %169 = getelementptr inbounds i32, i32* %166, i64 %168
  store i32 %160, i32* %169, align 4
  %170 = load i32, i32* %20, align 4
  %171 = getelementptr inbounds %struct.GraphMatrix, %struct.GraphMatrix* %17, i32 0, i32 0
  %172 = load i32**, i32*** %171, align 8
  %173 = load i32, i32* %19, align 4
  %174 = sext i32 %173 to i64
  %175 = getelementptr inbounds i32*, i32** %172, i64 %174
  %176 = load i32*, i32** %175, align 8
  %177 = load i32, i32* %18, align 4
  %178 = sext i32 %177 to i64
  %179 = getelementptr inbounds i32, i32* %176, i64 %178
  store i32 %170, i32* %179, align 4
  br label %180

180:                                              ; preds = %157
  %181 = load i32, i32* %19, align 4
  %182 = add nsw i32 %181, 1
  store i32 %182, i32* %19, align 4
  br label %154, !llvm.loop !52

183:                                              ; preds = %154
  br label %184

184:                                              ; preds = %183
  %185 = load i32, i32* %18, align 4
  %186 = add nsw i32 %185, 1
  store i32 %186, i32* %18, align 4
  br label %148, !llvm.loop !53

187:                                              ; preds = %148
  call void @floydWarshall(%struct.GraphMatrix* noundef %17)
  call void @freeGraphMatrix(%struct.GraphMatrix* noundef %17)
  store i32 100000, i32* %21, align 4
  %188 = load i32, i32* %21, align 4
  %189 = sext i32 %188 to i64
  %190 = mul i64 %189, 4
  %191 = call noalias i8* @malloc(i64 noundef %190) #6
  %192 = bitcast i8* %191 to i32*
  store i32* %192, i32** %22, align 8
  store i32 0, i32* %23, align 4
  br label %193

193:                                              ; preds = %204, %187
  %194 = load i32, i32* %23, align 4
  %195 = load i32, i32* %21, align 4
  %196 = icmp slt i32 %194, %195
  br i1 %196, label %197, label %207

197:                                              ; preds = %193
  %198 = call i32 @rand() #6
  %199 = srem i32 %198, 100
  %200 = load i32*, i32** %22, align 8
  %201 = load i32, i32* %23, align 4
  %202 = sext i32 %201 to i64
  %203 = getelementptr inbounds i32, i32* %200, i64 %202
  store i32 %199, i32* %203, align 4
  br label %204

204:                                              ; preds = %197
  %205 = load i32, i32* %23, align 4
  %206 = add nsw i32 %205, 1
  store i32 %206, i32* %23, align 4
  br label %193, !llvm.loop !54

207:                                              ; preds = %193
  %208 = load i32*, i32** %22, align 8
  %209 = load i32, i32* %21, align 4
  call void @threadedArraySum(i32* noundef %208, i32 noundef %209, i32 noundef 8)
  %210 = load i32*, i32** %22, align 8
  %211 = bitcast i32* %210 to i8*
  call void @free(i8* noundef %211) #6
  %212 = call { i64, i32** } @createRandomMatrix(i32 noundef 5, i32 noundef 3)
  %213 = bitcast %struct.Matrix* %24 to { i64, i32** }*
  %214 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %213, i32 0, i32 0
  %215 = extractvalue { i64, i32** } %212, 0
  store i64 %215, i64* %214, align 8
  %216 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %213, i32 0, i32 1
  %217 = extractvalue { i64, i32** } %212, 1
  store i32** %217, i32*** %216, align 8
  %218 = call { i64, i32** } @createRandomMatrix(i32 noundef 3, i32 noundef 5)
  %219 = bitcast %struct.Matrix* %25 to { i64, i32** }*
  %220 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %219, i32 0, i32 0
  %221 = extractvalue { i64, i32** } %218, 0
  store i64 %221, i64* %220, align 8
  %222 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %219, i32 0, i32 1
  %223 = extractvalue { i64, i32** } %218, 1
  store i32** %223, i32*** %222, align 8
  %224 = call { i64, i32** } @multiplyMatrices(%struct.Matrix* noundef %24, %struct.Matrix* noundef %25)
  %225 = bitcast %struct.Matrix* %26 to { i64, i32** }*
  %226 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %225, i32 0, i32 0
  %227 = extractvalue { i64, i32** } %224, 0
  store i64 %227, i64* %226, align 8
  %228 = getelementptr inbounds { i64, i32** }, { i64, i32** }* %225, i32 0, i32 1
  %229 = extractvalue { i64, i32** } %224, 1
  store i32** %229, i32*** %228, align 8
  %230 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %26, i32 0, i32 2
  %231 = load i32**, i32*** %230, align 8
  %232 = icmp ne i32** %231, null
  br i1 %232, label %233, label %241

233:                                              ; preds = %207
  %234 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %26, i32 0, i32 2
  %235 = load i32**, i32*** %234, align 8
  %236 = getelementptr inbounds i32*, i32** %235, i64 0
  %237 = load i32*, i32** %236, align 8
  %238 = getelementptr inbounds i32, i32* %237, i64 0
  %239 = load i32, i32* %238, align 4
  %240 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([39 x i8], [39 x i8]* @.str.16, i64 0, i64 0), i32 noundef %239)
  br label %243

241:                                              ; preds = %207
  %242 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([27 x i8], [27 x i8]* @.str.17, i64 0, i64 0))
  br label %243

243:                                              ; preds = %241, %233
  call void @freeMatrix(%struct.Matrix* noundef %24)
  call void @freeMatrix(%struct.Matrix* noundef %25)
  call void @freeMatrix(%struct.Matrix* noundef %26)
  store i32 20, i32* %27, align 4
  %244 = load i32, i32* %27, align 4
  %245 = load i32, i32* %27, align 4
  %246 = call i64 @fibonacci(i32 noundef %245)
  %247 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([22 x i8], [22 x i8]* @.str.18, i64 0, i64 0), i32 noundef %244, i64 noundef %246)
  store i32 10, i32* %28, align 4
  %248 = load i32, i32* %28, align 4
  %249 = load i32, i32* %28, align 4
  %250 = call i64 @factorial(i32 noundef %249)
  %251 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([22 x i8], [22 x i8]* @.str.19, i64 0, i64 0), i32 noundef %248, i64 noundef %250)
  store i64 1234567890123, i64* %29, align 8
  %252 = load i64, i64* %29, align 8
  %253 = load i64, i64* %29, align 8
  %254 = call i32 @isPrime(i64 noundef %253)
  %255 = icmp ne i32 %254, 0
  %256 = zext i1 %255 to i64
  %257 = select i1 %255, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.21, i64 0, i64 0), i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.22, i64 0, i64 0)
  %258 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([28 x i8], [28 x i8]* @.str.20, i64 0, i64 0), i64 noundef %252, i8* noundef %257)
  %259 = load i64, i64* %29, align 8
  call void @primeFactorization(i64 noundef %259)
  %260 = getelementptr inbounds [32 x i8], [32 x i8]* %30, i64 0, i64 0
  call void @randomStringManipulation(i8* noundef %260, i64 noundef 32)
  %261 = getelementptr inbounds [32 x i8], [32 x i8]* %30, i64 0, i64 0
  %262 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([24 x i8], [24 x i8]* @.str.23, i64 0, i64 0), i8* noundef %261)
  call void @createVariantInt(%struct.Variant* sret(%struct.Variant) align 8 %31, i32 noundef 42)
  call void @createVariantDouble(%struct.Variant* sret(%struct.Variant) align 8 %32, double noundef 3.141590e+00)
  call void @createVariantString(%struct.Variant* sret(%struct.Variant) align 8 %33, i8* noundef getelementptr inbounds ([12 x i8], [12 x i8]* @.str.24, i64 0, i64 0))
  call void @printVariant(%struct.Variant* noundef %31)
  call void @printVariant(%struct.Variant* noundef %32)
  call void @printVariant(%struct.Variant* noundef %33)
  %263 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([18 x i8], [18 x i8]* @.str.25, i64 0, i64 0))
  ret i32 0
}

; Function Attrs: nounwind
declare void @srand(i32 noundef) #1

; Function Attrs: nounwind
declare i64 @time(i64* noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noreturn "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nofree nosync nounwind willreturn }
attributes #5 = { nounwind readonly willreturn "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { nounwind }
attributes #7 = { noreturn }
attributes #8 = { nounwind readonly willreturn }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
!11 = distinct !{!11, !7}
!12 = distinct !{!12, !7}
!13 = distinct !{!13, !7}
!14 = distinct !{!14, !7}
!15 = distinct !{!15, !7}
!16 = distinct !{!16, !7}
!17 = distinct !{!17, !7}
!18 = distinct !{!18, !7}
!19 = distinct !{!19, !7}
!20 = distinct !{!20, !7}
!21 = distinct !{!21, !7}
!22 = distinct !{!22, !7}
!23 = distinct !{!23, !7}
!24 = distinct !{!24, !7}
!25 = distinct !{!25, !7}
!26 = distinct !{!26, !7}
!27 = distinct !{!27, !7}
!28 = distinct !{!28, !7}
!29 = distinct !{!29, !7}
!30 = distinct !{!30, !7}
!31 = distinct !{!31, !7}
!32 = distinct !{!32, !7}
!33 = distinct !{!33, !7}
!34 = distinct !{!34, !7}
!35 = distinct !{!35, !7}
!36 = distinct !{!36, !7}
!37 = distinct !{!37, !7}
!38 = distinct !{!38, !7}
!39 = distinct !{!39, !7}
!40 = distinct !{!40, !7}
!41 = distinct !{!41, !7}
!42 = distinct !{!42, !7}
!43 = distinct !{!43, !7}
!44 = distinct !{!44, !7}
!45 = distinct !{!45, !7}
!46 = distinct !{!46, !7}
!47 = distinct !{!47, !7}
!48 = distinct !{!48, !7}
!49 = distinct !{!49, !7}
!50 = distinct !{!50, !7}
!51 = distinct !{!51, !7}
!52 = distinct !{!52, !7}
!53 = distinct !{!53, !7}
!54 = distinct !{!54, !7}
