#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void clearQueue(queue<int> &q) {  // Очистка очереди
    while (!q.empty()) {
        q.pop();
    }
}

void clearStack(stack<int> &s) {  // Очистка стека
    while (!s.empty()) {
        s.pop();
    }
}

void printQueue(const queue<int> &q) {  // Вывод очереди на экран
    if (q.empty()) {
        cout << "Очередь пуста\n";
        return;
    }

    int i = 1;
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << i++ << "-й элемент очереди: " << temp.front() << endl;
        temp.pop();
    }
}

void printStack(const stack<int> &s) {  // Вывод стека на экран
    if (s.empty()) {
        cout << "Стек пуст\n";
        return;
    }

    int i = 1;
    stack<int> temp = s;  // Используем временный стек для итерации
    while (!temp.empty()) {
        cout << i++ << "-й элемент стека: " << temp.top() << endl;
        temp.pop();
    }
}

void solutionTask(queue<int> &q, stack<int> &s) {  // Решение задачи
    if (q.empty()) {
        cout << "ERROR: solutionTask()\nДана пустая очередь\n";
        return;
    }

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
}

// Проверка на корректность ввода
bool initInt(int &tempInt) {
    string str;
    cout << "\nВведите число -> ";
    cin >> str;

    // Проверка на пустую строку
    if (str.empty()) {
        cout << "Ошибка: ввод не должен быть пустым.\n";
        return false;
    }

    // Проверка, является ли строка числом
    size_t first = (str[0] == '-') ? 1 : 0;

    for (size_t i = first; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            cout << "Ошибка: ввод должен содержать только цифры.\n";
            return false;
        }
    }

    // Преобразование строки в число с проверкой диапазона
    try {
        tempInt = stoi(str);  // Преобразуем строку в число
    } catch (const out_of_range &) {
        cout << "Ошибка: число вне допустимого диапазона.\n";
        return false;
    } catch (const invalid_argument &) {
        cout << "Ошибка: ввод не является числом.\n";
        return false;
    }

    return true;  // Возвращает true, если число корректно
}

int main() {
    string input;
    int tempInt;
    queue<int> q;  // Объявляем очередь
    stack<int> s;  // Объявляем стек

    char c, attribute_c;
    cout << "МЕНЮ:\n";
    do {
        // Главное меню программы
        cout << "1. Создать очередь/стек (добавить первый элемент)\n"
             << "2. Добавить элемент в очередь/стек\n"
             << "3. Удаление элемента из очереди/стека\n"
             << "4. Очистка очереди/стека\n"
             << "5. Вывод очереди/стека\n"
             << "6. Преобразование из очереди в стек\n"
             << "0. Выход\n";

        // Проверка на корректность выбора пункта меню
        cin >> input;

        // Проверка длины ввода
        if (input.length() != 1 || (input[0] < '0' || input[0] > '6')) {
            cout << "Некорректный ввод. Попробуйте снова.\n";
            cin.clear();  // "блокировка" потока ввода, очистка флага ошибки
            cin.ignore(5, '\n');  // очистка оставшихся символов
            continue;
        }

        // Преобразование символа в char
        c = input[0];

        switch (c) {
            case '1':
                cout << "Что создать?\n1. Очередь\n2. Стек\n";
                cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Создание очереди или стека
                if (attribute_c == '1') {
                    if (initInt(tempInt))
                        q.push(tempInt);  // Создание очереди
                    else
                        cout << "Ошибка ввода числа.\n";
                } else {
                    if (initInt(tempInt))
                        s.push(tempInt);  // Создание стека
                    else
                        cout << "Ошибка ввода числа.\n";
                }
                break;

            case '2':
                cout << "Куда добавить элемент?\n1. Очередь\n2. Стек\n";
                cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Добавление элемента в очередь или стек
                if (attribute_c == '1') {
                    if (initInt(tempInt))
                        q.push(tempInt);  // Добавление в очередь
                    else
                        cout << "Ошибка ввода числа.\n";
                } else {
                    if (initInt(tempInt))
                        s.push(tempInt);  // Добавление в стек
                    else
                        cout << "Ошибка ввода числа.\n";
                }
                break;

            case '3':
                cout << "Откуда удалить элемент?\n1. Из очереди\n2. Из стека\n";
                cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Удаление элемента из очереди или стека
                if (attribute_c == '1') {
                    if (!q.empty())
                        q.pop();  // Удаление из очереди
                    else
                        cout << "Очередь пуста.\n";
                } else {
                    if (!s.empty())
                        s.pop();  // Удаление из стека
                    else
                        cout << "Стек пуст.\n";
                }
                break;

            case '4':
                cout << "Что очистить?\n1. Очередь\n2. Стек\n";
                cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Очистка очереди или стека
                if (attribute_c == '1') {
                    clearQueue(q);  // Очистка очереди
                } else {
                    clearStack(s);  // Очистка стека
                }
                break;

            case '5':
                cout << "Что вывести?\n1. Очередь\n2. Стек\n";
                cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Вывод элементов очереди или стека
                if (attribute_c == '1') {
                    printQueue(q);  // Вывод очереди
                } else {
                    printStack(s);  // Вывод стека
                }
                break;

            case '6':
                // Преобразование очереди в стек
                solutionTask(q, s);
                cout << "Очередь преобразована в стек.\n";
                break;

            case '0':
                cout << "Завершение программы.\n";
                break;

            default:
                cout << "Ошибка: такой команды нет.\n";
                break;
        }
    } while (input[0] != '0');

    clearQueue(q);  // Очистка очереди перед завершением
    clearStack(s);  // Очистка стека перед завершением

    return 0;
}