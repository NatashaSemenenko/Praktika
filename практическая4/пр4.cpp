#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const char* REG_PATH = "Software\\MyCityApp";

void SaveStringToRegistry(const string& valueName, const string& data) {
    HKEY hKey;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, valueName.c_str(), 0, REG_SZ, (const BYTE*)data.c_str(), data.length() + 1);
        RegCloseKey(hKey);
    }
}

void SaveIntToRegistry(const string& valueName, DWORD data) {
    HKEY hKey;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, valueName.c_str(), 0, REG_DWORD, (const BYTE*)&data, sizeof(data));
        RegCloseKey(hKey);
    }
}

string ReadStringFromRegistry(const string& valueName) {
    char buffer[255];
    DWORD bufferSize = sizeof(buffer);
    if (RegGetValueA(HKEY_CURRENT_USER, REG_PATH, valueName.c_str(), RRF_RT_REG_SZ, NULL, buffer, &bufferSize) == ERROR_SUCCESS) {
        return string(buffer);
    }
    return "";
}

int ReadIntFromRegistry(const string& valueName) {
    DWORD data = 0;
    DWORD dataSize = sizeof(data);
    if (RegGetValueA(HKEY_CURRENT_USER, REG_PATH, valueName.c_str(), RRF_RT_REG_DWORD, NULL, &data, &dataSize) == ERROR_SUCCESS) {
        return (int)data;
    }
    return -1; // Возвращаем -1, если значение не найдено
}

int main() {
    setlocale(LC_ALL, "Russian");

    string city = ReadStringFromRegistry("FavoriteCity");
    int color = ReadIntFromRegistry("ConsoleColor");

    if (city.empty() || color == -1) {
        cout << "Данные не найдены. Давайте их сохраним.\n";

        cout << "Введите ваш любимый город: ";
        getline(cin, city);

        cout << "Выберите цвет текста (1 - Синий, 2 - Зеленый, 3 - Голубой, 4 - Красный, 5 - фиолетовый, 6 - Желтый, 7 - Белый): ";
        cin >> color;

        SaveStringToRegistry("FavoriteCity", city);
        SaveIntToRegistry("ConsoleColor", (DWORD)color);

        cout << "Данные успешно сохранены в реестр!\n";
        cout << "Перезапустите программу, чтобы увидеть результат.\n";
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (WORD)color);
        cout << "Приветствуем в вашей программе!" << endl;
        cout << "Ваш любимый город: " << city << endl;

        // Сброс цвета к стандартному (белый) перед выходом
        SetConsoleTextAttribute(hConsole, 7);
    }

    system("pause");
    return 0;
}