; ModuleID = 'test1.c'
source_filename = "test1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.Graph = type { %struct.GraphNode*, i32 }
%struct.GraphNode = type { i32*, i32 }
%struct.Matrix = type { i32**, i32, i32 }
%struct.ThreadData = type { i32, i32*, i32, i64 }
%union.pthread_attr_t = type { i64, [48 x i8] }

@globalArray = dso_local global [1024 x i32] zeroinitializer, align 16
@.str = private unnamed_addr constant [25 x i8] c"Czynniki pierwsze %lld: \00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.2 = private unnamed_addr constant [6 x i8] c"%lld \00", align 1
@.str.3 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@.str.5 = private unnamed_addr constant [37 x i8] c"Pierwsze 10 element\C3\B3w globalArray:\0A\00", align 1
@globalGraph = dso_local global %struct.Graph zeroinitializer, align 8
@.str.6 = private unnamed_addr constant [50 x i8] c"Wykonuj\C4\99 BFS w globalGraph od wierzcho\C5\82ka 0...\0A\00", align 1
@.str.7 = private unnamed_addr constant [28 x i8] c"Tablica przed sortowaniem:\0A\00", align 1
@.str.8 = private unnamed_addr constant [23 x i8] c"Tablica po MergeSort:\0A\00", align 1
@.str.9 = private unnamed_addr constant [23 x i8] c"Tablica po QuickSort:\0A\00", align 1
@.str.10 = private unnamed_addr constant [60 x i8] c"Wynik mno\C5\BCenia macierzy A(5x3) i B(3x5) to macierz %dx%d.\0A\00", align 1
@.str.11 = private unnamed_addr constant [42 x i8] c"Nie mo\C5\BCna pomno\C5\BCy\C4\87 podanych macierzy.\0A\00", align 1
@.str.12 = private unnamed_addr constant [26 x i8] c"Sum of largeArray = %lld\0A\00", align 1
@.str.13 = private unnamed_addr constant [37 x i8] c"Czy %lld jest liczb\C4\85 pierwsz\C4\85? %s\0A\00", align 1
@.str.14 = private unnamed_addr constant [4 x i8] c"TAK\00", align 1
@.str.15 = private unnamed_addr constant [4 x i8] c"NIE\00", align 1
@.str.16 = private unnamed_addr constant [22 x i8] c"fibonacci(%d) = %lld\0A\00", align 1
@.str.17 = private unnamed_addr constant [22 x i8] c"factorial(%d) = %lld\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @fillGlobalArrayRandomly() #0 {
  %1 = alloca i32, align 4
  %2 = call i64 @time(i64* noundef null) #7
  %3 = trunc i64 %2 to i32
  call void @srand(i32 noundef %3) #7
  store i32 0, i32* %1, align 4
  br label %4

4:                                                ; preds = %13, %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp slt i32 %5, 1024
  br i1 %6, label %7, label %16

7:                                                ; preds = %4
  %8 = call i32 @rand() #7
  %9 = srem i32 %8, 10000
  %10 = load i32, i32* %1, align 4
  %11 = sext i32 %10 to i64
  %12 = getelementptr inbounds [1024 x i32], [1024 x i32]* @globalArray, i64 0, i64 %11
  store i32 %9, i32* %12, align 4
  br label %13

13:                                               ; preds = %7
  %14 = load i32, i32* %1, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %1, align 4
  br label %4, !llvm.loop !6

16:                                               ; preds = %4
  ret void
}

; Function Attrs: nounwind
declare void @srand(i32 noundef) #1

; Function Attrs: nounwind
declare i64 @time(i64* noundef) #1

