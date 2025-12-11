#include <iostream>  // Для ввода-вывода (std::cout, std::cin)
#include <iomanip>   // Для форматирования вывода (std::setprecision, std::fixed)
#include <clocale>   // Для setlocale и LC_ALL

// Функция для вычисления площади круга
double calculateCircleArea(double radius)
{
    // Определяем константу PI с высокой точностью
    const double PI = 3.14159265358979323846;
    // Формула: S = π * r²
    return PI * radius * radius;
}

int main()
{
    // Настройка вывода для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    // Ввод пользователя
    double radius;
    std::cout << "Введите радиус круга: ";
    std::cin >> radius;

    if (radius < 0) {
        std::cout << "Ошибка! Радиус не может быть отрицательным!" << std::endl;
    }
    else {
        double area = calculateCircleArea(radius);
        // Выводим результат (fixed и setprecision(2) оставляют 2 знака после запятой)
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Площадь круга = " << area << std::endl;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Тестовые значения: " << std::endl;

    //Тестирование
    std::cout << "Радиус = 4: Площадь = " << calculateCircleArea(4) << std::endl;
    std::cout << "Радиус = 7: Площадь = " << calculateCircleArea(7) << std::endl;
    std::cout << "Радиус = 11: Площадь = " << calculateCircleArea(11) << std::endl;

    return 0;
}
