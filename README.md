[![License: Apache 2.0](https://img.shields.io/badge/License-Apache%202.0-green.svg)](../../LICENSE)

---

# C++ Labs

A collection of laboratory works for a C++ course. Each lab is a standalone console program demonstrating a specific set of language features — from basic types and arithmetic to more advanced topics.

## Labs

| # | Topic | Status | Link |
|---|---|---|---|
| 1 | First program | ✅ done | [lab1](./src/lab01/README.md) |
| 2 | Variables and Arithmetic Operations | ✅ done | [lab2](./src/lab02/README.md) |
| 3 | Branching. Logical operators | ✅ done | [lab3](./src/lab03/README.md) |
| 4 | Switch statement. Nested loops | ✅ done | [lab4](./src/lab04/README.md) |
> Status legend: ✅ done · 🚧 in progress · _planned_ 

## Structure
```aiignore
├── src/
│ ├── lab01/
│ │ ├── lab01.cpp
│ │ └── README.md
│ └── labxx/
│ ├── labxx.cpp
│ └── README.md
├── .clang-format
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```
Each lab folder contains its own `README.md` with a description, usage instructions, and implementation notes.

---
## Requirements

- A C++ compiler with support for C++11 or later (e.g., `g++`, `clang++`, MSVC).

---

## Build

Using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra -o console_utils ./labxx/labxx.cpp
```
---
## Run
On linux:
```bash
./console_utils
```
On Windows
```bash
console_utils.exe
```

---
## License

This project is available under the [Apache License Version 2.0](../../LICENSE).