; Function Attrs: nounwind
declare i32 @rand() #1

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
define dso_local { %struct.GraphNode*, i32 } @createRandomGraph(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.Graph, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  %8 = load i32, i32* %4, align 4
  %9 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 1
  store i32 %8, i32* %9, align 8
  %10 = load i32, i32* %4, align 4
  %11 = sext i32 %10 to i64
  %12 = mul i64 16, %11
  %13 = call noalias i8* @malloc(i64 noundef %12) #7
  %14 = bitcast i8* %13 to %struct.GraphNode*
  %15 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  store %struct.GraphNode* %14, %struct.GraphNode** %15, align 8
  store i32 0, i32* %6, align 4
  br label %16

16:                                               ; preds = %76, %2
  %17 = load i32, i32* %6, align 4
  %18 = load i32, i32* %4, align 4
  %19 = icmp slt i32 %17, %18
  br i1 %19, label %20, label %79

20:                                               ; preds = %16
  %21 = call i32 @rand() #7
  %22 = load i32, i32* %5, align 4
  %23 = add nsw i32 %22, 1
  %24 = srem i32 %21, %23
  %25 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  %26 = load %struct.GraphNode*, %struct.GraphNode** %25, align 8
  %27 = load i32, i32* %6, align 4
  %28 = sext i32 %27 to i64
  %29 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %26, i64 %28
  %30 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %29, i32 0, i32 1
  store i32 %24, i32* %30, align 8
  %31 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  %32 = load %struct.GraphNode*, %struct.GraphNode** %31, align 8
  %33 = load i32, i32* %6, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %32, i64 %34
  %36 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %35, i32 0, i32 1
  %37 = load i32, i32* %36, align 8
  %38 = sext i32 %37 to i64
  %39 = mul i64 4, %38
  %40 = call noalias i8* @malloc(i64 noundef %39) #7
  %41 = bitcast i8* %40 to i32*
  %42 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  %43 = load %struct.GraphNode*, %struct.GraphNode** %42, align 8
  %44 = load i32, i32* %6, align 4
  %45 = sext i32 %44 to i64
  %46 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %43, i64 %45
  %47 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %46, i32 0, i32 0
  store i32* %41, i32** %47, align 8
  store i32 0, i32* %7, align 4
  br label %48

48:                                               ; preds = %72, %20
  %49 = load i32, i32* %7, align 4
  %50 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  %51 = load %struct.GraphNode*, %struct.GraphNode** %50, align 8
  %52 = load i32, i32* %6, align 4
  %53 = sext i32 %52 to i64
  %54 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %51, i64 %53
  %55 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %54, i32 0, i32 1
  %56 = load i32, i32* %55, align 8
  %57 = icmp slt i32 %49, %56
  br i1 %57, label %58, label %75

58:                                               ; preds = %48
  %59 = call i32 @rand() #7
  %60 = load i32, i32* %4, align 4
  %61 = srem i32 %59, %60
  %62 = getelementptr inbounds %struct.Graph, %struct.Graph* %3, i32 0, i32 0
  %63 = load %struct.GraphNode*, %struct.GraphNode** %62, align 8
  %64 = load i32, i32* %6, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %63, i64 %65
  %67 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %66, i32 0, i32 0
  %68 = load i32*, i32** %67, align 8
  %69 = load i32, i32* %7, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds i32, i32* %68, i64 %70
  store i32 %61, i32* %71, align 4
  br label %72

72:                                               ; preds = %58
  %73 = load i32, i32* %7, align 4
  %74 = add nsw i32 %73, 1
  store i32 %74, i32* %7, align 4
  br label %48, !llvm.loop !8

75:                                               ; preds = %48
  br label %76

76:                                               ; preds = %75
  %77 = load i32, i32* %6, align 4
  %78 = add nsw i32 %77, 1
  store i32 %78, i32* %6, align 4
  br label %16, !llvm.loop !9

79:                                               ; preds = %16
  %80 = bitcast %struct.Graph* %3 to { %struct.GraphNode*, i32 }*
  %81 = load { %struct.GraphNode*, i32 }, { %struct.GraphNode*, i32 }* %80, align 8
  ret { %struct.GraphNode*, i32 } %81
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @freeGraph(%struct.Graph* noundef %0) #0 {
  %2 = alloca %struct.Graph*, align 8
  %3 = alloca i32, align 4
  store %struct.Graph* %0, %struct.Graph** %2, align 8
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %20, %1
  %5 = load i32, i32* %3, align 4
  %6 = load %struct.Graph*, %struct.Graph** %2, align 8
  %7 = getelementptr inbounds %struct.Graph, %struct.Graph* %6, i32 0, i32 1
  %8 = load i32, i32* %7, align 8
  %9 = icmp slt i32 %5, %8
  br i1 %9, label %10, label %23

10:                                               ; preds = %4
  %11 = load %struct.Graph*, %struct.Graph** %2, align 8
  %12 = getelementptr inbounds %struct.Graph, %struct.Graph* %11, i32 0, i32 0
  %13 = load %struct.GraphNode*, %struct.GraphNode** %12, align 8
  %14 = load i32, i32* %3, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %13, i64 %15
  %17 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %16, i32 0, i32 0
  %18 = load i32*, i32** %17, align 8
  %19 = bitcast i32* %18 to i8*
  call void @free(i8* noundef %19) #7
  br label %20

20:                                               ; preds = %10
  %21 = load i32, i32* %3, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, i32* %3, align 4
  br label %4, !llvm.loop !10

23:                                               ; preds = %4
  %24 = load %struct.Graph*, %struct.Graph** %2, align 8
  %25 = getelementptr inbounds %struct.Graph, %struct.Graph* %24, i32 0, i32 0
  %26 = load %struct.GraphNode*, %struct.GraphNode** %25, align 8
  %27 = bitcast %struct.GraphNode* %26 to i8*
  call void @free(i8* noundef %27) #7
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @bfs(%struct.Graph* noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.Graph*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i8*, align 8
  %6 = alloca i64, align 8
  %7 = alloca [1000 x i32], align 16
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  store %struct.Graph* %0, %struct.Graph** %3, align 8
  store i32 %1, i32* %4, align 4
  %13 = load i32, i32* %4, align 4
  %14 = icmp slt i32 %13, 0
  br i1 %14, label %21, label %15

15:                                               ; preds = %2
  %16 = load i32, i32* %4, align 4
  %17 = load %struct.Graph*, %struct.Graph** %3, align 8
  %18 = getelementptr inbounds %struct.Graph, %struct.Graph* %17, i32 0, i32 1
  %19 = load i32, i32* %18, align 8
  %20 = icmp sge i32 %16, %19
  br i1 %20, label %21, label %22

21:                                               ; preds = %15, %2
  br label %94

22:                                               ; preds = %15
  %23 = load %struct.Graph*, %struct.Graph** %3, align 8
  %24 = getelementptr inbounds %struct.Graph, %struct.Graph* %23, i32 0, i32 1
  %25 = load i32, i32* %24, align 8
  %26 = zext i32 %25 to i64
  %27 = call i8* @llvm.stacksave()
  store i8* %27, i8** %5, align 8
  %28 = alloca i32, i64 %26, align 16
  store i64 %26, i64* %6, align 8
  %29 = bitcast i32* %28 to i8*
  %30 = mul nuw i64 4, %26
  call void @llvm.memset.p0i8.i64(i8* align 16 %29, i8 0, i64 %30, i1 false)
  store i32 0, i32* %8, align 4
  store i32 0, i32* %9, align 4
  %31 = load i32, i32* %4, align 4
  %32 = load i32, i32* %9, align 4
  %33 = add nsw i32 %32, 1
  store i32 %33, i32* %9, align 4
  %34 = sext i32 %32 to i64
  %35 = getelementptr inbounds [1000 x i32], [1000 x i32]* %7, i64 0, i64 %34
  store i32 %31, i32* %35, align 4
  %36 = load i32, i32* %4, align 4
  %37 = sext i32 %36 to i64
  %38 = getelementptr inbounds i32, i32* %28, i64 %37
  store i32 1, i32* %38, align 4
  br label %39

39:                                               ; preds = %91, %22
  %40 = load i32, i32* %8, align 4
  %41 = load i32, i32* %9, align 4
  %42 = icmp slt i32 %40, %41
  br i1 %42, label %43, label %92

43:                                               ; preds = %39
  %44 = load i32, i32* %8, align 4
  %45 = add nsw i32 %44, 1
  store i32 %45, i32* %8, align 4
  %46 = sext i32 %44 to i64
  %47 = getelementptr inbounds [1000 x i32], [1000 x i32]* %7, i64 0, i64 %46
  %48 = load i32, i32* %47, align 4
  store i32 %48, i32* %10, align 4
  store i32 0, i32* %11, align 4
  br label %49

49:                                               ; preds = %88, %43
  %50 = load i32, i32* %11, align 4
  %51 = load %struct.Graph*, %struct.Graph** %3, align 8
  %52 = getelementptr inbounds %struct.Graph, %struct.Graph* %51, i32 0, i32 0
  %53 = load %struct.GraphNode*, %struct.GraphNode** %52, align 8
  %54 = load i32, i32* %10, align 4
  %55 = sext i32 %54 to i64
  %56 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %53, i64 %55
  %57 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %56, i32 0, i32 1
  %58 = load i32, i32* %57, align 8
  %59 = icmp slt i32 %50, %58
  br i1 %59, label %60, label %91

60:                                               ; preds = %49
  %61 = load %struct.Graph*, %struct.Graph** %3, align 8
  %62 = getelementptr inbounds %struct.Graph, %struct.Graph* %61, i32 0, i32 0
  %63 = load %struct.GraphNode*, %struct.GraphNode** %62, align 8
  %64 = load i32, i32* %10, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %63, i64 %65
  %67 = getelementptr inbounds %struct.GraphNode, %struct.GraphNode* %66, i32 0, i32 0
  %68 = load i32*, i32** %67, align 8
  %69 = load i32, i32* %11, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds i32, i32* %68, i64 %70
  %72 = load i32, i32* %71, align 4
  store i32 %72, i32* %12, align 4
  %73 = load i32, i32* %12, align 4
  %74 = sext i32 %73 to i64
  %75 = getelementptr inbounds i32, i32* %28, i64 %74
  %76 = load i32, i32* %75, align 4
  %77 = icmp ne i32 %76, 0
  br i1 %77, label %87, label %78

78:                                               ; preds = %60
  %79 = load i32, i32* %12, align 4
  %80 = sext i32 %79 to i64
  %81 = getelementptr inbounds i32, i32* %28, i64 %80
  store i32 1, i32* %81, align 4
  %82 = load i32, i32* %12, align 4
  %83 = load i32, i32* %9, align 4
  %84 = add nsw i32 %83, 1
  store i32 %84, i32* %9, align 4
  %85 = sext i32 %83 to i64
  %86 = getelementptr inbounds [1000 x i32], [1000 x i32]* %7, i64 0, i64 %85
  store i32 %82, i32* %86, align 4
  br label %87

87:                                               ; preds = %78, %60
  br label %88

88:                                               ; preds = %87
  %89 = load i32, i32* %11, align 4
  %90 = add nsw i32 %89, 1
  store i32 %90, i32* %11, align 4
  br label %49, !llvm.loop !11

91:                                               ; preds = %49
  br label %39, !llvm.loop !12

92:                                               ; preds = %39
  %93 = load i8*, i8** %5, align 8
  call void @llvm.stackrestore(i8* %93)
  br label %94

94:                                               ; preds = %92, %21
  ret void
}

; Function Attrs: nofree nosync nounwind willreturn
declare i8* @llvm.stacksave() #2

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

; Function Attrs: nofree nosync nounwind willreturn
declare void @llvm.stackrestore(i8*) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @merge(i32* noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) #0 {
  %5 = alloca i32*, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32*, align 8
  %15 = alloca i32*, align 8
  store i32* %0, i32** %5, align 8
  store i32 %1, i32* %6, align 4
  store i32 %2, i32* %7, align 4
  store i32 %3, i32* %8, align 4
  %16 = load i32, i32* %7, align 4
  %17 = load i32, i32* %6, align 4
  %18 = sub nsw i32 %16, %17
  %19 = add nsw i32 %18, 1
  store i32 %19, i32* %12, align 4
  %20 = load i32, i32* %8, align 4
  %21 = load i32, i32* %7, align 4
  %22 = sub nsw i32 %20, %21
  store i32 %22, i32* %13, align 4
  %23 = load i32, i32* %12, align 4
  %24 = sext i32 %23 to i64
  %25 = mul i64 4, %24
  %26 = call noalias i8* @malloc(i64 noundef %25) #7
  %27 = bitcast i8* %26 to i32*
  store i32* %27, i32** %14, align 8
  %28 = load i32, i32* %13, align 4
  %29 = sext i32 %28 to i64
  %30 = mul i64 4, %29
  %31 = call noalias i8* @malloc(i64 noundef %30) #7
  %32 = bitcast i8* %31 to i32*
  store i32* %32, i32** %15, align 8
  store i32 0, i32* %9, align 4
  br label %33

33:                                               ; preds = %49, %4
  %34 = load i32, i32* %9, align 4
  %35 = load i32, i32* %12, align 4
  %36 = icmp slt i32 %34, %35
  br i1 %36, label %37, label %52

37:                                               ; preds = %33
  %38 = load i32*, i32** %5, align 8
  %39 = load i32, i32* %6, align 4
  %40 = load i32, i32* %9, align 4
  %41 = add nsw i32 %39, %40
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32, i32* %38, i64 %42
  %44 = load i32, i32* %43, align 4
  %45 = load i32*, i32** %14, align 8
  %46 = load i32, i32* %9, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds i32, i32* %45, i64 %47
  store i32 %44, i32* %48, align 4
  br label %49

49:                                               ; preds = %37
  %50 = load i32, i32* %9, align 4
  %51 = add nsw i32 %50, 1
  store i32 %51, i32* %9, align 4
  br label %33, !llvm.loop !13

52:                                               ; preds = %33
  store i32 0, i32* %10, align 4
  br label %53

53:                                               ; preds = %70, %52
  %54 = load i32, i32* %10, align 4
  %55 = load i32, i32* %13, align 4
  %56 = icmp slt i32 %54, %55
  br i1 %56, label %57, label %73

57:                                               ; preds = %53
  %58 = load i32*, i32** %5, align 8
  %59 = load i32, i32* %7, align 4
  %60 = add nsw i32 %59, 1
  %61 = load i32, i32* %10, align 4
  %62 = add nsw i32 %60, %61
  %63 = sext i32 %62 to i64
  %64 = getelementptr inbounds i32, i32* %58, i64 %63
  %65 = load i32, i32* %64, align 4
  %66 = load i32*, i32** %15, align 8
  %67 = load i32, i32* %10, align 4
  %68 = sext i32 %67 to i64
  %69 = getelementptr inbounds i32, i32* %66, i64 %68
  store i32 %65, i32* %69, align 4
  br label %70

70:                                               ; preds = %57
  %71 = load i32, i32* %10, align 4
  %72 = add nsw i32 %71, 1
  store i32 %72, i32* %10, align 4
  br label %53, !llvm.loop !14

73:                                               ; preds = %53
  store i32 0, i32* %9, align 4
  store i32 0, i32* %10, align 4
  %74 = load i32, i32* %6, align 4
  store i32 %74, i32* %11, align 4
  br label %75

75:                                               ; preds = %121, %73
  %76 = load i32, i32* %9, align 4
  %77 = load i32, i32* %12, align 4
  %78 = icmp slt i32 %76, %77
  br i1 %78, label %79, label %83

79:                                               ; preds = %75
  %80 = load i32, i32* %10, align 4
  %81 = load i32, i32* %13, align 4
  %82 = icmp slt i32 %80, %81
  br label %83

83:                                               ; preds = %79, %75
  %84 = phi i1 [ false, %75 ], [ %82, %79 ]
  br i1 %84, label %85, label %122

85:                                               ; preds = %83
  %86 = load i32*, i32** %14, align 8
  %87 = load i32, i32* %9, align 4
  %88 = sext i32 %87 to i64
  %89 = getelementptr inbounds i32, i32* %86, i64 %88
  %90 = load i32, i32* %89, align 4
  %91 = load i32*, i32** %15, align 8
  %92 = load i32, i32* %10, align 4
  %93 = sext i32 %92 to i64
  %94 = getelementptr inbounds i32, i32* %91, i64 %93
  %95 = load i32, i32* %94, align 4
  %96 = icmp sle i32 %90, %95
  br i1 %96, label %97, label %109

97:                                               ; preds = %85
  %98 = load i32*, i32** %14, align 8
  %99 = load i32, i32* %9, align 4
  %100 = add nsw i32 %99, 1
  store i32 %100, i32* %9, align 4
  %101 = sext i32 %99 to i64
  %102 = getelementptr inbounds i32, i32* %98, i64 %101
  %103 = load i32, i32* %102, align 4
  %104 = load i32*, i32** %5, align 8
  %105 = load i32, i32* %11, align 4
  %106 = add nsw i32 %105, 1
  store i32 %106, i32* %11, align 4
  %107 = sext i32 %105 to i64
  %108 = getelementptr inbounds i32, i32* %104, i64 %107
  store i32 %103, i32* %108, align 4
  br label %121

109:                                              ; preds = %85
  %110 = load i32*, i32** %15, align 8
  %111 = load i32, i32* %10, align 4
  %112 = add nsw i32 %111, 1
  store i32 %112, i32* %10, align 4
  %113 = sext i32 %111 to i64
  %114 = getelementptr inbounds i32, i32* %110, i64 %113
  %115 = load i32, i32* %114, align 4
  %116 = load i32*, i32** %5, align 8
  %117 = load i32, i32* %11, align 4
  %118 = add nsw i32 %117, 1
  store i32 %118, i32* %11, align 4
  %119 = sext i32 %117 to i64
  %120 = getelementptr inbounds i32, i32* %116, i64 %119
  store i32 %115, i32* %120, align 4
  br label %121

121:                                              ; preds = %109, %97
  br label %75, !llvm.loop !15

122:                                              ; preds = %83
  br label %123

123:                                              ; preds = %127, %122
  %124 = load i32, i32* %9, align 4
  %125 = load i32, i32* %12, align 4
  %126 = icmp slt i32 %124, %125
  br i1 %126, label %127, label %139

127:                                              ; preds = %123
  %128 = load i32*, i32** %14, align 8
  %129 = load i32, i32* %9, align 4
  %130 = add nsw i32 %129, 1
  store i32 %130, i32* %9, align 4
  %131 = sext i32 %129 to i64
  %132 = getelementptr inbounds i32, i32* %128, i64 %131
  %133 = load i32, i32* %132, align 4
  %134 = load i32*, i32** %5, align 8
  %135 = load i32, i32* %11, align 4
  %136 = add nsw i32 %135, 1
  store i32 %136, i32* %11, align 4
  %137 = sext i32 %135 to i64
  %138 = getelementptr inbounds i32, i32* %134, i64 %137
  store i32 %133, i32* %138, align 4
  br label %123, !llvm.loop !16

139:                                              ; preds = %123
  br label %140

140:                                              ; preds = %144, %139
  %141 = load i32, i32* %10, align 4
  %142 = load i32, i32* %13, align 4
  %143 = icmp slt i32 %141, %142
  br i1 %143, label %144, label %156

144:                                              ; preds = %140
  %145 = load i32*, i32** %15, align 8
  %146 = load i32, i32* %10, align 4
  %147 = add nsw i32 %146, 1
  store i32 %147, i32* %10, align 4
  %148 = sext i32 %146 to i64
  %149 = getelementptr inbounds i32, i32* %145, i64 %148
  %150 = load i32, i32* %149, align 4
  %151 = load i32*, i32** %5, align 8
  %152 = load i32, i32* %11, align 4
  %153 = add nsw i32 %152, 1
  store i32 %153, i32* %11, align 4
  %154 = sext i32 %152 to i64
  %155 = getelementptr inbounds i32, i32* %151, i64 %154
  store i32 %150, i32* %155, align 4
  br label %140, !llvm.loop !17

156:                                              ; preds = %140
  %157 = load i32*, i32** %14, align 8
  %158 = bitcast i32* %157 to i8*
  call void @free(i8* noundef %158) #7
  %159 = load i32*, i32** %15, align 8
  %160 = bitcast i32* %159 to i8*
  call void @free(i8* noundef %160) #7
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

20:                                               ; preds = %55, %3
  %21 = load i32, i32* %9, align 4
  %22 = load i32, i32* %6, align 4
  %23 = icmp slt i32 %21, %22
  br i1 %23, label %24, label %58

24:                                               ; preds = %20
  %25 = load i32*, i32** %4, align 8
  %26 = load i32, i32* %9, align 4
  %27 = sext i32 %26 to i64
  %28 = getelementptr inbounds i32, i32* %25, i64 %27
  %29 = load i32, i32* %28, align 4
  %30 = load i32, i32* %7, align 4
  %31 = icmp slt i32 %29, %30
  br i1 %31, label %32, label %54

32:                                               ; preds = %24
  %33 = load i32, i32* %8, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %8, align 4
  %35 = load i32*, i32** %4, align 8
  %36 = load i32, i32* %8, align 4
  %37 = sext i32 %36 to i64
  %38 = getelementptr inbounds i32, i32* %35, i64 %37
  %39 = load i32, i32* %38, align 4
  store i32 %39, i32* %10, align 4
  %40 = load i32*, i32** %4, align 8
  %41 = load i32, i32* %9, align 4
  %42 = sext i32 %41 to i64
  %43 = getelementptr inbounds i32, i32* %40, i64 %42
  %44 = load i32, i32* %43, align 4
  %45 = load i32*, i32** %4, align 8
  %46 = load i32, i32* %8, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds i32, i32* %45, i64 %47
  store i32 %44, i32* %48, align 4
  %49 = load i32, i32* %10, align 4
  %50 = load i32*, i32** %4, align 8
  %51 = load i32, i32* %9, align 4
  %52 = sext i32 %51 to i64
  %53 = getelementptr inbounds i32, i32* %50, i64 %52
  store i32 %49, i32* %53, align 4
  br label %54

54:                                               ; preds = %32, %24
  br label %55

55:                                               ; preds = %54
  %56 = load i32, i32* %9, align 4
  %57 = add nsw i32 %56, 1
  store i32 %57, i32* %9, align 4
  br label %20, !llvm.loop !18

58:                                               ; preds = %20
  %59 = load i32*, i32** %4, align 8
  %60 = load i32, i32* %8, align 4
  %61 = add nsw i32 %60, 1
  %62 = sext i32 %61 to i64
  %63 = getelementptr inbounds i32, i32* %59, i64 %62
  %64 = load i32, i32* %63, align 4
  store i32 %64, i32* %11, align 4
  %65 = load i32*, i32** %4, align 8
  %66 = load i32, i32* %6, align 4
  %67 = sext i32 %66 to i64
  %68 = getelementptr inbounds i32, i32* %65, i64 %67
  %69 = load i32, i32* %68, align 4
  %70 = load i32*, i32** %4, align 8
  %71 = load i32, i32* %8, align 4
  %72 = add nsw i32 %71, 1
  %73 = sext i32 %72 to i64
  %74 = getelementptr inbounds i32, i32* %70, i64 %73
  store i32 %69, i32* %74, align 4
  %75 = load i32, i32* %11, align 4
  %76 = load i32*, i32** %4, align 8
  %77 = load i32, i32* %6, align 4
  %78 = sext i32 %77 to i64
  %79 = getelementptr inbounds i32, i32* %76, i64 %78
  store i32 %75, i32* %79, align 4
  %80 = load i32, i32* %8, align 4
  %81 = add nsw i32 %80, 1
  ret i32 %81
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
define dso_local { i32**, i64 } @createMatrix(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca %struct.Matrix, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  %8 = load i32, i32* %4, align 4
  %9 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  store i32 %8, i32* %9, align 8
  %10 = load i32, i32* %5, align 4
  %11 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  store i32 %10, i32* %11, align 4
  %12 = load i32, i32* %4, align 4
  %13 = sext i32 %12 to i64
  %14 = mul i64 %13, 8
  %15 = call noalias i8* @malloc(i64 noundef %14) #7
  %16 = bitcast i8* %15 to i32**
  %17 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
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
  %26 = call noalias i8* @malloc(i64 noundef %25) #7
  %27 = bitcast i8* %26 to i32*
  %28 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
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
  %38 = call i32 @rand() #7
  %39 = srem i32 %38, 10
  %40 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
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
  br label %33, !llvm.loop !19

52:                                               ; preds = %33
  br label %53

53:                                               ; preds = %52
  %54 = load i32, i32* %6, align 4
  %55 = add nsw i32 %54, 1
  store i32 %55, i32* %6, align 4
  br label %18, !llvm.loop !20

56:                                               ; preds = %18
  %57 = bitcast %struct.Matrix* %3 to { i32**, i64 }*
  %58 = load { i32**, i64 }, { i32**, i64 }* %57, align 8
  ret { i32**, i64 } %58
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
  %7 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %6, i32 0, i32 1
  %8 = load i32, i32* %7, align 8
  %9 = icmp slt i32 %5, %8
  br i1 %9, label %10, label %22

10:                                               ; preds = %4
  %11 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %12 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %11, i32 0, i32 0
  %13 = load i32**, i32*** %12, align 8
  %14 = load i32, i32* %3, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32*, i32** %13, i64 %15
  %17 = load i32*, i32** %16, align 8
  %18 = bitcast i32* %17 to i8*
  call void @free(i8* noundef %18) #7
  br label %19

19:                                               ; preds = %10
  %20 = load i32, i32* %3, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %3, align 4
  br label %4, !llvm.loop !21

22:                                               ; preds = %4
  %23 = load %struct.Matrix*, %struct.Matrix** %2, align 8
  %24 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %23, i32 0, i32 0
  %25 = load i32**, i32*** %24, align 8
  %26 = bitcast i32** %25 to i8*
  call void @free(i8* noundef %26) #7
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local { i32**, i64 } @multiplyMatrices(%struct.Matrix* noundef %0, %struct.Matrix* noundef %1) #0 {
  %3 = alloca %struct.Matrix, align 8
  %4 = alloca %struct.Matrix*, align 8
  %5 = alloca %struct.Matrix*, align 8
  %6 = alloca %struct.Matrix, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  store %struct.Matrix* %0, %struct.Matrix** %4, align 8
  store %struct.Matrix* %1, %struct.Matrix** %5, align 8
  %11 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %12 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %11, i32 0, i32 2
  %13 = load i32, i32* %12, align 4
  %14 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %15 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %14, i32 0, i32 1
  %16 = load i32, i32* %15, align 8
  %17 = icmp ne i32 %13, %16
  br i1 %17, label %18, label %22

18:                                               ; preds = %2
  %19 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 1
  store i32 0, i32* %19, align 8
  %20 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 2
  store i32 0, i32* %20, align 4
  %21 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  store i32** null, i32*** %21, align 8
  br label %108

22:                                               ; preds = %2
  %23 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %24 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %23, i32 0, i32 1
  %25 = load i32, i32* %24, align 8
  %26 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %27 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %26, i32 0, i32 2
  %28 = load i32, i32* %27, align 4
  %29 = call { i32**, i64 } @createMatrix(i32 noundef %25, i32 noundef %28)
  %30 = bitcast %struct.Matrix* %6 to { i32**, i64 }*
  %31 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %30, i32 0, i32 0
  %32 = extractvalue { i32**, i64 } %29, 0
  store i32** %32, i32*** %31, align 8
  %33 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %30, i32 0, i32 1
  %34 = extractvalue { i32**, i64 } %29, 1
  store i64 %34, i64* %33, align 8
  %35 = bitcast %struct.Matrix* %3 to i8*
  %36 = bitcast %struct.Matrix* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %35, i8* align 8 %36, i64 16, i1 false)
  store i32 0, i32* %7, align 4
  br label %37

37:                                               ; preds = %104, %22
  %38 = load i32, i32* %7, align 4
  %39 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %40 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %39, i32 0, i32 1
  %41 = load i32, i32* %40, align 8
  %42 = icmp slt i32 %38, %41
  br i1 %42, label %43, label %107

43:                                               ; preds = %37
  store i32 0, i32* %8, align 4
  br label %44

44:                                               ; preds = %100, %43
  %45 = load i32, i32* %8, align 4
  %46 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %47 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %46, i32 0, i32 2
  %48 = load i32, i32* %47, align 4
  %49 = icmp slt i32 %45, %48
  br i1 %49, label %50, label %103

50:                                               ; preds = %44
  store i64 0, i64* %9, align 8
  store i32 0, i32* %10, align 4
  br label %51

51:                                               ; preds = %85, %50
  %52 = load i32, i32* %10, align 4
  %53 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %54 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %53, i32 0, i32 2
  %55 = load i32, i32* %54, align 4
  %56 = icmp slt i32 %52, %55
  br i1 %56, label %57, label %88

57:                                               ; preds = %51
  %58 = load %struct.Matrix*, %struct.Matrix** %4, align 8
  %59 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %58, i32 0, i32 0
  %60 = load i32**, i32*** %59, align 8
  %61 = load i32, i32* %7, align 4
  %62 = sext i32 %61 to i64
  %63 = getelementptr inbounds i32*, i32** %60, i64 %62
  %64 = load i32*, i32** %63, align 8
  %65 = load i32, i32* %10, align 4
  %66 = sext i32 %65 to i64
  %67 = getelementptr inbounds i32, i32* %64, i64 %66
  %68 = load i32, i32* %67, align 4
  %69 = sext i32 %68 to i64
  %70 = load %struct.Matrix*, %struct.Matrix** %5, align 8
  %71 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %70, i32 0, i32 0
  %72 = load i32**, i32*** %71, align 8
  %73 = load i32, i32* %10, align 4
  %74 = sext i32 %73 to i64
  %75 = getelementptr inbounds i32*, i32** %72, i64 %74
  %76 = load i32*, i32** %75, align 8
  %77 = load i32, i32* %8, align 4
  %78 = sext i32 %77 to i64
  %79 = getelementptr inbounds i32, i32* %76, i64 %78
  %80 = load i32, i32* %79, align 4
  %81 = sext i32 %80 to i64
  %82 = mul nsw i64 %69, %81
  %83 = load i64, i64* %9, align 8
  %84 = add nsw i64 %83, %82
  store i64 %84, i64* %9, align 8
  br label %85

85:                                               ; preds = %57
  %86 = load i32, i32* %10, align 4
  %87 = add nsw i32 %86, 1
  store i32 %87, i32* %10, align 4
  br label %51, !llvm.loop !22

88:                                               ; preds = %51
  %89 = load i64, i64* %9, align 8
  %90 = trunc i64 %89 to i32
  %91 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %3, i32 0, i32 0
  %92 = load i32**, i32*** %91, align 8
  %93 = load i32, i32* %7, align 4
  %94 = sext i32 %93 to i64
  %95 = getelementptr inbounds i32*, i32** %92, i64 %94
  %96 = load i32*, i32** %95, align 8
  %97 = load i32, i32* %8, align 4
  %98 = sext i32 %97 to i64
  %99 = getelementptr inbounds i32, i32* %96, i64 %98
  store i32 %90, i32* %99, align 4
  br label %100

100:                                              ; preds = %88
  %101 = load i32, i32* %8, align 4
  %102 = add nsw i32 %101, 1
  store i32 %102, i32* %8, align 4
  br label %44, !llvm.loop !23

103:                                              ; preds = %44
  br label %104

104:                                              ; preds = %103
  %105 = load i32, i32* %7, align 4
  %106 = add nsw i32 %105, 1
  store i32 %106, i32* %7, align 4
  br label %37, !llvm.loop !24

107:                                              ; preds = %37
  br label %108

108:                                              ; preds = %107, %18
  %109 = bitcast %struct.Matrix* %3 to { i32**, i64 }*
  %110 = load { i32**, i64 }, { i32**, i64 }* %109, align 8
  ret { i32**, i64 } %110
}

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @threadFunction(i8* noundef %0) #0 {
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
  br label %8, !llvm.loop !25

