#include <iostream>  // Для ввода-вывода
#include <iomanip>   // Для форматирования вывода
using namespace std;
// Функция для вычисления площади круга
double calculateCircleArea(double r) {
    // Определяем константу ? с высокой точностью
    const double PI = 3.14159265358979323846;
    // Формула: S = ? * r?
    return PI * r * r;
}
int main() {
    // Настройка вывода для поддержки кириллицы
    setlocale(0, "");
    // Ввод пользователя
    double r;
    cout << "Введите радиус круга: ";
    cin >> r;
     // Если введенное число отрицательное
    if (r < 0) {
        cout << "Ошибка! Радиус не может быть отрицательным!" << endl;
    }
    // В остальных случаях
    else {
        double area = calculateCircleArea(r);

        // Выводим результат (fixed и setprecision(2) оставляют 2 знака после запятой)
        cout << fixed << setprecision(2);
        cout << "Площадь круга = " << area << endl;
    }
    cout << fixed << setprecision(2);
    cout << "Тестовые значения: " << endl;

    //Тестирование
    cout << "Радиус = 4: Площадь = " << calculateCircleArea(4) << endl;
    cout << "Радиус = 7: Площадь = " << calculateCircleArea(7) << endl;
    cout << "Радиус = 11: Площадь = " << calculateCircleArea(11) << endl;
    return 0;
}
