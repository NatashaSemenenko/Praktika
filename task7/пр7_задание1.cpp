#include <iostream>
#include <cmath>
#include <limits> // Для очистки буфера ввода

struct PowerRootOperations {
    static double square(double a) {
        return a * a;
    }

    static double cube(double a) {
        return a * a * a;
    }

    static double power(double a, double n) {
        return std::pow(a, n);
    }

    static double nthRoot(double a, int n) {
        if (n <= 0) {
            throw std::invalid_argument("Показатель корня должен быть положительным числом.");
        }

        if (a < 0 && n % 2 == 0) {
            throw std::invalid_argument("Извлечение четного корня из отрицательного числа невозможно.");
        }
        return std::pow(a, 1.0 / n);
    }
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    setlocale(0, "");

    int choice;
    double number, exponent;
    int rootDegree;

    do {
        std::cout << "Меню операций: " << std::endl;
        std::cout << "1. Возвести число в квадрат" << std::endl;
        std::cout << "2. Возвести число в куб" << std::endl;
        std::cout << "3. Возвести число в произвольную степень" << std::endl;
        std::cout << "4. Извлечь корень произвольной степени из числа" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт меню: ";

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Введите число." << std::endl;
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1: // Квадрат
            std::cout << "Введите число: ";
            if (!(std::cin >> number)) {
                std::cout << "Ошибка ввода числа!" << std::endl;
                clearInputBuffer();
                break;
            }
            std::cout << "Квадрат введенного числа" << number << " = " << PowerRootOperations::square(number) << std::endl;
            break;

        case 2: // Куб
            std::cout << "Введите число: ";
            if (!(std::cin >> number)) {
                std::cout << "Ошибка ввода числа!" << std::endl;
                clearInputBuffer();
                break;
            }
            std::cout << "Куб введенного числа" << number << " = " << PowerRootOperations::cube(number) << std::endl;
            break;

        case 3: // Произвольная степень
            std::cout << "Введите число: ";
            if (!(std::cin >> number)) {
                std::cout << "Ошибка ввода числа!" << std::endl;
                clearInputBuffer();
                break;
            }
            std::cout << "Введите степень: ";
            if (!(std::cin >> exponent)) {
                std::cout << "Ошибка ввода степени!" << std::endl;
                clearInputBuffer();
                break;
            }
            std::cout << number << " в степени " << exponent << " = " << PowerRootOperations::power(number, exponent) << std::endl;
            break;

        case 4: // Корень произвольной степени
            std::cout << "Введите число: ";
            if (!(std::cin >> number)) {
                std::cout << "Ошибка ввода числа!" << std::endl;
                clearInputBuffer();
                break;
            }
            std::cout << "Введите степень корня (целое положительное число): ";
            if (!(std::cin >> rootDegree)) {
                std::cout << "Ошибка ввода степени корня!" << std::endl;
                clearInputBuffer();
                break;
            }

            try {
                std::cout << "Корень степени " << rootDegree << " из " << number << " = " << PowerRootOperations::nthRoot(number, rootDegree) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;

        case 5: // Выход
            std::cout << "Выход из программы." << std::endl;
            break;

        default:
            std::cout << "Неверный пункт меню! Попробуйте снова." << std::endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