28:                                               ; preds = %8
  %29 = load i64, i64* %4, align 8
  %30 = load %struct.ThreadData*, %struct.ThreadData** %3, align 8
  %31 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %30, i32 0, i32 3
  store i64 %29, i64* %31, align 8
  call void @pthread_exit(i8* noundef null) #8
  unreachable
}

; Function Attrs: noreturn
declare void @pthread_exit(i8* noundef) #5

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
  br label %22, !llvm.loop !26

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
  %5 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([25 x i8], [25 x i8]* @.str, i64 0, i64 0), i64 noundef %4)
  br label %6

6:                                                ; preds = %10, %1
  %7 = load i64, i64* %2, align 8
  %8 = srem i64 %7, 2
  %9 = icmp eq i64 %8, 0
  br i1 %9, label %10, label %14

10:                                               ; preds = %6
  %11 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef 2)
  %12 = load i64, i64* %2, align 8
  %13 = sdiv i64 %12, 2
  store i64 %13, i64* %2, align 8
  br label %6, !llvm.loop !27

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
  %29 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i64 0, i64 0), i64 noundef %28)
  %30 = load i64, i64* %3, align 8
  %31 = load i64, i64* %2, align 8
  %32 = sdiv i64 %31, %30
  store i64 %32, i64* %2, align 8
  br label %22, !llvm.loop !28

