#include <iostream>
#include <expected>
#include <cassert>

#define Expects(expr) assert(expr)
#define Ensures(expr) assert(expr)

using namespace std;

int square(int x) {
    Expects(x > 0);             //Expects() is Not supported in C++17, so we used assert() instead
    Ensures(x * x > 0);
    return x * x;
}

int main() {

    int input;
    cout << "Enter a number: ";
    cin >> input;
    cout << "Square : " << square(input) << endl;

    return 0;
}