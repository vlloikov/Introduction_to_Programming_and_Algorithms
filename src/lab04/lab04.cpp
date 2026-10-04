#include <iostream>
#include <limits>

// Helper function to clear the stream after invalid input.
void ClearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ShowAction() {
  int action;

  std::cout << "===================================================\n"
            << "                  Action Selection\n"
            << "===================================================\n\n";
  std::cout << "Enter action (1 - Start, 2 - Pause, 3 - Stop): ";
  std::cin >> action;

  // Check whether the user entered an integer.
  if (std::cin.fail()) {
    std::cerr << "\nError: input must be an integer.\n";
    ClearInput();
    return;
  }

  switch (action) {
    case 1:  // Display the start action.
      std::cout << "Start\n";
      break;
    case 2:  // Display the pause action.
      std::cout << "Pause\n";
      break;
    case 3:  // Display the stop action.
      std::cout << "Stop\n";
      break;
    default:  // Handle an unknown action code.
      std::cerr << "Error: action must be from 1 to 3.\n";
      break;
  }
}

void ShowNumberInEnglish() {
  int number;

  std::cout << "\n===================================================\n"
            << "                  Number in English\n"
            << "===================================================\n\n";
  std::cout << "Enter a number from 1 to 10: ";
  std::cin >> number;

  // Check whether the user entered an integer.
  if (std::cin.fail()) {
    std::cerr << "\nError: input must be an integer.\n";
    ClearInput();
    return;
  }

  switch (number) {
    case 1:  // Display the name of 1.
      std::cout << "One\n";
      break;
    case 2:  // Display the name of 2.
      std::cout << "Two\n";
      break;
    case 3:  // Display the name of 3.
      std::cout << "Three\n";
      break;
    case 4:  // Display the name of 4.
      std::cout << "Four\n";
      break;
    case 5:  // Display the name of 5.
      std::cout << "Five\n";
      break;
    case 6:  // Display the name of 6.
      std::cout << "Six\n";
      break;
    case 7:  // Display the name of 7.
      std::cout << "Seven\n";
      break;
    case 8:  // Display the name of 8.
      std::cout << "Eight\n";
      break;
    case 9:  // Display the name of 9.
      std::cout << "Nine\n";
      break;
    case 10:  // Display the name of 10.
      std::cout << "Ten\n";
      break;
    default:  // Handle a number outside the required range.
      std::cerr << "Error: number must be from 1 to 10.\n";
      break;
  }
}