33:                                               ; preds = %22
  br label %34

34:                                               ; preds = %33
  %35 = load i64, i64* %3, align 8
  %36 = add nsw i64 %35, 2
  store i64 %36, i64* %3, align 8
  br label %15, !llvm.loop !29

37:                                               ; preds = %15
  %38 = load i64, i64* %2, align 8
  %39 = icmp sgt i64 %38, 2
  br i1 %39, label %40, label %43

40:                                               ; preds = %37
  %41 = load i64, i64* %2, align 8
  %42 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.3, i64 0, i64 0), i64 noundef %41)
  br label %43

43:                                               ; preds = %40, %37
  %44 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  ret void
}

declare i32 @printf(i8* noundef, ...) #6

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca %struct.Graph, align 8
  %4 = alloca [10 x i32], align 16
  %5 = alloca [10 x i32], align 16
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca %struct.Matrix, align 8
  %12 = alloca %struct.Matrix, align 8
  %13 = alloca %struct.Matrix, align 8
  %14 = alloca i32, align 4
  %15 = alloca i32*, align 8
  %16 = alloca i32, align 4
  %17 = alloca [4 x i64], align 16
  %18 = alloca [4 x %struct.ThreadData], align 16
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i64, align 8
  %22 = alloca i32, align 4
  %23 = alloca i64, align 8
  %24 = alloca i32, align 4
  %25 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %26 = call i64 @time(i64* noundef null) #7
  %27 = trunc i64 %26 to i32
  call void @srand(i32 noundef %27) #7
  call void @fillGlobalArrayRandomly()
  %28 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([37 x i8], [37 x i8]* @.str.5, i64 0, i64 0))
  store i32 0, i32* %2, align 4
  br label %29

