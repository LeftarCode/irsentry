; ModuleID = '.\str.c'
source_filename = ".\\str.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.44.35211"

$sprintf = comdat any

$vsprintf = comdat any

$_snprintf = comdat any

$_vsnprintf = comdat any

$printf = comdat any

$_vsprintf_l = comdat any

$_vsnprintf_l = comdat any

$__local_stdio_printf_options = comdat any

$_vfprintf_l = comdat any

$"??_C@_0L@HKNOIAKA@TRAFIONY?$CB?6?$AA@" = comdat any

$"??_C@_0BH@GLEOPPOK@Usage?3?5?4?1str?4exe?5?$FLreq?$FN?$AA@" = comdat any

$"??_C@_0BB@INHLFELC@POST?5?1?5HTTP?11?41?$EA?$AA@" = comdat any

$"??_C@_0BA@DIGAFIOK@Content?9Length?3?$AA@" = comdat any

@"??_C@_0L@HKNOIAKA@TRAFIONY?$CB?6?$AA@" = linkonce_odr dso_local unnamed_addr constant [11 x i8] c"TRAFIONY!\0A\00", comdat, align 1
@"??_C@_0BH@GLEOPPOK@Usage?3?5?4?1str?4exe?5?$FLreq?$FN?$AA@" = linkonce_odr dso_local unnamed_addr constant [23 x i8] c"Usage: ./str.exe [req]\00", comdat, align 1
@"??_C@_0BB@INHLFELC@POST?5?1?5HTTP?11?41?$EA?$AA@" = linkonce_odr dso_local unnamed_addr constant [17 x i8] c"POST / HTTP/1.1@\00", comdat, align 1
@"??_C@_0BA@DIGAFIOK@Content?9Length?3?$AA@" = linkonce_odr dso_local unnamed_addr constant [16 x i8] c"Content-Length:\00", comdat, align 1
@__local_stdio_printf_options._OptionsStorage = internal global i64 0, align 8

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @sprintf(ptr noundef %_Buffer, ptr noundef %_Format, ...) #0 comdat {
entry:
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  call void @llvm.va_start.p0(ptr %_ArgList)
  %0 = load ptr, ptr %_ArgList, align 8
  %1 = load ptr, ptr %_Format.addr, align 8
  %2 = load ptr, ptr %_Buffer.addr, align 8
  %call = call i32 @_vsprintf_l(ptr noundef %2, ptr noundef %1, ptr noundef null, ptr noundef %0)
  store i32 %call, ptr %_Result, align 4
  call void @llvm.va_end.p0(ptr %_ArgList)
  %3 = load i32, ptr %_Result, align 4
  ret i32 %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @vsprintf(ptr noundef %_Buffer, ptr noundef %_Format, ptr noundef %_ArgList) #0 comdat {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  %0 = load ptr, ptr %_ArgList.addr, align 8
  %1 = load ptr, ptr %_Format.addr, align 8
  %2 = load ptr, ptr %_Buffer.addr, align 8
  %call = call i32 @_vsnprintf_l(ptr noundef %2, i64 noundef -1, ptr noundef %1, ptr noundef null, ptr noundef %0)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_snprintf(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ...) #0 comdat {
