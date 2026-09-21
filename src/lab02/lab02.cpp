#include <iomanip>
#include <iostream>
#include <limits>

// Helper function to clear the stream after invalid input.
void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to find the radius using the formula -> 2 * PI * R
void CalculateCircumference() {

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

void ConvertkilometersphToMetersps() {
  double kilometersph; // kilometers per hour
  std::cout << "==================================================\n"
            << "             Speed Conversion\n"
            << "==================================================\n";
  std::cout << "Enter the kilometers per hour: ";
  std::cin >> kilometersph;
  if (std::cin.fail() || kilometersph < 0) {
    std::cerr << "Error: kilometers per hour must be a non-negative number.\n";
    ClearInput();
    return;
  }
  /* Conversion formula: meters per second = kilometers per hour / (3600 / 1000)
   3600.0 || 1000.0 must be a double to avoid integer division.
   For example double metersps = kilometersps / (3600/1000) Incorrect
   Or double metersps = kilometrsps / static_cast<double>(3600/1000) That's also
   incorrect.*/
  double metersps = kilometersph / (3600.0 / 1000);
  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\nResult:\n"
            << "Kilometers per hour: " << kilometersph << "\n"
            << "Meters per second: " << metersps << "\n\n";
}

void CalculateBMI() {
  double weight; // in kilograms
  double height; // in centimeters

  std::cout << "==================================================\n"
            << "             BMI Calculation\n"
            << "==================================================\n";

  std::cout << "Enter your weight in kilograms: ";
  std::cin >> weight;

  if (std::cin.fail() || weight <= 0) {
    std::cerr << "Error: weight must be a positive number.\n";
    ClearInput();
    return;
  }

  std::cout << "Enter your height in centimeters: ";
  std::cin >> height;

  if (std::cin.fail() || height <= 0) {
    std::cerr << "Error: height must be a positive number.\n";
    ClearInput();
    return;
  }
  /*
  100.0 must be a double to avoid integer division.
   */
  double bmi = weight / ((height / 100.0) * (height / 100.0));

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\nResult:\n"
            << "Weight: " << weight << " kg\n"
            << "Height: " << height << " cm\n"
            << "BMI: " << bmi << "\n\n";
  if (bmi < 18.5) {
    std::cout << "You are underweight.\n";
  } else if (bmi >= 18.5 && bmi < 25) {
    std::cout << "You have a normal weight.\n";
  } else if (bmi >= 25 && bmi < 30) {
    std::cout << "You are overweight.\n";
  } else {
    std::cout << "You are obese.\n";
  }
}
int main() {
  CalculateCircumference();
  ConvertkilometersphToMetersps();
  CalculateBMI();
}