29:                                               ; preds = %38, %0
  %30 = load i32, i32* %2, align 4
  %31 = icmp slt i32 %30, 10
  br i1 %31, label %32, label %41

32:                                               ; preds = %29
  %33 = load i32, i32* %2, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], [1024 x i32]* @globalArray, i64 0, i64 %34
  %36 = load i32, i32* %35, align 4
  %37 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %36)
  br label %38

38:                                               ; preds = %32
  %39 = load i32, i32* %2, align 4
  %40 = add nsw i32 %39, 1
  store i32 %40, i32* %2, align 4
  br label %29, !llvm.loop !30

41:                                               ; preds = %29
  %42 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  %43 = call { %struct.GraphNode*, i32 } @createRandomGraph(i32 noundef 20, i32 noundef 5)
  %44 = bitcast %struct.Graph* %3 to { %struct.GraphNode*, i32 }*
  %45 = getelementptr inbounds { %struct.GraphNode*, i32 }, { %struct.GraphNode*, i32 }* %44, i32 0, i32 0
  %46 = extractvalue { %struct.GraphNode*, i32 } %43, 0
  store %struct.GraphNode* %46, %struct.GraphNode** %45, align 8
  %47 = getelementptr inbounds { %struct.GraphNode*, i32 }, { %struct.GraphNode*, i32 }* %44, i32 0, i32 1
  %48 = extractvalue { %struct.GraphNode*, i32 } %43, 1
  store i32 %48, i32* %47, align 8
  %49 = bitcast %struct.Graph* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 bitcast (%struct.Graph* @globalGraph to i8*), i8* align 8 %49, i64 16, i1 false)
  %50 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([50 x i8], [50 x i8]* @.str.6, i64 0, i64 0))
  call void @bfs(%struct.Graph* noundef @globalGraph, i32 noundef 0)
  store i32 0, i32* %6, align 4
  br label %51

