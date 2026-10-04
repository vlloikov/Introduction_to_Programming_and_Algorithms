# Lab 04 — Switch Statement

A small educational C++ project containing three independent console utilities.
The project demonstrates the `switch` statement, nested branching, loops, input validation, and answer checking.

## Structure

```text
.
├── lab04.cpp
└── README.md
```

| Function | Purpose |
|---|---|
| `ClearInput()` | Resets `std::cin` state and discards the rest of the input line after a failed read |
| `ShowAction()` | Displays an action corresponding to the entered code |
| `ShowNumberInEnglish()` | Displays the English name of an integer from 1 to 10 |
| `RunExaminer()` | Runs a five-question exam on the selected programming language |

---

## Usage

Compile and run the program from the directory containing `lab04.cpp`:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic lab04.cpp -o lab04
./lab04
```

The program runs three utilities sequentially, reading values from standard input:

1. **ShowAction** — enter `1`, `2`, or `3` to display Start, Pause, or Stop.
2. **ShowNumberInEnglish** — enter an integer from `1` to `10` to display its English name.
3. **RunExaminer** — select C++, Python, or Java and answer five questions. Enter `0` in the topic menu to exit.

Invalid input in the first two utilities produces an error message and moves execution to the next utility. The examiner repeats the current prompt after invalid input.

### Example

To run only the examiner, change `main()` to:

```cpp
int main() {
  RunExaminer();
}
```

You can call any of the other utilities in the same way.

---

## Features

### 1. Action Selection

Uses `switch` to display an action based on its code:

| Code | Action |
|---|---|
| `1` | Start |
| `2` | Pause |
| `3` | Stop |

An unsupported code produces an error message.

### 2. Number in English

Displays the English name of an integer in the range **[1, 10]**: One, Two, Three, Four, Five, Six, Seven, Eight, Nine, or Ten.

Each number is handled by a separate `case`. Values outside the range are handled by `default`.

### 3. Programming Examiner

Offers three topics:

* **C++**
* **Python**
* **Java**

Each topic contains **five predefined questions** presented in a fixed order. Every question has four answer options.

* A nested `switch` selects the topic and the question.
* A `for` loop presents the five questions.
* A `do ... while` loop repeats the answer prompt until the user enters a value from `1` to `4`.
* Correct answers increase the score by one.
* Incorrect answers display the correct option number.

After the exam, the program displays the score out of five and returns to the topic menu. The user can take another exam or enter `0` to exit. The score resets before each new exam.

---

## Technologies

* **C++17**
* **Standard Library**
* `iostream` — console input/output
* `limits` — input stream management

---

## Input Validation

The program handles:

* failed numeric reads, such as entering letters instead of a number;
* action codes outside the range `1–3`;
* numbers outside the range `1–10`;
* topic codes other than `0`, `1`, `2`, or `3`;
* answer numbers outside the range `1–4`.

`ClearInput()` clears the input stream's error state and discards the rest of the current line after a failed read.

In the examiner, invalid input does not count as an incorrect answer. The user is prompted again for the same topic or question. End-of-input or a serious input stream error ends the examiner.

---

## License

This project is available under the [Apache License Version 2.0](../../LICENSE).
