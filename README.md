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
7. Refactor accepted types in bit instructions

# Elementy do opisania
- Generatory Python'a kodu C++ bazuj¹c na `.g4`,
- Memory layout (porównanie kilku layoutów) dla:
	- Klasy i listy instrukcji,
	- Drzewa binarnego CFG.
- Porównanie std::variant vs polimorfizm. Porównanie cache miss i hitów, zu¿ycia pamiêci i szybkoœæ przeszukiwania std::vector'a.