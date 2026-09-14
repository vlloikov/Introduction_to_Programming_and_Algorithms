#include <iomanip>
#include <iostream>
#include <limits>

// Helper function to clear the stream after invalid input.
void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to find the radius using the formula -> 2 * PI * R
void CalculationCircumference() {

  double radius;

  // The value of PI is a constant and does not change.
  const double PI{3.14159265358979323846};

  std::cout << "==================================================\n"
            << "             Circumference\n"
            << "==================================================\n";

  std::cout << "Enter the radius: ";
  std::cin >> radius;

  // Check:
  // 1) whether the user entered letters instead of a number;
  // 2) whether the radius is negative.
  if (std::cin.fail() || radius < 0) {
    std::cerr << "Error: the radius must be "
                 "a non-negative number.\n";
    ClearInput();
    return;
  }

  // Circumference formula: L = 2 * PI * R.
  double circumference = 2.0 * PI * radius;

  // Format the floating-point result:
  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\nResult:\n"
            << "Radius: " << radius << "\n"
            << "Circumference: " << circumference << "\n\n";
}

// Function to convert seconds -> hours, minutes, seconds
void SecondsToHours() {
  int totalSeconds;

  std::cout << "==================================================\n"
            << "             Seconds Conversion\n"
            << "==================================================\n";

  std::cout << "Enter the number of seconds: ";
  std::cin >> totalSeconds;

  // Check for invalid input and negative values.
  if (std::cin.fail() || totalSeconds < 0) {
    std::cerr << "Error: the number of seconds must be "
                 "a non-negative integer.\n";

    ClearInput();
    return;
  }

  // There are 3600 seconds in one hour.
  const int SECONDS_IN_HOUR = 3600;

  // There are 60 seconds in one minute.
  const int SECONDS_IN_MINUTE = 60;

  // Find the number of full hours.
  int hours = totalSeconds / SECONDS_IN_HOUR;

  // Convert the remainder after extracting hours into minutes.
  int minutes = (totalSeconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;

  // The remaining remainder is the number of seconds.
  int seconds = totalSeconds % SECONDS_IN_MINUTE;

  // Output the result in a structured form.
  std::cout << "\nResult:\n"
            << "Total seconds: " << totalSeconds << "\n"
            << "Hours:         " << hours << "\n"
            << "Minutes:       " << minutes << "\n"
            << "Seconds:       " << seconds << "\n\n";
}

// Function to convert currency Rubles -> dollars -> euros
void CurrencyConversion() {
  double rubles;
  double rubleToDollar;
  double rubleToEuro;

  std::cout << "==================================================\n"
            << "             Currency Converter\n"
            << "==================================================\n";

  std::cout << "Enter the amount in rubles: ";
  std::cin >> rubles;

  // Check input validity.
  if (std::cin.fail() || rubles < 0) {
    std::cerr << "Error: the amount in rubles must be "
                 "a non-negative number.\n";

    ClearInput();
    return;
  }

  std::cout << "Enter the ruble-to-dollar exchange rate "
               "(rubles per 1 dollar): ";
  std::cin >> rubleToDollar;

  if (std::cin.fail() || rubleToDollar <= 0) {
    std::cerr << "Error: the ruble-to-dollar exchange rate "
                 "must be greater than zero.\n";

    ClearInput();
    return;
  }

  std::cout << "Enter the dollar-to-euro exchange rate "
               "(euros per 1 dollar): ";
  std::cin >> rubleToEuro;

  // Check that the exchange rate is positive.
  if (std::cin.fail() || rubleToEuro <= 0) {
    std::cerr << "Error: the dollar-to-euro exchange rate "
                 "must be greater than zero.\n";

    ClearInput();
    return;
  }

  double dollars = static_cast<double>(rubles) / rubleToDollar;

  double euros = static_cast<double>(rubles) / rubleToEuro;

  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\n+----------------------+--------------+\n";
  std::cout << "| Indicator            | Value        |\n";
  std::cout << "+----------------------+--------------+\n";

  std::cout << "| Rubles               | " << std::setw(12) << rubles << " |\n";

  std::cout << "| RUB -> USD rate      | " << std::setw(12) << rubleToDollar
            << " |\n";

  std::cout << "| Dollars              | " << std::setw(12) << dollars
            << " |\n";

  std::cout << "| USD -> EUR rate      | " << std::setw(12) << rubleToEuro
            << " |\n";

  std::cout << "| Euros                | " << std::setw(12) << euros << " |\n";

  std::cout << "+----------------------+--------------+\n\n";
}

int main() {
  CalculationCircumference();
  SecondsToHours();
  CurrencyConversion();

  return 0;
}