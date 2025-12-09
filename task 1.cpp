
#include <iostream>
using namespace std;

int factorial(int n) {
    setlocale(0, "");
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    setlocale(0, "");
    cout << "Числа от 1 до 10:" << endl;

    for (int i = 1; i <= 10; ++i) {
        cout << i << " ";
    }
    cout << "\n\nФакториал числа 5: " << factorial(5) << endl;

    return 0;
}