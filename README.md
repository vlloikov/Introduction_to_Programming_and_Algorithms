[![License: Apache 2.0](https://img.shields.io/badge/License-Apache%202.0-green.svg)](LICENSE)
# Console Utilities

A small C++ console application that bundles three simple utilities:

1. **Circumference Calculator** — computes the circumference of a circle from its radius.
2. **Seconds Converter** — converts a number of seconds into hours, minutes, and seconds.
3. **Currency Converter** — converts rubles to dollars and euros using user-provided exchange rates.

---

## Features

- Interactive console flow (functions run sequentially).
- Input validation for non-numeric input, negative numbers, and zero or negative exchange rates.
- Automatic stream cleanup after invalid input.
- Formatted floating-point output with fixed precision (`std::fixed`, `std::setprecision`).

---

## Requirements

- A C++ compiler with support for C++11 or later (e.g., `g++`, `clang++`, MSVC).

---

## Build

Using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra -o console_utils main.cpp
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

This project is available under the [Apache License Version 2.0](LICENSE).