entry:
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  call void @llvm.va_start.p0(ptr %_ArgList)
  %0 = load ptr, ptr %_ArgList, align 8
  %1 = load ptr, ptr %_Format.addr, align 8
  %2 = load i64, ptr %_BufferCount.addr, align 8
  %3 = load ptr, ptr %_Buffer.addr, align 8
  %call = call i32 @_vsnprintf(ptr noundef %3, i64 noundef %2, ptr noundef %1, ptr noundef %0)
  store i32 %call, ptr %_Result, align 4
  call void @llvm.va_end.p0(ptr %_ArgList)
  %4 = load i32, ptr %_Result, align 4
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ptr noundef %_ArgList) #0 comdat {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  %0 = load ptr, ptr %_ArgList.addr, align 8
  %1 = load ptr, ptr %_Format.addr, align 8
  %2 = load i64, ptr %_BufferCount.addr, align 8
  %3 = load ptr, ptr %_Buffer.addr, align 8
  %call = call i32 @_vsnprintf_l(ptr noundef %3, i64 noundef %2, ptr noundef %1, ptr noundef null, ptr noundef %0)
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @IRSENTRY_MOCK_NOPARAMS() #0 {
entry:
  %call = call i32 (ptr, ...) @printf(ptr noundef @"??_C@_0L@HKNOIAKA@TRAFIONY?$CB?6?$AA@")
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @printf(ptr noundef %_Format, ...) #0 comdat {
entry:
  %_Format.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  call void @llvm.va_start.p0(ptr %_ArgList)
  %0 = load ptr, ptr %_ArgList, align 8
  %1 = load ptr, ptr %_Format.addr, align 8
  %call = call ptr @__acrt_iob_func(i32 noundef 1)
  %call1 = call i32 @_vfprintf_l(ptr noundef %call, ptr noundef %1, ptr noundef null, ptr noundef %0)
  store i32 %call1, ptr %_Result, align 4
  call void @llvm.va_end.p0(ptr %_ArgList)
  %2 = load i32, ptr %_Result, align 4
  ret i32 %2
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %argc, ptr noundef %argv) #0 {
entry:
  %retval = alloca i32, align 4
  %argv.addr = alloca ptr, align 8
  %argc.addr = alloca i32, align 4
  %req_buf = alloca ptr, align 8
  %hdr_start = alloca ptr, align 8
  %cl_start = alloca ptr, align 8
  %cl_num = alloca ptr, align 8
  store i32 0, ptr %retval, align 4
  store ptr %argv, ptr %argv.addr, align 8
  store i32 %argc, ptr %argc.addr, align 4
  %0 = load i32, ptr %argc.addr, align 4
  %cmp = icmp ne i32 %0, 2
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %call = call i32 (ptr, ...) @printf(ptr noundef @"??_C@_0BH@GLEOPPOK@Usage?3?5?4?1str?4exe?5?$FLreq?$FN?$AA@")
  store i32 1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load ptr, ptr %argv.addr, align 8
  %arrayidx = getelementptr inbounds ptr, ptr %1, i64 1
  %2 = load ptr, ptr %arrayidx, align 8
  store ptr %2, ptr %req_buf, align 8
  %3 = load ptr, ptr %req_buf, align 8
  %call1 = call ptr @strstr(ptr noundef %3, ptr noundef @"??_C@_0BB@INHLFELC@POST?5?1?5HTTP?11?41?$EA?$AA@") #4
  %4 = load ptr, ptr %req_buf, align 8
  %cmp2 = icmp ne ptr %call1, %4
  br i1 %cmp2, label %if.then3, label %if.end4

if.then3:                                         ; preds = %if.end
  store i32 1, ptr %retval, align 4
  br label %return

if.end4:                                          ; preds = %if.end
  %5 = load ptr, ptr %req_buf, align 8
  %add.ptr = getelementptr inbounds nuw i8, ptr %5, i64 16
  store ptr %add.ptr, ptr %hdr_start, align 8
  %6 = load ptr, ptr %hdr_start, align 8
  %call5 = call ptr @strstr(ptr noundef %6, ptr noundef @"??_C@_0BA@DIGAFIOK@Content?9Length?3?$AA@") #4
  store ptr %call5, ptr %cl_start, align 8
  %7 = load ptr, ptr %cl_start, align 8
  %cmp6 = icmp eq ptr %7, null
  br i1 %cmp6, label %if.then7, label %if.end8

if.then7:                                         ; preds = %if.end4
  store i32 1, ptr %retval, align 4
  br label %return

