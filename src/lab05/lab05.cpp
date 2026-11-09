#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

const double STEP_TOLERANCE = 1e-9;

void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool CheckInterval(double a, double b, double h) {
  if (std::cin.fail()) {
    if (!std::cin.eof() && !std::cin.bad()) {
      std::cerr << "Error: enter three numbers.\n";
      ClearInput();
    }
    return false;
  }

  std::string rest;
  std::getline(std::cin, rest);
  if (rest.find_first_not_of(" \t\r") != std::string::npos) {
    std::cerr << "Error: enter three numbers.\n";
    return false;
  }

  if (a > b || h <= 0) {
    std::cerr << "Error: a must be <= b and h must be > 0.\n";
    return false;
  }

  if ((b - a) / h >= std::numeric_limits<int>::max()) {
    std::cerr << "Error: the step is too small for this interval.\n";
    return false;
  }

  return true;
}

void RunBasic() {
  std::cout << "===================================================\n"
            << "              Basic level: y = x^4\n"
            << "===================================================\n";

  double a = 0, b = 0, h = 0;
  do {
    if (!std::cin) {
      return;
    }
    std::cout << "Enter a, b and h: ";
    std::cin >> a >> b >> h;
  } while (!CheckInterval(a, b, h));

  std::cout << "\n           x |          x^4\n"
            << "-------------+-------------\n";

  // The tolerance keeps the last point when the step count rounds down.
  const double steps = (b - a) / h + STEP_TOLERANCE;
  for (int i = 0; i <= steps; ++i) {
    const double x = std::min(a + i * h, b);
    const double y = x * x * x * x;
    std::cout << std::setw(12) << x << " | " << std::setw(12) << y << '\n';
  }
}

void RunIntermediate() {
  std::cout << "\n===================================================\n"
            << "          Intermediate level: y = atan(x)\n"
            << "===================================================\n";

  double a = 0, b = 0, h = 0;
  do {
    if (!std::cin) {
      return;
    }
    std::cout << "Enter a, b and h: ";
    std::cin >> a >> b >> h;
  } while (!CheckInterval(a, b, h));

  std::cout << "\n           x |      atan(x)\n"
            << "-------------+-------------\n";

  double closestX = a;
  double closestY = std::atan(a);
  const double steps = (b - a) / h + STEP_TOLERANCE;
  for (int i = 0; i <= steps; ++i) {
    const double x = std::min(a + i * h, b);
    const double y = std::atan(x);
    std::cout << std::setw(12) << x << " | " << std::setw(12) << y << '\n';

    // Compare the distance to zero, regardless of the sign of y.
    if (std::abs(y) < std::abs(closestY)) {
      closestX = x;
      closestY = y;
    }
  }

  std::cout << "Closest to zero: atan(" << closestX << ") = " << closestY
            << '\n';
}

void RunAdvanced() {
  std::cout << "\n===================================================\n"
            << "          Advanced level: animated y = x^4\n"
            << "===================================================\n";

  double a = 0, b = 0, h = 0;
  do {
    if (!std::cin) {
      return;
    }
    std::cout << "Enter a, b and h: ";
    std::cin >> a >> b >> h;
  } while (!CheckInterval(a, b, h));

  std::cout << "\n           x |          x^4\n"
            << "-------------+-------------\n";

  const std::chrono::milliseconds delay(600);
  const double steps = (b - a) / h + STEP_TOLERANCE;
  for (int i = 0; i <= steps; ++i) {
    const double x = std::min(a + i * h, b);
    const double y = x * x * x * x;

    // std::endl displays the row before the delay begins.
    std::cout << std::setw(12) << x << " | " << std::setw(12) << y << std::endl;
    if (i + 1 <= steps) {
      std::this_thread::sleep_for(delay);
    }
  }
}

int main() {
  std::cout << std::fixed << std::setprecision(4);
  RunBasic();
  if (std::cin) {
    RunIntermediate();
  }
  if (std::cin) {
    RunAdvanced();
  }
}
