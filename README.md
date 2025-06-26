# IRSentry – Static LLVM IR Vulnerability Analyzer 🛡️

> *"Transform code into paths, and paths into proofs of vulnerability."*

## 📖 Project Overview

**IRSentry** is a C++ CLI tool for static analysis of LLVM IR. It employs **Path-Guided Symbolic Execution** with **Function Summaries** and a **Symbolic Memory** model, all powered by the Z3 SMT solver. IRSentry tracks data flow from user inputs to unsafe calls, then generates concrete inputs to reproduce vulnerabilities.

## 🚀 Key Features

- **Language Agnostic** – Works on any source language compiled to LLVM IR.
- **Path-Guided Symbolic Execution** – Direct analysis along likely paths with pruning.
- **Function Summaries** – Reuse summarized constraints to boost performance and scalability.
- **Symbolic Memory Model** – Precise handling of buffers, pointers, and memory operations.
- **Automated Proof Generation** – Convert path constraints to SMT and extract inputs with Z3.
- **FTXUI CLI** – User-friendly terminal interface for configuration and execution.
- **Doxygen Documentation** – Auto-generated code docs for easy exploration.

## 🎯 Architecture Overview

1. **LLVM Front-End**: Parse LLVM IR and build the Control Flow Graph (CFG).
2. **Input Discovery**: Locate user-controlled data (`argv`, `fread`, `recv`, etc.).
3. **Hotspot Detection**: Identify unsafe functions (`strcpy`, `memcpy`, etc.).
4. **Symbolic Engine**:
   - **Path-Guided Exploration**: Prioritize feasible paths based on heuristics.
   - **Function Summaries**: Apply pre-computed summaries for scalable interprocedural analysis.
   - **Constraint Collection**: Formulate path constraints symbolically.
5. **SMT Solving**: Translate constraints to SMT queries and derive concrete inputs with Z3.

## ⚙️ Requirements

- **C++17** or newer
- **LLVM** (v12 or later)
- **Z3** C++ API
- **CMake**
- **FTXUI** (terminal UI)

## 🛠️ Installation & Build

```bash
# Clone the repo
git clone https://github.com/YourUser/IRSentry.git
cd IRSentry

# Create build directory
mkdir build && cd build

# Configure and build
cmake .. && make -j$(nproc)
```

## ▶️ Usage Examples

```bash
# Static analysis and JSON report
./irsentry --input path/to/program.ll --output report.json

# Interactive FTXUI mode
./irsentry --interactive
```

## 📚 Documentation

```bash
cd docs && doxygen Doxyfile
# Open docs/html/index.html
```

## 🤝 Contributing

Issues, ideas, and pull requests are welcome!

## 📄 License

Licensed under the **MIT License**. See [LICENSE](LICENSE).

---

*IRSentry* – Your first line of defense on the path to secure code!

