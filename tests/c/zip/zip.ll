; ModuleID = 'zip.c'
source_filename = "zip.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.44.35211"

%struct.ZIP_HEADER = type { i32, i16, i16, i16, i16, i16, i32, i32, i32, i16, i16 }

$sprintf = comdat any

$vsprintf = comdat any

$_snprintf = comdat any

$_vsnprintf = comdat any

$printf = comdat any

$_vsprintf_l = comdat any

$_vsnprintf_l = comdat any

$__local_stdio_printf_options = comdat any

$_vfprintf_l = comdat any

$"??_C@_02JDPG@rb?$AA@" = comdat any

$"??_C@_0N@HOJHICKB@Filename?3?5?$CFs?$AA@" = comdat any

@"??_C@_02JDPG@rb?$AA@" = linkonce_odr dso_local unnamed_addr constant [3 x i8] c"rb\00", comdat, align 1, !dbg !0
@"??_C@_0N@HOJHICKB@Filename?3?5?$CFs?$AA@" = linkonce_odr dso_local unnamed_addr constant [13 x i8] c"Filename: %s\00", comdat, align 1, !dbg !7
@__local_stdio_printf_options._OptionsStorage = internal global i64 0, align 8, !dbg !12

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @sprintf(ptr noundef %_Buffer, ptr noundef %_Format, ...) #0 comdat !dbg !35 {
entry:
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !46, !DIExpression(), !47)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !48, !DIExpression(), !49)
    #dbg_declare(ptr %_Result, !50, !DIExpression(), !51)
    #dbg_declare(ptr %_ArgList, !52, !DIExpression(), !55)
  call void @llvm.va_start.p0(ptr %_ArgList), !dbg !56
  %0 = load ptr, ptr %_ArgList, align 8, !dbg !57
  %1 = load ptr, ptr %_Format.addr, align 8, !dbg !57
  %2 = load ptr, ptr %_Buffer.addr, align 8, !dbg !57
  %call = call i32 @_vsprintf_l(ptr noundef %2, ptr noundef %1, ptr noundef null, ptr noundef %0), !dbg !57
  store i32 %call, ptr %_Result, align 4, !dbg !57
  call void @llvm.va_end.p0(ptr %_ArgList), !dbg !58
  %3 = load i32, ptr %_Result, align 4, !dbg !59
  ret i32 %3, !dbg !59
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @vsprintf(ptr noundef %_Buffer, ptr noundef %_Format, ptr noundef %_ArgList) #0 comdat !dbg !60 {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
    #dbg_declare(ptr %_ArgList.addr, !63, !DIExpression(), !64)
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !65, !DIExpression(), !66)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !67, !DIExpression(), !68)
  %0 = load ptr, ptr %_ArgList.addr, align 8, !dbg !69
  %1 = load ptr, ptr %_Format.addr, align 8, !dbg !69
  %2 = load ptr, ptr %_Buffer.addr, align 8, !dbg !69
  %call = call i32 @_vsnprintf_l(ptr noundef %2, i64 noundef -1, ptr noundef %1, ptr noundef null, ptr noundef %0), !dbg !69
  ret i32 %call, !dbg !69
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_snprintf(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ...) #0 comdat !dbg !70 {
entry:
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !74, !DIExpression(), !75)
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
    #dbg_declare(ptr %_BufferCount.addr, !76, !DIExpression(), !77)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !78, !DIExpression(), !79)
    #dbg_declare(ptr %_Result, !80, !DIExpression(), !81)
    #dbg_declare(ptr %_ArgList, !82, !DIExpression(), !83)
  call void @llvm.va_start.p0(ptr %_ArgList), !dbg !84
  %0 = load ptr, ptr %_ArgList, align 8, !dbg !85
  %1 = load ptr, ptr %_Format.addr, align 8, !dbg !85
  %2 = load i64, ptr %_BufferCount.addr, align 8, !dbg !85
  %3 = load ptr, ptr %_Buffer.addr, align 8, !dbg !85
  %call = call i32 @_vsnprintf(ptr noundef %3, i64 noundef %2, ptr noundef %1, ptr noundef %0), !dbg !85
  store i32 %call, ptr %_Result, align 4, !dbg !85
  call void @llvm.va_end.p0(ptr %_ArgList), !dbg !86
  %4 = load i32, ptr %_Result, align 4, !dbg !87
  ret i32 %4, !dbg !87
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ptr noundef %_ArgList) #0 comdat !dbg !88 {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
    #dbg_declare(ptr %_ArgList.addr, !91, !DIExpression(), !92)
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !93, !DIExpression(), !94)
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
    #dbg_declare(ptr %_BufferCount.addr, !95, !DIExpression(), !96)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !97, !DIExpression(), !98)
  %0 = load ptr, ptr %_ArgList.addr, align 8, !dbg !99
  %1 = load ptr, ptr %_Format.addr, align 8, !dbg !99
  %2 = load i64, ptr %_BufferCount.addr, align 8, !dbg !99
  %3 = load ptr, ptr %_Buffer.addr, align 8, !dbg !99
  %call = call i32 @_vsnprintf_l(ptr noundef %3, i64 noundef %2, ptr noundef %1, ptr noundef null, ptr noundef %0), !dbg !99
  ret i32 %call, !dbg !99
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %argc, ptr noundef %argv) #0 !dbg !100 {
entry:
  %retval = alloca i32, align 4
  %argv.addr = alloca ptr, align 8
  %argc.addr = alloca i32, align 4
  %zip = alloca ptr, align 8
  %header = alloca %struct.ZIP_HEADER, align 4
  %filename = alloca [128 x i8], align 16
  store i32 0, ptr %retval, align 4
  store ptr %argv, ptr %argv.addr, align 8
    #dbg_declare(ptr %argv.addr, !104, !DIExpression(), !105)
  store i32 %argc, ptr %argc.addr, align 4
    #dbg_declare(ptr %argc.addr, !106, !DIExpression(), !105)
    #dbg_declare(ptr %zip, !107, !DIExpression(), !115)
  %0 = load ptr, ptr %argv.addr, align 8, !dbg !115
  %arrayidx = getelementptr inbounds ptr, ptr %0, i64 1, !dbg !115
  %1 = load ptr, ptr %arrayidx, align 8, !dbg !115
  %call = call ptr @fopen(ptr noundef %1, ptr noundef @"??_C@_02JDPG@rb?$AA@"), !dbg !115
  store ptr %call, ptr %zip, align 8, !dbg !115
  %2 = load ptr, ptr %zip, align 8, !dbg !116
  %tobool = icmp ne ptr %2, null, !dbg !116
  br i1 %tobool, label %if.end, label %if.then, !dbg !116

