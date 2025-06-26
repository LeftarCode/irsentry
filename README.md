# IRSentry – Static LLVM IR Vulnerability Analyzer 🛡️

> *"Transform code into paths, and paths into proofs of vulnerability."*

## 📖 Project Overview

**IRSentry** is a command‑line tool for static analysis of LLVM IR code. It automatically discovers potential security vulnerabilities and generates concrete inputs to reproduce them. By combining **Symbolic Execution** with a **Symbolic Memory** model and leveraging the power of the Z3 SMT solver, IRSentry precisely tracks data flow from user inputs to risky function calls ("hotspots").

## 🚀 Key Features

- **Language Agnostic** – Analyze any source language compiled to LLVM IR.
- **Symbolic Execution Engine** – Explore execution paths symbolically, preserving constraints along the way.
- **Symbolic Memory Model** – Accurately represent buffer and pointer operations in memory.
- **Automated Proof Generation** – Convert path constraints into SMT formulas and obtain concrete inputs via Z3.
- **FTXUI-based CLI** – Intuitive terminal interface for configuring and running analyses.
- **Doxygen Documentation** – Comprehensive docs generated directly from the source code.

## 🎯 Architecture Overview

1. **LLVM Front-End**: Parse LLVM IR and build the Control Flow Graph (CFG).
2. **Input Discovery**: Identify potential user inputs (`argv`, `fread`, `recv`, etc.).
3. **Hotspot Detection**: Recognize unsafe functions (`strcpy`, `memcpy`, etc.) and patterns.
4. **Symbolic Engine**: Traverse paths between inputs and hotspots, collecting symbolic constraints.
5. **SMT Solving**: Translate each path into an SMT formula and derive concrete inputs with Z3.

## ⚙️ Requirements

- **C++17** or newer
- **LLVM** (v12 or later)
- **Z3** C++ API
- **CMake**
- **FTXUI** (terminal UI)

## 🛠️ Installation & Build Instructions

```bash
# Clone the repository
git clone https://github.com/YourUser/IRSentry.git
cd IRSentry

# Create and enter build directory
mkdir build && cd build

# Configure the project
cmake ..

# Build
make -j$(nproc)
```

## ▶️ Usage Examples

```bash
# Analyze an LLVM IR file and output results in JSON
./irsentry --input path/to/program.ll --output report.json

# Launch the interactive FTXUI interface
./irsentry --interactive
```

## 📚 Documentation

Generate and view the Doxygen documentation:

```bash
cd docs
doxygen Doxyfile
# Open docs/html/index.html in your browser
```

## 🤝 Contributing

Found a bug or have an idea for improvement? Feel free to open an issue or submit a pull request on GitHub!

## 📄 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

*IRSentry* – Your first line of defense on the path to secure code!

