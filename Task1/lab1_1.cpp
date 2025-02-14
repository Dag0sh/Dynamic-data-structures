#include <iostream>
using namespace std;

struct Queue {
    Queue *prev;
    int data;
};

// стек
struct Stack {
    Stack *prev;
    int data;
};
Queue *createQueue(int data) {
    Queue *newQueue = new Queue();
    newQueue->prev = nullptr;
    newQueue->data = data;
    return newQueue;
}

void addElemQueue(Queue **elem, int data) {  // функция добавления элемента в очередь
    if (!*elem) {  // проверка на существование указателя на "последний" элемент очереди
        std::cout << "ERROR: addElem()\nДана пустая очередь\n";
        return;
    }
    Queue *temp = *elem;
    while (temp->prev) temp = temp->prev;
    Queue *newElem = new Queue();
    newElem->prev = nullptr;
    newElem->data = data;
    temp->prev = newElem;
}

void delElemQueue(Queue **elem) {  // удаление элемента из очереди
    if (!*elem) {
        std::cout << "ERROR: delElem()\nДана пустая очередь\n";
        return;
    }
    Queue *temp = (*elem)->prev;
    delete *elem;
    *elem = temp;
}

int getInfoQueue(Queue **elem) {  // получение данных
    if (!*elem) {
        std::cout << "ERROR: getInfo()\nДана пустая очередь\n";
        return 0;
    }
    int temp = (*elem)->data;
    delElemQueue(elem);
    return temp;
}

void clearQueue(Queue **elem) {  // очистка очереди
    while (*elem) delElemQueue(elem);
}

void printQueue(Queue *elem) {  // вывод очереди на экран
    if (!elem) {
        std::cout << "Очередь пуста\n";
        return;
    }
    int i = 1;
    while (elem) {
        std::cout << i++ << "-й элемент очереди: " << elem->data << std::endl;
        elem = elem->prev;
    }
}

Stack *createStack(int data) {  // создание стека
    Stack *newStack = new Stack();
    newStack->prev = nullptr;
    newStack->data = data;
    return newStack;
}

void addElemStack(Stack **elem, int data) {  // добавление элемента в стек
    Stack *newElem = new Stack();
    newElem->prev = *elem;
    newElem->data = data;
    *elem = newElem;
}

void delElemStack(Stack **elem) {  // удаление элемента из стека
    if (!*elem) {
        std::cout << "ERROR: delElem()\nДан пустой стек\n";
        return;
    }
    Stack *temp = (*elem)->prev;
    delete *elem;
    *elem = temp;
}

void clearStack(Stack **elem) {  // очистка стека
    while (*elem) delElemStack(elem);
}

void printStack(Stack *elem) {  // вывод стека на экран
    if (!elem) {
        std::cout << "Стек пуст\n";
        return;
    }
    int i = 1;
    while (elem) {
        std::cout << i++ << "-й элемент стека: " << elem->data << std::endl;
        elem = elem->prev;
    }
}

void solutionTask(Queue **queue, Stack **stack) {  // решение задачи
    if (!*queue) {
        std::cout << "ERROR: solutionTask()\nДана пустая очередь\n";
        return;
    }

    while (*queue) {
        addElemStack(stack, getInfoQueue(queue));
    }
}

// проверка на корректность ввода ---------
bool initInt(int &tempInt) {
    std::string str;
    std::cout << "\nВведите число -> ";
    std::cin >> str;

    // Проверка на пустую строку
    if (str.empty()) {
        std::cout << "Ошибка: ввод не должен быть пустым.\n";
        return false;
    }

    // Проверка, является ли строка числом (с учетом возможного минуса в начале)
    size_t first = 0;
    if (str[0] == '-') {
        first = 1;  // Пропускаем проверку первого символа, если это минус
    }

    for (size_t i = first; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            std::cout << "Ошибка: ввод должен содержать только цифры.\n";
            return false;
        }
    }

    // Преобразование строки в число с проверкой диапазона
    try {
        tempInt = std::stoi(str);  // Преобразуем строку в число
    } catch (const std::out_of_range &) {
        std::cout << "Ошибка: число вне допустимого диапазона.\n";
        return false;
    } catch (const std::invalid_argument &) {
        std::cout << "Ошибка: ввод не является числом.\n";
        return false;
    }

    return true;  // Возвращает true, если число корректно
}