if.then:                                          ; preds = %entry
  store i32 1, ptr %retval, align 4, !dbg !117
  br label %return, !dbg !117

if.end:                                           ; preds = %entry
    #dbg_declare(ptr %header, !120, !DIExpression(), !136)
  %3 = load ptr, ptr %zip, align 8, !dbg !137
  %call1 = call i64 @fread(ptr noundef %header, i64 noundef 32, i64 noundef 1, ptr noundef %3), !dbg !137
  %signature = getelementptr inbounds nuw %struct.ZIP_HEADER, ptr %header, i32 0, i32 0, !dbg !138
  %4 = load i32, ptr %signature, align 4, !dbg !138
  %cmp = icmp ne i32 %4, 67324752, !dbg !138
  br i1 %cmp, label %if.then8, label %lor.lhs.false, !dbg !138

lor.lhs.false:                                    ; preds = %if.end
  %version = getelementptr inbounds nuw %struct.ZIP_HEADER, ptr %header, i32 0, i32 1, !dbg !138
  %5 = load i16, ptr %version, align 4, !dbg !138
  %conv = zext i16 %5 to i32, !dbg !138
  %cmp2 = icmp ne i32 %conv, 20, !dbg !138
  br i1 %cmp2, label %if.then8, label %lor.lhs.false4, !dbg !138

lor.lhs.false4:                                   ; preds = %lor.lhs.false
  %compressionMethod = getelementptr inbounds nuw %struct.ZIP_HEADER, ptr %header, i32 0, i32 3, !dbg !138
  %6 = load i16, ptr %compressionMethod, align 4, !dbg !138
  %conv5 = zext i16 %6 to i32, !dbg !138
  %cmp6 = icmp ne i32 %conv5, 8, !dbg !138
  br i1 %cmp6, label %if.then8, label %if.end10, !dbg !138

if.then8:                                         ; preds = %lor.lhs.false4, %lor.lhs.false, %if.end
  %7 = load ptr, ptr %zip, align 8, !dbg !139
  %call9 = call i32 @fclose(ptr noundef %7), !dbg !139
  store i32 0, ptr %retval, align 4, !dbg !142
  br label %return, !dbg !142