51:                                               ; preds = %65, %41
  %52 = load i32, i32* %6, align 4
  %53 = icmp slt i32 %52, 10
  br i1 %53, label %54, label %68

54:                                               ; preds = %51
  %55 = call i32 @rand() #7
  %56 = srem i32 %55, 100
  store i32 %56, i32* %7, align 4
  %57 = load i32, i32* %7, align 4
  %58 = load i32, i32* %6, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds [10 x i32], [10 x i32]* %4, i64 0, i64 %59
  store i32 %57, i32* %60, align 4
  %61 = load i32, i32* %7, align 4
  %62 = load i32, i32* %6, align 4
  %63 = sext i32 %62 to i64
  %64 = getelementptr inbounds [10 x i32], [10 x i32]* %5, i64 0, i64 %63
  store i32 %61, i32* %64, align 4
  br label %65

65:                                               ; preds = %54
  %66 = load i32, i32* %6, align 4
  %67 = add nsw i32 %66, 1
  store i32 %67, i32* %6, align 4
  br label %51, !llvm.loop !31

68:                                               ; preds = %51
  %69 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([28 x i8], [28 x i8]* @.str.7, i64 0, i64 0))
  store i32 0, i32* %8, align 4
  br label %70

70:                                               ; preds = %79, %68
  %71 = load i32, i32* %8, align 4
  %72 = icmp slt i32 %71, 10
  br i1 %72, label %73, label %82

