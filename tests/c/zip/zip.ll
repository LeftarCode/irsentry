; ModuleID = '.\zip.c'
source_filename = ".\\zip.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.43.34809"

%struct.LocalFileHeader = type <{ i32, i16, i16, i16, i16, i16, i32, i32, i32, i16, i16 }>

$sprintf = comdat any

$vsprintf = comdat any

$_snprintf = comdat any

$_vsnprintf = comdat any

$fprintf = comdat any

$_vsprintf_l = comdat any

$_vsnprintf_l = comdat any

$__local_stdio_printf_options = comdat any

$_vfprintf_l = comdat any

$"??_C@_0BF@NGOGHLPP@Usage?3?5?$CFs?5?$DMzipfile?$DO?6?$AA@" = comdat any

$"??_C@_02JDPG@rb?$AA@" = comdat any

$"??_C@_05FFKPLNPJ@fopen?$AA@" = comdat any

$"??_C@_0CO@DHNPNHHO@Unknown?5header?5signature?3?50x?$CF08x@" = comdat any

$"??_C@_02GMLFBBN@wb?$AA@" = comdat any

$"??_C@_0M@CCMCDPOK@open?5output?$AA@" = comdat any

$"??_C@_0P@LEGHBOFO@malloc?5failed?6?$AA@" = comdat any

@"??_C@_0BF@NGOGHLPP@Usage?3?5?$CFs?5?$DMzipfile?$DO?6?$AA@" = linkonce_odr dso_local unnamed_addr constant [21 x i8] c"Usage: %s <zipfile>\0A\00", comdat, align 1
@"??_C@_02JDPG@rb?$AA@" = linkonce_odr dso_local unnamed_addr constant [3 x i8] c"rb\00", comdat, align 1
@"??_C@_05FFKPLNPJ@fopen?$AA@" = linkonce_odr dso_local unnamed_addr constant [6 x i8] c"fopen\00", comdat, align 1
@"??_C@_0CO@DHNPNHHO@Unknown?5header?5signature?3?50x?$CF08x@" = linkonce_odr dso_local unnamed_addr constant [46 x i8] c"Unknown header signature: 0x%08x \96 stopping.\0A\00", comdat, align 1
@__local_stdio_printf_options._OptionsStorage = internal global i64 0, align 8
@"??_C@_02GMLFBBN@wb?$AA@" = linkonce_odr dso_local unnamed_addr constant [3 x i8] c"wb\00", comdat, align 1
@"??_C@_0M@CCMCDPOK@open?5output?$AA@" = linkonce_odr dso_local unnamed_addr constant [12 x i8] c"open output\00", comdat, align 1
@"??_C@_0P@LEGHBOFO@malloc?5failed?6?$AA@" = linkonce_odr dso_local unnamed_addr constant [15 x i8] c"malloc failed\0A\00", comdat, align 1

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @sprintf(ptr noundef %0, ptr noundef %1, ...) #0 comdat {
  %3 = alloca ptr, align 8
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca ptr, align 8
  store ptr %1, ptr %3, align 8
  store ptr %0, ptr %4, align 8
  call void @llvm.va_start.p0(ptr %6)
  %7 = load ptr, ptr %6, align 8
  %8 = load ptr, ptr %3, align 8
  %9 = load ptr, ptr %4, align 8
  %10 = call i32 @_vsprintf_l(ptr noundef %9, ptr noundef %8, ptr noundef null, ptr noundef %7)
  store i32 %10, ptr %5, align 4
  call void @llvm.va_end.p0(ptr %6)
  %11 = load i32, ptr %5, align 4
  ret i32 %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @vsprintf(ptr noundef %0, ptr noundef %1, ptr noundef %2) #0 comdat {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  store ptr %2, ptr %4, align 8
  store ptr %1, ptr %5, align 8
  store ptr %0, ptr %6, align 8
  %7 = load ptr, ptr %4, align 8
  %8 = load ptr, ptr %5, align 8
  %9 = load ptr, ptr %6, align 8
  %10 = call i32 @_vsnprintf_l(ptr noundef %9, i64 noundef -1, ptr noundef %8, ptr noundef null, ptr noundef %7)
  ret i32 %10
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_snprintf(ptr noundef %0, i64 noundef %1, ptr noundef %2, ...) #0 comdat {
  %4 = alloca ptr, align 8
  %5 = alloca i64, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %2, ptr %4, align 8
  store i64 %1, ptr %5, align 8
  store ptr %0, ptr %6, align 8
  call void @llvm.va_start.p0(ptr %8)
  %9 = load ptr, ptr %8, align 8
  %10 = load ptr, ptr %4, align 8
  %11 = load i64, ptr %5, align 8
  %12 = load ptr, ptr %6, align 8
  %13 = call i32 @_vsnprintf(ptr noundef %12, i64 noundef %11, ptr noundef %10, ptr noundef %9)
  store i32 %13, ptr %7, align 4
  call void @llvm.va_end.p0(ptr %8)
  %14 = load i32, ptr %7, align 4
  ret i32 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf(ptr noundef %0, i64 noundef %1, ptr noundef %2, ptr noundef %3) #0 comdat {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i64, align 8
  %8 = alloca ptr, align 8
  store ptr %3, ptr %5, align 8
  store ptr %2, ptr %6, align 8
  store i64 %1, ptr %7, align 8
  store ptr %0, ptr %8, align 8
  %9 = load ptr, ptr %5, align 8
  %10 = load ptr, ptr %6, align 8
  %11 = load i64, ptr %7, align 8
  %12 = load ptr, ptr %8, align 8
  %13 = call i32 @_vsnprintf_l(ptr noundef %12, i64 noundef %11, ptr noundef %10, ptr noundef null, ptr noundef %9)
  ret i32 %13
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca ptr, align 8
  %7 = alloca %struct.LocalFileHeader, align 1
  %8 = alloca i64, align 8
  store i32 0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  store i32 %0, ptr %5, align 4
  %9 = load i32, ptr %5, align 4
  %10 = icmp ne i32 %9, 2
  br i1 %10, label %11, label %17