if.end10:                                         ; preds = %lor.lhs.false4
    #dbg_declare(ptr %filename, !143, !DIExpression(), !147)
  %8 = load ptr, ptr %zip, align 8, !dbg !148
  %filenameLength = getelementptr inbounds nuw %struct.ZIP_HEADER, ptr %header, i32 0, i32 9, !dbg !148
  %9 = load i16, ptr %filenameLength, align 4, !dbg !148
  %conv11 = zext i16 %9 to i64, !dbg !148
  %arraydecay = getelementptr inbounds [128 x i8], ptr %filename, i64 0, i64 0, !dbg !148
  %call12 = call i64 @fread(ptr noundef %arraydecay, i64 noundef 1, i64 noundef %conv11, ptr noundef %8), !dbg !148
  %arraydecay13 = getelementptr inbounds [128 x i8], ptr %filename, i64 0, i64 0, !dbg !149
  %call14 = call i32 (ptr, ...) @printf(ptr noundef @"??_C@_0N@HOJHICKB@Filename?3?5?$CFs?$AA@", ptr noundef %arraydecay13), !dbg !149
  %10 = load ptr, ptr %zip, align 8, !dbg !150
  %call15 = call i32 @fclose(ptr noundef %10), !dbg !150
  store i32 0, ptr %retval, align 4, !dbg !151
  br label %return, !dbg !151

return:                                           ; preds = %if.end10, %if.then8, %if.then
  %11 = load i32, ptr %retval, align 4, !dbg !152
  ret i32 %11, !dbg !152
}

declare dso_local ptr @fopen(ptr noundef, ptr noundef) #1

declare dso_local i64 @fread(ptr noundef, i64 noundef, i64 noundef, ptr noundef) #1

declare dso_local i32 @fclose(ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @printf(ptr noundef %_Format, ...) #0 comdat !dbg !153 {
entry:
  %_Format.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  %_ArgList = alloca ptr, align 8
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !156, !DIExpression(), !157)
    #dbg_declare(ptr %_Result, !158, !DIExpression(), !159)
    #dbg_declare(ptr %_ArgList, !160, !DIExpression(), !161)
  call void @llvm.va_start.p0(ptr %_ArgList), !dbg !162
  %0 = load ptr, ptr %_ArgList, align 8, !dbg !163
  %1 = load ptr, ptr %_Format.addr, align 8, !dbg !163
  %call = call ptr @__acrt_iob_func(i32 noundef 1), !dbg !163
  %call1 = call i32 @_vfprintf_l(ptr noundef %call, ptr noundef %1, ptr noundef null, ptr noundef %0), !dbg !163
  store i32 %call1, ptr %_Result, align 4, !dbg !163
  call void @llvm.va_end.p0(ptr %_ArgList), !dbg !164
  %2 = load i32, ptr %_Result, align 4, !dbg !165
  ret i32 %2, !dbg !165
}

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_start.p0(ptr) #2

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsprintf_l(ptr noundef %_Buffer, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat !dbg !166 {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Buffer.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
    #dbg_declare(ptr %_ArgList.addr, !182, !DIExpression(), !183)
  store ptr %_Locale, ptr %_Locale.addr, align 8
    #dbg_declare(ptr %_Locale.addr, !184, !DIExpression(), !185)
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !186, !DIExpression(), !187)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !188, !DIExpression(), !189)
  %0 = load ptr, ptr %_ArgList.addr, align 8, !dbg !190
  %1 = load ptr, ptr %_Locale.addr, align 8, !dbg !190
  %2 = load ptr, ptr %_Format.addr, align 8, !dbg !190
  %3 = load ptr, ptr %_Buffer.addr, align 8, !dbg !190
  %call = call i32 @_vsnprintf_l(ptr noundef %3, i64 noundef -1, ptr noundef %2, ptr noundef %1, ptr noundef %0), !dbg !190
  ret i32 %call, !dbg !190
}

