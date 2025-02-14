#include <iostream>
#include <limits>
#include <vector>

int getInteger() {
    int value;
    while (true) {
        std::cin >> value;
        if (value <= -1000 || value >= 1000) {
            std::cin.clear();  // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем ввод
            std::cout << "Ошибка: введите число из (-1000, 1000).\n";
            std::cout << "Попробуйте снова: ";
        } else {
            return value;
        }
    }
}

// Функция для получения размера массива (целое положительное число)
int getArraySize() {
    int n;
    while (true) {
        std::cout << "Введите размер массива (целое положительное число от 1 до 10): ";
        n = getInteger();

        if (n > 0 && n <= 10) {
            return n;
        } else {
            std::cout << "Ошибка: размер массива должен быть положительным числом от 1 до 10.\n";
        }
    }
}

// Функция для ввода элементов массива
void fillArray(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Введите элемент массива [" << i << "] (-1000, 1000): ";
        arr[i] = getInteger();
    }
}

// Функция для нахождения суммы элементов между первым и последним нулями
int sumBetweenZeros(const std::vector<int>& arr) {
    int firstZeroIndex = -1;
    int lastZeroIndex = -1;

    // Поиск первого и последнего нулевых элементов
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;  // Запоминаем индекс первого нуля
            }
            lastZeroIndex = i;  // Обновляем индекс последнего нуля
        }
    }

    // Проверяем, найдены ли оба нуля
    if (firstZeroIndex == -1 || lastZeroIndex == -1 || firstZeroIndex == lastZeroIndex) {
        std::cout << "Ошибка: В массиве недостаточно нулевых элементов для выполнения операции.\n";
        return 0;
    }

    // Вычисляем сумму между первым и последним нулями
    int sum = 0;
    for (int i = firstZeroIndex + 1; i < lastZeroIndex; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    // Ввод размерности массива
    int size = getArraySize();

    // Создание вектора
    std::vector<int> array(size);

    // Ввод элементов массива
    fillArray(array);

    // Вычисление суммы элементов между первым и последним нулями
    int sum = sumBetweenZeros(array);

    // Вывод результата
    std::cout << "Сумма элементов между первым и последним нулями: " << sum << "\n";

    return 0;  // Нет необходимости очищать память, так как std::vector это делает автоматически
}