73:                                               ; preds = %70
  %74 = load i32, i32* %8, align 4
  %75 = sext i32 %74 to i64
  %76 = getelementptr inbounds [10 x i32], [10 x i32]* %4, i64 0, i64 %75
  %77 = load i32, i32* %76, align 4
  %78 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %77)
  br label %79

79:                                               ; preds = %73
  %80 = load i32, i32* %8, align 4
  %81 = add nsw i32 %80, 1
  store i32 %81, i32* %8, align 4
  br label %70, !llvm.loop !32

82:                                               ; preds = %70
  %83 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  %84 = getelementptr inbounds [10 x i32], [10 x i32]* %4, i64 0, i64 0
  call void @mergeSort(i32* noundef %84, i32 noundef 0, i32 noundef 9)
  %85 = getelementptr inbounds [10 x i32], [10 x i32]* %5, i64 0, i64 0
  call void @quickSort(i32* noundef %85, i32 noundef 0, i32 noundef 9)
  %86 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([23 x i8], [23 x i8]* @.str.8, i64 0, i64 0))
  store i32 0, i32* %9, align 4
  br label %87

87:                                               ; preds = %96, %82
  %88 = load i32, i32* %9, align 4
  %89 = icmp slt i32 %88, 10
  br i1 %89, label %90, label %99

90:                                               ; preds = %87
  %91 = load i32, i32* %9, align 4
  %92 = sext i32 %91 to i64
  %93 = getelementptr inbounds [10 x i32], [10 x i32]* %4, i64 0, i64 %92
  %94 = load i32, i32* %93, align 4
  %95 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %94)
  br label %96

96:                                               ; preds = %90
  %97 = load i32, i32* %9, align 4
  %98 = add nsw i32 %97, 1
  store i32 %98, i32* %9, align 4
  br label %87, !llvm.loop !33

99:                                               ; preds = %87
  %100 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  %101 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([23 x i8], [23 x i8]* @.str.9, i64 0, i64 0))
  store i32 0, i32* %10, align 4
  br label %102

102:                                              ; preds = %111, %99
  %103 = load i32, i32* %10, align 4
  %104 = icmp slt i32 %103, 10
  br i1 %104, label %105, label %114

105:                                              ; preds = %102
  %106 = load i32, i32* %10, align 4
  %107 = sext i32 %106 to i64
  %108 = getelementptr inbounds [10 x i32], [10 x i32]* %5, i64 0, i64 %107
  %109 = load i32, i32* %108, align 4
  %110 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %109)
  br label %111

111:                                              ; preds = %105
  %112 = load i32, i32* %10, align 4
  %113 = add nsw i32 %112, 1
  store i32 %113, i32* %10, align 4
  br label %102, !llvm.loop !34

114:                                              ; preds = %102
  %115 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  %116 = call { i32**, i64 } @createMatrix(i32 noundef 5, i32 noundef 3)
  %117 = bitcast %struct.Matrix* %11 to { i32**, i64 }*
  %118 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %117, i32 0, i32 0
  %119 = extractvalue { i32**, i64 } %116, 0
  store i32** %119, i32*** %118, align 8
  %120 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %117, i32 0, i32 1
  %121 = extractvalue { i32**, i64 } %116, 1
  store i64 %121, i64* %120, align 8
  %122 = call { i32**, i64 } @createMatrix(i32 noundef 3, i32 noundef 5)
  %123 = bitcast %struct.Matrix* %12 to { i32**, i64 }*
  %124 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %123, i32 0, i32 0
  %125 = extractvalue { i32**, i64 } %122, 0
  store i32** %125, i32*** %124, align 8
  %126 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %123, i32 0, i32 1
  %127 = extractvalue { i32**, i64 } %122, 1
  store i64 %127, i64* %126, align 8
  %128 = call { i32**, i64 } @multiplyMatrices(%struct.Matrix* noundef %11, %struct.Matrix* noundef %12)
  %129 = bitcast %struct.Matrix* %13 to { i32**, i64 }*
  %130 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %129, i32 0, i32 0
  %131 = extractvalue { i32**, i64 } %128, 0
  store i32** %131, i32*** %130, align 8
  %132 = getelementptr inbounds { i32**, i64 }, { i32**, i64 }* %129, i32 0, i32 1
  %133 = extractvalue { i32**, i64 } %128, 1
  store i64 %133, i64* %132, align 8
  %134 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %13, i32 0, i32 0
  %135 = load i32**, i32*** %134, align 8
  %136 = icmp ne i32** %135, null
  br i1 %136, label %137, label %143

137:                                              ; preds = %114
  %138 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %13, i32 0, i32 1
  %139 = load i32, i32* %138, align 8
  %140 = getelementptr inbounds %struct.Matrix, %struct.Matrix* %13, i32 0, i32 2
  %141 = load i32, i32* %140, align 4
  %142 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([60 x i8], [60 x i8]* @.str.10, i64 0, i64 0), i32 noundef %139, i32 noundef %141)
  br label %145

143:                                              ; preds = %114
  %144 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([42 x i8], [42 x i8]* @.str.11, i64 0, i64 0))
  br label %145

145:                                              ; preds = %143, %137
  call void @freeMatrix(%struct.Matrix* noundef %11)
  call void @freeMatrix(%struct.Matrix* noundef %12)
  call void @freeMatrix(%struct.Matrix* noundef %13)
  store i32 100000, i32* %14, align 4
  %146 = load i32, i32* %14, align 4
  %147 = sext i32 %146 to i64
  %148 = mul i64 %147, 4
  %149 = call noalias i8* @malloc(i64 noundef %148) #7
  %150 = bitcast i8* %149 to i32*
  store i32* %150, i32** %15, align 8
  store i32 0, i32* %16, align 4
  br label %151

151:                                              ; preds = %162, %145
  %152 = load i32, i32* %16, align 4
  %153 = load i32, i32* %14, align 4
  %154 = icmp slt i32 %152, %153
  br i1 %154, label %155, label %165

155:                                              ; preds = %151
  %156 = call i32 @rand() #7
  %157 = srem i32 %156, 100
  %158 = load i32*, i32** %15, align 8
  %159 = load i32, i32* %16, align 4
  %160 = sext i32 %159 to i64
  %161 = getelementptr inbounds i32, i32* %158, i64 %160
  store i32 %157, i32* %161, align 4
  br label %162