11:                                               ; preds = %2
  %12 = load ptr, ptr %4, align 8
  %13 = getelementptr inbounds ptr, ptr %12, i64 0
  %14 = load ptr, ptr %13, align 8
  %15 = call ptr @__acrt_iob_func(i32 noundef 2)
  %16 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %15, ptr noundef @"??_C@_0BF@NGOGHLPP@Usage?3?5?$CFs?5?$DMzipfile?$DO?6?$AA@", ptr noundef %14) #4
  store i32 1, ptr %3, align 4
  br label %46

17:                                               ; preds = %2
  %18 = load ptr, ptr %4, align 8
  %19 = getelementptr inbounds ptr, ptr %18, i64 1
  %20 = load ptr, ptr %19, align 8
  %21 = call ptr @fopen(ptr noundef %20, ptr noundef @"??_C@_02JDPG@rb?$AA@")
  store ptr %21, ptr %6, align 8
  %22 = load ptr, ptr %6, align 8
  %23 = icmp ne ptr %22, null
  br i1 %23, label %25, label %24

24:                                               ; preds = %17
  call void @perror(ptr noundef @"??_C@_05FFKPLNPJ@fopen?$AA@")
  store i32 1, ptr %3, align 4
  br label %46

25:                                               ; preds = %17
  br label %26

26:                                               ; preds = %25, %41
  %27 = load ptr, ptr %6, align 8
  %28 = call i64 @fread(ptr noundef %7, i64 noundef 30, i64 noundef 1, ptr noundef %27)
  store i64 %28, ptr %8, align 8
  %29 = load i64, ptr %8, align 8
  %30 = icmp ne i64 %29, 1
  br i1 %30, label %31, label %32

31:                                               ; preds = %26
  br label %43

32:                                               ; preds = %26
  %33 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %7, i32 0, i32 0
  %34 = load i32, ptr %33, align 1
  %35 = icmp ne i32 %34, 67324752
  br i1 %35, label %36, label %41

36:                                               ; preds = %32
  %37 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %7, i32 0, i32 0
  %38 = load i32, ptr %37, align 1
  %39 = call ptr @__acrt_iob_func(i32 noundef 2)
  %40 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %39, ptr noundef @"??_C@_0CO@DHNPNHHO@Unknown?5header?5signature?3?50x?$CF08x@", i32 noundef %38) #4
  br label %43

