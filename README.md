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