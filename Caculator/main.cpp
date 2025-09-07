#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

std::vector<std::string> list {
    "Menu Options:",
    "[1]. Add",
    "[2]. Subtract",
    "[3]. Multiply",
    "[4]. Divide",
    "---------------------",
    "[5]. Square Root",
    "[6]. Factorial",
};

template<typename T>
bool getValue(T& number) {
    std::cout << "Enter number: ";
    std::cin >> number;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

class calc {
public:
    double firstNum, nextNum, result = 0;
    char option;
    std::string input;

    int addition() {
        std::cout << "Previous result: " << result << '\n';
        bool executed = getValue(nextNum);
        
        if (!executed) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            return 1;
        }

        result += nextNum;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Result: " << result << '\n';
        return 0;
    }

    int subtraction() {
        std::cout << "Previous result: " << result << '\n';
        bool executed = getValue(nextNum);
        
        if (!executed) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            return 1;
        }

        result -= nextNum;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Result: " << result << '\n';
        return 0;
    }

    int multiplication() {
        std::cout << "Previous result: " << result << '\n';
        bool executed = getValue(nextNum);
        
        if (!executed) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            return 1;
        }

        result *= nextNum;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Result: " << result << '\n';
        return 0;
    }

    int division() {
        std::cout << "Previous result: " << result << '\n';
        bool executed = getValue(nextNum);
        
        if (!executed) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            return 1;
        }

        if (nextNum == 0) {
            std::cout << "Error: Division by zero is undefined.\n";
            return 1;
        } else {
            result /= nextNum;
            std::cout << "Result: " << result << '\n';
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    int squareRoot() {
        std::cout << "Which number would you like to compute square root of? (Current number: y || New number: n)?: ";
        char computeChoice;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "No input detected.\n";
        }

        computeChoice = input[0];

        if (computeChoice == 'y' || computeChoice == 'Y') {
            if (result <= 0) {
                std::cout << "Error: Cannot compute square root of a negative number or zero.\n";
                return 1;
            }

            result = sqrt(result);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Result: " << result << '\n';
            return 0;
        } else if (computeChoice == 'n' || computeChoice == 'N') {
            bool executed = getValue(nextNum);
                    
            if (!executed) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                return 1;
            }

            if (nextNum < 0) {
                std::cout << "Error: Cannot compute square root of a negative number.\n";
                return 1;
            }

            result = sqrt(nextNum);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Result: " << result << '\n';
            return 0;
        } else {
            std::cout << "Invalid choice.\n";
            return 1;
        }
    }

    int factorial() {
        std::cout << "Which number would you like to compute factorial of? (Current number: y || New number: n): ";
        char computeChoice;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "No input detected.\n";
            return 1;
        }

        computeChoice = input[0];

        int n;
        if (computeChoice == 'y' || computeChoice == 'Y') {
            n = static_cast<int>(result);
        } else if (computeChoice == 'n' || computeChoice == 'N') {
            bool executed = getValue(nextNum);
            if (!executed) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                return 1;
            }
            n = static_cast<int>(nextNum);
        } else {
            std::cout << "Invalid choice.\n";
            return 1;
        }

        if (n < 0) {
            std::cout << "Error: Cannot compute factorial of a negative number.\n";
            return 1;
        }

        double fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }

        result = fact;
        std::cout << "Result: " << result << '\n';
        return 0;
    }
};

void menu() {
    char option;
    std::string input;
    calc calculator;

    clearScreen();
    std::cout << "Welcome to the Calculator Program!\n";

    for (const auto& option : list) {
        std::cout << option << '\n';
    }

    while (1) {
        std::cout << "|| AC: c || Exit: q || Execute operation: [1-6] || Menu: m ||\n";
        std::cout << "Choose an option: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "No input detected. Please enter a valid option.\n";
            continue;
        }
        
        option = input[0];

        switch(option) {
            case '1': calculator.addition(); break;
            case '2': calculator.subtraction(); break;
            case '3': calculator.multiplication(); break;
            case '4': calculator.division(); break;
            case '5': calculator.squareRoot(); break;
            case '6': calculator.factorial(); break;
            case 'c':
            case 'C':
                calculator.result = 0;
                std::cout << "Result cleared. Current result: " << calculator.result << '\n';
                break;
            case 'q':
            case 'Q':
                std::cout << "Exiting program.\n";
                return;
            case 'm':
            case 'M':
                clearScreen();
                for (const auto& option : list) {
                    std::cout << option << '\n';
                }
                break;
            default:
                std::cout << "Invalid option selected.\n";
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}