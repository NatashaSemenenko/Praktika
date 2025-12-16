#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 

class RandomNumberGenerator {
private:
    std::vector<int> generatedNumbers; 
    std::mt19937 generator;           

public:
    RandomNumberGenerator() {
        std::random_device rd;
        generator.seed(rd());
    }

    std::vector<int> generateRandom(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        std::vector<int> result;

        for (int i = min; i <= max; ++i) {
            int value = distribution(generator);
            result.push_back(value);
            generatedNumbers.push_back(value);
        }

        return result;
    }

    std::vector<int> generateEven(int min, int max) {
        if (min % 2 != 0) {
            min++;
        }
        if (min > max) {
            return {};
        }

        std::vector<int> result;
        int count = (max - min) / 2 + 1; 

        for (int i = 0; i < count; ++i) {
            int value = min + i * 2;
            result.push_back(value);
            generatedNumbers.push_back(value);
        }

        return result;
    }

    std::vector<int> generateOdd(int min, int max) {
        if (min % 2 == 0) {
            min++;
        }
        if (min > max) {
            return {}; 
        }

        std::vector<int> result;
        int count = (max - min) / 2 + 1; 

        for (int i = 0; i < count; ++i) {
            int value = min + i * 2;
            result.push_back(value);
            generatedNumbers.push_back(value);
        }

        return result;
    }

    
    std::vector<int> getGeneratedArray() const {
        return generatedNumbers;
    }
};

int main() {
    setlocale(0,"");
    RandomNumberGenerator generator;

      
    std::vector<int> randomNumbers = generator.generateRandom(1, 10);
    std::cout << "Случайные числа: ";
    for (int num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    
    std::vector<int> evenNumbers = generator.generateEven(2, 10);
    std::cout << "Четные числа: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> oddNumbers = generator.generateOdd(1, 9);
    std::cout << "Нечетные числа: ";
    for (int num : oddNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> allGenerated = generator.getGeneratedArray();
    std::cout << "Все сгенерированные числа: ";
    for (int num : allGenerated) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