; Function Attrs: nocallback nofree nosync nounwind willreturn
declare void @llvm.va_end.p0(ptr) #2

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vsnprintf_l(ptr noundef %_Buffer, i64 noundef %_BufferCount, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat !dbg !191 {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_BufferCount.addr = alloca i64, align 8
  %_Buffer.addr = alloca ptr, align 8
  %_Result = alloca i32, align 4
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
    #dbg_declare(ptr %_ArgList.addr, !194, !DIExpression(), !195)
  store ptr %_Locale, ptr %_Locale.addr, align 8
    #dbg_declare(ptr %_Locale.addr, !196, !DIExpression(), !197)
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !198, !DIExpression(), !199)
  store i64 %_BufferCount, ptr %_BufferCount.addr, align 8
    #dbg_declare(ptr %_BufferCount.addr, !200, !DIExpression(), !201)
  store ptr %_Buffer, ptr %_Buffer.addr, align 8
    #dbg_declare(ptr %_Buffer.addr, !202, !DIExpression(), !203)
    #dbg_declare(ptr %_Result, !204, !DIExpression(), !206)
  %0 = load ptr, ptr %_ArgList.addr, align 8, !dbg !206
  %1 = load ptr, ptr %_Locale.addr, align 8, !dbg !206
  %2 = load ptr, ptr %_Format.addr, align 8, !dbg !206
  %3 = load i64, ptr %_BufferCount.addr, align 8, !dbg !206
  %4 = load ptr, ptr %_Buffer.addr, align 8, !dbg !206
  %call = call ptr @__local_stdio_printf_options(), !dbg !206
  %5 = load i64, ptr %call, align 8, !dbg !206
  %or = or i64 %5, 1, !dbg !206
  %call1 = call i32 @__stdio_common_vsprintf(i64 noundef %or, ptr noundef %4, i64 noundef %3, ptr noundef %2, ptr noundef %1, ptr noundef %0), !dbg !206
  store i32 %call1, ptr %_Result, align 4, !dbg !206
  %6 = load i32, ptr %_Result, align 4, !dbg !207
  %cmp = icmp slt i32 %6, 0, !dbg !207
  br i1 %cmp, label %cond.true, label %cond.false, !dbg !207

cond.true:                                        ; preds = %entry
  br label %cond.end, !dbg !207

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %_Result, align 4, !dbg !207
  br label %cond.end, !dbg !207

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ -1, %cond.true ], [ %7, %cond.false ], !dbg !207
  ret i32 %cond, !dbg !207
}

declare dso_local i32 @__stdio_common_vsprintf(i64 noundef, ptr noundef, i64 noundef, ptr noundef, ptr noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local ptr @__local_stdio_printf_options() #0 comdat !dbg !14 {
entry:
  ret ptr @__local_stdio_printf_options._OptionsStorage, !dbg !208
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i32 @_vfprintf_l(ptr noundef %_Stream, ptr noundef %_Format, ptr noundef %_Locale, ptr noundef %_ArgList) #0 comdat !dbg !209 {
entry:
  %_ArgList.addr = alloca ptr, align 8
  %_Locale.addr = alloca ptr, align 8
  %_Format.addr = alloca ptr, align 8
  %_Stream.addr = alloca ptr, align 8
  store ptr %_ArgList, ptr %_ArgList.addr, align 8
    #dbg_declare(ptr %_ArgList.addr, !213, !DIExpression(), !214)
  store ptr %_Locale, ptr %_Locale.addr, align 8
    #dbg_declare(ptr %_Locale.addr, !215, !DIExpression(), !216)
  store ptr %_Format, ptr %_Format.addr, align 8
    #dbg_declare(ptr %_Format.addr, !217, !DIExpression(), !218)
  store ptr %_Stream, ptr %_Stream.addr, align 8
    #dbg_declare(ptr %_Stream.addr, !219, !DIExpression(), !220)
  %0 = load ptr, ptr %_ArgList.addr, align 8, !dbg !221
  %1 = load ptr, ptr %_Locale.addr, align 8, !dbg !221
  %2 = load ptr, ptr %_Format.addr, align 8, !dbg !221
  %3 = load ptr, ptr %_Stream.addr, align 8, !dbg !221
  %call = call ptr @__local_stdio_printf_options(), !dbg !221
  %4 = load i64, ptr %call, align 8, !dbg !221
  %call1 = call i32 @__stdio_common_vfprintf(i64 noundef %4, ptr noundef %3, ptr noundef %2, ptr noundef %1, ptr noundef %0), !dbg !221
  ret i32 %call1, !dbg !221
}

declare dso_local ptr @__acrt_iob_func(i32 noundef) #1

declare dso_local i32 @__stdio_common_vfprintf(i64 noundef, ptr noundef, ptr noundef, ptr noundef, ptr noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn }

!llvm.dbg.cu = !{!20}
!llvm.module.flags = !{!28, !29, !30, !31, !32, !33}
!llvm.ident = !{!34}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 22, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "zip.c", directory: "D:\\irsentry\\tests\\c\\zip", checksumkind: CSK_MD5, checksum: "0a71119d61cb346db6ce20bf55402261")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 24, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 3)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 38, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 104, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 13)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(name: "_OptionsStorage", scope: !14, file: !15, line: 91, type: !19, isLocal: true, isDefinition: true)
!14 = distinct !DISubprogram(name: "__local_stdio_printf_options", scope: !15, file: !15, line: 89, type: !16, scopeLine: 90, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20)
!15 = !DIFile(filename: "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.26100.0\\ucrt\\corecrt_stdio_config.h", directory: "", checksumkind: CSK_MD5, checksum: "dacf907bda504afb0b64f53a242bdae6")
!16 = !DISubroutineType(types: !17)
!17 = !{!18}
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !19, size: 64)
!19 = !DIBasicType(name: "unsigned long long", size: 64, encoding: DW_ATE_unsigned)
!20 = distinct !DICompileUnit(language: DW_LANG_C11, file: !2, producer: "clang version 20.1.0", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, retainedTypes: !21, globals: !27, splitDebugInlining: false, nameTableKind: None)
!21 = !{!22, !25}
!22 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint16_t", file: !23, line: 23, baseType: !24)
!23 = !DIFile(filename: "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.44.35207\\include\\stdint.h", directory: "", checksumkind: CSK_MD5, checksum: "56e2956fe219a08d408dc2fb7a857cfc")
!24 = !DIBasicType(name: "unsigned short", size: 16, encoding: DW_ATE_unsigned)
!25 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !26, line: 188, baseType: !19)
!26 = !DIFile(filename: "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.44.35207\\include\\vcruntime.h", directory: "", checksumkind: CSK_MD5, checksum: "52b0f67d23fb299eb670469dd77ef832")
!27 = !{!0, !7, !12}
!28 = !{i32 2, !"CodeView", i32 1}
!29 = !{i32 2, !"Debug Info Version", i32 3}
!30 = !{i32 1, !"wchar_size", i32 2}
!31 = !{i32 8, !"PIC Level", i32 2}
!32 = !{i32 7, !"uwtable", i32 2}
!33 = !{i32 1, !"MaxTLSAlign", i32 65536}
!34 = !{!"clang version 20.1.0"}
!35 = distinct !DISubprogram(name: "sprintf", scope: !36, file: !36, line: 1764, type: !37, scopeLine: 1771, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!36 = !DIFile(filename: "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.26100.0\\ucrt\\stdio.h", directory: "", checksumkind: CSK_MD5, checksum: "c1a1fbc43e7d45f0ea4ae539ddcffb19")
!37 = !DISubroutineType(types: !38)
!38 = !{!39, !40, !42, null}
!39 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!40 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !41)
!41 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !4, size: 64)
!42 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !43)
!43 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !44, size: 64)
!44 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!45 = !{}
!46 = !DILocalVariable(name: "_Format", arg: 2, scope: !35, file: !36, line: 1766, type: !42)
!47 = !DILocation(line: 1766, scope: !35)
!48 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !35, file: !36, line: 1765, type: !40)
!49 = !DILocation(line: 1765, scope: !35)
!50 = !DILocalVariable(name: "_Result", scope: !35, file: !36, line: 1772, type: !39)
!51 = !DILocation(line: 1772, scope: !35)
!52 = !DILocalVariable(name: "_ArgList", scope: !35, file: !36, line: 1773, type: !53)
!53 = !DIDerivedType(tag: DW_TAG_typedef, name: "va_list", file: !54, line: 72, baseType: !41)
!54 = !DIFile(filename: "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.44.35207\\include\\vadefs.h", directory: "", checksumkind: CSK_MD5, checksum: "a4b8f96637d0704c82f39ecb6bde2ab4")
!55 = !DILocation(line: 1773, scope: !35)
!56 = !DILocation(line: 1774, scope: !35)
!57 = !DILocation(line: 1776, scope: !35)
!58 = !DILocation(line: 1778, scope: !35)
!59 = !DILocation(line: 1779, scope: !35)
!60 = distinct !DISubprogram(name: "vsprintf", scope: !36, file: !36, line: 1465, type: !61, scopeLine: 1473, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!61 = !DISubroutineType(types: !62)
!62 = !{!39, !40, !42, !53}
!63 = !DILocalVariable(name: "_ArgList", arg: 3, scope: !60, file: !36, line: 1468, type: !53)
!64 = !DILocation(line: 1468, scope: !60)
!65 = !DILocalVariable(name: "_Format", arg: 2, scope: !60, file: !36, line: 1467, type: !42)
!66 = !DILocation(line: 1467, scope: !60)
!67 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !60, file: !36, line: 1466, type: !40)
!68 = !DILocation(line: 1466, scope: !60)
!69 = !DILocation(line: 1474, scope: !60)
!70 = distinct !DISubprogram(name: "_snprintf", scope: !36, file: !36, line: 1939, type: !71, scopeLine: 1947, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!71 = !DISubroutineType(types: !72)
!72 = !{!39, !40, !73, !42, null}
!73 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !25)
!74 = !DILocalVariable(name: "_Format", arg: 3, scope: !70, file: !36, line: 1942, type: !42)
!75 = !DILocation(line: 1942, scope: !70)
!76 = !DILocalVariable(name: "_BufferCount", arg: 2, scope: !70, file: !36, line: 1941, type: !73)
!77 = !DILocation(line: 1941, scope: !70)
!78 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !70, file: !36, line: 1940, type: !40)
!79 = !DILocation(line: 1940, scope: !70)
!80 = !DILocalVariable(name: "_Result", scope: !70, file: !36, line: 1948, type: !39)
!81 = !DILocation(line: 1948, scope: !70)
!82 = !DILocalVariable(name: "_ArgList", scope: !70, file: !36, line: 1949, type: !53)
!83 = !DILocation(line: 1949, scope: !70)
!84 = !DILocation(line: 1950, scope: !70)
!85 = !DILocation(line: 1951, scope: !70)
!86 = !DILocation(line: 1952, scope: !70)
!87 = !DILocation(line: 1953, scope: !70)
!88 = distinct !DISubprogram(name: "_vsnprintf", scope: !36, file: !36, line: 1402, type: !89, scopeLine: 1411, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!89 = !DISubroutineType(types: !90)
!90 = !{!39, !40, !73, !42, !53}
!91 = !DILocalVariable(name: "_ArgList", arg: 4, scope: !88, file: !36, line: 1406, type: !53)
!92 = !DILocation(line: 1406, scope: !88)
!93 = !DILocalVariable(name: "_Format", arg: 3, scope: !88, file: !36, line: 1405, type: !42)
!94 = !DILocation(line: 1405, scope: !88)
!95 = !DILocalVariable(name: "_BufferCount", arg: 2, scope: !88, file: !36, line: 1404, type: !73)
!96 = !DILocation(line: 1404, scope: !88)
!97 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !88, file: !36, line: 1403, type: !40)
!98 = !DILocation(line: 1403, scope: !88)
!99 = !DILocation(line: 1412, scope: !88)
!100 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 21, type: !101, scopeLine: 21, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!101 = !DISubroutineType(types: !102)
!102 = !{!39, !39, !103}
!103 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !41, size: 64)
!104 = !DILocalVariable(name: "argv", arg: 2, scope: !100, file: !2, line: 21, type: !103)
!105 = !DILocation(line: 21, scope: !100)
!106 = !DILocalVariable(name: "argc", arg: 1, scope: !100, file: !2, line: 21, type: !39)
!107 = !DILocalVariable(name: "zip", scope: !100, file: !2, line: 22, type: !108)
!108 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !109, size: 64)
!109 = !DIDerivedType(tag: DW_TAG_typedef, name: "FILE", file: !110, line: 31, baseType: !111)
!110 = !DIFile(filename: "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.26100.0\\ucrt\\corecrt_wstdio.h", directory: "", checksumkind: CSK_MD5, checksum: "bf50373b435d0afd0235dd3e05c4a277")
!111 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "_iobuf", file: !110, line: 28, size: 64, align: 64, elements: !112)
!112 = !{!113}
!113 = !DIDerivedType(tag: DW_TAG_member, name: "_Placeholder", scope: !111, file: !110, line: 30, baseType: !114, size: 64)
!114 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!115 = !DILocation(line: 22, scope: !100)
!116 = !DILocation(line: 23, scope: !100)
!117 = !DILocation(line: 24, scope: !118)
!118 = distinct !DILexicalBlock(scope: !119, file: !2, line: 23)
!119 = distinct !DILexicalBlock(scope: !100, file: !2, line: 23)
!120 = !DILocalVariable(name: "header", scope: !100, file: !2, line: 27, type: !121)
!121 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "ZIP_HEADER", file: !2, line: 7, size: 256, elements: !122)
!122 = !{!123, !126, !127, !128, !129, !130, !131, !132, !133, !134, !135}
!123 = !DIDerivedType(tag: DW_TAG_member, name: "signature", scope: !121, file: !2, line: 8, baseType: !124, size: 32)
!124 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint32_t", file: !23, line: 24, baseType: !125)
!125 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!126 = !DIDerivedType(tag: DW_TAG_member, name: "version", scope: !121, file: !2, line: 9, baseType: !22, size: 16, offset: 32)
!127 = !DIDerivedType(tag: DW_TAG_member, name: "flags", scope: !121, file: !2, line: 10, baseType: !22, size: 16, offset: 48)
!128 = !DIDerivedType(tag: DW_TAG_member, name: "compressionMethod", scope: !121, file: !2, line: 11, baseType: !22, size: 16, offset: 64)
!129 = !DIDerivedType(tag: DW_TAG_member, name: "lastModTime", scope: !121, file: !2, line: 12, baseType: !22, size: 16, offset: 80)
!130 = !DIDerivedType(tag: DW_TAG_member, name: "lastModDate", scope: !121, file: !2, line: 13, baseType: !22, size: 16, offset: 96)
!131 = !DIDerivedType(tag: DW_TAG_member, name: "crc32", scope: !121, file: !2, line: 14, baseType: !124, size: 32, offset: 128)
!132 = !DIDerivedType(tag: DW_TAG_member, name: "compressedSize", scope: !121, file: !2, line: 15, baseType: !124, size: 32, offset: 160)
!133 = !DIDerivedType(tag: DW_TAG_member, name: "uncompressedSize", scope: !121, file: !2, line: 16, baseType: !124, size: 32, offset: 192)
!134 = !DIDerivedType(tag: DW_TAG_member, name: "filenameLength", scope: !121, file: !2, line: 17, baseType: !22, size: 16, offset: 224)
!135 = !DIDerivedType(tag: DW_TAG_member, name: "extrafieldLength", scope: !121, file: !2, line: 18, baseType: !22, size: 16, offset: 240)
!136 = !DILocation(line: 27, scope: !100)
!137 = !DILocation(line: 28, scope: !100)
!138 = !DILocation(line: 29, scope: !100)
!139 = !DILocation(line: 31, scope: !140)
!140 = distinct !DILexicalBlock(scope: !141, file: !2, line: 30)
!141 = distinct !DILexicalBlock(scope: !100, file: !2, line: 29)
!142 = !DILocation(line: 32, scope: !140)
!143 = !DILocalVariable(name: "filename", scope: !100, file: !2, line: 36, type: !144)
!144 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 1024, elements: !145)
!145 = !{!146}
!146 = !DISubrange(count: 128)
!147 = !DILocation(line: 36, scope: !100)
!148 = !DILocation(line: 37, scope: !100)
!149 = !DILocation(line: 38, scope: !100)
!150 = !DILocation(line: 40, scope: !100)
!151 = !DILocation(line: 41, scope: !100)
!152 = !DILocation(line: 42, scope: !100)
!153 = distinct !DISubprogram(name: "printf", scope: !36, file: !36, line: 950, type: !154, scopeLine: 956, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!154 = !DISubroutineType(types: !155)
!155 = !{!39, !42, null}
!156 = !DILocalVariable(name: "_Format", arg: 1, scope: !153, file: !36, line: 951, type: !42)
!157 = !DILocation(line: 951, scope: !153)
!158 = !DILocalVariable(name: "_Result", scope: !153, file: !36, line: 957, type: !39)
!159 = !DILocation(line: 957, scope: !153)
!160 = !DILocalVariable(name: "_ArgList", scope: !153, file: !36, line: 958, type: !53)
!161 = !DILocation(line: 958, scope: !153)
!162 = !DILocation(line: 959, scope: !153)
!163 = !DILocation(line: 960, scope: !153)
!164 = !DILocation(line: 961, scope: !153)
!165 = !DILocation(line: 962, scope: !153)
!166 = distinct !DISubprogram(name: "_vsprintf_l", scope: !36, file: !36, line: 1449, type: !167, scopeLine: 1458, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!167 = !DISubroutineType(types: !168)
!168 = !{!39, !40, !42, !169, !53}
!169 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !170)
!170 = !DIDerivedType(tag: DW_TAG_typedef, name: "_locale_t", file: !171, line: 623, baseType: !172)
!171 = !DIFile(filename: "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.26100.0\\ucrt\\corecrt.h", directory: "", checksumkind: CSK_MD5, checksum: "4ce81db8e96f94c79f8dce86dd46b97f")
!172 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !173, size: 64)
!173 = !DIDerivedType(tag: DW_TAG_typedef, name: "__crt_locale_pointers", file: !171, line: 621, baseType: !174)
!174 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "__crt_locale_pointers", file: !171, line: 617, size: 128, align: 64, elements: !175)
!175 = !{!176, !179}
!176 = !DIDerivedType(tag: DW_TAG_member, name: "locinfo", scope: !174, file: !171, line: 619, baseType: !177, size: 64)
!177 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !178, size: 64)
!178 = !DICompositeType(tag: DW_TAG_structure_type, name: "__crt_locale_data", file: !171, line: 619, flags: DIFlagFwdDecl)
!179 = !DIDerivedType(tag: DW_TAG_member, name: "mbcinfo", scope: !174, file: !171, line: 620, baseType: !180, size: 64, offset: 64)
!180 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !181, size: 64)
!181 = !DICompositeType(tag: DW_TAG_structure_type, name: "__crt_multibyte_data", file: !171, line: 620, flags: DIFlagFwdDecl)
!182 = !DILocalVariable(name: "_ArgList", arg: 4, scope: !166, file: !36, line: 1453, type: !53)
!183 = !DILocation(line: 1453, scope: !166)
!184 = !DILocalVariable(name: "_Locale", arg: 3, scope: !166, file: !36, line: 1452, type: !169)
!185 = !DILocation(line: 1452, scope: !166)
!186 = !DILocalVariable(name: "_Format", arg: 2, scope: !166, file: !36, line: 1451, type: !42)
!187 = !DILocation(line: 1451, scope: !166)
!188 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !166, file: !36, line: 1450, type: !40)
!189 = !DILocation(line: 1450, scope: !166)
!190 = !DILocation(line: 1459, scope: !166)
!191 = distinct !DISubprogram(name: "_vsnprintf_l", scope: !36, file: !36, line: 1381, type: !192, scopeLine: 1391, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!192 = !DISubroutineType(types: !193)
!193 = !{!39, !40, !73, !42, !169, !53}
!194 = !DILocalVariable(name: "_ArgList", arg: 5, scope: !191, file: !36, line: 1386, type: !53)
!195 = !DILocation(line: 1386, scope: !191)
!196 = !DILocalVariable(name: "_Locale", arg: 4, scope: !191, file: !36, line: 1385, type: !169)
!197 = !DILocation(line: 1385, scope: !191)
!198 = !DILocalVariable(name: "_Format", arg: 3, scope: !191, file: !36, line: 1384, type: !42)
!199 = !DILocation(line: 1384, scope: !191)
!200 = !DILocalVariable(name: "_BufferCount", arg: 2, scope: !191, file: !36, line: 1383, type: !73)
!201 = !DILocation(line: 1383, scope: !191)
!202 = !DILocalVariable(name: "_Buffer", arg: 1, scope: !191, file: !36, line: 1382, type: !40)
!203 = !DILocation(line: 1382, scope: !191)
!204 = !DILocalVariable(name: "_Result", scope: !191, file: !36, line: 1392, type: !205)
!205 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !39)
!206 = !DILocation(line: 1392, scope: !191)
!207 = !DILocation(line: 1396, scope: !191)
!208 = !DILocation(line: 92, scope: !14)
!209 = distinct !DISubprogram(name: "_vfprintf_l", scope: !36, file: !36, line: 635, type: !210, scopeLine: 644, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !20, retainedNodes: !45)
!210 = !DISubroutineType(types: !211)
!211 = !{!39, !212, !42, !169, !53}
!212 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !108)
!213 = !DILocalVariable(name: "_ArgList", arg: 4, scope: !209, file: !36, line: 639, type: !53)
!214 = !DILocation(line: 639, scope: !209)
!215 = !DILocalVariable(name: "_Locale", arg: 3, scope: !209, file: !36, line: 638, type: !169)
!216 = !DILocation(line: 638, scope: !209)
!217 = !DILocalVariable(name: "_Format", arg: 2, scope: !209, file: !36, line: 637, type: !42)
!218 = !DILocation(line: 637, scope: !209)
!219 = !DILocalVariable(name: "_Stream", arg: 1, scope: !209, file: !36, line: 636, type: !212)
!220 = !DILocation(line: 636, scope: !209)
!221 = !DILocation(line: 645, scope: !209)
