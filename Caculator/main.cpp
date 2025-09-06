#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "formula.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

std::vector<std::string> menu {
    "Menu Options:",
    "[1]. Add",
    "[2]. Subtract",
    "[3]. Multiply",
    "[4]. Divide",
    "---------------------",
    "[5]. Square Root",
    "[6]. Factorial",
    //
};

bool executeOperation(int& number) {
    std::cout << "Enter number: ";
    std::cin >> number;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

int main() {
    int firstNum, nextNum, result = 0;
    char option;
    std::string input;

    clearScreen();
    std::cout << "Welcome to the Calculator Program!\n";

    for (const auto& option : menu) {
        std::cout << option << '\n';
    }

    while (1) {
        std::cout << "|| AC: c || Exit: q || Execute operation: [1-5] || Menu: m ||\n";
        std::cout << "Choose an option: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "No input detected. Please enter a valid option.\n";
            continue;
        }
        
        option = input[0];

        switch(option) {
            case '1': {
                std::cout << "Previous result: " << result << '\n';
                bool executed = executeOperation(nextNum);
                
                if (!executed) {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                    break;
                }

                result = add(result, nextNum);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Result: " << result << '\n';
                break;
            }

            case '2': {
                std::cout << "Previous result: " << result << '\n';
                bool executed = executeOperation(nextNum);
                
                if (!executed) {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                    break;
                }

                result = subtract(result, nextNum);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Result: " << result << '\n';
                break;
            }

            case '3': {
                std::cout << "Previous result: " << result << '\n';
                bool executed = executeOperation(nextNum);
                
                if (!executed) {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                    break;
                }

                result = multiply(result, nextNum);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Result: " << result << '\n';
                break;
            }

            case '4': {
                std::cout << "Previous result: " << result << '\n';
                bool executed = executeOperation(nextNum);
                
                if (!executed) {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                    break;
                }

                if (nextNum == 0) {
                    std::cout << "Error: Division by zero is undefined.\n";
                } else {
                    result = divide(result, nextNum);
                    std::cout << "Result: " << result << '\n';
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case '5': {
                std::cout << "Which number would you like to compute square root of? (Current number: y || New number: n)?: ";
                char computeChoice;
                std::getline(std::cin, input);

                if (input.empty()) {
                    std::cout << "No input detected.\n";
                    break;
                }

                computeChoice = input[0];

                if (computeChoice == 'y' || computeChoice == 'Y') {
                    if (result <= 0) {
                        std::cout << "Error: Cannot compute square root of a negative number or zero.\n";
                        break;
                    }

                    result = squareRoot(result);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Result: " << result << '\n';
                    break;
                } else if (computeChoice == 'n' || computeChoice == 'N') {
                    bool executed = executeOperation(nextNum);
                    
                    if (!executed) {
                        std::cout << "Invalid input. Please enter a valid number.\n";
                        break;
                    }

                    if (nextNum <= 0) {
                        std::cout << "Error: Cannot compute square root of a negative number.\n";
                        break;
                    }

                    result = squareRoot(nextNum);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Result: " << result << '\n';
                    break;
                } else {
                    std::cout << "Invalid choice.\n";
                    break;
                }
            }

            case '6': {
                std::cout << "Which number would you like to compute factorial of? (Current number: y || New number: n): ";
                char computeChoice;
                std::getline(std::cin, input);

                if (input.empty()) {
                    std::cout << "No input detected.\n";
                    break;
                }

                computeChoice = input[0];

                if (computeChoice == 'y' || computeChoice == 'Y') {
                    if (result < 0) {
                        std::cout << "Error: Cannot compute factorial of a negative number.\n";
                        break;
                    }

                    result = factorial(result);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Result: " << result << '\n';
                    break;
                } else if (computeChoice == 'n' || computeChoice == 'N') {
                    bool executed = executeOperation(nextNum);
                    
                    if (!executed) {
                        std::cout << "Invalid input. Please enter a valid number.\n";
                        break;
                    }

                    if (nextNum < 0) {
                        std::cout << "Error: Cannot compute factorial of a negative number.\n";
                        break;
                    }

                    result = factorial(nextNum);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Result: " << result << '\n';
                    break;
                } else {
                    std::cout << "Invalid choice.\n";
                    break;
                }
            }

            case 'c':
            case 'C':
                result = 0;
                std::cout << "Result cleared. Current result: " << result << '\n';
                break;

            case 'q':
            case 'Q':
                std::cout << "Exiting program.\n";
                return 0;

            case 'm':
            case 'M':
                clearScreen();
                for (const auto& option : menu) {
                    std::cout << option << '\n';
                }
                break;

            default:
                std::cout << "Invalid option selected.\n";
                break;
        }
    }
}