void RunExaminer() {
  const int QUESTION_COUNT = 5;

  std::cout << "\n===================================================\n"
            << "                  Programming Examiner\n"
            << "===================================================\n";

  while (true) {
    int topic;
    std::cout << "\n1. C++\n2. Python\n3. Java\n0. Exit\n"
              << "Select a topic: ";
    std::cin >> topic;

    // Repeat invalid input, but finish if the input stream has ended.
    if (std::cin.fail()) {
      if (std::cin.eof() || std::cin.bad()) {
        return;
      }
      std::cerr << "Error: input must be an integer.\n";
      ClearInput();
      continue;
    }

    switch (topic) {
      case 1:  // These topics all start an exam, so the labels are grouped.
      case 2:
      case 3:
        break;
      case 0:  // Finish the examiner.
        return;
      default:  // Request another topic if the code is invalid.
        std::cerr << "Error: select 1, 2, 3 or 0.\n";
        continue;
    }

    int correctAnswers = 0;

    // Ask the five selected questions in order.
    for (int question = 0; question < QUESTION_COUNT; ++question) {
      int correctAnswer = 0;
      std::cout << "\nQuestion " << question + 1 << " of " << QUESTION_COUNT << ":\n";

      // The outer switch selects the topic; the inner one selects a question.
      switch (topic) {
        case 1:  // Questions about C++.
          switch (question) {
            case 0:  // Question 1.
              std::cout << "Which header declares std::cout?\n"
                        << "1. <iostream>  2. <cmath>  3. <vector>  4. <limits>\n";
              correctAnswer = 1;
              break;
            case 1:  // Question 2.
              std::cout << "What is the result of 5 / 2 in C++?\n"
                        << "1. 2.5  2. 2  3. 3  4. 0\n";
              correctAnswer = 2;
              break;
            case 2:  // Question 3.
              std::cout << "Which operator means logical AND?\n"
                        << "1. ||  2. !  3. &&  4. ==\n";
              correctAnswer = 3;
              break;
            case 3:  // Question 4.
              std::cout << "Which keyword declares a read-only variable?\n"
                        << "1. static  2. return  3. switch  4. const\n";
              correctAnswer = 4;
              break;
            case 4:  // Question 5.
              std::cout << "Which type can be used directly in switch?\n"
                        << "1. double  2. char  3. float  4. std::string\n";
              correctAnswer = 2;
              break;
            default:  // The question number is always from 0 to 4.
              return;
          }
          break;
        case 2:  // Questions about Python.
          switch (question) {
            case 0:  // Question 1.
              std::cout << "Which function returns the length of a list?\n"
                        << "1. size()  2. len()  3. length()  4. count_all()\n";
              correctAnswer = 2;
              break;
            case 1:  // Question 2.
              std::cout << "Which brackets create a list literal?\n"
                        << "1. []  2. ()  3. {}  4. <>\n";
              correctAnswer = 1;
              break;
            case 2:  // Question 3.
              std::cout << "Which keyword starts a function definition?\n"
                        << "1. function  2. void  3. def  4. func\n";
              correctAnswer = 3;
              break;
            case 3:  // Question 4.
              std::cout << "Which operator raises a number to a power?\n"
                        << "1. ^  2. //  3. %  4. **\n";
              correctAnswer = 4;
              break;
            case 4:  // Question 5.
              std::cout << "Which symbol starts a comment?\n"
                        << "1. //  2. #  3. /*  4. <!--\n";
              correctAnswer = 2;
              break;
            default:  // The question number is always from 0 to 4.
              return;
          }
          break;
        case 3:  // Questions about Java.
          switch (question) {
            case 0:  // Question 1.
              std::cout << "Which type stores true or false?\n"
                        << "1. bool  2. boolean  3. int  4. char\n";
              correctAnswer = 2;
              break;
            case 1:  // Question 2.
              std::cout << "Which method prints text with a newline?\n"
                        << "1. System.out.println()  2. System.out.print()  3. cout()  4. printline()\n";
              correctAnswer = 1;
              break;
            case 2:  // Question 3.
              std::cout << "Which keyword creates an object?\n"
                        << "1. create  2. class  3. new  4. object\n";
              correctAnswer = 3;
              break;
            case 3:  // Question 4.
              std::cout << "Which method compares String contents?\n"
                        << "1. same()  2. compare()  3. is()  4. equals()\n";
              correctAnswer = 4;
              break;
            case 4:  // Question 5.
              std::cout << "What is the result of 7 / 2 in Java?\n"
                        << "1. 3.5  2. 4  3. 3  4. 0\n";
              correctAnswer = 3;
              break;
            default:  // The question number is always from 0 to 4.
              return;
          }
          break;
        default:  // The topic was already checked before the exam.
          return;
      }

      int answer = 0;
      do {
        std::cout << "Your answer (1-4): ";
        std::cin >> answer;

        // A wrong input must not count as a wrong answer to the question.
        if (std::cin.fail()) {
          if (std::cin.eof() || std::cin.bad()) {
            return;
          }
          std::cerr << "Error: input must be an integer.\n";
          ClearInput();
          answer = 0;
        } else if (answer < 1 || answer > 4) {
          // Use if for a range; switch matches individual constant values.
          std::cerr << "Error: answer must be from 1 to 4.\n";
        }
      } while (answer < 1 || answer > 4);

      // Increase the score only when the selected answer is correct.
      if (answer == correctAnswer) {
        ++correctAnswers;
        std::cout << "Correct!\n";
      } else {
        std::cout << "Incorrect. Correct answer: " << correctAnswer << '\n';
      }
    }

    std::cout << "\nResult: " << correctAnswers << " / " << QUESTION_COUNT << '\n';
    // Return to topic selection so the user can take another exam or exit.
  }
}

int main() {
  ShowAction();
  ShowNumberInEnglish();
  RunExaminer();
}
