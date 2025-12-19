#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

struct PerimeterOperations {
    static double squarePerimeter(double a) {
        if (a <= 0) throw std::invalid_argument("Сторона квадрата должна быть > 0");
        return 4.0 * a;
    }

    static double rectanglePerimeter(double a, double b) {
        if (a <= 0 || b <= 0) throw std::invalid_argument("Стороны прямоугольника должны быть > 0");
        return 2.0 * (a + b);
    }

    static double trianglePerimeter(double a, double b, double c) {
        if (a <= 0 || c <= 0) throw std::invalid_argument("Стороны треугольника должны быть > 0");
        if (a + b <= c || b + c <= a)
            throw std::invalid_argument("Треугольник с такими сторонами не существует");
        return a + b + c;
    }

    static double circleCircumference(double r) {
        if (r <= 0) throw std::invalid_argument("Радиус должен быть > 0");
        const double PI = 3.14159265358979323846;
        return 2.0 * PI * r;
    }
};

// безопасное чтение числа double с проверкой ввода
double readDouble(const char* prompt) {
    while (true) {
        std::cout << prompt;
        double x;
        if (std::cin >> x) return x;

        std::cout << "Ошибка ввода. Введите число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// безопасное чтение пункта меню (int)
int readInt(const char* prompt) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x) return x;

        std::cout << "Ошибка ввода. Введите целое число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    setlocale(0, "");

    while (true) {
        std::cout << "\n=== Вычисление периметров ===\n";
        std::cout << "1) Периметр квадрата\n";
        std::cout << "2) Периметр прямоугольника\n";
        std::cout << "3) Периметр треугольника\n";
        std::cout << "4) Длина окружности\n";
        std::cout << "0) Выход\n";

        int choice = readInt("Выберите пункт: ");

        try {
            if (choice == 0) {
                std::cout << "Выход.\n";
                break;
            }
            else if (choice == 1) {
                double a = readDouble("Введите сторону квадрата a: ");
                double p = PerimeterOperations::squarePerimeter(a);
                std::cout << "Периметр квадрата: " << p << "\n";
            }
            else if (choice == 2) {
                double a = readDouble("Введите сторону прямоугольника a: ");
                double b = readDouble("Введите сторону прямоугольника b: ");
                double p = PerimeterOperations::rectanglePerimeter(a, b);
                std::cout << "Периметр прямоугольника: " << p << "\n";
            }
            else if (choice == 3) {
                double a = readDouble("Введите сторону треугольника a: ");
                double b = readDouble("Введите сторону треугольника b: ");
                double c = readDouble("Введите сторону треугольника c: ");
                double p = PerimeterOperations::trianglePerimeter(a, b, c);
                std::cout << "Периметр треугольника: " << p << "\n";
            }
            else if (choice == 4) {
                double r = readDouble("Введите радиус окружности r: ");
                double c = PerimeterOperations::circleCircumference(r);
                std::cout << "Длина окружности: " << c << "\n";
            }
            else {
                std::cout << "Нет такого пункта меню. Повторите ввод.\n";
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}