41:                                               ; preds = %32
  %42 = load ptr, ptr %6, align 8
  call void @extract_file(ptr noundef %42, ptr noundef %7)
  br label %26

43:                                               ; preds = %36, %31
  %44 = load ptr, ptr %6, align 8
  %45 = call i32 @fclose(ptr noundef %44)
  store i32 0, ptr %3, align 4
  br label %46

46:                                               ; preds = %43, %24, %11
  %47 = load i32, ptr %3, align 4
  ret i32 %47
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @fprintf(ptr noundef %0, ptr noundef %1, ...) #0 comdat {
  %3 = alloca ptr, align 8
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca ptr, align 8
  store ptr %1, ptr %3, align 8
  store ptr %0, ptr %4, align 8
  call void @llvm.va_start.p0(ptr %6)
  %7 = load ptr, ptr %6, align 8
  %8 = load ptr, ptr %3, align 8
  %9 = load ptr, ptr %4, align 8
  %10 = call i32 @_vfprintf_l(ptr noundef %9, ptr noundef %8, ptr noundef null, ptr noundef %7)
  store i32 %10, ptr %5, align 4
  call void @llvm.va_end.p0(ptr %6)
  %11 = load i32, ptr %5, align 4
  ret i32 %11
}

declare dso_local ptr @__acrt_iob_func(i32 noundef) #1

declare dso_local ptr @fopen(ptr noundef, ptr noundef) #1

declare dso_local void @perror(ptr noundef) #1

declare dso_local i64 @fread(ptr noundef, i64 noundef, i64 noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define internal void @extract_file(ptr noundef %0, ptr noundef %1) #0 {
  %3 = alloca ptr, align 8
  %4 = alloca ptr, align 8
  %5 = alloca [128 x i8], align 16
  %6 = alloca i64, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %1, ptr %3, align 8
  store ptr %0, ptr %4, align 8
  %9 = load ptr, ptr %3, align 8
  %10 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %9, i32 0, i32 9
  %11 = load i16, ptr %10, align 1
  %12 = zext i16 %11 to i64
  store i64 %12, ptr %6, align 8
  %13 = load ptr, ptr %4, align 8
  %14 = load i64, ptr %6, align 8
  %15 = getelementptr inbounds [128 x i8], ptr %5, i64 0, i64 0
  %16 = call i64 @fread(ptr noundef %15, i64 noundef 1, i64 noundef %14, ptr noundef %13)
  %17 = load i64, ptr %6, align 8
  %18 = icmp ult i64 %17, 128
  br i1 %18, label %19, label %21

19:                                               ; preds = %2
  %20 = load i64, ptr %6, align 8
  br label %22

21:                                               ; preds = %2
  br label %22

22:                                               ; preds = %21, %19
  %23 = phi i64 [ %20, %19 ], [ 127, %21 ]
  %24 = getelementptr inbounds nuw [128 x i8], ptr %5, i64 0, i64 %23
  store i8 0, ptr %24, align 1
  %25 = getelementptr inbounds [128 x i8], ptr %5, i64 0, i64 0
  call void @sanitize_name(ptr noundef %25)
  %26 = getelementptr inbounds [128 x i8], ptr %5, i64 0, i64 0
  %27 = call ptr @fopen(ptr noundef %26, ptr noundef @"??_C@_02GMLFBBN@wb?$AA@")
  store ptr %27, ptr %7, align 8
  %28 = load ptr, ptr %7, align 8
  %29 = icmp ne ptr %28, null
  br i1 %29, label %41, label %30

30:                                               ; preds = %22
  call void @perror(ptr noundef @"??_C@_0M@CCMCDPOK@open?5output?$AA@")
  %31 = load ptr, ptr %3, align 8
  %32 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %31, i32 0, i32 10
  %33 = load i16, ptr %32, align 1
  %34 = zext i16 %33 to i32
  %35 = load ptr, ptr %3, align 8
  %36 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %35, i32 0, i32 7
  %37 = load i32, ptr %36, align 1
  %38 = add i32 %34, %37
  %39 = zext i32 %38 to i64
  %40 = load ptr, ptr %4, align 8
  call void @skip_bytes(ptr noundef %40, i64 noundef %39)
  br label %82

41:                                               ; preds = %22
  %42 = load ptr, ptr %3, align 8
  %43 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %42, i32 0, i32 10
  %44 = load i16, ptr %43, align 1
  %45 = zext i16 %44 to i64
  %46 = load ptr, ptr %4, align 8
  call void @skip_bytes(ptr noundef %46, i64 noundef %45)
  %47 = load ptr, ptr %3, align 8
  %48 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %47, i32 0, i32 7
  %49 = load i32, ptr %48, align 1
  %50 = zext i32 %49 to i64
  %51 = call noalias ptr @malloc(i64 noundef %50) #5
  store ptr %51, ptr %8, align 8
  %52 = load ptr, ptr %8, align 8
  %53 = icmp ne ptr %52, null
  br i1 %53, label %64, label %54

54:                                               ; preds = %41
  %55 = call ptr @__acrt_iob_func(i32 noundef 2)
  %56 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %55, ptr noundef @"??_C@_0P@LEGHBOFO@malloc?5failed?6?$AA@") #4
  %57 = load ptr, ptr %7, align 8
  %58 = call i32 @fclose(ptr noundef %57)
  %59 = load ptr, ptr %3, align 8
  %60 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %59, i32 0, i32 7
  %61 = load i32, ptr %60, align 1
  %62 = zext i32 %61 to i64
  %63 = load ptr, ptr %4, align 8
  call void @skip_bytes(ptr noundef %63, i64 noundef %62)
  br label %82

