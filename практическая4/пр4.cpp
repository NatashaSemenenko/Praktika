#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

const char* REG_PATH = "Software\\MyFavoriteCityApp";

void SaveToRegistry(const std::string& city, DWORD color) {
    HKEY hKey;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "FavoriteCity", 0, REG_SZ, (const BYTE*)city.c_str(), (DWORD)(city.length() + 1));
        RegSetValueExA(hKey, "ConsoleColor", 0, REG_DWORD, (const BYTE*)&color, sizeof(DWORD));
        RegCloseKey(hKey);
        std::cout << "Данные сохранены в реестр.\n";
    }
    else {
        std::cerr << "Ошибка при открытии реестра для записи.\n";
    }
}

bool LoadFromRegistry(std::string& city, DWORD& color) {
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, REG_PATH, 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char buffer[255];
        DWORD bufferSize = sizeof(buffer);
        DWORD colorSize = sizeof(DWORD);

        if (RegQueryValueExA(hKey, "FavoriteCity", NULL, NULL, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            city = buffer;
        }
        else {
            city = "Неизвестно";
        }

        if (RegQueryValueExA(hKey, "ConsoleColor", NULL, NULL, (LPBYTE)&color, &colorSize) != ERROR_SUCCESS) {
            color = 7; // По умолчанию стандартный
        }
        RegCloseKey(hKey);
        return true;
    }
    return false;
}

void SetColor(DWORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string city;
    DWORD color = 7;

    if (LoadFromRegistry(city, color)) {
        SetColor(color);
        std::cout << "Введите Ваш любимый город: " << city << std::endl;
        SetColor(7); // Сброс цвета на стандартный
    }
    else {
        std::cout << "Сохраненные данные не найдены.\n";
    }

    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Изменить любимый город и цвет\n";
        std::cout << "2. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Введите название города: ";
            std::cin.ignore();
            std::getline(std::cin, city);

            std::cout << "Выберите цвет текста (1 - Синий, 2 - Зеленый, 3 - голубой, 4 - Красный, 5 - фиолетовый, 6 - Желтый, 7 - Белый): ";
            std::cin >> color;

            SaveToRegistry(city, color);

            SetColor(color);
            std::cout << "\nДанные обновлены. Ваш любимый город: " << city << "!\n";
            SetColor(7);
        }
    } while (choice != 2);
    return 0;
}
