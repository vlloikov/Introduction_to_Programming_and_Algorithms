# Lab 03 — Branching. Logical operators

A small educational C++ project containing several independent console utilities.
The project demonstrates basic input validation, conditional logic, unit conversion, and a simple cash withdrawal algorithm.

## Structure

```text
.
├── lab03.cpp
└── README.md
```

  | Function | Purpose |
  |---|---|
  | `ClearInput()` | Resets `std::cin` state and discards the buffer after a failed read |
  | `IsRange()` | Checks whether a value belongs to the specified range |
  | `ConvertToMeters()` | Converts a value to meters |
  | `WithdrawCash()` | Calculates the banknotes required for a withdrawal |

---

## Usage

The program runs three calculators sequentially, reading values from stdin:

1. **IsRange** — enter a value to check if it belongs to the specified range.
2. **ConvertToMeters** — enter a value and its unit to convert it to meters.
3. **WithdrawCash** — enter the amount to withdraw (must be a multiple of 100 and not exceed 100,000).

Invalid input (non-numeric, negative, or zero where not allowed) produces an error message and skips the corresponding calculation.

### Example
```C++
int main()
{
    IsRange();
}
```
Or any other function what you want to use

---

## Features

The program currently includes three utilities:

### 1. Range Check

Checks whether an integer value belongs to the range **[10, 20]**.

* Validates user input.
* Handles invalid input.
* Determines whether the entered value is inside or outside the specified range.

### 2. Unit Converter

Converts a value from one of the following units to meters:

* `cm` — centimeters
* `m` — meters
* `km` — kilometers

The program validates the entered value and reports an error for unsupported units.

### 3. Cash Withdrawal

Simulates a simple ATM cash withdrawal.

The entered amount must:

* be a multiple of `100`;
* not exceed `100,000`;
* be a non-negative integer.

The program calculates the minimum number of banknotes required using the following denominations:

```text
5000
2000
1000
100
```

The banknotes are processed from the largest denomination to the smallest.

---

## Technologies

* **C++**
* **Standard Library**
* `iostream` — console input/output
* `iomanip` — output formatting
* `limits` — input stream management

---

## Input Validation

The program handles several types of invalid input:

* non-numeric input where a number is expected;
* negative values where they are not allowed;
* withdrawal amounts greater than `100000`;
* withdrawal amounts that are not multiples of `100`;
* unsupported measurement units.

Invalid input is handled by clearing the standard input stream before returning from the corresponding function.

---

## License

This project is available under the [Apache License Version 2.0](../../LICENSE).