64:                                               ; preds = %41
  %65 = load ptr, ptr %4, align 8
  %66 = load ptr, ptr %3, align 8
  %67 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %66, i32 0, i32 7
  %68 = load i32, ptr %67, align 1
  %69 = zext i32 %68 to i64
  %70 = load ptr, ptr %8, align 8
  %71 = call i64 @fread(ptr noundef %70, i64 noundef 1, i64 noundef %69, ptr noundef %65)
  %72 = load ptr, ptr %7, align 8
  %73 = load ptr, ptr %3, align 8
  %74 = getelementptr inbounds nuw %struct.LocalFileHeader, ptr %73, i32 0, i32 7
  %75 = load i32, ptr %74, align 1
  %76 = zext i32 %75 to i64
  %77 = load ptr, ptr %8, align 8
  %78 = call i64 @fwrite(ptr noundef %77, i64 noundef 1, i64 noundef %76, ptr noundef %72)
  %79 = load ptr, ptr %7, align 8
  %80 = call i32 @fclose(ptr noundef %79)
  %81 = load ptr, ptr %8, align 8
  call void @free(ptr noundef %81)
  br label %82

82:                                               ; preds = %64, %54, %30
  ret void
}

declare dso_local i32 @fclose(ptr noundef) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_start.p0(ptr) #2

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsprintf_l(ptr noundef %0, ptr noundef %1, ptr noundef %2, ptr noundef %3) #0 comdat {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %3, ptr %5, align 8
  store ptr %2, ptr %6, align 8
  store ptr %1, ptr %7, align 8
  store ptr %0, ptr %8, align 8
  %9 = load ptr, ptr %5, align 8
  %10 = load ptr, ptr %6, align 8
  %11 = load ptr, ptr %7, align 8
  %12 = load ptr, ptr %8, align 8
  %13 = call i32 @_vsnprintf_l(ptr noundef %12, i64 noundef -1, ptr noundef %11, ptr noundef %10, ptr noundef %9)
  ret i32 %13
}

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_end.p0(ptr) #2

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf_l(ptr noundef %0, i64 noundef %1, ptr noundef %2, ptr noundef %3, ptr noundef %4) #0 comdat {
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca i64, align 8
  %10 = alloca ptr, align 8
  %11 = alloca i32, align 4
  store ptr %4, ptr %6, align 8
  store ptr %3, ptr %7, align 8
  store ptr %2, ptr %8, align 8
  store i64 %1, ptr %9, align 8
  store ptr %0, ptr %10, align 8
  %12 = load ptr, ptr %6, align 8
  %13 = load ptr, ptr %7, align 8
  %14 = load ptr, ptr %8, align 8
  %15 = load i64, ptr %9, align 8
  %16 = load ptr, ptr %10, align 8
  %17 = call ptr @__local_stdio_printf_options()
  %18 = load i64, ptr %17, align 8
  %19 = or i64 %18, 1
  %20 = call i32 @__stdio_common_vsprintf(i64 noundef %19, ptr noundef %16, i64 noundef %15, ptr noundef %14, ptr noundef %13, ptr noundef %12)
  store i32 %20, ptr %11, align 4
  %21 = load i32, ptr %11, align 4
  %22 = icmp slt i32 %21, 0
  br i1 %22, label %23, label %24