162:                                              ; preds = %155
  %163 = load i32, i32* %16, align 4
  %164 = add nsw i32 %163, 1
  store i32 %164, i32* %16, align 4
  br label %151, !llvm.loop !35

165:                                              ; preds = %151
  %166 = load i32, i32* %14, align 4
  %167 = sdiv i32 %166, 4
  store i32 %167, i32* %19, align 4
  store i32 0, i32* %20, align 4
  br label %168

168:                                              ; preds = %215, %165
  %169 = load i32, i32* %20, align 4
  %170 = icmp slt i32 %169, 4
  br i1 %170, label %171, label %218

171:                                              ; preds = %168
  %172 = load i32, i32* %20, align 4
  %173 = load i32, i32* %20, align 4
  %174 = sext i32 %173 to i64
  %175 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %174
  %176 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %175, i32 0, i32 0
  store i32 %172, i32* %176, align 16
  %177 = load i32*, i32** %15, align 8
  %178 = load i32, i32* %20, align 4
  %179 = load i32, i32* %19, align 4
  %180 = mul nsw i32 %178, %179
  %181 = sext i32 %180 to i64
  %182 = getelementptr inbounds i32, i32* %177, i64 %181
  %183 = load i32, i32* %20, align 4
  %184 = sext i32 %183 to i64
  %185 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %184
  %186 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %185, i32 0, i32 1
  store i32* %182, i32** %186, align 8
  %187 = load i32, i32* %20, align 4
  %188 = icmp eq i32 %187, 3
  br i1 %188, label %189, label %195

189:                                              ; preds = %171
  %190 = load i32, i32* %14, align 4
  %191 = load i32, i32* %20, align 4
  %192 = load i32, i32* %19, align 4
  %193 = mul nsw i32 %191, %192
  %194 = sub nsw i32 %190, %193
  br label %197

195:                                              ; preds = %171
  %196 = load i32, i32* %19, align 4
  br label %197

197:                                              ; preds = %195, %189
  %198 = phi i32 [ %194, %189 ], [ %196, %195 ]
  %199 = load i32, i32* %20, align 4
  %200 = sext i32 %199 to i64
  %201 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %200
  %202 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %201, i32 0, i32 2
  store i32 %198, i32* %202, align 16
  %203 = load i32, i32* %20, align 4
  %204 = sext i32 %203 to i64
  %205 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %204
  %206 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %205, i32 0, i32 3
  store i64 0, i64* %206, align 8
  %207 = load i32, i32* %20, align 4
  %208 = sext i32 %207 to i64
  %209 = getelementptr inbounds [4 x i64], [4 x i64]* %17, i64 0, i64 %208
  %210 = load i32, i32* %20, align 4
  %211 = sext i32 %210 to i64
  %212 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %211
  %213 = bitcast %struct.ThreadData* %212 to i8*
  %214 = call i32 @pthread_create(i64* noundef %209, %union.pthread_attr_t* noundef null, i8* (i8*)* noundef @threadFunction, i8* noundef %213) #7
  br label %215

215:                                              ; preds = %197
  %216 = load i32, i32* %20, align 4
  %217 = add nsw i32 %216, 1
  store i32 %217, i32* %20, align 4
  br label %168, !llvm.loop !36

218:                                              ; preds = %168
  store i64 0, i64* %21, align 8
  store i32 0, i32* %22, align 4
  br label %219

219:                                              ; preds = %235, %218
  %220 = load i32, i32* %22, align 4
  %221 = icmp slt i32 %220, 4
  br i1 %221, label %222, label %238

222:                                              ; preds = %219
  %223 = load i32, i32* %22, align 4
  %224 = sext i32 %223 to i64
  %225 = getelementptr inbounds [4 x i64], [4 x i64]* %17, i64 0, i64 %224
  %226 = load i64, i64* %225, align 8
  %227 = call i32 @pthread_join(i64 noundef %226, i8** noundef null)
  %228 = load i32, i32* %22, align 4
  %229 = sext i32 %228 to i64
  %230 = getelementptr inbounds [4 x %struct.ThreadData], [4 x %struct.ThreadData]* %18, i64 0, i64 %229
  %231 = getelementptr inbounds %struct.ThreadData, %struct.ThreadData* %230, i32 0, i32 3
  %232 = load i64, i64* %231, align 8
  %233 = load i64, i64* %21, align 8
  %234 = add nsw i64 %233, %232
  store i64 %234, i64* %21, align 8
  br label %235

235:                                              ; preds = %222
  %236 = load i32, i32* %22, align 4
  %237 = add nsw i32 %236, 1
  store i32 %237, i32* %22, align 4
  br label %219, !llvm.loop !37

238:                                              ; preds = %219
  %239 = load i64, i64* %21, align 8
  %240 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([26 x i8], [26 x i8]* @.str.12, i64 0, i64 0), i64 noundef %239)
  %241 = load i32*, i32** %15, align 8
  %242 = bitcast i32* %241 to i8*
  call void @free(i8* noundef %242) #7
  store i64 1234567890, i64* %23, align 8
  %243 = load i64, i64* %23, align 8
  %244 = load i64, i64* %23, align 8
  %245 = call i32 @isPrime(i64 noundef %244)
  %246 = icmp ne i32 %245, 0
  %247 = zext i1 %246 to i64
  %248 = select i1 %246, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.14, i64 0, i64 0), i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.15, i64 0, i64 0)
  %249 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([37 x i8], [37 x i8]* @.str.13, i64 0, i64 0), i64 noundef %243, i8* noundef %248)
  %250 = load i64, i64* %23, align 8
  call void @primeFactorization(i64 noundef %250)
  store i32 20, i32* %24, align 4
  %251 = load i32, i32* %24, align 4
  %252 = load i32, i32* %24, align 4
  %253 = call i64 @fibonacci(i32 noundef %252)
  %254 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([22 x i8], [22 x i8]* @.str.16, i64 0, i64 0), i32 noundef %251, i64 noundef %253)
  store i32 12, i32* %25, align 4
  %255 = load i32, i32* %25, align 4
  %256 = load i32, i32* %25, align 4
  %257 = call i64 @factorial(i32 noundef %256)
  %258 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([22 x i8], [22 x i8]* @.str.17, i64 0, i64 0), i32 noundef %255, i64 noundef %257)
  call void @freeGraph(%struct.Graph* noundef @globalGraph)
  ret i32 0
}

; Function Attrs: nounwind
declare i32 @pthread_create(i64* noundef, %union.pthread_attr_t* noundef, i8* (i8*)* noundef, i8* noundef) #1

declare i32 @pthread_join(i64 noundef, i8** noundef) #6

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nofree nosync nounwind willreturn }
attributes #3 = { argmemonly nofree nounwind willreturn writeonly }
attributes #4 = { argmemonly nofree nounwind willreturn }
attributes #5 = { noreturn "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { nounwind }
attributes #8 = { noreturn }

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