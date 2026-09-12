#include <iomanip>
#include <iostream>
#include <limits>

// Вспомогательная функция очистки потока после ошибочного ввода.
void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Радиус -> 2 * PI * R
void CalculationCircumference() {

  double radius;

  // Значение PI является константой и не изменяется.
  const double PI = 3.14159265358979323846;

  std::cout << "==================================================\n"
            << "             БАЗОВЫЙ УРОВЕНЬ\n"
            << "             Длина окружности\n"
            << "==================================================\n";

  std::cout << "Введите радиус: ";
  std::cin >> radius;

  // Проверяем:
  // 1) не ввёл ли пользователь буквы вместо числа;
  // 2) не является ли радиус отрицательным.
  if (std::cin.fail() || radius < 0) {
    std::cerr << "Ошибка: радиус должен быть "
                 "неотрицательным числом.\n";
    ClearInput();
    return;
  }

  // Формула длины окружности: L = 2 * PI * R.
  double circumference = 2.0 * PI * radius;

  // Форматируем вещественный результат:
  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\nРезультат:\n"
            << "Радиус: " << radius << "\n"
            << "Длина окружности: " << circumference << "\n\n";
}

// Секунды -> часы, минуты, секунды
void SecondsToHours() {
  int totalSeconds;

  std::cout << "==================================================\n"
            << "             СРЕДНИЙ УРОВЕНЬ\n"
            << "             Перевод секунд\n"
            << "==================================================\n";

  std::cout << "Введите количество секунд: ";
  std::cin >> totalSeconds;

  // Проверяем некорректный ввод и отрицательные значения.
  if (std::cin.fail() || totalSeconds < 0) {
    std::cerr << "Ошибка: количество секунд должно быть "
                 "неотрицательным целым числом.\n";

    ClearInput();
    return;
  }

  // В одном часе 3600 секунд.
  const int SECONDS_IN_HOUR = 3600;

  // В одной минуте 60 секунд.
  const int SECONDS_IN_MINUTE = 60;

  // Находим количество полных часов.
  int hours = totalSeconds / SECONDS_IN_HOUR;

  // Остаток после выделения часов переводим в минуты.
  int minutes = (totalSeconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;

  // Оставшийся остаток является количеством секунд.
  int seconds = totalSeconds % SECONDS_IN_MINUTE;

  // Выводим результат в структурированном виде.
  std::cout << "\nРезультат:\n"
            << "Всего секунд: " << totalSeconds << "\n"
            << "Часы:         " << hours << "\n"
            << "Минуты:       " << minutes << "\n"
            << "Секунды:      " << seconds << "\n\n";
}

// Рубли -> доллары -> евро
void CurrencyConversion() {
  double rubles;
  double rubleToDollar;
  double rubleToEuro;

  std::cout << "==================================================\n"
            << "           ПОВЫШЕННЫЙ УРОВЕНЬ\n"
            << "             Конвертер валют\n"
            << "==================================================\n";

  std::cout << "Введите сумму в рублях: ";
  std::cin >> rubles;

  // Проверка корректности ввода.
  if (std::cin.fail() || rubles < 0) {
    std::cerr << "Ошибка: сумма в рублях должна быть "
                 "неотрицательным числом.\n";

    ClearInput();
    return;
  }

  std::cout << "Введите курс рубля к доллару "
               "(рублей за 1 доллар): ";
  std::cin >> rubleToDollar;

  if (std::cin.fail() || rubleToDollar <= 0) {
    std::cerr << "Ошибка: курс рубля к доллару "
                 "должен быть больше нуля.\n";

    ClearInput();
    return;
  }

  std::cout << "Введите курс доллара к евро "
               "(евро за 1 доллар): ";
  std::cin >> rubleToEuro;

  // Проверяем, что курс является положительным.
  if (std::cin.fail() || rubleToEuro <= 0) {
    std::cerr << "Ошибка: курс доллара к евро "
                 "должен быть больше нуля.\n";

    ClearInput();
    return;
  }

  double dollars = static_cast<double>(rubles) / rubleToDollar;

  double euros = static_cast<double>(rubles) / rubleToEuro;

  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\n+----------------------+--------------+\n";
  std::cout << "| Показатель           | Значение     |\n";
  std::cout << "+----------------------+--------------+\n";

  std::cout << "| Рубли                | " << std::setw(12) << rubles << " |\n";

  std::cout << "| Курс RUB -> USD      | " << std::setw(12) << rubleToDollar
            << " |\n";

  std::cout << "| Доллары              | " << std::setw(12) << dollars
            << " |\n";

  std::cout << "| Курс USD -> EUR      | " << std::setw(12) << rubleToEuro
            << " |\n";

  std::cout << "| Евро                 | " << std::setw(12) << euros << " |\n";

  std::cout << "+----------------------+--------------+\n\n";
}

int main() {
  CalculationCircumference();
  SecondsToHours();
  CurrencyConversion();

  return 0;
}