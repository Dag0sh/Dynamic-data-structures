#include <iostream>

// Функция для получения целого числа из диапазона (-1000, 1000)
int getInteger() {
    int value;
    while (true) {
        std::cin >> value;

        // Проверяем на ввод некорректного значения
        if (std::cin.fail() || value <= -1000 || value >= 1000) {
            std::cin.clear();  // Сбрасываем флаг ошибки
            while (std::cin.get() != '\n')
                ;  // Очищаем ввод до символа новой строки
            std::cout << "Ошибка: введите число из диапазона (-1000, 1000).\n";
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
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите элемент массива [" << i << "] (-1000, 1000): ";
        arr[i] = getInteger();
    }
}

// Функция для нахождения суммы элементов между первым и последним нулями
int sumBetweenZeros(const int arr[], int size) {
    int firstZeroIndex = -1;
    int lastZeroIndex = -1;

    // Поиск первого и последнего нулевых элементов
    for (int i = 0; i < size; ++i) {
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

    // Создание массива
    int array[10];  // Максимальный размер массива - 10 элементов

    // Ввод элементов массива
    fillArray(array, size);

    // Вычисление суммы элементов между первым и последним нулями
    int sum = sumBetweenZeros(array, size);

    // Вывод результата
    std::cout << "Сумма элементов между первым и последним нулями: " << sum << "\n";

    return 0;  // Память для массива очищать не нужно, так как он статический
}