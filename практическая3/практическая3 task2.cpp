#include <iostream>
#include <iomanip>
#include <clocale>

double calculateCircleArea(double radius)
{
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double radius;
    std::cout << "Введите радиус круга: ";
    std::cin >> radius;

    if (radius < 0) {
        std::cout << "Ошибка! Радиус не может быть отрицательным!" << std::endl;
    }
    else {
        double area = calculateCircleArea(radius);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Площадь круга = " << area << std::endl;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Тестовые значения: " << std::endl;
    std::cout << "Радиус = 4: Площадь = " << calculateCircleArea(4) << std::endl;
    std::cout << "Радиус = 7: Площадь = " << calculateCircleArea(7) << std::endl;
    std::cout << "Радиус = 11: Площадь = " << calculateCircleArea(11) << std::endl;

    return 0;
}