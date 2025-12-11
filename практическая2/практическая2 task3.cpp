#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
bool isPrime(int n) {
    setlocale(0, "");
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    setlocale(0, "");
    const int VECTOR_SIZE = 10'000'000;
    const int PRIME_LIMIT = 500'000;

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Ãåíåðàöèÿ è ñ÷¸ò÷èêâåêòîðà " << VECTOR_SIZE << " ýëåìåíòû..." << std::endl;
    std::vector<int>data(VECTOR_SIZE);

    for (int i = 0; i < VECTOR_SIZE; ++i) {
        data[i] = rand() % 1000000;
    }
    std::sort(data.begin(), data.end());

    std::cout << "Âû÷èñëåíèå ïðîñòûõ÷èñåë ñ òî÷íîñòüþ äî " << PRIME_LIMIT << "..." << std::endl;
    int primeCount = 0;
    for (int i = 0; i < PRIME_LIMIT; ++i) {
        if (isPrime(i)) {
            primeCount++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>elapsed = end - start;
    std::cout << "\n--- Ðåçóëüòàò---" << std::endl;
    std::cout << "Íàèìåíüøèé ýëåìåíò: " << data[0] << std::endl;
    std::cout << "Íàèáîëüøèé ýëåìåíò: " << data[VECTOR_SIZE - 1] << std::endl;
    std::cout << "Íàéäåííûå ïðîñòûå ÷èñëà: " << primeCount << std::endl;
    std::cout << "Îáùåå âðåìÿ âûïîëíåíèÿ: " << elapsed.count() << " ñåêóíä" << std::endl;
    return 0;
}