23:                                               ; preds = %5
  br label %26

24:                                               ; preds = %5
  %25 = load i32, ptr %11, align 4
  br label %26

26:                                               ; preds = %24, %23
  %27 = phi i32 [ -1, %23 ], [ %25, %24 ]
  ret i32 %27
}

declare dso_local i32 @__stdio_common_vsprintf(i64 noundef, ptr noundef, i64 noundef, ptr noundef, ptr noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local ptr @__local_stdio_printf_options() #0 comdat {
  ret ptr @__local_stdio_printf_options._OptionsStorage
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vfprintf_l(ptr noundef %0, ptr noundef %1, ptr noundef %2, ptr noundef %3) #0 comdat {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  store ptr %3, ptr %5, align 8
  store ptr %2, ptr %6, align 8
  store ptr %1, ptr %7, align 8
  store ptr %0, ptr %8, align 8
  %9 = load ptr, ptr %5, align 8
  %10 = load ptr, ptr %6, align 8
  %11 = load ptr, ptr %7, align 8
  %12 = load ptr, ptr %8, align 8
  %13 = call ptr @__local_stdio_printf_options()
  %14 = load i64, ptr %13, align 8
  %15 = call i32 @__stdio_common_vfprintf(i64 noundef %14, ptr noundef %12, ptr noundef %11, ptr noundef %10, ptr noundef %9)
  ret i32 %15
}

declare dso_local i32 @__stdio_common_vfprintf(i64 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define internal void @sanitize_name(ptr noundef %0) #0 {
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %4 = load ptr, ptr %2, align 8
  store ptr %4, ptr %3, align 8
  br label %5

5:                                                ; preds = %22, %1
  %6 = load ptr, ptr %3, align 8
  %7 = load i8, ptr %6, align 1
  %8 = icmp ne i8 %7, 0
  br i1 %8, label %9, label %25

9:                                                ; preds = %5
  %10 = load ptr, ptr %3, align 8
  %11 = load i8, ptr %10, align 1
  %12 = sext i8 %11 to i32
  %13 = icmp eq i32 %12, 47
  br i1 %13, label %19, label %14

14:                                               ; preds = %9
  %15 = load ptr, ptr %3, align 8
  %16 = load i8, ptr %15, align 1
  %17 = sext i8 %16 to i32
  %18 = icmp eq i32 %17, 92
  br i1 %18, label %19, label %21

19:                                               ; preds = %14, %9
  %20 = load ptr, ptr %3, align 8
  store i8 95, ptr %20, align 1
  br label %21

21:                                               ; preds = %19, %14
  br label %22

22:                                               ; preds = %21
  %23 = load ptr, ptr %3, align 8
  %24 = getelementptr inbounds nuw i8, ptr %23, i32 1
  store ptr %24, ptr %3, align 8
  br label %5, !llvm.loop !5

25:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define internal void @skip_bytes(ptr noundef %0, i64 noundef %1) #0 {
  %3 = alloca i64, align 8
  %4 = alloca ptr, align 8
  store i64 %1, ptr %3, align 8
  store ptr %0, ptr %4, align 8
  %5 = load i64, ptr %3, align 8
  %6 = trunc i64 %5 to i32
  %7 = load ptr, ptr %4, align 8
  %8 = call i32 @fseek(ptr noundef %7, i32 noundef %6, i32 noundef 1)
  ret void
}

; Function Attrs: allocsize(0)
declare dso_local noalias ptr @malloc(i64 noundef) #3

declare dso_local i64 @fwrite(ptr noundef, i64 noundef, i64 noundef, ptr noundef) #1

declare dso_local void @free(ptr noundef) #1

declare dso_local i32 @fseek(ptr noundef, i32 noundef, i32 noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn }
attributes #3 = { allocsize(0) "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }
attributes #5 = { allocsize(0) }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"clang version 20.1.0"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
