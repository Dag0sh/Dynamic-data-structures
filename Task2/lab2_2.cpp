#include <iostream>
#include <list>
#include <string>

using namespace std;

// Функция для проверки корректности ввода целого положительного числа
int getPositiveInteger() {
    int n;
    while (true) {
        cout << "Введите целое положительное число: ";
        cin >> n;

        if (cin.fail() || n <= 0 || n > 10) {
            cin.clear();  // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаем ввод
            cout << "Ошибка: введите корректное целое положительное число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаем буфер после ввода числа
            return n;
        }
    }
}

// Функция для проверки, содержит ли строка цифры
bool containsDigits(const string& str) {
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            return true;
        }
    }
    return false;
}

bool containsInList(const list<string>& vec, const string& str) {
    for (const string& s : vec) {
        if (s == str) {
            return false;
        }
    }
    return true;
}

// Функция для получения строки, которая не содержит цифр
string getStringWithoutDigitsp(const string& prompt, const list<string>& vec) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (containsDigits(input)) {
            cout << "Ошибка: строка не должна содержать цифры. Попробуйте снова.\n";
        } else if (containsInList(vec, input)) {
            cout << "Ошибка: такая строка не существует в списке. Попробуйте снова.\n";
        } else {
            return input;
        }
    }
}

string getStringWithoutDigits(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (containsDigits(input)) {
            cout << "Ошибка: строка не должна содержать цифры. Попробуйте снова.\n";
        } else {
            return input;
        }
    }
}

// Функция для формирования списка из n элементов
list<string> createList(int n) {
    list<string> list;

    for (int i = 0; i < n; ++i) {
        string newData = getStringWithoutDigits("Введите строку для элемента " + to_string(i + 1) + ": ");
        list.push_back(newData);
    }

    return list;
}

// Функция для вставки элемента после элемента со значением X
void insertAfter(list<string>& list, const string& X, const string& newValue) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == X) {
            list.insert(next(it), newValue);
            cout << "Элемент " << newValue << " вставлен после " << X << ".\n";
            return;
        }
    }
    cout << "Элемент со значением " << X << " не найден в списке.\n";
}

// Функция для удаления первого элемента списка
void deleteFirst(list<string>& list) {
    if (list.empty()) {
        cout << "Ошибка: список пуст.\n";
        return;
    }

    list.erase(list.begin());
    cout << "Первый элемент удалён.\n";
}

// Функция для смены местами первого и последнего элементов списка
void swapFirstAndLast(list<string>& list) {
    if (list.empty() || list.size() == 1) {
        cout << "Ошибка: недостаточно элементов в списке для обмена.\n";
        return;
    }

    swap(list.front(), list.back());
    cout << "Первый и последний элементы поменялись местами.\n";
}

// Функция для вывода списка
void printList(const list<string>& list) {
    if (list.empty()) {
        cout << "Список пуст.\n";
        return;
    }

    cout << "Список: ";
    for (const string& item : list) {
        cout << item << " -> ";
    }
    cout << "NULL\n";
}

int main() {
    list<string> list;
    int n;

    // Формирование списка
    n = getPositiveInteger();
    list = createList(n);

    printList(list);

    // Вставка элемента после элемента со значением X
    string X =
        getStringWithoutDigitsp("Введите значение X, после которого нужно вставить новый элемент: ", list);
    string newValue = getStringWithoutDigits("Введите значение нового элемента: ");

    insertAfter(list, X, newValue);

    printList(list);

    // Удаление первого элемента
    deleteFirst(list);

    printList(list);

    // Смена местами первого и последнего элементов
    swapFirstAndLast(list);

    printList(list);

    return 0;
}