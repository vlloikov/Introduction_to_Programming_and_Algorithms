# Lab 1 — First program

Console C++ program demonstrating variable types, arithmetic operations, and explicit/implicit type casting.

## Structure
```aiignore
lab01/
├── README.md
└── lab01.cpp
```

| Function | Purpose |
|---|---|
| `ClearInput()` | Resets `std::cin` state and discards the buffer after a failed read |
| `CalculateCircumference()` | Computes the circumference of a circle from its radius: `2 * PI * R` |
| `ConvertkilometersphToMetersps()` | Converts speed from km/h to m/s |
| `CalculateBMI()` | Computes BMI and prints the weight category |

## Usage

The program runs three calculators sequentially, reading values from `stdin`:

1. **Circumference** — enter radius (non-negative number).
2. **Speed conversion** — enter speed in km/h (non-negative number).
3. **BMI** — enter weight in kg and height in cm (both positive).

Invalid input (non-numeric, negative, or zero where not allowed) produces an error message on `stderr` and skips the corresponding calculation.

### Example
```C++
int main()
{
    CalculateCircumference();
}
```
Or any other function what you want to use

---

## Implementation notes

- All floating-point values use `double` to avoid precision loss.
- `PI` is declared `const` and never changes.
- `SECONDS_IN_HOUR` and `SECONDS_IN_MINUTE` are declared `const int` to avoid magic numbers.
- `SecondsToHours()` demonstrates integer division (`/`) and the modulo operator (`%`) for extracting hours, minutes, and seconds.
- `CurrencyConversion()` uses `static_cast<double>` to ensure floating-point division.
- Input validation uses `std::cin.fail()` combined with `ClearInput()`.
- Output is formatted with `std::fixed`, `std::setprecision(2)`, and `std::setw(12)` for table alignment.

---

## License

This project is available under the [Apache License Version 2.0](../../LICENSE).