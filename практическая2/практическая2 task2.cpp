#include <iostream>
#include <stdexcept>

int safe_divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("DivisionbyzeroException");
    }
    return a / b;
}

int main() {
    try {
        int x = 10;
        int y = 0;
        std::cout << "Result: " << safe_divide(x, y) << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << "\n";
    }
    return 0;
}
