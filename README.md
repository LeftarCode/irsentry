# Build
- Generate project
```bash
cmake -S . -B build
```

- Build project
```bash
cmake --build build --config Release
cmake --build build --config Debug
```
# Requirements
## Development
Development on Windows is strongly discouraged, it require Debug build of LLVM which require ~100GB free space. But feel free to build Release version!

# TODO
1. Better gramma for param attributes.
2. Make CMake to update `IRSENTRY_REVISION` var.
3. Create GitHub Actions:
	1. Linter,
	2. Tests,
	3. Build binaries,
	4. Build documentation,
	5. Upload to GitHub.
4. Support case where function is defined inside another function (check if that's possible).
5. Change submodule antlr4 module name from antrl4 to antlr4.
6. Quite possible that SInstr and UInstr accept both Integer and UInteger??
7. Refactor accepted types in bit instructions - all numeric types are allowed?
8. Value in instructions can accept constExpressions, which can contain another instruction, but that nested instruction can use only const values (number literals or variable).
	- It's worth to unroll that expression and write it as an another variable e.g.:
```
%res = addi (addi %0, %1), %2

%sse_result_0 = addi %0, %1
%res = addi %sse_result_0, %2
```
9. Support VA args.
10. Add nofree and willreturn to attributes.
11. Fix warning with `immarg` in `tests/c/init_perf1/init_perf1.ll`:
```
This indicates the parameter is required to be an immediate value. This must be a trivial immediate integer or floating-point constant. Undef or constant expressions are not valid. This is only valid on intrinsic declarations and cannot be applied to a call site or arbitrary function.
```
12. Update documentation for all classes.
13. Organize CMake files
14. Make CMake more flexible, add some options eg.:
	1. Add option to build irsentry with static linking oraz dynamic.
	1. 
15. Test CMake under Linux and macOS.
16. Write more requirements that are needed to build the tools (like LLVM).
17. Adjust all CMake condtions to work with Linux and macOS.
18. Write small step-by-step tutorial how to build that tool.
19. Delete UnsignedIntegers!
# Elementy do opisania
- Generatory Python'a kodu C++ bazuj�c na `.g4`,
- Memory layout (por�wnanie kilku layout�w) dla:
	- Klasy i listy instrukcji,
	- Drzewa binarnego CFG.
- Por�wnanie std::variant vs polimorfizm. Por�wnanie cache miss i hit�w, zu�ycia pami�ci i szybko�� przeszukiwania std::vector'a.
- Unrolling wyra�e� zagnie�d�onych