if.end8:                                          ; preds = %if.end4
  %8 = load ptr, ptr %cl_start, align 8
  %add.ptr9 = getelementptr inbounds nuw i8, ptr %8, i64 15
  store ptr %add.ptr9, ptr %cl_num, align 8
  %9 = load ptr, ptr %cl_num, align 8
  %call10 = call i32 @atoi(ptr noundef %9)
  %cmp11 = icmp sgt i32 %call10, 1234
  br i1 %cmp11, label %if.then12, label %if.end13

if.then12:                                        ; preds = %if.end8
  store i32 1, ptr %retval, align 4
  br label %return

if.end13:                                         ; preds = %if.end8
  call void @IRSENTRY_MOCK_NOPARAMS()
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end13, %if.then12, %if.then7, %if.then3, %if.then
  %10 = load i32, ptr %retval, align 4
  ret i32 %10
}

; Function Attrs: nounwind
declare dso_local ptr @strstr(ptr noundef, ptr noundef) #1

declare dso_local i32 @atoi(ptr noundef) #2

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_start.p0(ptr) #3

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsprintf_l(ptr noundef %_Buffer, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
  store ptr %_Locale, ptr %_Locale.addr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  %0 = load ptr, ptr %_ArgList.addr, align 8
  %1 = load ptr, ptr %_Locale.addr, align 8
  %2 = load ptr, ptr %_Format.addr, align 8
  %3 = load ptr, ptr %_Buffer.addr, align 8
  %call = call i32 @_vsnprintf_l(ptr noundef %3, i64 noundef -1, ptr noundef %2, ptr noundef %1, ptr noundef %0)
  ret i32 %call
}

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_end.p0(ptr) #3

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf_l(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
  store ptr %_Locale, ptr %_Locale.addr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
  %0 = load ptr, ptr %_ArgList.addr, align 8
  %1 = load ptr, ptr %_Locale.addr, align 8
  %2 = load ptr, ptr %_Format.addr, align 8
  %3 = load i64, ptr %_BufferCount.addr, align 8
  %4 = load ptr, ptr %_Buffer.addr, align 8
  %call = call ptr @__local_stdio_printf_options()
  %5 = load i64, ptr %call, align 8
  %or = or i64 %5, 1
  %call1 = call i32 @__stdio_common_vsprintf(i64 noundef %or, ptr noundef %4, i64 noundef %3, ptr noundef %2, ptr noundef %1, ptr noundef %0)
  store i32 %call1, ptr %_Result, align 4
  %6 = load i32, ptr %_Result, align 4
  %cmp = icmp slt i32 %6, 0
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %_Result, align 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ -1, %cond.true ], [ %7, %cond.false ]
  ret i32 %cond
}

declare dso_local i32 @__stdio_common_vsprintf(i64 noundef, ptr noundef, i64 noundef, ptr noundef, ptr noundef, ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local ptr @__local_stdio_printf_options() #0 comdat {
entry:
  ret ptr @__local_stdio_printf_options._OptionsStorage
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vfprintf_l(ptr noundef %_Stream, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Stream.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
  store ptr %_Locale, ptr %_Locale.addr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
  store ptr %_Stream, ptr %_Stream.addr, align 8
  %0 = load ptr, ptr %_ArgList.addr, align 8
  %1 = load ptr, ptr %_Locale.addr, align 8
  %2 = load ptr, ptr %_Format.addr, align 8
  %3 = load ptr, ptr %_Stream.addr, align 8
  %call = call ptr @__local_stdio_printf_options()
  %4 = load i64, ptr %call, align 8
  %call1 = call i32 @__stdio_common_vfprintf(i64 noundef %4, ptr noundef %3, ptr noundef %2, ptr noundef %1, ptr noundef %0)
  ret i32 %call1
}

declare dso_local ptr @__acrt_iob_func(i32 noundef) #2

declare dso_local i32 @__stdio_common_vfprintf(i64 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #2

attributes #0 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nocallback nofree nosync nounwind willreturn }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"clang version 20.1.0"}
