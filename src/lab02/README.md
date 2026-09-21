# Lab 2 — Variables and Arithmetic Operations

Console C++ program demonstrating variable types, arithmetic operations, and explicit/implicit type casting.

## Structure
```aiignore
lab02/
├── README.md
└── lab02.cpp
```

| Function | Purpose |
|---|---|
| `ClearInput()` | Resets `std::cin` state and discards the buffer after a failed read |
| `CalculateCircumference()` | Computes circumference from radius: `2 * PI * R` |
| `ConvertkilometersphToMetersps()` | Converts km/h to m/s |
| `CalculateBMI()` | Computes BMI and prints weight category |

## Usage

The program runs three calculators sequentially, reading values from stdin:

1. **Circumference** — enter radius (non-negative number).
2. **Speed conversion** — enter speed in km/h (non-negative number).
3. **BMI** — enter weight in kg and height in cm (both positive).

Invalid input (non-numeric, negative, or zero where not allowed) produces an error message and skips the corresponding calculation.

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
- Floating-point literals (`3600.0`, `1000.0`, `100.0`) are used to prevent integer division.
- Input validation uses `std::cin.fail()` combined with `ClearInput()`.
- Output is formatted with `std::fixed` and `std::setprecision(2)`.
- BMI categories follow standard thresholds: `< 18.5` underweight, `18.5–24.9` normal, `25–29.9` overweight, `≥ 30` obese.
---

## License

This project is available under the [Apache License Version 2.0](../../LICENSE).