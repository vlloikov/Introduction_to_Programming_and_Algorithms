#include <iomanip>
#include <iostream>
#include <limits>

// Helper function to clear the stream after invalid input.
void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void IsRange() {

  int value;

  std::cout << "===================================================\n"
            << "             Range Check\n"
            << "===================================================\n\n";

  std::cout << "Enter a value: ";
  std::cin >> value;

  // Check if the input is valid
  if (std::cin.fail()) {
    std::cerr << "\nError: input must be a int number.\n";
    ClearInput();
    return;
  }

  // Check if the value is in the range [10, 20]
  if (value < 10 || value > 20) {
    std::cout << "\nThe value is out of range[10, 20].\n";
  } else {
    std::cout << "\nThe value is in range[10, 20].\n";
  }
}

void ConvertToMeters() {
  double value;
  std::string unit;

  std::cout << "\n===================================================\n "
            << "             Convert to Meters\n"
            << "===================================================\n\n";
  std::cout << "Enter value: ";
  std::cin >> value;

  // Check if the input is valid and positive
  if (std::cin.fail() || value < 0) {
    std::cerr << "\nError: input must be a positive number.\n";
    ClearInput();
    return;
  }

  std::cout << "Enter unit (cm, m, km): ";
  std::cin >> unit;
  double meters;

  // Convert the value to meters based on the unit
  if (unit == "cm") {
    meters = value / 100.0;
  } else if (unit == "m") {
    meters = value;
  } else if (unit == "km") {
    meters = value * 1000.0;
  } else {
    std::cout << "Error: unknown unit.\n";
    return;
  }
  // Output the result
  std::cout << value << ' ' << unit << " = " << meters << " m\n";
}

void WithdrawCash()
{
  int amount;
  std::cout << "\n===================================================\n "
            << "             Withdraw Cash\n"
            << "===================================================\n\n";
  std::cout << "Enter withdrawal amount (multiple of 100, maximum 100000): ";
  std::cin >> amount;

  if (std::cin.fail() || amount < 0 || amount > 100000 || amount % 100 != 0)
  {
    std::cerr << "\nError: input must be a positive multiple of 100 and not exceed 100000.\n";
    ClearInput();
    return;
  }

  // Define the available banknotes in descending order
  const int banknotes[] = {5000, 2000, 1000, 100};

  std::cout << "Banknotes to dispense:\n";

  // Calculate the number of each banknote to dispense
  for (const int banknote : banknotes)
  {
    const int count = amount / banknote;

    if (count > 0)
    {
      // Output the banknote and its count
      std::cout << banknote << " x " << count << '\n';
      // Update the remaining amount
      amount %= banknote;
    }
  }
}

int main() {
  IsRange();
  ConvertToMeters();
  WithdrawCash();
}