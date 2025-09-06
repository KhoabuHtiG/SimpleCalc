#pragma once
#include <cmath>

int add(int x, int y) {return x + y;}
int subtract(int x, int y) {return x - y;}
int multiply(int x, int y) {return x * y;}
int divide(int x, int y) {return x / y;}

int squareRoot(int x) {return sqrt(x);}
int factorial(unsigned __int128 x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}