int main() {
    std::string input;
    int tempInt;
    Queue *queue = nullptr;
    Stack *stack = nullptr;

    char c, attribute_c;
    std::cout << "МЕНЮ:\n";
    do {
        // Главное меню программы
        std::cout << "1. Создать очередь/стек (добавить первый элемент)\n"
                  << "2. Добавить элемент в очередь/стек\n"
                  << "3. Удаление элемента из очереди/стека\n"
                  << "4. Очистка очереди/стека\n"
                  << "5. Вывод очереди/стека\n"
                  << "6. Преобразование из очереди в стек\n"
                  << "0. Выход\n";

        // Проверка на корректность выбора пункта меню
        // Считываем ввод как строку
        std::cin >> input;

        // Проверка длины ввода
        if (input.length() != 1 || (input[0] < '0' || input[0] > '6')) {
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            std::cin.clear();  // "блокировка" потока ввода, очистка флага ошибки
            std::cin.ignore(32767, '\n');  // очистка оставшихся символов
            continue;
        }

        // преобразование символа в char
        c = input[0];

        switch (c) {
            case '1':
                std::cout << "Что создать?\n1. Очередь\n2. Стек\n";
                std::cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    std::cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Создание очереди или стека
                if (attribute_c == '1') {
                    if (!queue && initInt(tempInt))
                        queue = createQueue(tempInt);  // Создание очереди
                    else if (!queue)
                        std::cout << "Ошибка ввода числа.\n";
                    else
                        std::cout << "Очередь уже создана.\n";
                } else {
                    if (!stack && initInt(tempInt))
                        stack = createStack(tempInt);  // Создание стека
                    else if (!stack)
                        std::cout << "Ошибка ввода числа.\n";
                    else
                        std::cout << "Стек уже создан.\n";
                }
                break;

            case '2':
                std::cout << "Куда добавить элемент?\n1. Очередь\n2. Стек\n";
                std::cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    std::cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Добавление элемента в очередь или стек
                if (attribute_c == '1') {
                    if (queue && initInt(tempInt))
                        addElemQueue(&queue, tempInt);  // Добавление в очередь
                    else if (queue)
                        std::cout << "Ошибка ввода числа.\n";
                    else
                        std::cout << "Очередь не создана.\n";
                } else {
                    if (stack && initInt(tempInt))
                        addElemStack(&stack, tempInt);  // Добавление в стек
                    else if (stack)
                        std::cout << "Ошибка ввода числа.\n";
                    else
                        std::cout << "Стек не создан.\n";
                }
                break;

            case '3':
                std::cout << "Откуда удалить элемент?\n1. Из очереди\n2. Из стека\n";
                std::cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    std::cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Удаление элемента из очереди или стека
                if (attribute_c == '1') {
                    if (queue)
                        delElemQueue(&queue);  // Удаление из очереди
                    else
                        std::cout << "Очередь пуста.\n";
                } else {
                    if (stack)
                        delElemStack(&stack);  // Удаление из стека
                    else
                        std::cout << "Стек пуст.\n";
                }
                break;

            case '4':
                std::cout << "Что очистить?\n1. Очередь\n2. Стек\n";
                std::cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    std::cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Очистка очереди или стека
                if (attribute_c == '1') {
                    if (queue)
                        clearQueue(&queue);  // Очистка очереди
                    else
                        std::cout << "Очередь пуста.\n";
                } else {
                    if (stack)
                        clearStack(&stack);  // Очистка стека
                    else
                        std::cout << "Стек пуст.\n";
                }
                break;

            case '5':
                std::cout << "Что вывести?\n1. Очередь\n2. Стек\n";
                std::cin >> attribute_c;
                if (attribute_c != '1' && attribute_c != '2') {
                    std::cout << "Ошибка: неверная команда.\n";
                    break;
                }
                // Вывод элементов очереди или стека
                if (attribute_c == '1') {
                    if (queue)
                        printQueue(queue);  // Вывод очереди
                    else
                        std::cout << "Очередь пуста.\n";
                } else {
                    if (stack)
                        printStack(stack);  // Вывод стека
                    else
                        std::cout << "Стек пуст.\n";
                }
                break;

            case '6':
                // Преобразование очереди в стек
                if (queue) {
                    solutionTask(&queue, &stack);
                    std::cout << "Очередь преобразована в стек.\n";
                } else
                    std::cout << "Очередь пуста.\n";
                break;

            case '0':
                std::cout << "Завершение программы.\n";
                break;

            default:
                std::cout << "Ошибка: такой команды нет.\n";
                break;
        }
    } while (input[0] != '0');

    clearQueue(&queue);  // Очистка очереди перед завершением
    clearStack(&stack);  // Очистка стека перед завершением

    return 0;
}